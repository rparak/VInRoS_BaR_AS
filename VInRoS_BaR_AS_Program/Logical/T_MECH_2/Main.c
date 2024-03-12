#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include "Main.h"

_LOCAL struct MpAxisBasic MpAxisBasic_0;
_LOCAL struct MpAxisBasicParType AxisParameters;
_LOCAL enum Mechanism_State_ID_enum state_id;

void _INIT ProgramInit(void)
{
	memset(&Global_VInRoS_Str.Mech_Id_2, 0, sizeof(Global_VInRoS_Str.Mech_Id_2));
	
	MpAxisBasic_0.Enable     = 1;
	MpAxisBasic_0.MpLink     = &gAxis_Mech_02;
	MpAxisBasic_0.Parameters = &AxisParameters;
	
	Trajectory_Str.Targets.Position[0] = 100.0;
	Trajectory_Str.Targets.Position[1] = 1100.0;
	Trajectory_Str.Targets.Position[2] = 700.0;
	Trajectory_Str.Targets.Position[3] = 300.0;
	Trajectory_Str.Targets.Position[4] = 1200.0;
	
	Trajectory_Str.Targets.Velocity[0] = 500.0;
	Trajectory_Str.Targets.Velocity[1] = 1000.0;
	Trajectory_Str.Targets.Velocity[2] = 200.0;
	Trajectory_Str.Targets.Velocity[3] = 1500.0;
	Trajectory_Str.Targets.Velocity[4] = 400.0;
	
	Trajectory_Str.Length = 5;
	
	state_id = MECH_STATE_ACTIVE;
}

void _CYCLIC ProgramCyclic(void)
{
	switch(state_id){
		case MECH_STATE_ACTIVE:
			{
				if(Global_VInRoS_Str.Mech_Id_2.Info.Active == 1){
					state_id = MECH_STATE_POWER;
				}
			}
			break;
		
		case MECH_STATE_POWER:
			{
				if(Global_VInRoS_Str.Mech_Id_2.Info.Power == 1){
					state_id = MECH_STATE_HOME;
				}
			}
			break;
		
		case MECH_STATE_HOME:
			{
				if(Global_VInRoS_Str.Mech_Id_2.Info.Home == 1){
					MpAxisBasic_0.Home = 0;
					Global_VInRoS_Str.Mech_Id_2.Command.Home = 0;
					state_id = MECH_STATE_WAIT;
				}
			}
			break;
		
		case MECH_STATE_WAIT:
			{
				if(Global_VInRoS_Str.Mech_Id_2.Command.Home == 1){
					state_id = MECH_STATE_HOME_UPD_PARAMETERS;
				}
				
				if(Global_VInRoS_Str.Mech_Id_2.Command.Start == 1){
					Trajectory_Str.Iteration = 0;
					state_id = MECH_STATE_UPD_PARAMETERS;
				}
			}
			break;
		
		case MECH_STATE_UPD_PARAMETERS:
			{
				Global_VInRoS_Str.Mech_Id_2.Parameters.Position = Trajectory_Str.Targets.Position[Trajectory_Str.Iteration];
				Global_VInRoS_Str.Mech_Id_2.Parameters.Velocity = Trajectory_Str.Targets.Velocity[Trajectory_Str.Iteration];
				Global_VInRoS_Str.Mech_Id_2.Parameters.Acc_Dec  = Trajectory_Str.Targets.Velocity[Trajectory_Str.Iteration]*10;
				
				Global_VInRoS_Str.Mech_Id_2.Command.Update = 1;
				if(Global_VInRoS_Str.Mech_Id_2.Info.Update_Done == 1){
					state_id = MECH_STATE_MOTION_1;
				}
			}
			break;
		
		case MECH_STATE_MOTION_1:
			{
				Global_VInRoS_Str.Mech_Id_2.Command.Move = 1;
				if(Global_VInRoS_Str.Mech_Id_2.Info.Move_Active == 1){
					state_id = MECH_STATE_MOTION_2;
				}
			}
			break;
		
		case MECH_STATE_MOTION_2:
			{
				if(Global_VInRoS_Str.Mech_Id_2.Command.Stop == 1){
					state_id = MECH_STATE_STOP;
				}else{
					if(Global_VInRoS_Str.Mech_Id_2.Info.In_Position == 1){
						Global_VInRoS_Str.Mech_Id_2.Command.Move = 0;
					
						if(Trajectory_Str.Iteration == Trajectory_Str.Length - 1){
							state_id = MECH_STATE_WAIT;
						}else{
							Trajectory_Str.Iteration++;
							state_id = MECH_STATE_UPD_PARAMETERS;
						}
					}
				}
			}
			break;
		
		case MECH_STATE_HOME_UPD_PARAMETERS:
			{
				Global_VInRoS_Str.Mech_Id_2.Parameters.Position = 700.0;
				Global_VInRoS_Str.Mech_Id_2.Parameters.Velocity = 500.0;
				Global_VInRoS_Str.Mech_Id_2.Parameters.Acc_Dec  = 5000.0;
				
				Global_VInRoS_Str.Mech_Id_2.Command.Update = 1;
				if(Global_VInRoS_Str.Mech_Id_2.Info.Update_Done == 1){
					state_id = MECH_STATE_HOME_MOTION_1;
				}
			}
			break;
		
		case MECH_STATE_HOME_MOTION_1:
			{		
				Global_VInRoS_Str.Mech_Id_2.Command.Move = 1;
				if(Global_VInRoS_Str.Mech_Id_2.Info.Move_Active == 1){
					state_id = MECH_STATE_HOME_MOTION_2;
				}	
			}
			break;
		
		case MECH_STATE_HOME_MOTION_2:
			{
				if(Global_VInRoS_Str.Mech_Id_2.Info.In_Position == 1){
					Global_VInRoS_Str.Mech_Id_2.Command.Move = 0;
					Global_VInRoS_Str.Mech_Id_2.Command.Home = 0;
					state_id = MECH_STATE_WAIT;
				}
			}
			break;
		
		
		case MECH_STATE_STOP:
			{
				Global_VInRoS_Str.Mech_Id_2.Command.Stop  = 0;
				Global_VInRoS_Str.Mech_Id_2.Command.Start = 0;
				
				Global_VInRoS_Str.Mech_Id_2.Command.Move = 0;
				if(Global_VInRoS_Str.Mech_Id_2.Info.Move_Active == 0){
					state_id = MECH_STATE_WAIT;
				}
			}
			break;
		
		case MECH_STATE_SAFETY:
			{
			}
			break;
		
		case MECH_STATE_ERROR:
			{
				Global_VInRoS_Str.Mech_Id_2.Command.Home   = 0;
				Global_VInRoS_Str.Mech_Id_2.Command.Update = 0;
				Global_VInRoS_Str.Mech_Id_2.Command.Stop   = 0;
				Global_VInRoS_Str.Mech_Id_2.Command.Start  = 0;
				Global_VInRoS_Str.Mech_Id_2.Command.Move   = 0;	
				
				Global_VInRoS_Str.Mech_Id_2.Command.Move = 0;	
				if(Global_VInRoS_Str.Mech_Id_2.Info.Error == 0){
					state_id = MECH_STATE_WAIT;	
				}
			}
			break;
		
	}
	
	AxisParameters.Position     = Global_VInRoS_Str.Mech_Id_2.Parameters.Position;
	AxisParameters.Velocity     = Global_VInRoS_Str.Mech_Id_2.Parameters.Velocity;
	AxisParameters.Acceleration = Global_VInRoS_Str.Mech_Id_2.Parameters.Acc_Dec;
	AxisParameters.Deceleration = Global_VInRoS_Str.Mech_Id_2.Parameters.Acc_Dec;
	
	MpAxisBasic_0.Power = Global_VInRoS_Str.Mech_Id_2.Command.Power;
	if(Global_VInRoS_Str.Mech_Id_2.Command.Home == 1 && Global_VInRoS_Str.Mech_Id_2.Info.Home == 0){
		MpAxisBasic_0.Home = 1;
	}
	MpAxisBasic_0.ErrorReset = Global_VInRoS_Str.Mech_Id_2.Command.Reset_Error;
	MpAxisBasic_0.Update     = Global_VInRoS_Str.Mech_Id_2.Command.Update;
	MpAxisBasic_0.MoveAbsolute = Global_VInRoS_Str.Mech_Id_2.Command.Move;
	
	MpAxisBasic(&MpAxisBasic_0);
	
	Global_VInRoS_Str.Mech_Id_2.Info.Active = MpAxisBasic_0.Active;
	Global_VInRoS_Str.Mech_Id_2.Info.Power  = MpAxisBasic_0.PowerOn;
	Global_VInRoS_Str.Mech_Id_2.Info.Home   = MpAxisBasic_0.IsHomed;
	Global_VInRoS_Str.Mech_Id_2.Info.Error  = MpAxisBasic_0.Error;
	Global_VInRoS_Str.Mech_Id_2.Info.Update_Done = MpAxisBasic_0.UpdateDone;
	Global_VInRoS_Str.Mech_Id_2.Info.Move_Active = MpAxisBasic_0.MoveActive;
	if(MpAxisBasic_0.InPosition == 1 && MpAxisBasic_0.MoveDone == 1){
		Global_VInRoS_Str.Mech_Id_2.Info.In_Position = 1;
	}else{
		Global_VInRoS_Str.Mech_Id_2.Info.In_Position = 0;
	}
	Global_VInRoS_Str.Mech_Id_2.Position = MpAxisBasic_0.Position;
	
	if(Global_VInRoS_Str.Mech_Id_2.Info.Error == 1){
		state_id = MECH_STATE_ERROR;	
	}
	
	if(SAFETY_ACTIVE == 0 || SAFETY_STATUS == 0){
		Global_VInRoS_Str.Mech_Id_2.Info.Safety = 1;
	}else{
		Global_VInRoS_Str.Mech_Id_2.Info.Safety = 0;
	}
	if(SAFETY_ACTIVE == 1 || SAFETY_STATUS == 0){
		RESET_SAFETY = Global_VInRoS_Str.Mech_Id_2.Command.Reset_Safety;
	}
}

