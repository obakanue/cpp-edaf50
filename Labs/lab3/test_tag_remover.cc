#include <iostream>
#include <fstream>
#include "TagRemover.h"
using namespace std;

string input_to_string(ifstream &input){
    string str="";
    string line;
    string file_name;
    input >> file_name;
    ifstream file(file_name);
    while (getline(file, line)){
        str.append(line);
    }
    return str;
}

int main() {
    TagRemover tag_remover(cin, true);
    ofstream output_tags_processed("tags_processed.html");
    ofstream output_html_processed("html_processed.html");
    
    cout << "####Test removing tags.####" << endl;
    tag_remover.remove_tags(output_tags_processed);

    string PATH = "tags_processed.html";
    ifstream input_tags_processed(PATH);
    if (!input_tags_processed){ 
        cerr << "File 'tags_processed.html' is not found in folder" <<
            " '/cpp-edaf50/Labs/lab3/'." << endl;
        return 0;
    }
    string tags_processed = input_to_string(input_tags_processed);

    PATH = "/Users/sofiflink/Skola/Pågående Kurser/C++-programmering EDAF50/cpp-edaf50/Labs/lab3/tags_test.html";
    ifstream input_tags_test(PATH);
    if (!input_tags_test){
        cerr << "File 'tags_test.html' is not found in folder" <<
        " '/Users/sofiflink/Skola/Pågående Kurser/C++-programmering EDAF50/cpp-edaf50/Labs/lab3/'." << endl;
        return 0;
    }
    string tags_test = input_to_string(input_tags_test);

    if(tags_processed == tags_test){
        cout << "####Tags properly removed.####" << endl;
    } else{
        cout << "####Tags not properly removed.####" << endl;
    }
    
    cout << "####Test processing special characters.####" << endl;
    tag_remover.print(cout, output_html_processed);

    PATH = "/Users/sofiflink/Skola/Pågående Kurser/C++-programmering EDAF50/cpp-edaf50/Labs/lab3/html_processed.html";
    ifstream input_processed(PATH);
    if (!input_processed){ 
        cerr << "File 'html_processed.txt' is not found in folder" <<
        " '/Users/sofiflink/Skola/Pågående Kurser/C++-programmering EDAF50/cpp-edaf50/Labs/lab3/'." << endl;
        return 0;
    }
    string html_processed = input_to_string(input_processed);

    PATH = "/Users/sofiflink/Skola/Pågående Kurser/C++-programmering EDAF50/cpp-edaf50/Labs/lab3/processed_test.html";
    ifstream input_test(PATH);
    if (!input_test){
        cerr << "File 'tags_test.txt' is not found in folder" <<
        " '/Users/sofiflink/Skola/Pågående Kurser/C++-programmering EDAF50/cpp-edaf50/Labs/lab3/'." << endl;
        return 0;
    }
    string processed_test = input_to_string(input_test);

    if(html_processed == processed_test){
        cout << "####Special characters properly processed.###" << endl;
        cout << "####Test cleared.####" << endl;
    } else{
        cout << "####Special characters not properly processed.####" << endl;
        cout << "####Test not cleared.####" << endl;
    }


    return 0;
}
