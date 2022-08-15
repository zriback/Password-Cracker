# Password-Cracker

This is an incredibly simple yet effective hash cracker written in C++. Given a hashing algorithm, the hash itself, and a wordlist it is able to crack the hash through brute force.

# Usage

Compile the main directory using the command

```g++ ./main/*.cpp -o passcracker.exe -lcrypto -lssl```

then run ```passcracker.exe``` with the following command line arguments:

```./passcracker.exe [hash type] [target hash] [word list]```

As of 8/15/2022, the supported hash types are 
* md5
* sha1
* sha256
* sha512

