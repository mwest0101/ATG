#include "Debug_class.h"

using namespace std;


void  Debug_class::log(string text,bool toFile) {
	cout << text << endl;
	fstream newfile;
	string filename = "debug.log";
	newfile.open(filename, ios::out | ios::app);
	if (newfile.is_open() && toFile) //checking whether the file is open
	{
		newfile << text << endl;   //inserting text
		newfile.close();    //close the file object
		//cout << "archivo existe" << endl;
		//Debug_class::log("The File : " + filename + " Exist");
	}

	//writeFile("debug.log", text);

}