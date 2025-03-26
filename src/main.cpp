#include <iostream>
#include "Blockchain/Blockchain.h"
#include <math.h>
using namespace std;

#define NUM_TRANSACTIONS_PER_NODE 3


int main(int argc, char* argv[]) {
    auto blockchain = Blockchain();

    int numAccounts;
    cin >> numAccounts;

    for (int i = 0; i < numAccounts; i++) {
        AccountName name;
        int balance;

        cin >> name >> balance;

        Account::insert(name, balance);
    }

    int numTransactions;
    cin >> numTransactions;
    int numValidTransactions = 0;

    vector<Transaction> transactions;
    for (int i = 0; i < numTransactions; i++) {
        AccountName sender;
        AccountName receiver;
        int amount;
        int extraData;

        cin >> sender >> receiver >> amount >> extraData;

        auto transaction = Transaction(
            sender,
            receiver,
            amount,
            extraData
        );

        if (transaction.isValid()) {
            transactions.push_back(transaction);
            numValidTransactions++;
        }
    }

    int numBlocks = ceil(numValidTransactions / NUM_TRANSACTIONS_PER_NODE);

    for (int i = 0; i < numValidTransactions; i += NUM_TRANSACTIONS_PER_NODE) {
        int start = i;
        int end = min(i + NUM_TRANSACTIONS_PER_NODE, numValidTransactions);

        vector<Transaction> subset;
        for (int j = start; j < end; j++)
            subset.push_back(transactions[j]);

        auto block = Block(subset, blockchain.tail());

        blockchain.insert(block);
    }

    blockchain.print();
}