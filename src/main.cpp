#include <iostream>
#include "Blockchain/Blockchain.h"
#include <math.h>
#include <algorithm>
#include "Miner/Miner.h"
using namespace std;


int main() {

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

    int blockReward;
    cin >> blockReward;

    int numMiners;
    cin >> numMiners;

    vector<Miner> miners;
    for (int i = 0; i < numMiners; i++) {
        char name;
        int computationScore;
        int blockHashScoreArray[HASH_SCORE_ARRAY_SIZE];

        cin >> name;
        cin >> computationScore;
        for (int j = 0; j < HASH_SCORE_ARRAY_SIZE; j++)
            cin >> blockHashScoreArray[j];

        auto miner = Miner(name, computationScore, blockHashScoreArray);
        miners.push_back(miner);
        Account::insert(miner.name(), 0);
    }

    auto blockchain = Blockchain(miners, blockReward);

    sort(transactions.begin(), transactions.end(), [&](Transaction& t1, Transaction& t2) {
        if (t1.incentive() > t2.incentive()) {
            return true;
        }
        else if (t1.incentive() == t2.incentive()) {
            if (t1.receiver() < t2.receiver())
                return true;
        }

        return false;
        }
    );

    for (auto& transaction : transactions) {
        if (transaction.validate())
            blockchain.insert(transaction);
    }

    blockchain.print();
}