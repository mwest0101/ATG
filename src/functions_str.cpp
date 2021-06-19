#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
string leftTrim(string str, string chars) {
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

string rightTrim(string str, string chars) {
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

string trimString(string str, string chars) {
	return leftTrim(rightTrim(str, chars), chars);
}

vector<string> splitStr(string str, char sep) {
	vector<string> vecRetStr;
	stringstream string_stream(str);  // creating string stream object	
	string strTemp;
	while (string_stream.good())   // loop will continue if string stream is error free
	{
		strTemp = "";
		getline(string_stream, strTemp, sep);   //calling getline fuction	
		//cout << "strTemp -> " << strTemp << endl;
		vecRetStr.push_back(strTemp);		
	}
	return vecRetStr;
}

void printStrVector(vector<string> strVec) {	
	for (string str : strVec) {
		cout << str << endl;   // printing a result
	}
	
}

int findStr(string stringFile, string stringToSearh) {
	int result = stringFile.find(stringToSearh);
	return result;
}

int findEndOfStr(string stringFile, string stringToSearh) {
	int result = stringFile.find(stringToSearh);
	if (result != (-1)) result += stringToSearh.size();
	return result;
}
