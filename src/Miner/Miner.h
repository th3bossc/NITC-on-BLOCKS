#ifndef MINER_H
#define MINER_H

#include <iostream>
#include <string>
#define HASH_SCORE_ARRAY_SIZE 8

class Miner {
private:
    char _name;
    int computationScore;
    int blockHashScoreArray[HASH_SCORE_ARRAY_SIZE];

public:
    Miner(char name, int computation_score, int block_hash_score_array[HASH_SCORE_ARRAY_SIZE]);
    ~Miner();
    void print();
    char name();
    int computeSealingScore(int blockNumber);

    bool operator== (const Miner& other);
};

#endif