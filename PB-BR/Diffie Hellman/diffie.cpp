#include<iostream>

long exhaustiveSearch(long p, long g, long t);
using namespace std;
int main() {

    long p, g, a, b;

    // 25 Bit
    p = 131231564657789987221314359;  /* the prime */
    g = 483905;         /* the generator */
    a = 38289573795047443088133899;   /* the logarithm of a */
    b = 6676335;   /* the logarithm of b */

    exhaustiveSearch(p, g, a);
    //exhaustiveSearch(p, g, b);

    return 0;
}

long exhaustiveSearch(long p, long g, long t) {
    long i, x;
    i = 0;
    x = 1;
    while ((x = (x % p)) != t) {
        i++;
        x = x * g;
    }
    cout << endl << endl << "p = " << p << endl << "g = " << g << endl << "t = " << t << endl << "secret: = " << i << endl;
    return i;
}
