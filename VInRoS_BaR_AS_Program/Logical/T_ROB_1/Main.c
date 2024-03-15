#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#include <Main.h>

void _INIT ProgramInit(void)
{

	ABB_Library_Rob_1.Enable = 1;
	
	ABB_Library_Rob_1.Status.PLC.Active = 1;
	ABB_Library_Rob_1.Status.PLC.Module_OK = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	ABB_Library(&ABB_Library_Rob_1);
}

