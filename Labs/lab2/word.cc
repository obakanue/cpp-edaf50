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
    auto trigramsSize = trigrams.size();
    auto tSize = t.size();
    auto length = 0;
    if(trigramsSize <= tSize){
        length = trigramsSize;
    } else {
        length = tSize;
    }
    for(int i = 0; i < length; i++){
        if (this->trigrams.at(i) == t.at(i)){
            ++matches;
        }
    }
	return matches;
}
