#include <string>
#include <sstream>
#include <iostream>
#include <vector>


#ifndef FUNCTIONS_STR_H
#define FUNCTIONS_STR_H
	using namespace std;
	

	char * strTochars(string vStr);
	char strTochar(string vStr);
		
	string charToStr(string vChar);

	char intToChar(string vInt);
	int charToInt(string vChar);
	string intToStr(string vInt);
	int strToInt(string vStr);

	string leftTrim(string str, string chars);
	string rightTrim(string str, string chars);
	string trimString(string str, string chars);
	vector<string> splitStr(string str, char sep);
	void printStrVector(vector<string> strVec);
	int findStr(string stringFile, string stringToSearh);
	int findStrLastChar(string stringFile, string stringToSearh);
	int findEndOfStr(string stringFile, string stringToSearh);
	string strReplace(string strOrig, string strToFind, string strToPut);

	string normalizeStr(string result);
	string normalizeChar(string result);
	string normalizeUrl(string result);
	const wchar_t* stringToConstWchar_t(string data);
	wchar_t* stringToWchar_t(string data);
	wstring stringToWstring(const string& multi);

	string createSpaces(int numSpaces);


	string eraseRightChars(string data, int num);
	string eraseLeftChars(string data, int num);
	string eraseCentersChars(string data, int num);

	string compWithRightSpaces(string source, int numSpaces);
	string compWithLeftSpaces(string source, int numSpaces);
	string compWithCenterSpaces(string source, int numSpaces);
#endif
