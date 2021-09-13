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

const wchar_t* stringToConstWchar_t(string data){
	wstring wsFileName = wstring(data.begin(), data.end());
	const wchar_t* wStringFileName = wsFileName.c_str();
	return wStringFileName;
}
wchar_t* stringToWchar_t(string data) {
	wchar_t* wide_string = new wchar_t[data.length() + 1];
	copy(data.begin(), data.end(), wide_string);
	wide_string[data.length()] = 0;	
	return wide_string;
}

wstring stringToWstring(const string& multi) {
	wstring wide; wchar_t w; mbstate_t mb{};
	size_t n = 0, len = multi.length() + 1;
	while (auto res = mbrtowc(&w, multi.c_str() + n, len - n, &mb)) {
		if (res == size_t(-1) || res == size_t(-2))
			throw "invalid encoding";

		n += res;
		wide += w;
	}
	return wide;
}

string createSpaces(int numSpaces) {
	string strRet = "";
	for (int i = 0; i < numSpaces; i++) {
		strRet += " ";
	}
	return strRet;
}

string cutRightStr(string data,int num) {
	string result;
	//cout << "entre data=" << data <<" num="<<num << " data size "<< data.size() << endl;
	result = data.substr(0, num);
	//cout << "sali " << result << endl;
	return result;
}

string cutLeftStr(string data, int num) {
	string result;
	result = data.substr(num, data.size());
	return result;
}

string cutCentStr(string data, int num) {
	string result;
	result = cutRightStr(data,(int)((float)num/2));
	result = cutLeftStr(data, (int)((float)num/2));
	return result;
}

string compWithRightSpaces(string source,int numSpaces) {
	string spacesToAdd = "";
	string resultStrl = "";

	if((int)source.size()<= numSpaces){
		spacesToAdd = createSpaces(numSpaces - (source.size()));
		resultStrl = source + spacesToAdd;
	}
	else {
		resultStrl = cutRightStr(source,numSpaces);
		//cout << "pase por aca [" << source << "] " << source.size() << endl;
	}
	
	return resultStrl;
}

string compWithLeftSpaces(string source, int numSpaces) {
	string spacesToAdd = "";
	string resultStrl = "";

	if ((int)source.size() <= numSpaces) {
		spacesToAdd = createSpaces(numSpaces - (source.size()));
		resultStrl = spacesToAdd + source;
	}
	else {
		resultStrl = cutRightStr(source, numSpaces);
	}
	
	return resultStrl;
}

string compWithCenterSpaces(string source, int numSpaces) {
	string spacesToAdd = "";
	string resultStrl = "";

	if ((int)source.size() <= numSpaces) {
		spacesToAdd = createSpaces(((int)(numSpaces / 2)) - (source.size()));
		resultStrl = spacesToAdd + source + spacesToAdd;
	}
	else {
		resultStrl = cutRightStr(source, numSpaces);
	}

	return resultStrl;
}
string convStrToUpper(string data) {


	for (unsigned int i = 0; i < data.length(); i++)
	{
		data[i] = toupper(data[i]);
	}

	

	return data;
}

string getLeftString(string data, string find) {
	int pos = 0;
	string result;
	if ((pos = findStr(data, find)) != (-1)) {
		result = cutLeftStr(data, findStr(data, find));
	}
	else {
		result = "";
	}
	return result;
}

