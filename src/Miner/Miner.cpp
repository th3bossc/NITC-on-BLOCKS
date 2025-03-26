#include "Miner.h"

Miner::Miner(char name, int computation_score, int blockHashScoreArray[HASH_SCORE_ARRAY_SIZE]) {
    this->name = name;
    this->computationScore = computation_score;

    for (int i = 0; i < HASH_SCORE_ARRAY_SIZE; i++) {
        this->blockHashScoreArray[i] = blockHashScoreArray[i];
    }
}


Miner::~Miner() {
    // TODO destroctor
}

void Miner::print() {
    // TODO print the thing
}

char Miner::getName() {
    return this->name;
}

int Miner::computeSealingScore(int blockNumber) {
    return computationScore * blockHashScoreArray[blockNumber % HASH_SCORE_ARRAY_SIZE];
}