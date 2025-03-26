#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <unordered_map>

typedef char AccountName;

class Account {
private:
    static std::unordered_map<AccountName, int> balances;
public:

    static void insert(AccountName name, int balance);
    static int get(AccountName name);
    static bool has(AccountName name);
    static void set(AccountName name, int value);
};


#endif