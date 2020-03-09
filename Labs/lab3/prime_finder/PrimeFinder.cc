#include <fstream>
#include <iostream>
#include <string>
#include "PrimeFinder.h"
using namespace std;

PrimeFinder::PrimeFinder(int range){
    this->range = range;
    string primesString = "";
    primesString.append(this->range, 'P');
    primesString = find_primes(primesString);
    add_primes(primesString);
}

string PrimeFinder::find_primes(string primesString){
    primesString[0] = 'C';
    primesString[1] = 'C';
    for(int i = 2; i < this->range; i++){
        for(int j = 2; i*j < this->range; j++){
            primesString[i*j] = 'C';
        }
    }
    return primesString;
}

void PrimeFinder::add_primes(string primesString){
    for(int i = 0; i < this->range; i++){
        if(primesString[i] == 'P'){
            this->primes.push_back(i);
        }
    }
}

void PrimeFinder::print_primes(int low, int high){
    cout << "### Primes between " << low << " and " << high << ": ";
    for(int i = 0; i < static_cast<int>(this->primes.size()); i ++){
        if(high < this->primes[i]){
            break;
        }        
        if(low < primes[i]){
            cout << primes[i] << " ";
        }
    }
    cout << endl;
}

void PrimeFinder::print_largest_prime(){
    int largestPrime = *max_element(this->primes.begin(), this->primes.end());
    cout << "### Largest prime for below " << this->range << ": " << largestPrime << endl;
}
