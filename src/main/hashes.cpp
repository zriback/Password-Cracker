#include "hashes.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

#include <openssl/evp.h>

void hash_md5(const unsigned char *message, size_t message_len, unsigned char **digest, unsigned int *digest_len) {
	
	EVP_MD_CTX *mdctx;

	if((mdctx = EVP_MD_CTX_new()) == NULL) {std::cout << "Error computing md5 hash"; }

	if(1 != EVP_DigestInit_ex(mdctx, EVP_md5(), NULL)) {std::cout << "Error computing md5 hash"; }

	if(1 != EVP_DigestUpdate(mdctx, message, message_len)) {std::cout << "Error computing md5 hash"; }

	if((*digest = (unsigned char *)OPENSSL_malloc(EVP_MD_size(EVP_md5()))) == NULL) {std::cout << "Error computing md5 hash"; }

	if(1 != EVP_DigestFinal_ex(mdctx, *digest, digest_len)) {std::cout << "Error computing md5 hash"; }

	EVP_MD_CTX_free(mdctx);
}