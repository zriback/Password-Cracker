#include "hashes.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

#include <openssl/evp.h>

void hash_md5(const char *hashTypeStr, const unsigned char *message, size_t message_len, unsigned char **digest, unsigned int *digest_len) {
	
	const EVP_MD *hashType = getHashType(hashTypeStr);
	if (hashType == NULL){
		std::cout << "Not a valid hash type\n";
		exit(1);
	}

	EVP_MD_CTX *mdctx;

	if((mdctx = EVP_MD_CTX_new()) == NULL) {std::cout << "Error computing hash\n"; }

	if(1 != EVP_DigestInit_ex(mdctx, hashType, NULL)) {std::cout << "Error computing hash\n"; }

	if(1 != EVP_DigestUpdate(mdctx, message, message_len)) {std::cout << "Error computing hash\n"; }

	if((*digest = (unsigned char *)OPENSSL_malloc(EVP_MD_size(hashType))) == NULL) {std::cout << "Error computing hash\n"; }

	if(1 != EVP_DigestFinal_ex(mdctx, *digest, digest_len)) {std::cout << "Error computing hash\n"; }

	EVP_MD_CTX_free(mdctx);
}

/*
Takes type in string format and returns the correct EVP_MD pointer for it from openssl/evp.h
Returns NULL if hash type is not supported
*/
const EVP_MD* getHashType(const char * type){
	if (strcmp(type, "md5") == 0){
		return EVP_md5();
	}
	else if (strcmp(type, "sha1") == 0){
		return EVP_sha1();
	}
	else if (strcmp(type, "sha256") == 0){
		return EVP_sha256();
	}
	else if (strcmp(type, "sha512") == 0){
		return EVP_sha512();
	}
	else{
		return NULL;
	}
}