#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"
#include <locale>
#include "Debug_class.h"
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
	
	Debug_class::log("Prepare for storage");
	/*
	if (fileExist(filename)) {
		newfile.open(filename,  ios::out | ios::app);
		if (newfile.is_open()) //checking whether the file is open
		{			
			newfile << textToInsert;   //inserting text
			newfile.close();    //close the file object
			Debug_class::log("File storaged");
			//cout << "archivo existe" << endl;
			Debug_class::log("The File : "+filename+" Exist");
		}
	}
	else {
		newfile.open(filename, ios::out | ios::app);
		if (newfile.is_open()) //checking whether the file is open
		{
			newfile << "\xEF\xBB\xBF";
			newfile << textToInsert;   //inserting text
			newfile.close();    //close the file object	
			//cout << "archivo NO existe" << endl;
			Debug_class::log("The File : " + filename + " Not exist");
		}
	}
    */
    
        //cout << textToInsert;
		
    
	
	
}









