#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "../Sha3/Sha256.h"
#include "../Account/Account.h"
#include <iostream>
#include <string>
class Transaction {
private:
    AccountName sender;
    AccountName receiver;
    int amount;
    int extraData;
    bool valid;

public:
    Transaction(AccountName sender, AccountName receiver, int amount, int extraData);
    ~Transaction();

    AccountName getSender();
    AccountName getReceiver();
    int getAmount();
    std::string hash();
    void print();
    bool isValid();

};

#endif