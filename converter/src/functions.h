#include <iostream>
#include <fstream>
#include <string>
#include <vector>



#ifndef FUNCTIONS_H
#define FUNCTIONS_H
	using namespace std;



	string normalizeStr(string result);
	string normalizeChar(string result);
	string normalizeUrl(string result);
	void writeFile(string filename, string text);

#endif
