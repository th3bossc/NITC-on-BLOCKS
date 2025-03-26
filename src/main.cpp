#include <iostream>
#include "Blockchain/Blockchain.h"
#include <math.h>
#include <algorithm>
using namespace std;

#define NUM_TRANSACTIONS_PER_NODE 4


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
        int incentive;

        cin >> sender >> receiver >> amount >> incentive;

        auto transaction = Transaction(
            sender,
            receiver,
            amount,
            incentive
        );

        transactions.push_back(transaction);
    }

    sort(transactions.begin(), transactions.end(), [&](Transaction& t1, Transaction& t2) {
        if (t1.getIncentive() > t2.getIncentive()) {
            return true;
        }
        else if (t1.getIncentive() == t2.getIncentive()) {
            if (t1.getReceiver() < t2.getReceiver())
                return true;
        }

        return false;
        });



    vector<Transaction> validTransactions;
    for (auto& transaction : transactions) {
        if (transaction.validate()) {
            validTransactions.push_back(transaction);
            numValidTransactions++;
        }
    }

    int numBlocks = ceil(numValidTransactions / NUM_TRANSACTIONS_PER_NODE);

    for (int i = 0; i < numValidTransactions; i += NUM_TRANSACTIONS_PER_NODE) {
        int start = i;
        int end = min(i + NUM_TRANSACTIONS_PER_NODE, numValidTransactions);

        vector<Transaction> subset;
        for (int j = start; j < end; j++)
            subset.push_back(validTransactions[j]);

        auto block = Block(subset, blockchain.tail());

        blockchain.insert(block);
    }

    blockchain.print();
}