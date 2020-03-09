#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PrimeFinder{
public:
    PrimeFinder(int range);
    void print_primes(int low, int high);
    void print_largest_prime();
   private:
    vector<int> primes;
    int range;
    string find_primes(string primesString);
    void add_primes(string primesString);
};
#endif
