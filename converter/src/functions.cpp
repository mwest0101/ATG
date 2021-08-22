#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"
#include <locale>
#include "Debug_class.h"
using namespace std;




bool fileExist(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}

char* iso_latin_1_to_utf8(char* buffer, char* end, unsigned char c) {
	if (c < 128) {
		if (buffer == end) { throw std::runtime_error("out of space"); }
		*buffer++ = c;
	}
	else {
		if (end - buffer < 2) { throw std::runtime_error("out of space"); }
		*buffer++ = 0xC0 | (c >> 6);
		*buffer++ = 0x80 | (c & 0x3f);
	}
	return buffer;
}

void writeFile(string filename, string textToInsert) {
    fstream newfile;
	
	Debug_class::log("Prepare for storage");
	
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
			newfile << "\xEF\xBB\xBF"; // \xEF\xBF\xBD -  original UTF8 BOMM"\xEF\xBB\xBF"


			newfile << textToInsert;   //inserting text
			newfile.close();    //close the file object	
			//cout << "archivo NO existe" << endl;
			Debug_class::log("The File : " + filename + " Not exist");
		}
	}
    
    
        //cout << textToInsert;
		
    
	
	
}









