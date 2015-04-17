#include "stdafx.h"
#include "dbgtool.h"
#include <stdexcept>
#include <tchar.h>
#include <time.h>

#define _NO_CVCONST_H
#include <DbgHelp.h>
#include <stdio.h>
using namespace std;

#pragma comment ( lib, "dbghelp.lib")

namespace DBGTOOL {
	static char *findbase(char *name)
	{
		char *cp = NULL;
		int	len;
		int i;

		len = strlen(name);

		for (i = len - 1; i >= 0; i--)
		{
			if (name[i] == '\\')
			{
				cp = &name[i];
				break;
			}
		}
		return cp;
	}

	int dbgtool::stack_trace(CONTEXT *context, frames *frame_ptrs, size_t count)
	{
		BOOL			result;
		CONTEXT			current_context;
		HANDLE			process;
		HANDLE			thread;
		DWORD64			displacement;
		STACKFRAME64	stack;
		int				size = 0;
		static UINT64	savedEip = 0;

		if (!context)
		{
			::RtlCaptureContext(&current_context);
			context = &current_context;
		}
		::ZeroMemory(&stack, sizeof(STACKFRAME64));

		process = ::GetCurrentProcess();
		thread  = ::GetCurrentThread();

		displacement = 0;

		stack.AddrPC.Mode      = AddrModeFlat;
		stack.AddrFrame.Mode   = AddrModeFlat;
		stack.AddrStack.Mode   = AddrModeFlat;
		stack.AddrPC.Offset    = context->Eip;
		stack.AddrFrame.Offset = context->Ebp;
		stack.AddrStack.Offset = context->Esp;

		for (size_t i = 0; i < count; i++)
		{
			result = StackWalk64
				(	IMAGE_FILE_MACHINE_I386,
					process,
					thread,
					&stack,
					context,
					NULL,
					SymFunctionTableAccess64,
					SymGetModuleBase64,
					NULL);
			frame_ptrs[i].eip = stack.AddrPC.Offset;
			frame_ptrs[i].ebp = stack.AddrFrame.Offset;
			frame_ptrs[i].esp = stack.AddrStack.Offset;
			if (savedEip == frame_ptrs[i].eip)
				break;
			savedEip = frame_ptrs[i].eip;
			size++;
		}
		return size;
	}

	#define PRINTSTACK_NORMAL	(0)
	#define PRINTSTACK_EXCEPT	(1)

	static 	void _printStackInfo(frames frame_ptr[], int count, int mode)
	{
		int				i;
		HANDLE			process;
		CHAR			*name;
		char			symbol_buffer[sizeof(SYMBOL_INFO)+256];
		SYMBOL_INFO		*symbol = reinterpret_cast<SYMBOL_INFO*>(symbol_buffer);

		if (dbgtool::getPdbInfo() == -1)
		{
			for (i = 0; i < count; i++)
			{
				dbgtool::xprintf(">>    [%02i: sp=0x%08llx, pc=0x%08llx]\n",
					count - i - 1,
					frame_ptr[i].esp,
					frame_ptr[i].eip);
			}
			return;
		}

		process = ::GetCurrentProcess();
		::SymInitialize(process, NULL, TRUE);

		symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
		symbol->MaxNameLen = 255;

		for (i = 0; i < count; i++)
		{
			IMAGEHLP_LINE64	LineInfo;
			DWORD			LineDisplacement = 0; // Displacement from the beginning of the line

			::SymFromAddr(process, (DWORD64)(frame_ptr[i].eip), 0, symbol);
			name = (CHAR*)symbol->Name;
			if (mode == PRINTSTACK_NORMAL && i == 0)
				continue;
			(void)::SymGetLineFromAddr64(process, frame_ptr[i].eip, &LineDisplacement, &LineInfo);
			dbgtool::xprintf(">>    [%02i: sp=0x%08llx, pc=0x%08llx, %s()@%s]:%d\n",
				count - i - 1,
				frame_ptr[i].esp,
				frame_ptr[i].eip,
				name,
				findbase(LineInfo.FileName),
				LineInfo.LineNumber);
		}
	}


	void dbgtool::printStack(void)
	{
		#define			MAX_FRAME_COUNT		(100)
		frames			frame_ptr[MAX_FRAME_COUNT];
		int				size;

		size = dbgtool::stack_trace(NULL, frame_ptr, MAX_FRAME_COUNT);
		_printStackInfo(frame_ptr, size, PRINTSTACK_NORMAL);
	}

	void dbgtool::printExcStack(frames frame_ptr[], int count)
	{
		_printStackInfo(frame_ptr, count, PRINTSTACK_EXCEPT);
	}

	UINT32 dbgtool::findSymByAddr(UINT32 addr, char **pSymName)
	{
		HANDLE			process;
		UINT32			symAddr;
		char			symbol_buffer[sizeof(SYMBOL_INFO) + 256];
		SYMBOL_INFO		*symbol = reinterpret_cast<SYMBOL_INFO*>(symbol_buffer);
		static char		symbolName[256];

		if (dbgtool::getPdbInfo() == -1)
			return 0;

		process = ::GetCurrentProcess();
		if (0 != ::SymInitialize(process, NULL, TRUE))
		{
			dbgtool::xprintf("%d @ %s\n", __LINE__, __FUNCTION__);
			symAddr = 0;
			*pSymName = NULL;
			dbgtool::xprintf("%d @ %s\n", __LINE__, __FUNCTION__);
			goto _END;
		}
		symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
		symbol->MaxNameLen = 255;

		if (0 == ::SymFromAddr(process, (DWORD64)addr, 0, symbol))
		{
			symAddr = 0;
			*pSymName = NULL;
			goto _END;
		}
		symAddr = (UINT32)symbol->Address;
		*pSymName = &symbolName[0];
		strncpy_s(*pSymName, sizeof(symbolName), symbol->Name, symbol->NameLen+1);
	_END:
		return symAddr;
	}
}
