#include <windows.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;

void iterateFiles(char*, HANDLE, WIN32_FIND_DATA&);
bool readFileAndOutput(char*, char*);

int main()
{

	char* directory = "C:\\Users\\Paul\\Desktop\\files\\";

	WIN32_FIND_DATA file;
	HANDLE search_handle = FindFirstFile(strcat(directory, (char*)"*"), &file);
	if (search_handle)
	{
		do
		{
			std::wcout << file.cFileName << std::endl;
		} while (FindNextFile(search_handle, &file));
		CloseHandle(search_handle);

	}


	return 0;
}

void iterateFiles(char *directory, HANDLE document_handle, WIN32_FIND_DATA &file) {
	char* fileName[sizeof(directory)];
	document_handle = FindFirstFile(directory, &file);
	if (document_handle) {
		while (FindNextFile(document_handle, &file)) {
			bool isFile;
			strcpy(*fileName, file.cFileName);
			for (int i = 0; i < sizeof(fileName); i++) {
				if (fileName[i] == (char*)'*') {
					if (readFileAndOutput(directory, file.cFileName)) {
						isFile = true;
					}
					else {
						isFile = false;
					}
				}
				else {
					isFile = false;
				}
			}
			if (!isFile) {
				strcat(directory, file.cFileName);
				strcat(directory, (char*)"\\");
				document_handle = FindFirstFile(strcat(directory, (char*)"*"), &file);
				iterateFiles(directory, document_handle, file);
			}
		}
	}
}

bool readFileAndOutput(char *directory, char *file) {
	ofstream outputFile;
	ifstream readFile;
	string line;

	readFile.open(strcat(directory, file));

	if (readFile) {
		outputFile.open(file);
		while (getline(readFile, line)) {
			outputFile << line << endl;
		}
		return true;
	}
	return false;
}

/*
#include <windows.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
	cout << typeid("C:\\*").name() << endl;
	//char* directory = "C:\\*";
	
    WIN32_FIND_DATA file;
    HANDLE search_handle=FindFirstFile("C:\\Users\\Paul\\Desktop\\files\\*",&file);
    if (search_handle)
    {
        do
        {
            std::wcout << file.cFileName << std::endl;
        }while(FindNextFile(search_handle,&file));
        CloseHandle(search_handle);

    }
	
	
	return 0;
}
*/