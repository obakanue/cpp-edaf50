#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
using namespace std;

bool check_length(const unsigned int &length){
    return length < Dictionary::MAX_LENGTH;
}

Dictionary::Dictionary() {
    const string PATH = "words.txt";
    ifstream words(PATH);
    if (!words) cerr << "File 'words.txt' is not found in folder" <<
        " '/Users/sofiflink/Skola/Pågående Kurser/C++-programmering" << 
            " EDAF50/cpp-edaf50/Labs/lab2/'." << endl;
    else{
        string str;
        int nbrTrigrams;
        while (words >> str){
            auto firstWord = str;
            words >> nbrTrigrams;
            vector<string> trigrams;
            for(auto i = 0; i < nbrTrigrams; i++){
                words >> str;
                trigrams.push_back(str);
            }
            if(check_length(firstWord.length())){
                this->wordSet.insert(firstWord);
                this->words[firstWord.length()].push_back(Word(firstWord, trigrams));    
            }
        }
    }
}

bool Dictionary::contains(const string &word) const {
	return this->wordSet.find(word) != this->wordSet.end();
}

vector<string> Dictionary::get_suggestions(const string &word) const {
	vector<string> suggestions;
    add_trigram_suggestions(suggestions, word);
    rank_suggestions(suggestions, word);
    trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const string word) const{
    auto length = 0;
    length = word.length();
    if(!check_length(length)){ 
        return;
    }
    
    vector<Word> words = this->words[length];
    if (length > 0){
        words.insert(words.end(), this->words[length - 1].begin(), 
        this->words[length - 1].end());
    }

    if (length + 1 <= static_cast<int>(Dictionary::MAX_LENGTH)){
        words.insert(words.end(), this->words[length + 1].begin(), 
        this->words[length + 1].end());
    }    

    vector<string> trigrams;
    if (length >= 3){
        for (auto i = 0; i + 3 <= length; ++i){
            string str;
            str.append(word, i, 3);
            trigrams.push_back(str);
        }
        sort(trigrams.begin(), trigrams.end());
    }
    
    for (Word suggestion : words){
        if (suggestion.get_matches(trigrams) >= trigrams.size() / 2){
            suggestions.push_back(suggestion.get_word());
        }
    }
}

int levenshtein_distance(const string &word, const string &suggestion){
    // for all i and j, d[i,j] will hold the Levenshtein distance between
    // the first i characters of s and the first j characters of t
    // set each element in d to zero
    int d[Dictionary::MAX_LENGTH + 1][Dictionary::MAX_LENGTH + 1];

    // source prefixes can be transformed into empty string by
    // dropping all characters
    for (unsigned int i = 0; i <= word.length(); ++i){
        d[i][0] = i;
    }

    // target prefixes can be reached from empty source prefix
    // by inserting every character
    for (unsigned int j = 0; j <= suggestion.length(); ++j){
        d[0][j] = j;
    }
    
    for (unsigned int i = 1; i <= word.length(); ++i){
        auto substitutionCost = 0;
        for (unsigned int j = 1; j <= suggestion.length(); ++j){

            cout << "i: " << i << " j: " << j << " " << word << endl;
            if(word.at(i - 1) == suggestion.at(j - 1)){
                substitutionCost = 0;
            } else {
                substitutionCost = 1;
            }
            auto temp = min((d[i-1][j] + 1), (d[i][j-1] + 1));
            d[i][j] = min(temp, (d[i-1][j-1]+substitutionCost));
        }
        
    }
    return d[word.length()][suggestion.length()];
}

bool compare_distance(pair<int, string> &pair1, pair<int, string> &pair2){
    return pair1.first < pair2.first;
}

void Dictionary::rank_suggestions(vector<string> &suggestions, const string word) const{
    vector< pair<int, string> > pairs;
    for (string suggestion : suggestions){
        int dist = levenshtein_distance(word, suggestion);
        pairs.push_back(make_pair(dist, suggestion));
    }

    sort(pairs.begin(), pairs.end(), compare_distance);
    suggestions.clear();

    for (unsigned int i = 0; i < pairs.size(); ++i){
        auto suggestion = pairs.at(i).second;
        suggestions.push_back(suggestion);
    }

}

void Dictionary::trim_suggestions(vector<string> &suggestions) const{
    if(suggestions.size() > 5){
        suggestions.resize(5);
    }
}
