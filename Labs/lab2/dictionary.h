#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <unordered_set>
#include <string>
#include <vector>
#include "word.h"
using namespace std;

class Dictionary {
public:
    static const unsigned int MAX_LENGTH = 25;
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
    unordered_set<string> wordSet;
    vector<Word> words[MAX_LENGTH];
    void add_trigram_suggestions(vector<string>&, const string) const;
    void rank_suggestions(vector<string> &, const string ) const;
    void trim_suggestions(vector<string> &) const;
};

#endif
