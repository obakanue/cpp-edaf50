#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

tuple<int, string> getTrigrams(const string &word)
{   
    vector<string> trigramsVector;
    string trigrams = "";
    if(word.length() >= 3){
        for (unsigned int i = 0; i + 3 <= word.length(); i++){
            string s;
            s.append(word, i, 3);
            trigramsVector.push_back(s);
        }

        sort(trigramsVector.begin(), trigramsVector.end());
        for (long unsigned int i = 0; i < trigramsVector.size(); ++i){
            trigrams.append(trigramsVector.at(i) + " ");
            }
    }
    return {trigramsVector.size(), trigrams};
}

void preprocess(ifstream &input, ofstream &output)
{
    string word;
    while (getline(input, word)){
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        auto [trigramsSize, trigrams] = getTrigrams(word);
        output << word << " " << trigramsSize << " " << trigrams << endl;
    }
}

int main()
{
    const string PATH = "/Users/sofiflink/Skola/Pågående Kurser/C++-programmering EDAF50/cpp-edaf50/Labs/lab2/dict/words";
    ifstream input(PATH);
    if (!input) cerr << "File 'words' is not found in folder" <<
        " '/Users/sofiflink/Skola/Pågående Kurser/C++-programmering EDAF50/cpp-edaf50/Labs/lab2/dict/'." << endl;
    else{
        ofstream output("words.txt");
        preprocess(input, output);
    }

}
