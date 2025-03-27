#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "../Sha3/Sha256.h"
#include "../Account/Account.h"
#include <iostream>
#include <string>
class Transaction {
private:
    AccountName _sender;
    AccountName _receiver;
    int _amount;
    int _incentive;
    bool valid;

public:
    Transaction(AccountName sender, AccountName receiver, int amount, int incentive);
    ~Transaction();

    AccountName sender();
    bool validate();
    AccountName receiver();
    int amount();
    int incentive();
    std::string hash();
    void print();
    bool isValid();

};

#endif