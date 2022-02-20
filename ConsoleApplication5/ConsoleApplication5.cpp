#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
#include "../ConsoleApplication4/ConsoleApplication4.h"

#include <memory>
int _tmain()
{	
	if (const std::unique_ptr<std::remove_pointer_t<HANDLE>, decltype(CloseHandle)*>  hMapFile{ OpenFileMapping
	( FILE_MAP_ALL_ACCESS   // read/write access
	, FALSE                 // do not inherit the name
	, ConsoleApplication4_NameOfFileMappingObject               // name of mapping object
	), CloseHandle}) {
		
		if (const auto pBuf = std::unique_ptr<wchar_t, decltype(UnmapViewOfFile)*>{ (LPWSTR)MapViewOfFile
		(hMapFile.get() // handle to map object
		,FILE_MAP_ALL_ACCESS  // read/write permission
		,0
		,0
		,BUF_SIZE), UnmapViewOfFile }) {
			MessageBox(NULL, pBuf.get(), TEXT("Process2"), MB_OK);
			return EXIT_SUCCESS;
		}
		else {
			_tprintf(TEXT("Could not map view of file (%d).\n"), GetLastError());
			return EXIT_FAILURE;
		}
	}
	else {
		_tprintf(TEXT("Could not open file mapping object (%d).\n"), GetLastError());
		return EXIT_FAILURE;
	}
}
