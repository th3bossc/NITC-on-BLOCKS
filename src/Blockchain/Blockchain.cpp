#include "Blockchain.h"

Blockchain::Blockchain() {
    this->_head = NULL;
    this->_tail = NULL;
}

Blockchain::Blockchain(std::vector<Miner>& miners, int blockReward) {
    this->_head = NULL;
    this->_tail = NULL;
    this->miners = miners;
    this->blockReward = blockReward;
}

Blockchain::~Blockchain() {
    // TODO destructor
}


// void Blockchain::insert(Block block) {
//     this->blocks.push_back(block);
// }

void Blockchain::insert(Transaction& transaction) {
    Block* lastBlock = this->tail();
    if (lastBlock == NULL || lastBlock->full()) {
        Block* newBlock = new Block(lastBlock);
        newBlock->insert(transaction);
        appendBlock(newBlock);

        if (lastBlock != NULL) {
            auto minerForBlock = getMinerForBlock(*lastBlock);
            char minerId = minerForBlock->name();
            lastBlock->setMiner(minerId);
            int currentMinerBalance = Account::get(minerId);
            Account::set(minerId, currentMinerBalance + blockReward);
        }
    }
    else {
        lastBlock->insert(transaction);
        if (lastBlock->full()) {
            auto minerForBlock = getMinerForBlock(*lastBlock);
            char minerId = minerForBlock->name();
            lastBlock->setMiner(minerId);
            int currentMinerBalance = Account::get(minerId);
            Account::set(minerId, currentMinerBalance + blockReward);
        }
    }
}

void Blockchain::appendBlock(Block* block) {
    if (_head == NULL)
        _head = block;
    _tail = block;
}

void Blockchain::validate() {
    Block* lastBlock = this->tail();
    if (lastBlock != NULL) {
        auto minerForBlock = getMinerForBlock(*lastBlock);
        char minerId = minerForBlock->name();
        lastBlock->setMiner(minerId);
        int currentMinerBalance = Account::get(minerId);
        Account::set(minerId, currentMinerBalance + blockReward);
    }
}

void Blockchain::attachMiner(Miner& miner) {
    this->miners.push_back(miner);
}

void Blockchain::detachMiner(Miner& miner) {
    this->miners.erase(std::remove(miners.begin(), miners.end(), miner), miners.end());
}

void Blockchain::print() {
    std::cout << " == Blockchain == " << std::endl;

    for (auto it = this->_head; it != NULL; it = it->next()) {
        it->print();
    }

    std::cout << std::endl;
}

Block* Blockchain::tail() {
    if (this->_head == NULL)
        return NULL;
    return this->_tail;
}

Miner* Blockchain::getMinerForBlock(Block& block) {
    int blockNumber = block.getBlockNumber();
    Miner* minerForBlock = NULL;
    int maxBlockSealingScore = -1;
    for (auto& miner : miners) {
        int sealingScore = miner.computeSealingScore(blockNumber);
        if (sealingScore > maxBlockSealingScore) {
            minerForBlock = &miner;
            maxBlockSealingScore = sealingScore;
        }
    }
    return minerForBlock;
}