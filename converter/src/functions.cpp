#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"
#include <locale>
using namespace std;


string normalizeStr(string result) {
	result = strReplace(result, "\\", "\\\\");
	result = strReplace(result, "\'", "\\\'");
	result = strReplace(result, "\"", "\\\"");

	return result;
}

string normalizeChar(string result) {
	result = strReplace(result, "\\", "\\\\");
	//result = strReplace(result, "\'", "\\\'");
	result = strReplace(result, "\"", "\\\"");

	return result;
}


string normalizeUrl(string result) {
	result = strReplace(result, "\\\\", "/");
	result = strReplace(result, "\\'", "/");	
	return result;
}
inline bool fileExist(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}

void writeFile(string filename, string textToInsert) {
    fstream newfile;
/*
	unsigned char smarker[3];
	smarker[0] = 0xEF;
	smarker[1] = 0xBB;
	smarker[2] = 0xBF;
	*/
	

	if (fileExist(filename)) {
		newfile.open(filename, ios::binary | ios::out | ios::app);
		if (newfile.is_open()) //checking whether the file is open
		{			
			newfile << textToInsert;   //inserting text
			newfile.close();    //close the file object
			cout << "archivo existe" << endl;
		}
	}
	else {
		newfile.open(filename, ios::binary | ios::out | ios::app);
		if (newfile.is_open()) //checking whether the file is open
		{
			newfile << "\xEF\xBB\xBF";
			newfile << textToInsert;   //inserting text
			newfile.close();    //close the file object
			cout << "archivo NO existe" << endl;
		}
	}
    
    
        //cout << textToInsert;
		
    
	
	
}









