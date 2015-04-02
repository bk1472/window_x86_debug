#ifdef DBGTOOL_LIB_EXPORTS
#define DBGTOOL_API	__declspec(dllexport)
#else
#define DBGTOOL_API	__declspec(dllimport)
#endif
#include <Windows.h>

typedef signed char			SINT08;
typedef signed short		SINT16;
typedef signed int			SINT32;
typedef signed __int64		SINT64;

typedef unsigned char		UINT08;
typedef unsigned short		UINT16;
typedef unsigned int		UINT32;
typedef unsigned __int64	UINT64;

namespace DBGTOOL {
	struct frames {
		UINT64 eip;
		UINT64 ebp;
		UINT64 esp;
	};
	class dbgtool {
	public:
		            static int		getExcStat			(void);
		            static void		log_exc_file		(void);
		DBGTOOL_API static int		stack_trace			(CONTEXT *context, frames *frame_ptrs, size_t count);
		DBGTOOL_API static void		printStack			(void);
		DBGTOOL_API	static void		printExcStack		(frames frame_ptr[], int count);
		DBGTOOL_API static void		hexdump				(const char *name, void *vcp, int width, int size);
		DBGTOOL_API static void		printExcCode		(UINT32 eip, int win_sz);
		DBGTOOL_API static UINT32	findSymByAddr		(UINT32 addr, char **pSymName);
		DBGTOOL_API static int		dsmInst				(register UINT32* binInst, UINT32 address, void* prtAddress);
		DBGTOOL_API static int		regPrintDsmMode		(UINT32 print_func);
		DBGTOOL_API	static void		regExcepHandler		(void);
		DBGTOOL_API	static int		xprintf				(const char *format, ...);
	};
}
