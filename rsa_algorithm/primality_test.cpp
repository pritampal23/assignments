#include "header.h"

int CheckWitness(const ZZ& n, ZZ& a){
    //First need to compute s, k such that n-1=2^s * k
    ZZ k;
    size_t s=0;
    k = n-1;
    while(bit(k, 0) == 0){
        s++;
        k = RightShift(k,1);
    }
    //Now check for a^k = +- 1(mod n)
    ZZ m;
    m = powermod(a, k, n);
    if(m == 1 || m == n-1)
        return 0;
    //Now check for a^(2^i*k) = -1(mod n) upto i < s
    for (size_t i = 1; i < s; i++)
    {
        m = powermod(m, ZZ(2), n);
        if(m == n-1)
            return 0;
    }
    return 1;
    
}

int PrimeTest(const ZZ& num){
    //We will run miller-robin test to find witness 64 time
    //so that the odds that the number is composite becomes 2^(-128)
    ZZ witness;
    cout << "Checking for witness....." << endl;
    for (size_t i = 0; i < 64; i++)
    {
        witness = RandomBnd(num);
        if(CheckWitness(num, witness)==1)
            return 0;
    }
    return 1;
}
