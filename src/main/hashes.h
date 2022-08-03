#ifndef HASHES_HEADER
#define HASHES_HEADER

#include <stdio.h>
#include <openssl/evp.h>

void hash_md5(const unsigned char *message, size_t message_len, unsigned char **digest, unsigned int *digest_len);

#endif