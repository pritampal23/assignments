#include "header.h"

int check_gcd(const ZZ& a, const ZZ& b){

    ZZ r0=ZZ(a), r1=ZZ(b), r2;
    ZZ quotient;
    
    while(r0 % r1 != 0){
        quotient = r0/r1;
        r2 = r0 - quotient * r1;

        r0 = r1;
        r1 = r2;
        
    }
    if(r1 == 1)
        return 1;
    else
        return 0; 
}

ZZ ext_euclidean_algo(const ZZ &a, const ZZ& b){

    ZZ r0=ZZ(a), r1=ZZ(b), r2, s0=ZZ(1), s1=ZZ(0), s2, t0=ZZ(0), t1=ZZ(1), t2;
    ZZ quotient;
    
    while(r0 % r1 != 0){
        quotient = r0/r1;
        r2 = r0 - quotient * r1;
        s2 = s0 - quotient * s1;
        t2 = t0 - quotient * t1;

        r0 = r1;
        r1 = r2;
        s0 = s1;
        s1 = s2;
        t0 = t1; 
        t1 = t2;
    }
    return s1;
}