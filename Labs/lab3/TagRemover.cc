#include <fstream>
#include <iostream>
#include <string>
#include "TagRemover.h"
using namespace std;
using std::string;

TagRemover::TagRemover(istream &file){
    string line;
    while(getline(file, line)){
        this -> html += line + "\n";
    }
    remove_tags();
    // process_special_chars();
}

void TagRemover::remove_tags(){
    cout << "####Start.####" << endl;
    while(this->html.find_first_of('<') != string::npos && this->html.find_first_of('>') != string::npos){
        auto first = this->html.find_first_of('<');
        auto last = this->html.find_first_of('>');
        this->html.replace(first, last + 1 - first, "");
    }
}

void TagRemover::remove_tags(ofstream &output){
    cout << "####Start.####" << endl;
    while(this->html.find_first_of('<') != string::npos && this->html.find_first_of('>') != string::npos){
        auto first = this->html.find_first_of('<');
        auto last = this->html.find_first_of('>');
        this->html.replace(first, last + 1 - first, "");
    }
    output << this->html;
}

void TagRemover::process_special_chars(){
    int i = 0;
}

void TagRemover::process_char(){
    int i = 0;
}

void TagRemover::print(ostream &cout){
    cout << this-> html;
}

void TagRemover::print(ostream &cout, ofstream &output){
    cout << this-> html;
}
