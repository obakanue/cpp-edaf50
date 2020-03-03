#include <iostream>
#include <fstream>
#include "TagRemover.h"
using namespace std;

int main(){
    TagRemover tag_remover(cin, false);
    tag_remover.print(cout);
    
    return 0;
}
