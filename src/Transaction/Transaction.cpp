#include "Transaction.h"

Transaction::Transaction(AccountName sender, AccountName receiver, int amount, int incentive) {
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
    this->incentive = incentive;
}

Transaction::~Transaction() {
    //TODO implement destructor
}

bool Transaction::validate() {
    int senderBalance = Account::get(sender);
    int receiverBalance = Account::get(receiver);

    if (senderBalance < amount) {
        this->valid = false;
        return false;
    }
    else {
        this->valid = true;
        Account::set(sender, senderBalance - amount);
        Account::set(receiver, receiverBalance + amount);
        return true;
    }

}

AccountName Transaction::getSender() {
    return this->sender;
}

AccountName Transaction::getReceiver() {
    return this->receiver;
}

int Transaction::getAmount() {
    return this->amount;
}

int Transaction::getIncentive() {
    return this->incentive;
}

std::string Transaction::hash() {
    std::stringstream ss;
    ss << sender << incentive << receiver << amount;
    std::string result = ss.str();
    return Sha256::generateHash(result);
}

void Transaction::print() {
    std::cout << "['" << sender << "', '" << receiver << "', " << amount << ", " << incentive << "]";
}

bool Transaction::isValid() {
    return this->valid;
}