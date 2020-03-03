#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <iostream>
#include <string>
using namespace std;

class TagRemover {
public:
    TagRemover(istream &file, bool test);
    void remove_tags();
    void remove_tags(ofstream &output);             // Couldn't find a way to do optional arguments (default value) for ofstream.
    void process_special_chars();
    void print(ostream &cout);
    void print(ostream &cout, ofstream &output);
private:
    string html;
    void process_char(int start, int end);
};

#endif
