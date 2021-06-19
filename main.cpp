
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream myFile_Handler;
    string myLine;

    // File Open in the Read Mode
    myFile_Handler.open("D:\\pCpp\\ascciTextArtAttack\\fonts\\Speed.flf");

    if (myFile_Handler.is_open())
    {
        // Keep reading the file
        while (getline(myFile_Handler, myLine))
        {
            // print the line on the standard output
            cout << myLine << endl;
        }
        // File Close
        myFile_Handler.close();
    }
    else
    {
        cout << "Unable to open the file!";
    }
    return 0;
}

