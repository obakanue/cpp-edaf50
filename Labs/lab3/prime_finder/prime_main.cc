#include <iostream>
#include <fstream>
#include "PrimeFinder.h"
using namespace std;

int main(){

    PrimeFinder prime_finder(100000);
    prime_finder.print_primes(1, 200);
    prime_finder.print_largest_prime();
    
    return 0;
}
