#include "header.h"


void public_key( ZZ& p, ZZ& q, ZZ &n, ZZ &e){
    n = p * q;
    ZZ a = p-1, b = q-1;
    // e should be coprime to (p-1) and (q-1)
    while (1)
    {
        e = RandomBnd(n);
        if (check_gcd(e, a) && check_gcd(e, b))
            break;
    }

}
ZZ encrypt(ZZ& m, ZZ& e, ZZ& n){
    return powermod(m, e, n);
}
ZZ decrypt(ZZ &ciphertext, ZZ& d, ZZ& n){
    return powermod(ciphertext, d, n);
}
int main(){
    //Generate two prime nukbers p,q
    size_t bitlen = 2048;
    ZZ p,q;
    p = GenRandomPrime(bitlen);
    q = GenRandomPrime(bitlen);
    cout << "Two primes generated" << endl;
    // Generate public keys
    ZZ n, e;
    public_key(p, q, n,e);
    cout << "public keys generated" << endl;
    // Generate Private key
    ZZ d, phi_n;
    phi_n = (p-1)*(q-1);
    d = ext_euclidean_algo(e,phi_n);
    cout << "secret keys generated" << endl;
    //Example
    // m = 7884725671
    //Encryption
    ZZ m = ZZ(7884725671);
    ZZ ciphertext = encrypt(m, e, n);
    cout << "Encrypted message = " << ciphertext << endl;
    
    //Decryption
    ZZ decrypted_mes = decrypt(ciphertext, d, n);
    if(m == decrypted_mes)
        cout <<"Decryption Succesfull" <<endl;
    cout << "Decrypted message = " << decrypted_mes << endl;

    return 0;
    
}
