#include <string>
#include <sstream>
#include <iostream>
#include <vector>


#ifndef FUNCTIONS_STR_H
#define FUNCTIONS_STR_H
	using namespace std;
	string leftTrim(string str, string chars);
	string rightTrim(string str, string chars);
	string trimString(string str, string chars);
	vector<string> splitStr(string str, char sep);
	void printStrVector(vector<string> strVec);
	int findStr(string stringFile, string stringToSearh);
	int findStrLastChar(string stringFile, string stringToSearh);
	int findEndOfStr(string stringFile, string stringToSearh);
	string strReplace(string strOrig, string strToFind, string strToPut);
#endif
