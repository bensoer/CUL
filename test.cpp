#include "commandline/argparcer/h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    ArgParcer ap = new ArgParcer();
    string data = ap.GetTagData("-t");
    return 0;
}