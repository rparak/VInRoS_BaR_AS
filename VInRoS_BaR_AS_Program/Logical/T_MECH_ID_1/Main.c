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
	MpAxisBasic_0.Enable     = 1;
	MpAxisBasic_0.MpLink     = &gAxis_Mech_01;
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
	
	state_id = STATE_ID_ACTIVE;
}

void _CYCLIC ProgramCyclic(void)
{
	switch(state_id){
		case STATE_ID_ACTIVE:
			{
				if(Global_MappView_Str.Mech_Id_1.Info.Active == 1){
					state_id = STATE_ID_POWER;
				}
			}
			break;
		
		case STATE_ID_POWER:
			{
				if(Global_MappView_Str.Mech_Id_1.Info.Power == 1){
					state_id = STATE_ID_HOME;
				}
			}
			break;
		
		case STATE_ID_HOME:
			{
				if(Global_MappView_Str.Mech_Id_1.Info.Home == 1){
					MpAxisBasic_0.Home = 0;
					Global_MappView_Str.Mech_Id_1.Command.Home = 0;
					state_id = STATE_ID_WAIT;
				}
			}
			break;
		
		case STATE_ID_WAIT:
			{
				if(Global_MappView_Str.Mech_Id_1.Command.Home == 1){
					state_id = STATE_ID_HOME_UPDATE_PARAMETERS;
				}
				
				if(Global_MappView_Str.Mech_Id_1.Command.Start == 1){
					Trajectory_Str.Iteration = 0;
					state_id = STATE_ID_UPDATE_PARAMETERS;
				}
			}
			break;
		
		case STATE_ID_UPDATE_PARAMETERS:
			{
				AxisParameters.Position     = Trajectory_Str.Targets.Position[Trajectory_Str.Iteration];
				AxisParameters.Velocity     = Trajectory_Str.Targets.Velocity[Trajectory_Str.Iteration];
				AxisParameters.Acceleration = Trajectory_Str.Targets.Velocity[Trajectory_Str.Iteration]*10;
				AxisParameters.Deceleration = AxisParameters.Acceleration;
				
				MpAxisBasic_0.Update = 1;
				if(MpAxisBasic_0.UpdateDone == 1){
					state_id = STATE_ID_MOTION_1;
				}
			}
			break;
		
		case STATE_ID_MOTION_1:
			{
				MpAxisBasic_0.MoveAbsolute = 1;
				if(MpAxisBasic_0.MoveActive == 1){
					state_id = STATE_ID_MOTION_2;
				}
			}
			break;
		
		case STATE_ID_MOTION_2:
			{
				if(Global_MappView_Str.Mech_Id_1.Command.Stop == 1){
					state_id = STATE_ID_STOP;
				}else{
					if(MpAxisBasic_0.InPosition == 1 && MpAxisBasic_0.MoveDone == 1){
						MpAxisBasic_0.MoveAbsolute = 0;
					
						if(Trajectory_Str.Iteration == Trajectory_Str.Length - 1){
							state_id = STATE_ID_WAIT;
						}else{
							Trajectory_Str.Iteration++;
							state_id = STATE_ID_UPDATE_PARAMETERS;
						}
					}
				}
			}
			break;
		
		case STATE_ID_HOME_UPDATE_PARAMETERS:
			{
				AxisParameters.Position     = 700.0;
				AxisParameters.Velocity     = 500.0;
				AxisParameters.Acceleration = 5000.0;
				AxisParameters.Deceleration = 5000.0;
				
				MpAxisBasic_0.Update = 1;
				if(MpAxisBasic_0.UpdateDone == 1){
					state_id = STATE_ID_HOME_MOTION_1;
				}
			}
			break;
		
		case STATE_ID_HOME_MOTION_1:
			{				
				MpAxisBasic_0.MoveAbsolute = 1;
				if(MpAxisBasic_0.MoveActive == 1){
					state_id = STATE_ID_HOME_MOTION_2;
				}	
			}
			break;
		
		case STATE_ID_HOME_MOTION_2:
			{
				if(MpAxisBasic_0.InPosition == 1 && MpAxisBasic_0.MoveDone == 1){
					MpAxisBasic_0.MoveAbsolute = 0;
					Global_MappView_Str.Mech_Id_1.Command.Home = 0;
					state_id = STATE_ID_WAIT;
				}
			}
			break;
		
		
		case STATE_ID_STOP:
			{
				Global_MappView_Str.Mech_Id_1.Command.Stop  = 0;
				Global_MappView_Str.Mech_Id_1.Command.Start = 0;
				
				MpAxisBasic_0.MoveAbsolute = 0;
				if(MpAxisBasic_0.MoveActive == 0){
					state_id = STATE_ID_WAIT;
				}
			}
			break;
		
		case STATE_ID_SAFETY:
			{
			}
			break;
		
		case STATE_ID_ERROR:
			{
				if(Global_MappView_Str.Mech_Id_1.Info.Error == 1){
					state_id = STATE_ID_WAIT;	
				}
			}
			break;
		
	}
	
	MpAxisBasic_0.Power      = Global_MappView_Str.Mech_Id_1.Command.Power;
	if(Global_MappView_Str.Mech_Id_1.Command.Home == 1 && Global_MappView_Str.Mech_Id_1.Info.Home == 0){
		MpAxisBasic_0.Home = 1;
	}
	MpAxisBasic_0.ErrorReset = Global_MappView_Str.Mech_Id_1.Command.Reset_Error;
	
	MpAxisBasic(&MpAxisBasic_0);
	
	Global_MappView_Str.Mech_Id_1.Info.Active = MpAxisBasic_0.Active;
	Global_MappView_Str.Mech_Id_1.Info.Power  = MpAxisBasic_0.PowerOn;
	Global_MappView_Str.Mech_Id_1.Info.Home   = MpAxisBasic_0.IsHomed;
	Global_MappView_Str.Mech_Id_1.Info.Error  = MpAxisBasic_0.Error;
	Global_MappView_Str.Mech_Id_1.Position = MpAxisBasic_0.Position;
	
	if(Global_MappView_Str.Mech_Id_1.Info.Error == 1){
		state_id = STATE_ID_ERROR;	
	}

}

