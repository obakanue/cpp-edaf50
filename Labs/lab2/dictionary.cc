#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
using namespace std;

Dictionary::Dictionary() {
    const string PATH = "words.txt";
    ifstream words(PATH);
    if (!words) cerr << "File 'words.txt' is not found in folder" <<
        " '/Users/sofiflink/Skola/Pågående Kurser/C++-programmering" << 
            " EDAF50/cpp-edaf50/Labs/lab2/dict/'." << endl;
    else{
        string word;
        int nbrTrigrams;
        while (words >> word){
            auto firstWord = word;
            words >> nbrTrigrams;
            vector<string> trigrams;
            for(int i = 0; i < nbrTrigrams; i++){
                words >> word;
                trigrams.push_back(word);
            }
            if(word.length() < Dictionary::MAX_LENGTH){
                this->wordSet.insert(word);
                this->words[word.length()].push_back(Word(word, trigrams));    
            }
        }
    }
}

bool Dictionary::contains(const string& word) const {
	return this->wordSet.find(word) != this->wordSet.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
