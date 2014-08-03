// fixup epilog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <winspool.h>
#include <iostream>
#include <assert.h>
#include <vector>


int _tmain(int argc, _TCHAR* argv[])
{
	std::wstring driverName =  L"Epilog Engraver WinX64";
	std::vector<BYTE> buffer;
	DWORD needed = -1;
	DWORD returned = -1;
	BOOL result = EnumPrinters(PRINTER_ENUM_LOCAL, nullptr, 2, (BYTE*)nullptr, 0, &needed, &returned);
	buffer.resize(needed);
	result = EnumPrinters(PRINTER_ENUM_LOCAL, nullptr, 2, buffer.data(), (DWORD)buffer.size(), &needed, &returned);

	assert(needed <= buffer.size());

	PRINTER_INFO_2* printerInfo = reinterpret_cast<PRINTER_INFO_2*>(buffer.data());

	for (unsigned int i = 0; i < returned; ++i)
	{
		PRINTER_INFO_2& printer = printerInfo[i];
		if (printer.pDriverName == driverName)
		{
			if (printer.Attributes & PRINTER_ATTRIBUTE_WORK_OFFLINE)
			{
				BOOL success = FALSE;
				HANDLE printerHandle;
				success = OpenPrinter(printer.pPrinterName, &printerHandle, nullptr);
				std::cout << "OpenPrinter : " << success << std::endl;
				if (success)
				{
					std::wcout << L"Deleting Printer: " << printer.pPrinterName << " "; 
					success = DeletePrinter(printerHandle);
					std::cout << (success ? "(SUCCESS)" : "(FAILED)") << std::endl;
					// Deleting doesn't actually work.
				}
			}
			else
			{
				std::wcout << L"Setting Default Printer to " << printer.pPrinterName << std::endl;
				SetDefaultPrinter(printer.pPrinterName);
			}
		}
	}
	return 0;
}

