#include <string>
#include <vector>
#include "word.h"
using namespace std;

Word::Word(const string& w, const vector<string>& t) {
    this->word = w;
    this->trigrams = t;
}

string Word::get_word() const {
	return this->word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
    auto matches = 0;
    auto trigramsSize = this->trigrams.size();
    auto tSize = t.size();
    unsigned int i = 0;
    unsigned int j = 0;
    while(i < trigramsSize && j < tSize){
        if (this->trigrams.at(i) == t.at(j)){
            ++matches;
            ++i;
            ++j;
        } else if (this->trigrams.at(i) > t.at(j)){
            ++j;
        } else {
            ++i;
        }
    }
   	return matches;
}
