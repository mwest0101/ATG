#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"



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

       /*
    FILE* filepoint;

    const char* cFileName = filename.c_str();
    errno_t error_code;

    error_code = fopen_s(&filepoint, cFileName, "a+");

    if (error_code != 0) {
        printf("Error! Failed to open file in r mode!\n");
    }
    else {
        printf("I opened myfile.c in r mode!\n");
        fprintf(filepoint, text);
    }

    */
}

/*
void anlizeString(string str) {
	int count_find = 0;

	string subStr;

	int newPos = 0;

	subStr = str;
	int band = 1;

	while (band) {
		if ((count_find == 0) && ((newPos = str.find("((")) != -1)) {
			subStr = str.substr(0, newPos);
			cout << subStr;
			str = str.substr(newPos + 2);
			count_find = 1;
		} else {
			cout << str; //Imprimo cadena posterior al parametro			
			band = 0;
		}

	}
}*/







