// dbgtool_lib.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

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

#define ENABLE_LOGFILE		1

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

	static void _stack_trace(CONTEXT *context, frames *frame_ptrs, size_t count)
	{
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
		process                = ::GetCurrentProcess();
		thread                 = ::GetCurrentThread();
		displacement           = 0;
		stack.AddrPC.Mode      = AddrModeFlat;
		stack.AddrFrame.Mode   = AddrModeFlat;
		stack.AddrStack.Mode   = AddrModeFlat;
		stack.AddrPC.Offset    = context->Eip;
		stack.AddrFrame.Offset = context->Ebp;
		stack.AddrStack.Offset = context->Esp;

		for (size_t i = 0; i < count; i++)
		{
			result = StackWalk64
				(
				IMAGE_FILE_MACHINE_I386,
				process,
				thread,
				&stack,
				context,
				NULL,
				SymFunctionTableAccess64,
				SymGetModuleBase64,
				NULL
				);
				frame_ptrs[i].eip = stack.AddrPC.Offset;
				frame_ptrs[i].ebp = stack.AddrFrame.Offset;
				frame_ptrs[i].esp = stack.AddrStack.Offset;
				if(savedEip == frame_ptrs[i].eip)
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

	#define GHD_BUFSZ	(80)

	void dbgtool::hexdump(const char *name, void *vcp, int width, int size)
	{
		static UCHAR n2h[] = "0123456789abcdef";
		int		i, hpos, cpos;
		int		id[4];
		char	buf[GHD_BUFSZ + 1] = { 0 };
		UCHAR	*cp, uc;
		//volatile ULONG	*lp, word_buff[4];
		ULONG	crc_val = 0;

		_snprintf_s(buf, GHD_BUFSZ, GHD_BUFSZ, "%s(Size=0x%lx, CRC32=0x%08lx)", name, (ULONG)size, (ULONG)crc_val);
		buf[GHD_BUFSZ] = 0;
		xprintf(    "%s\n", buf);

		if (size == 0) return;

		memset(buf, ' ', GHD_BUFSZ);

		cp = (UCHAR*)vcp;
		hpos = cpos = 0;
		for (i = 0; i < size;) {

			if ((i % 16) == 0) {
				_snprintf_s(buf, GHD_BUFSZ, GHD_BUFSZ, "\t0x%08x(%04x):", (int)vcp + i, i);
				hpos = 18;
			}

			if ((i % 4) == 0) buf[hpos++] = ' ';

			switch (width)
			{
			case 1: // 8bit
				id[0] = 0; id[1] = 1; id[2] = 2; id[3] = 3;
				break;
			case 2: //16bit
				id[0] = 1; id[1] = 0; id[2] = 3; id[3] = 2;
				break;
			case 4: //32bit
				id[0] = 3; id[1] = 2; id[2] = 1; id[3] = 0;
				break;
			}
			if ((i + 0)<size) { uc = cp[i + id[0]]; buf[hpos++] = n2h[(uc & 0xF0) >> 4]; buf[hpos++] = n2h[uc & 15]; }
			if ((i + 1)<size) { uc = cp[i + id[1]]; buf[hpos++] = n2h[(uc & 0xF0) >> 4]; buf[hpos++] = n2h[uc & 15]; }
			if ((i + 2)<size) { uc = cp[i + id[2]]; buf[hpos++] = n2h[(uc & 0xF0) >> 4]; buf[hpos++] = n2h[uc & 15]; }
			if ((i + 3)<size) { uc = cp[i + id[3]]; buf[hpos++] = n2h[(uc & 0xF0) >> 4]; buf[hpos++] = n2h[uc & 15]; }
			//buf[hpos] = ' ';

			cpos = (i % 16) + 56;

			if (i<size) { buf[cpos++] = (isprint(cp[i]) ? cp[i] : '.'); i++; }
			if (i<size) { buf[cpos++] = (isprint(cp[i]) ? cp[i] : '.'); i++; }
			if (i<size) { buf[cpos++] = (isprint(cp[i]) ? cp[i] : '.'); i++; }
			if (i<size) { buf[cpos++] = (isprint(cp[i]) ? cp[i] : '.'); i++; }

			if ((i % 16) == 0) {
				buf[cpos] = 0x00;
				xprintf(    "%s\n", buf);
			}
		}
		buf[cpos] = 0x00;
		if ((i % 16) != 0) {
			for (; hpos < 56; hpos++)
				buf[hpos] = ' ';
			xprintf(    "%s\n", buf);
		}
	}

	void dbgtool::printExcCode(UINT32 eip, int win_sz)
	{
		UINT32			pc = eip;
		UINT32			dsmPc, symPc;
		int				i;
		char			*symName;

		symPc = dbgtool::findSymByAddr(pc, &symName);

		if(symPc)
		{
			dsmPc = pc - (win_sz * 2);
			dbgtool::regPrintDsmMode((UINT32)NULL);
			while(symPc < dsmPc)
			{
				symPc += dbgtool::dsmInst((UINT32*)(symPc), (UINT32)symPc, NULL);
			}
			dsmPc = symPc;
		}
		else
		{
			dsmPc = pc;
		}

		dbgtool::regPrintDsmMode((UINT32)dbgtool::xprintf);
		dbgtool::xprintf("\n        [SYMBOL : %-30s]\n", symName);
		for (i = 0; i < win_sz; i++)
		{
			if (dsmPc == pc) dbgtool::xprintf("    ** ");
			else             dbgtool::xprintf("       ");
			dsmPc += dbgtool::dsmInst((UINT32*)(dsmPc), (UINT32)dsmPc, NULL);
		}
	}

	UINT32 dbgtool::findSymByAddr(UINT32 addr, char **pSymName)
	{
		HANDLE			process;
		UINT32			symAddr;
		char			symbol_buffer[sizeof(SYMBOL_INFO) + 256];
		SYMBOL_INFO		*symbol = reinterpret_cast<SYMBOL_INFO*>(symbol_buffer);
		static char		symbolName[256];

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

	#define EXC_BUFFER_SZ		(8192)
	#define DBG_BUFSZ			( 512)
	static char	excBuffer[EXC_BUFFER_SZ] = {0};
	static int	excBufferRead	= 0;
	static int	excBufferWrite	= 0;
	int apndExcBuffer(const char *format, ...)
	{
		char	buffer[DBG_BUFSZ];
		int		count, nBytes;
		va_list	arg_pt;

		va_start(arg_pt, format);

		count = vsnprintf(buffer, DBG_BUFSZ, format, arg_pt);
		nBytes = (EXC_BUFFER_SZ + excBufferRead - excBufferWrite - 1) % EXC_BUFFER_SZ;
		count = min(count, nBytes);

		va_end(arg_pt);

		#if (ENABLE_LOGFILE == 0)
		return 0;
		#endif
		if (count <= 0)
		{
			return(count);
		}

		if ( EXC_BUFFER_SZ < excBufferWrite + count )
		{
			nBytes = EXC_BUFFER_SZ - excBufferWrite;
			memcpy(&excBuffer[excBufferWrite], buffer,        nBytes        );
			memcpy(&excBuffer[             0], buffer+nBytes, count - nBytes);
		}
		else
		{
			memcpy(&excBuffer[excBufferWrite], buffer, count);
		}
		excBufferWrite = (excBufferWrite + count) % EXC_BUFFER_SZ;

		return(count);
	}


	#define XBUF_SZ				(512)
	static char xbuffer[XBUF_SZ];
	int dbgtool::xprintf(const char *format, ...)
	{
		static int isFileOpen = 0;
		va_list	arg_pt;
		int		count;

		va_start(arg_pt, format);

		count = vsnprintf(xbuffer, XBUF_SZ, format, arg_pt);
		va_end(arg_pt);

		fprintf(stdout, "%s", &xbuffer[0]);
		if(dbgtool::getExcStat())
			apndExcBuffer("%s", &xbuffer[0]);

		return count;
	}

	void dbgtool::log_exc_file(void)
	{
		FILE		*fp;
		char		excLogName[300];
		time_t		rawtime;
		struct tm	timeinfo;

		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);

		#if (ENABLE_LOGFILE == 0)
		return;
		#endif
		sprintf_s(&excLogName[0], 300, "exc_log.%d-%02d-%02d_%02d-%02d-%02d.log",
									timeinfo.tm_year + 1900,
									timeinfo.tm_mon + 1,
									timeinfo.tm_mday,
									timeinfo.tm_hour,
									timeinfo.tm_min,
									timeinfo.tm_sec);

		fp = fopen(excLogName, "w");

		if(fp == NULL)
			return;

		if(excBufferWrite > EXC_BUFFER_SZ)
			excBufferWrite = EXC_BUFFER_SZ;
		fwrite(excBuffer, 1, excBufferWrite, fp);

		fclose(fp);
	}
}
