#include "argparcer.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

//finds param passed tag then gets associated value and returns it as a string
//returns NULL on failure to find tag
string ArgParcer::getTagData(string preTag, char *argArray[], int length)
{
	for(int i = 1; i < length; ++i)
	{
		if(preTag.compare(argArray[i])==0)
		{
			int t = i +1;
			return argArray[t];
		}
	}
	return "-1";

}

//finds param passed tag then gets associated value and returns it as an int
//returns -1 on failure to find tag
int ArgParcer::getTagVal(string preTag, char *argArray[], int length)
{
	for(int i = 1; i < length; ++i)
	{
		if(preTag.compare(argArray[i])==0)
		{
			int t = i+1;
				
			string number = (argArray[t]);
		
			int num;
			
			istringstream( number) >> num;
			
			return num;
		}
	
	}
	return -1;

}