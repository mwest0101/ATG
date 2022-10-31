
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"
#include <locale>
#include "text_encoding_detect.h"
#include "Debug_class.h"
#include "convert_string.h"

#include <stdio.h>
#include <tchar.h>

#include "text_encoding_detect.h"
using namespace AutoIt::Common;

using namespace std;




bool fileExist(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}
/*
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
}*/

string convertToUtf8(string data,string fileEncoding) {
	//
	// convert_ansi_to_unicode_string
	//
	/*
	"None"
	"ASCII"
	"ANSI"
	"UTF-8"
	"UTF-16"
	"UTF-16B";
	*/
//	Debug_class::log("El archivo esta codificado como :"+ fileEncoding);
	//cout << " ------------> "+fileEncoding << endl;
	if (fileEncoding == "ANSI") {
		Debug_class::log("    Converting ANSI to UTF-8 "+ data);
		wstring unicode = L"";		
		string textToInsert;		
		convert_ansi_to_unicode_string(unicode, data.c_str(), data.size());
		convert_unicode_to_utf8_string(textToInsert, unicode.c_str(), unicode.size());
		data = textToInsert;
	}

	if (fileEncoding == "UTF-16" || fileEncoding == "UTF-16B" ) {
		Debug_class::log("    Converting UTF-16B to Unicode a UTF-8 " + data);
		wstring unicode = L"";		
		string textToInsert;
		unicode = stringToWstring(data);
		convert_unicode_to_utf8_string(textToInsert, unicode.c_str(), unicode.size());
		data = textToInsert;
	}

	return data;
}

string getFileCoding(string fileName)
{
	FILE* file = NULL;	
	BOOL err = _wfopen_s(&file, stringToWchar_t(fileName), L"rb");	
	if (err != 0) {
		wprintf(L"\nCould not open file %ls .\n", stringToWchar_t(fileName));	
		return "NULL";
	}
	
	fseek(file, 0, SEEK_END);
	long fsize = ftell(file);
	fseek(file, 0, SEEK_SET);

	unsigned char* buffer = new unsigned char[fsize];
	fread(buffer, fsize, 1, file);
	fclose(file);

	TextEncodingDetect textDetect;
	TextEncodingDetect::Encoding encoding = textDetect.DetectEncoding(buffer, fsize);

	//wprintf(L"\nEncoding: ");
	if (encoding == TextEncodingDetect::None) return "None"; //wprintf(L"Binary");
	else if (encoding == TextEncodingDetect::ASCII) return "ASCII"; //wprintf(L"ASCII (chars in the 0-127 range)");
	else if (encoding == TextEncodingDetect::ANSI) return "ANSI"; //wprintf(L"ANSI (chars in the range 0-255 range)");
	else if (encoding == TextEncodingDetect::UTF8_BOM || encoding == TextEncodingDetect::UTF8_NOBOM) return "UTF-8"; //wprintf(L"UTF-8");
	else if (encoding == TextEncodingDetect::UTF16_LE_BOM || encoding == TextEncodingDetect::UTF16_LE_NOBOM) return "UTF-16"; //wprintf(L"UTF-16 Little Endian");
	else if (encoding == TextEncodingDetect::UTF16_BE_BOM || encoding == TextEncodingDetect::UTF16_BE_NOBOM) return "UTF-16B"; //wprintf(L"UTF-16 Big Endian");
	delete[] buffer;

	return "NULL";
}


void writeFile(string filename, string textToInsert) {
	fstream newfile;


	Debug_class::log("    Prepare for storage");

	if (fileExist(filename)) {
		newfile.open(filename, ios::out | ios::app);
		if (newfile.is_open()) //checking whether the file is open
		{

			newfile << textToInsert;   //inserting text
			newfile.close();    //close the file object
			Debug_class::log("    File storaged");
			//cout << "archivo existe" << endl;
			Debug_class::log("    The File : " + filename + " Exist");
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
			Debug_class::log("    The File : " + filename + " Not exist");
		}
	}


	//cout << textToInsert;




}

string strRemoveParamsEnveded(string data) {
	int pos1 = 0;
	int pos2 = 0;
	bool found = true;
	string strResult = "";

	while (found) {
		if ((pos1 = findStr(data, "[(")) != (-1)) {
			if ((pos2 = findStr(data, ")]")) != (-1)) {
				strResult += data.substr(0, pos1);
				data = data.substr(pos2 + 2, data.size());
				found = true;
			}

		}
		else {

			strResult += data + "\n";
			found = false;
		}
	}

	return strResult;
}


int getMaxWidthLine(vector<string> vectStr) {
	string strOfChar;
	unsigned int max = 0;
	string strTemp = "";

	for (string data : vectStr) {

		string strTemp = strRemoveParamsEnveded(data);
	
		if (strTemp.size() > max) {
			max = (int)strTemp.size();
		}

	}
	
	return max;
}









