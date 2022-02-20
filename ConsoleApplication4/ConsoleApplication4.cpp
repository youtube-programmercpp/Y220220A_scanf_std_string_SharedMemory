#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include "ConsoleApplication4.h"
#define BUF_SIZE 256

wchar_t szMsg [] = L"Message from first process.";

#include <memory>
int _tmain()
{
	if (const std::unique_ptr<std::remove_pointer_t<HANDLE>, decltype(CloseHandle)*> hMapFile
	{ CreateFileMapping
	( /*_In_     HANDLE                hFile                  */INVALID_HANDLE_VALUE   // use paging file
	, /*_In_opt_ LPSECURITY_ATTRIBUTES lpFileMappingAttributes*/NULL                   // default security
	, /*_In_     DWORD                 flProtect              */PAGE_READWRITE         // read/write access
	, /*_In_     DWORD                 dwMaximumSizeHigh      */0                      // maximum object size (high-order DWORD)
	, /*_In_     DWORD                 dwMaximumSizeLow       */BUF_SIZE               // maximum object size (low-order DWORD)
	, /*_In_opt_ LPCWSTR               lpName                 */ConsoleApplication4_NameOfFileMappingObject                 // name of mapping object
	), CloseHandle }) {
		if (const std::unique_ptr<wchar_t, decltype(UnmapViewOfFile)*> pBuf {(LPWSTR)MapViewOfFile
		( /*_In_ HANDLE hFileMappingObject  */hMapFile.get()   // handle to map object
		, /*_In_ DWORD  dwDesiredAccess     */FILE_MAP_ALL_ACCESS // read/write permission
		, /*_In_ DWORD  dwFileOffsetHigh    */0
		, /*_In_ DWORD  dwFileOffsetLow     */0
		, /*_In_ SIZE_T dwNumberOfBytesToMap*/BUF_SIZE
		), UnmapViewOfFile}) {
			CopyMemory(pBuf.get(), szMsg, lstrlenW(szMsg) * sizeof * szMsg);
			(void)_getch();
			return EXIT_SUCCESS;
		}
		else {
			_tprintf(TEXT("Could not map view of file (%d).\n"), GetLastError());
			return EXIT_FAILURE;
		}
	}
	else {
		_tprintf(TEXT("Could not create file mapping object (%d).\n"), GetLastError());
		return EXIT_FAILURE;
	}
}
