#include "Sha256.h"

std::string Sha256::generateHash(const std::string& input) {
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int length = 0;

    EVP_MD_CTX* context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(context, EVP_sha3_256(), nullptr);
    EVP_DigestUpdate(context, input.c_str(), input.size());
    EVP_DigestFinal_ex(context, hash, &length);
    EVP_MD_CTX_free(context);

    std::ostringstream hexStream;
    for (unsigned int i = 0; i < length; i++)
        hexStream << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];


    return hexStream.str();
}