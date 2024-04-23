#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include "ABB_Library.h"

// Custom Lib.: Base conversion between data.
#include "Converter.h"

void Sim_PROFINET_Mapping_IO_Data(struct ABB_Library* inst, USINT offset);
void Set_Trajectory_Parameters(struct Traj_Str* inst, REAL offset);

typedef enum Robot_State_ID_enum{
	ROB_STATE_ACTIVE,
	ROB_STATE_POWER,
	ROB_STATE_WAIT,
	ROB_STATE_UPD_PARAMETERS_1,
	ROB_STATE_UPD_PARAMETERS_2,
	ROB_STATE_MOTION_1,
	ROB_STATE_MOTION_2,
	ROB_STATE_HOME_UPD_PARAMETERS_1,
	ROB_STATE_HOME_UPD_PARAMETERS_2,
	ROB_STATE_HOME_MOTION_1,
	ROB_STATE_HOME_MOTION_2,
	ROB_STATE_STOP,
	ROB_STATE_SAFETY,
	ROB_STATE_ERROR
}Robot_State_ID_enum;

_LOCAL struct ABB_Library ABB_Library_Rob_1;

void Set_Trajectory_Parameters(struct Traj_Str* inst, REAL offset){
	
	// 
	inst->Targets.Joint[0].Q[0] = 0.0; inst->Targets.Joint[0].Q[1] = -130.0;
	inst->Targets.Joint[0].Q[2] = 30.0; inst->Targets.Joint[0].Q[3] = 0.0;
	inst->Targets.Joint[0].Q[4] = 40.0; inst->Targets.Joint[0].Q[5] = 0.0;
	inst->Targets.Joint[0].Q[6] = 135;
	inst->Targets.Speed[0] = vSPEED_100;
	inst->Targets.Zone[0]  = zZone_fine;
	
	//
	inst->Length = 22;
}
