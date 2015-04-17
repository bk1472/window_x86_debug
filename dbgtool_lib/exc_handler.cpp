#include <Windows.h>
#include <stdio.h>
#include <stdexcept>
#include <tchar.h>
#include "dbgtool.h"

namespace DBGTOOL
{
	#define X86REG_GS		(           0)
	#define X86REG_FS		(X86REG_GS +1)
	#define X86REG_ES		(X86REG_FS +1)
	#define X86REG_SS		(X86REG_ES +1)
	#define X86REG_CS		(X86REG_SS +1)
	#define X86REG_DS		(X86REG_CS +1)
	#define X86REG_ESP		(X86REG_DS +1)
	#define X86REG_EBP		(X86REG_ESP+1)
	#define X86REG_ESI		(X86REG_EBP+1)
	#define X86REG_EDI		(X86REG_ESI+1)
	#define X86REG_EAX		(X86REG_EDI+1)
	#define X86REG_EBX		(X86REG_EAX+1)
	#define X86REG_ECX		(X86REG_EBX+1)
	#define X86REG_EDX		(X86REG_ECX+1)
	#define X86REG_EIP		(X86REG_EDX+1)
	#define X86REG_EFL		(X86REG_EIP+1)
	#define X86REG_DR0		(X86REG_EFL+1)
	#define X86REG_DR1		(X86REG_DR0+1)
	#define X86REG_DR2		(X86REG_DR1+1)
	#define X86REG_DR3		(X86REG_DR2+1)
	#define X86REG_DR6		(X86REG_DR3+1)
	#define X86REG_DR7		(X86REG_DR6+1)
	#define X86REG_CTX		(X86REG_DR7+1)
	#define REG_COUNT		(X86REG_CTX+1)
	static char *_x86_reg[REG_COUNT] =
	{
		"[ GS]", "[ FS]", "[ ES]", "[ SS]",
		"[ CS]", "[ DS]", "[ESP]", "[EBP]",
		"[ESI]", "[EDI]", "[EAX]", "[EBX]",
		"[ECX]", "[EDX]", "[EIP]", "[EFL]",
		"[DR0]", "[DR1]", "[DR2]", "[DR3]",
		"[DR6]", "[DR7]", "[CTX]"
	};
	static int	_excStat = 0;

	#define REGTBL_SZ		(sizeof(_x86_reg)/sizeof(_x86_reg[0]))
	#define TABLE_NEWLINE	(4)
	static LONG WINAPI _UnhandledExceptionFilter(PEXCEPTION_POINTERS p)
	{
		CONTEXT				*pContext = p->ContextRecord;
		EXCEPTION_RECORD	*pExcRecord = p->ExceptionRecord;
		unsigned long		pRegs[REGTBL_SZ];
		int					i;

		_excStat = 1;
		pRegs[X86REG_GS]  = pContext->SegGs; pRegs[X86REG_FS]  = pContext->SegFs;
		pRegs[X86REG_ES]  = pContext->SegEs; pRegs[X86REG_DS]  = pContext->SegDs;
		pRegs[X86REG_EDI] = pContext->Edi;   pRegs[X86REG_ESI] = pContext->Esi;
		pRegs[X86REG_EBP] = pContext->Ebp;   pRegs[X86REG_ESP] = pContext->Esp;
		pRegs[X86REG_EBX] = pContext->Ebx;   pRegs[X86REG_EDX] = pContext->Edx;
		pRegs[X86REG_ECX] = pContext->Ecx;   pRegs[X86REG_EAX] = pContext->Eax;
		pRegs[X86REG_EIP] = pContext->Eip;   pRegs[X86REG_EFL] = pContext->EFlags;
		pRegs[X86REG_DR0] = pContext->Dr0;   pRegs[X86REG_DR1] = pContext->Dr1;
		pRegs[X86REG_DR2] = pContext->Dr2;   pRegs[X86REG_DR3] = pContext->Dr3;
		pRegs[X86REG_DR6] = pContext->Dr6;   pRegs[X86REG_DR7] = pContext->Dr7;
		pRegs[X86REG_CS]  = pContext->SegCs; pRegs[X86REG_SS]  = pContext->SegSs;
		pRegs[X86REG_CTX] = pContext->ContextFlags;

		dbgtool::xprintf("\n\n$$$ Exception occurred!(err:0x%08LX at %p)$$$\n\n",
										pExcRecord->ExceptionCode,
										pExcRecord->ExceptionAddress);

		dbgtool::xprintf("      ==== REGISTER map for exception depth %02d ====\n", REGTBL_SZ);

		for (i = 0; i < REGTBL_SZ; i++)
		{
			if(!(i%TABLE_NEWLINE)) dbgtool::xprintf("      ");
			dbgtool::xprintf("%-6s %08LX ", _x86_reg[i], pRegs[i]);
			if (!((i + 1) % TABLE_NEWLINE))
				dbgtool::xprintf("\n");
		}

		dbgtool::hexdump("\n      == Exception Stack ==", (void *)pRegs[X86REG_ESP], 4, 0x100);
		dbgtool::xprintf("      ==== Exception Code Disassembly ====");
		dbgtool::printExcCode((UINT32)pRegs[X86REG_EIP], 0x20);
		dbgtool::xprintf("      ==== Exception Stack backtrace ====\n");
		{
			int		size;
			frames	frame_ptr[100];
			size = dbgtool::stack_trace(pContext, frame_ptr, 100);
			dbgtool::printExcStack(frame_ptr, size);
		}

		dbgtool::xprintf("      == END ==\n");
		_excStat = 0;

		dbgtool::log_exc_file();
		return EXCEPTION_EXECUTE_HANDLER;
	}

	void dbgtool::regExcepHandler(void)
	{
		LPTOP_LEVEL_EXCEPTION_FILTER pOriginalFilter;
		pOriginalFilter = SetUnhandledExceptionFilter(_UnhandledExceptionFilter);
	}

	int dbgtool::getExcStat(void)
	{
		return _excStat;
	}
}
