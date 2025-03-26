#ifndef SHA_256_H
#define SHA_256_H

#include <string>
#include <openssl/evp.h>
#include <iomanip>
#include <iostream>

class Sha256 {
public:
    static std::string generateHash(const std::string& input);
};


#endif