#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"
using namespace std;


string normalizeStr(string result) {
	result = strReplace(result, "\\", "\\\\");
	result = strReplace(result, "\'", "\\\'");
	result = strReplace(result, "\"", "\\\"");

	return result;
}

string normalizeUrl(string result) {
	result = strReplace(result, "\\\\", "/");
	result = strReplace(result, "\\'", "/");	
	return result;
}
void writeFile(string filename, string textToInsert) {
    fstream newfile;
     
    newfile.open(filename, ios::out);  // open a file to perform write operation using file object
    if (newfile.is_open()) //checking whether the file is open
    {
        //cout << textToInsert;
        newfile << textToInsert;   //inserting text
        newfile.close();    //close the file object
    }


}









