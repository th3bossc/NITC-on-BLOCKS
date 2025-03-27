# NITC ON BLOCKS

## Overview
This is an implementation of the NITC On Blocks repository which gives a basic understanding on the logic behind blockchain architecture 
Refer the [documentation](https://nitc-on-blocks.netlify.app/) for more details regarding how to do it on your own


## Setup
- clone the repo
```bash
git clone https://github.com/th3bossc/NITC-on-BLOCKS.git
```

- build the binary
```bash
make clean && make
```

- run the code
```bash
make run
```

## Usage
The inputs are taken in the following format
```python
read(numAccounts: int)
for _ in range(numAccounts):
    read(accountName: char)
    read(accountBalance: int)

read(numTransactions: int)
for _ in range(numTransactions):
    read(sender: char)
    read(receiver: char)
    read(amount: int)
    read(incentive: int)

read(blockReward: int)

read(numMiners: int)
for _ in range(numMiners):
    read(name: char)
    read(compuationScore: int)
    for i in range(HASH_SCORE_ARRAY_SIZE): # HASH_SCORE_ARRAY_SIZE = 8
        read(blockHashScoreArray[i])
```

The outputs will be displayed in the order
```python
=== Blockchain ===
for block in blocks:
    write(block.blockNumber)
    write(block.blockHash)
    write(block.trasactions)
    write(block.merkleTreeHash)
    write(block.nonce) write(block.minerForBlock)
```