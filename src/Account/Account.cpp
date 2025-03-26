#include "Account.h"

std::unordered_map<AccountName, int> Account::balances;


void Account::insert(AccountName name, int balance) {
    if (Account::has(name))
        return;

    balances[name] = balance;
}

int Account::get(AccountName name) {
    return balances[name];
}

bool Account::has(AccountName name) {
    return (balances.count(name) != 0);
}

void Account::set(AccountName name, int balance) {
    balances[name] = balance;
}