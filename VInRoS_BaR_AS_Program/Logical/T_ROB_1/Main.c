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
	
	// 
	ABB_Library_Rob_1.Parameter.Joint[0].Q[0] = 0.0; ABB_Library_Rob_1.Parameter.Joint[0].Q[1] = 0.0;
	ABB_Library_Rob_1.Parameter.Joint[0].Q[2] = 0.0; ABB_Library_Rob_1.Parameter.Joint[0].Q[3] = 0.0;
	ABB_Library_Rob_1.Parameter.Joint[0].Q[4] = 0.0; ABB_Library_Rob_1.Parameter.Joint[0].Q[5] = 0.0;
	// 
	ABB_Library_Rob_1.Parameter.Joint[1].Q[0] = 0.0; ABB_Library_Rob_1.Parameter.Joint[1].Q[1] = 0.0;
	ABB_Library_Rob_1.Parameter.Joint[1].Q[2] = 0.0; ABB_Library_Rob_1.Parameter.Joint[1].Q[3] = 0.0;
	ABB_Library_Rob_1.Parameter.Joint[1].Q[4] = 90.0; ABB_Library_Rob_1.Parameter.Joint[1].Q[5] = 0.0;
	// 
	ABB_Library_Rob_1.Parameter.Joint[2].Q[0] = 90.0; ABB_Library_Rob_1.Parameter.Joint[2].Q[1] = 0.0;
	ABB_Library_Rob_1.Parameter.Joint[2].Q[2] = 0.0; ABB_Library_Rob_1.Parameter.Joint[2].Q[3] = 0.0;
	ABB_Library_Rob_1.Parameter.Joint[2].Q[4] = 90.0; ABB_Library_Rob_1.Parameter.Joint[2].Q[5] = 0.0;
	// 
	ABB_Library_Rob_1.Parameter.Joint[3].Q[0] = 90.0; ABB_Library_Rob_1.Parameter.Joint[3].Q[1] = 0.0;
	ABB_Library_Rob_1.Parameter.Joint[3].Q[2] = 0.0; ABB_Library_Rob_1.Parameter.Joint[3].Q[3] = 45.0;
	ABB_Library_Rob_1.Parameter.Joint[3].Q[4] = 90.0; ABB_Library_Rob_1.Parameter.Joint[3].Q[5] = 0.0;
	// 
	ABB_Library_Rob_1.Parameter.Joint[4].Q[0] = 0.0; ABB_Library_Rob_1.Parameter.Joint[4].Q[1] = 0.0;
	ABB_Library_Rob_1.Parameter.Joint[4].Q[2] = 0.0; ABB_Library_Rob_1.Parameter.Joint[4].Q[3] = 45.0;
	ABB_Library_Rob_1.Parameter.Joint[4].Q[4] = 90.0; ABB_Library_Rob_1.Parameter.Joint[4].Q[5] = 0.0;
	
	ABB_Library_Rob_1.Parameter.Speed = vSPEED_50;
	ABB_Library_Rob_1.Parameter.Zone = zZone_fine;
	ABB_Library_Rob_1.Parameter.Trajectory_Size = 5;
}

void _CYCLIC ProgramCyclic(void)
{
	ABB_Library(&ABB_Library_Rob_1);
}

