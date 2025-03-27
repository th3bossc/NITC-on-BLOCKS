#include "Transaction.h"

Transaction::Transaction(AccountName sender, AccountName receiver, int amount, int incentive) {
    this->_sender = sender;
    this->_receiver = receiver;
    this->_amount = amount;
    this->_incentive = incentive;
}

Transaction::~Transaction() {
    //TODO implement destructor
}

bool Transaction::validate() {
    int senderBalance = Account::get(_sender);
    int receiverBalance = Account::get(_receiver);

    if (senderBalance < _amount) {
        this->valid = false;
        return false;
    }
    else {
        this->valid = true;
        Account::set(_sender, senderBalance - _amount);
        Account::set(_receiver, receiverBalance + _amount);
        return true;
    }

}

AccountName Transaction::sender() {
    return this->_sender;
}

AccountName Transaction::receiver() {
    return this->_receiver;
}

int Transaction::amount() {
    return this->_amount;
}

int Transaction::incentive() {
    return this->_incentive;
}

std::string Transaction::hash() {
    std::stringstream ss;
    ss << _sender << _incentive << _receiver << _amount;
    std::string result = ss.str();
    return Sha256::generateHash(result);
}

void Transaction::print() {
    std::cout << "['" << _sender << "', '" << _receiver << "', " << _amount << ", " << _incentive << "]";
}

bool Transaction::isValid() {
    return this->valid;
}