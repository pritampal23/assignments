#include<iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "Enter two positive integers: " << endl;
    int a,b;
    cin >> a;
    cin >> b;
    
    int r0=fabs(a), r1=fabs(b), r2, s0=1, s1=0, s2, t0=0, t1=1, t2;
    int quotient;
    
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
    cout << "gcd (" << a << "," << b << ") = " << r1 << endl;
    cout << a << "*" << s1 << "+" << b << "*" << t1 << " = " << r1<<endl; 
}

