
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

string convertToUtf8(string data) {
	//
	// convert_ansi_to_unicode_string
	//
	wstring unicode = L"";
	string ansi = data;
	string textToInsert;
	convert_ansi_to_unicode_string(unicode, ansi.c_str(), ansi.size());

	//
	// convert_unicode_to_utf8_string
	//

	convert_unicode_to_utf8_string(textToInsert, unicode.c_str(), unicode.size());
	return textToInsert;
}

string getFileCoding(string fileName)
{

	//FILE* file = _wfopen_s(stringToWstring(fileName), L"rb");
	FILE* file = NULL;
	wprintf(L"\n ---->.%ls \n", stringToWchar_t2(fileName));
	//_wfopen_s(&file, L"Banner.flf", L"rb");
	cout << "Analizing :" << fileName << endl;
	cout << "llegue aca" << endl;
	//BOOL err = _wfopen_s(&file,stringToWstring(fileName), L"rb");
	BOOL err = _wfopen_s(&file, stringToWchar_t2(fileName), L"rb");
	//BOOL err = _wfopen_s(&file, fileName, L"rb");
	
	cout << "llegue aca 2" << endl;
	//FILE* file = _wfopen(L"D:\\pCpp\\ascciTextGen\\fonts\\3D Diagonal", L"rb");
	//wprintf(L"Strings in field (2):\n%25S\n"L"%25.4hs\n   %s%25.3ls\n",	string, string, wstring, wstring);
	if (err != 0) 
	{
		wprintf(L"\nCould not open file %ls .\n", stringToWchar_t2(fileName));
		//cout << fileName << endl;
		return "-1";
	}

	// Get file size
	fseek(file, 0, SEEK_END);
	long fsize = ftell(file);
	fseek(file, 0, SEEK_SET);

	// Read it all in
	unsigned char* buffer = new unsigned char[fsize];
	fread(buffer, fsize, 1, file);
	fclose(file);

	// Detect the encoding
	TextEncodingDetect textDetect;
	TextEncodingDetect::Encoding encoding = textDetect.DetectEncoding(buffer, fsize);

	wprintf(L"\nEncoding: ");
	if (encoding == TextEncodingDetect::None)
		wprintf(L"Binary");
	else if (encoding == TextEncodingDetect::ASCII)
		wprintf(L"ASCII (chars in the 0-127 range)");
	else if (encoding == TextEncodingDetect::ANSI)
		wprintf(L"ANSI (chars in the range 0-255 range)");
	else if (encoding == TextEncodingDetect::UTF8_BOM || encoding == TextEncodingDetect::UTF8_NOBOM)
		wprintf(L"UTF-8");
	else if (encoding == TextEncodingDetect::UTF16_LE_BOM || encoding == TextEncodingDetect::UTF16_LE_NOBOM)
		wprintf(L"UTF-16 Little Endian");
	else if (encoding == TextEncodingDetect::UTF16_BE_BOM || encoding == TextEncodingDetect::UTF16_BE_NOBOM)
		wprintf(L"UTF-16 Big Endian");

	// Free up
	delete[] buffer;

	return "coding";
}


void writeFile(string filename, string textToInsert) {
	fstream newfile;


	Debug_class::log("Prepare for storage");

	if (fileExist(filename)) {
		newfile.open(filename, ios::out | ios::app);
		if (newfile.is_open()) //checking whether the file is open
		{

			newfile << textToInsert;   //inserting text
			newfile.close();    //close the file object
			Debug_class::log("File storaged");
			//cout << "archivo existe" << endl;
			Debug_class::log("The File : " + filename + " Exist");
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









