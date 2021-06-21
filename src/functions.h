#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
using namespace std;


	//int IntLen(const char *cstr);
	//bool isNumber(const char *cstr);	
	//void changeConlorWithString(std::string colorStr);
string leftTrim(string str, string chars);
string rightTrim(string str, string chars);
string trimString(string str, string chars);
//void anlizeString(string strRest);
int getPosOfCharInFile(string chartoSearch);
vector<string> getCharFromFile(vector<vector <string>> sourceVecOfChar, string charToSearch);
vector<string> concStrVector(vector<string> vecOfAChar, vector<string> vecOfAllChars);
struct TextConfig getInitConfig(string myLine);
//void getInitConfig(ifstream &myFile_Handler);

#endif
