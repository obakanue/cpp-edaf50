#include <fstream>
#include <iostream>
#include <string>
#include "TagRemover.h"
using namespace std;
using std::string;

TagRemover::TagRemover(istream &input){
    string line;
    string file_name;
    input >> file_name;
    ifstream file(file_name);
    while(getline(file, line)){
        this->html += line + "\n";
    }
}

void TagRemover::remove_tags(){
    while(this->html.find_first_of('<') != string::npos && this->html.find_first_of('>') != string::npos){
        auto first = this->html.find_first_of('<');
        auto last = this->html.find_first_of('>');
        this->html.replace(first, last + 1 - first, "");
    }
}

void TagRemover::remove_tags(ofstream &output){
    while(this->html.find_first_of('<') != string::npos && this->html.find_first_of('>') != string::npos){
        auto first = this->html.find_first_of('<');
        auto last = this->html.find_first_of('>');
        this->html.replace(first, last + 1 - first, "");
    }
    output << this->html;
    process_special_chars();
}

void TagRemover::process_special_chars(){
    while(this->html.find_first_of("&") != string::npos && this->html.find_first_of(";") != string::npos){
        auto start = this->html.find_first_of("&");
        auto end = this->html.find_first_of(";");
        this->process_char(start, end);
    }
}

void TagRemover::process_char(int start, int end){
    string substr = this->html.substr(start, end + 1 - start);
    if(substr == "&nbsp;"){
       this->html.replace(start, end + 1 - start, " ");
    } else if (substr == "&lt;"){
       this->html.replace(start, end + 1 - start, "<");
    } else if (substr == "&gt;"){
        this->html.replace(start, end + 1 - start, ">");
    } else if (substr == "&amp;"){
        this->html.replace(start, end + 1 - start, "&");
    }
}

void TagRemover::print(ostream &cout){
    remove_tags();
    process_special_chars();
    cout << this-> html;
}

void TagRemover::print(ostream &cout, ofstream &output){
    cout << this-> html;
    output << this->html;
}
