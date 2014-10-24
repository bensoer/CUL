#ifndef ARGPARCER_H_
#define ARGPARCER_H_

#include <string>


using std::string;


class ArgParcer{

public:
	string getTagData(string preTag, char *argArray[], int length);
	int getTagVal(string preTag, char *argArray[], int length);

private:

};

#endif