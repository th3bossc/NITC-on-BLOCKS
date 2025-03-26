#include "Transaction.h"

Transaction::Transaction(AccountName sender, AccountName receiver, int amount, int extraData) {
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
    this->extraData = extraData;

    int senderBalance = Account::get(sender);
    int receiverBalance = Account::get(receiver);

    if (senderBalance < amount) {
        this->valid = false;
    }
    else {
        this->valid = true;
        Account::set(sender, senderBalance - amount);
        Account::set(receiver, receiverBalance + amount);
    }

}

Transaction::~Transaction() {
    //TODO implement destructor
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

std::string Transaction::hash() {
    std::stringstream ss;
    ss << sender << receiver << amount;
    std::string result = ss.str();
    return Sha256::generateHash(result);
}

void Transaction::print() {
    std::cout << "['" << sender << "', '" << receiver << "', " << amount << ", " << extraData << "]";
}

bool Transaction::isValid() {
    return this->valid;
}