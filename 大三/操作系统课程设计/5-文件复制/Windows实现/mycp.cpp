#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

bool MyFileCopy(char* src, char* obj) {
	WIN32_FIND_DATA file_data;
	HANDLE h = FindFirstFile(src, &file_data);
	if (h == INVALID_HANDLE_VALUE) {
		cout << "MyFileCopy FindFirstFile error" << endl;
		return false;
	}
	HANDLE hsrc = CreateFile(src, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hsrc == INVALID_HANDLE_VALUE) {
		cout << "MyFileCopy OpenFirstFile error" << endl;
		return false;
	}
	HANDLE hobj = CreateFile(obj, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hobj == INVALID_HANDLE_VALUE) {
		cout << "MyFileCopy CreateFile error" << endl;
		return false;
	}
	DWORD size = file_data.nFileSizeLow - file_data.nFileSizeHigh;
	int* buffer = new int[size];
	DWORD temp;
	ReadFile(hsrc, buffer, size, &temp, NULL);
	WriteFile(hobj, buffer, size, &temp, NULL);
	SetFileTime(hobj, &file_data.ftCreationTime, &file_data.ftLastAccessTime, &file_data.ftLastWriteTime);
	CloseHandle(h);
	CloseHandle(hsrc);
	CloseHandle(hobj);
	return true;
}

bool MyCopy(char* src, char* obj) {
	WIN32_FIND_DATA file_data;
	char source[1000], object[1000];
	strcpy(source, src);
	strcpy(object, obj);
	strcat(source, "\\*.*");
	strcat(object, "\\");
	HANDLE hfile = FindFirstFile(source, &file_data);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		cout << "FindFirstFile failed" << endl;
		return false;
	}
	for (; FindNextFile(hfile, &file_data) != false;) 
	{
		if (file_data.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
		{
			if (strcmp(file_data.cFileName, ".") != 0 && strcmp(file_data.cFileName, "..") != 0)
			{
				memset(source, 0, sizeof(source));
				strcpy(source, src);
				strcat(source, "\\");
				strcat(source, file_data.cFileName);
				strcat(object, file_data.cFileName);
				CreateDirectory(object, NULL);
				if (MyCopy(source, object) == false) {
					cout << "error copying!" << endl;
					return false;
				}
				HANDLE hsrcfile = CreateFile(source, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
				HANDLE hobjfile = CreateFile(object, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
				FILETIME tcreate, taccess, twrite;
				GetFileTime(hsrcfile, &tcreate, &taccess, &twrite);
				SetFileTime(hobjfile, &tcreate, &taccess, &twrite);
				strcpy(object, obj);
				strcat(object, "\\");
			}
		}
		else
		{
			memset(source, 0, sizeof(source));
			strcpy(source, src);
			strcat(source, "\\");
			strcat(source, file_data.cFileName);
			strcat(object, file_data.cFileName);
			MyFileCopy(source, object);
			strcpy(object, obj);
			strcat(object, "\\");
		}
	}
	CloseHandle(hfile);
	return true;
}

int main(int argc, char* argv[])
{
	WIN32_FIND_DATA file_data;
	if (FindFirstFile(argv[2], &file_data) == INVALID_HANDLE_VALUE)
	{
		if (CreateDirectory(argv[2], NULL) == false)
		{
			cout << "Create Object File fail" << endl;
			return 0;
		}
		else
			cout << "Created Object File done" << endl;
	}
	if (MyCopy(argv[1], argv[2]) == false) {
		cout << "copy fail..." << endl;
		return 0;
	}
	HANDLE src = CreateFile(argv[1], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	HANDLE obj = CreateFile(argv[2], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	FILETIME tcreate, taccess, twrite;
	GetFileTime(src, &tcreate, &taccess, &twrite);
	SetFileTime(obj, &tcreate, &taccess, &twrite);
	cout << "Copy Object File done" << endl;
	return 0;
}