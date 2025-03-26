#ifndef BLOCK_H
#define BLOCK_H

#include "../Transaction/Transaction.h"

class Block {
private:
    int blokNumber;
    // merkleRoot
    Transaction transactions;
}

#endif