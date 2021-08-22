#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

char* strTochars(string vStr) {
	char* cstr = new char[vStr.length() + 1];
	strcpy_s(cstr, vStr.length(),vStr.c_str());
	return cstr;
}

char strTochar(string vStr) {
	char charRet=' ';
	charRet = vStr[0];	return charRet;
}

string charToStr(char vChar) {
	string charRet(1, vChar);
	return charRet;
}

string intToStr(int vInt) {
	return to_string(vInt);
}

int strToInt(string vStr) {	
		return stoi(vStr);
}

char intToChar(int vInt) {
	return (char)vInt;
};

int charToInt(char vChar) {
	int a = isdigit(vChar);
	int ret = 0;
	if (!a == 0) {		
		int ret = vChar - '0';
	}
	return ret;
}

int charToIntAscci(char vChar) {
	return (int)vChar;
}





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

int findStrLastChar(string stringFile, string stringToSearh) {	
	string lastChars = "";
	lastChars=stringFile.substr((stringFile.size()- stringToSearh.size()),stringToSearh.size());
	int resToReturn = lastChars.find(stringToSearh);
	//cout << stringFile<<"|" << lastChars << "-" << stringToSearh << "|"<< resToReturn <<endl;


	return resToReturn;
}


int findEndOfStr(string stringFile, string stringToSearh) {
	int result = stringFile.find(stringToSearh);
	if (result != (-1)) result += stringToSearh.size();
	return result;
}

string strReplace(string strOrig, string strToFind, string strToPut) {
	unsigned int cont = 0;
	string retStr = "";
	string tempFind= "";
	string lastTempFind = "";
	string tempRes = "";
	string result = "";	
	while (cont < strOrig.size()) {		
		if (tempFind.size() <= strToFind.size()) {
			tempFind += strOrig[cont];					
		}
			
		if (tempFind.size() >= strToFind.size()) {
			if (tempFind == strToFind) {				
				result = result.substr(0,(result.size()-(strToFind.size()-1)))+ strToPut;
			}
			else {				
				result += strOrig[cont];
			}
			tempFind = tempFind.substr(1, tempFind.size());;

		}
		else {
			result += strOrig[cont];
		}		
		cont++;	
	
	}
	return result;
}

string normalizeStr(string result) {
	result = strReplace(result, "\\", "\\\\");

	result = strReplace(result, "\"", "\\\"");
	
	//result = strReplace(result, "\'", "\\\'");
	
	//result = strReplace(result, "\\", "\\\\");
	return result;
}

string normalizeChar(string result) {
	result = strReplace(result, "\\", "\\\\");
	// //result = strReplace(result, "\'", "\\\'");
	result = strReplace(result, "\"", "\\\"");
	result = strReplace(result, "\'", "\\\'");

	

	return result;
}


string normalizeUrl(string result) {
	result = strReplace(result, "\\", "/");
	result = strReplace(result, "//", "/");
	result = strReplace(result, "//", "/");
	result = strReplace(result, "//", "/");
	return result;
}