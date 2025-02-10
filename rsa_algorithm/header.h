#include<iostream>
#include<NTL/ZZ.h>
#include<openssl/rand.h>
#include<openssl/evp.h>
#include<cstring>

using namespace std;
using namespace NTL;

ZZ powermod(const ZZ& a, const ZZ& e, const ZZ& n);
int PrimeTest(const ZZ& num);
int CheckWitness(const ZZ& n, ZZ& a);
ZZ GenRandomNum(int bitlen);
ZZ GenRandomPrime(int bitlen);
void handleErrors();
void public_key( ZZ& p, ZZ& q, ZZ &n, ZZ &e);
ZZ secret_key(const ZZ& e, const ZZ& phi_n, ZZ &d);
int check_gcd(const ZZ& a, const ZZ& b);
ZZ ext_euclidean_algo(const ZZ &a, const ZZ& b);
ZZ encrypt(ZZ& m, ZZ& e, ZZ& n);
ZZ decrypt(ZZ &ciphertext, ZZ& d, ZZ& n);
