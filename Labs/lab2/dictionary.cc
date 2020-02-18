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
        string wordLine;
        while (getline(words, wordLine)){
            wordSet.insert(wordLine.substr(0, wordLine.find(" ")));
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
