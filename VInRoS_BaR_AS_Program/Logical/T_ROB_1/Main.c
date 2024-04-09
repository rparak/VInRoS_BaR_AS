#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include <Main.h>

_LOCAL enum Robot_State_ID_enum state_id;

void _INIT ProgramInit(void)
{
	// 
	memset(&Global_VInRoS_Str.Rob_Id_1, 0, sizeof(Global_VInRoS_Str.Rob_Id_1));
	
	ABB_Library_Rob_1.Enable = TRUE;
	
	//
	ABB_Library_Rob_1.Rob_Tool.robHold = FALSE;
	ABB_Library_Rob_1.Rob_Tool.tFrame.Position[0] = 0.0; ABB_Library_Rob_1.Rob_Tool.tFrame.Position[1] = 0.0; 
	ABB_Library_Rob_1.Rob_Tool.tFrame.Position[2] = 0.0;
	ABB_Library_Rob_1.Rob_Tool.tFrame.Rotation[0] = 1.0; ABB_Library_Rob_1.Rob_Tool.tFrame.Rotation[1] = 0.0;
	ABB_Library_Rob_1.Rob_Tool.tFrame.Rotation[2] = 0.0; ABB_Library_Rob_1.Rob_Tool.tFrame.Rotation[3] = 0.0;
	ABB_Library_Rob_1.Rob_Tool.tLoad.mass = 0.0;
	ABB_Library_Rob_1.Rob_Tool.tLoad.center_of_gravity[0] = 0.0; ABB_Library_Rob_1.Rob_Tool.tLoad.center_of_gravity[1] = 0.0;
	ABB_Library_Rob_1.Rob_Tool.tLoad.center_of_gravity[2] = 0.0;
	ABB_Library_Rob_1.Rob_Tool.tLoad.intertial_axes[0] = 1.0; ABB_Library_Rob_1.Rob_Tool.tLoad.intertial_axes[1] = 0.0;
	ABB_Library_Rob_1.Rob_Tool.tLoad.intertial_axes[2] = 0.0; ABB_Library_Rob_1.Rob_Tool.tLoad.intertial_axes[3] = 0.0;
	ABB_Library_Rob_1.Rob_Tool.tLoad.moment_of_inertia[0] = 0.0; ABB_Library_Rob_1.Rob_Tool.tLoad.moment_of_inertia[1] = 0.0;
	ABB_Library_Rob_1.Rob_Tool.tLoad.moment_of_inertia[2] = 0.0;
	
	// 
	Trajectory_Str.Targets.Joint[0].Q[0] = 130.0; Trajectory_Str.Targets.Joint[0].Q[1] = -10.0;
	Trajectory_Str.Targets.Joint[0].Q[2] = 15.0; Trajectory_Str.Targets.Joint[0].Q[3] = -50.0;
	Trajectory_Str.Targets.Joint[0].Q[4] = 60.0; Trajectory_Str.Targets.Joint[0].Q[5] = 60.0;
	Trajectory_Str.Targets.Speed[0] = vSPEED_100;
	Trajectory_Str.Targets.Zone[0]  = zZone_fine;
	// 
	Trajectory_Str.Targets.Joint[1].Q[0] = 110.0; Trajectory_Str.Targets.Joint[1].Q[1] = 60.0;
	Trajectory_Str.Targets.Joint[1].Q[2] = -20.0; Trajectory_Str.Targets.Joint[1].Q[3] = 0.0;
	Trajectory_Str.Targets.Joint[1].Q[4] = -60.0; Trajectory_Str.Targets.Joint[1].Q[5] = -40.0;
	Trajectory_Str.Targets.Speed[1] = vSPEED_100;
	Trajectory_Str.Targets.Zone[1]  = zZone_fine;
	// 
	Trajectory_Str.Targets.Joint[2].Q[0] = -30.0; Trajectory_Str.Targets.Joint[2].Q[1] = 20.0;
	Trajectory_Str.Targets.Joint[2].Q[2] = 10.0; Trajectory_Str.Targets.Joint[2].Q[3] = 40.0;
	Trajectory_Str.Targets.Joint[2].Q[4] = 90.0; Trajectory_Str.Targets.Joint[2].Q[5] = 0.0;
	Trajectory_Str.Targets.Speed[2] = vSPEED_100;
	Trajectory_Str.Targets.Zone[2]  = zZone_fine;
	// 
	Trajectory_Str.Targets.Joint[3].Q[0] = 0.0; Trajectory_Str.Targets.Joint[3].Q[1] = -50.0;
	Trajectory_Str.Targets.Joint[3].Q[2] = -20.0; Trajectory_Str.Targets.Joint[3].Q[3] = 90.0;
	Trajectory_Str.Targets.Joint[3].Q[4] = -40.0; Trajectory_Str.Targets.Joint[3].Q[5] = 100.0;
	Trajectory_Str.Targets.Speed[3] = vSPEED_100;
	Trajectory_Str.Targets.Zone[3]  = zZone_fine;
	// 
	Trajectory_Str.Targets.Joint[4].Q[0] = 65.0; Trajectory_Str.Targets.Joint[4].Q[1] = 10.0;
	Trajectory_Str.Targets.Joint[4].Q[2] = 20.0; Trajectory_Str.Targets.Joint[4].Q[3] = 50.0;
	Trajectory_Str.Targets.Joint[4].Q[4] = 55.0; Trajectory_Str.Targets.Joint[4].Q[5] = -20.0;
	Trajectory_Str.Targets.Speed[4] = vSPEED_100;
	Trajectory_Str.Targets.Zone[4]  = zZone_fine;
	
	//
	Trajectory_Str.Length = 5;
}

void _CYCLIC ProgramCyclic(void)
{
	switch(state_id){
		case ROB_STATE_ACTIVE:
			{
				if(Global_VInRoS_Str.Rob_Id_1.Info.Active == TRUE){
					state_id = ROB_STATE_POWER;
				}
			}
			break;
			
		case ROB_STATE_POWER:
			{
				if(Global_VInRoS_Str.Rob_Id_1.Info.Power == TRUE){
					state_id = ROB_STATE_WAIT;
				}
			}
			break;
			
		case ROB_STATE_WAIT:
			{
				if(Global_VInRoS_Str.Rob_Id_1.Command.Home == TRUE){
					state_id = ROB_STATE_HOME_UPD_PARAMETERS;
				}
				
				if(Global_VInRoS_Str.Rob_Id_1.Command.Start == TRUE){
					state_id = ROB_STATE_UPD_PARAMETERS;
				}
			}
			break;
			
		case ROB_STATE_UPD_PARAMETERS:
			{
				memcpy(ABB_Library_Rob_1.Parameter.Joint, Trajectory_Str.Targets.Joint, 
					(sizeof(Trajectory_Str.Targets.Joint) / sizeof(Trajectory_Str.Targets.Joint[0])) * sizeof(REAL));
				int i;
				for(i = 0; i < Trajectory_Str.Length; i++){
					ABB_Library_Rob_1.Parameter.Speed[i] = Trajectory_Str.Targets.Speed[i];
					ABB_Library_Rob_1.Parameter.Zone[i] = Trajectory_Str.Targets.Zone[i];
				}
				
				ABB_Library_Rob_1.Parameter.Trajectory_Size = Trajectory_Str.Length;
				
				Global_VInRoS_Str.Rob_Id_1.Command.Update = TRUE;
				
				if(Global_VInRoS_Str.Rob_Id_1.Info.Update_Done == FALSE){
					state_id = ROB_STATE_MOTION_1;
				}
			}
			break;
			
		case ROB_STATE_MOTION_1:
			{
				Global_VInRoS_Str.Rob_Id_1.Command.Start = TRUE;
				
				if(Global_VInRoS_Str.Rob_Id_1.Info.Move_Active == TRUE && Global_VInRoS_Str.Rob_Id_1.Info.Update_Done == TRUE){
					state_id = ROB_STATE_MOTION_2;
				}
			}
			break;
			
		case ROB_STATE_MOTION_2:
			{
				Trajectory_Str.Iteration = ABB_Library_Rob_1.Status.Robot.Trajectory_ID;
				
				if(Global_VInRoS_Str.Rob_Id_1.Command.Stop == TRUE){
					ABB_Library_Rob_1.Command.STOP = TRUE;
					state_id = ROB_STATE_STOP;
				}else{
					if(Global_VInRoS_Str.Rob_Id_1.Info.In_Position == TRUE){
						state_id = ROB_STATE_WAIT;
					}
				}
			}
			break;
			
		case ROB_STATE_HOME_UPD_PARAMETERS:
			{
				Global_VInRoS_Str.Rob_Id_1.Command.Home = FALSE;
				
				ABB_Library_Rob_1.Parameter.Joint[0].Q[0] = 90.0; ABB_Library_Rob_1.Parameter.Joint[0].Q[1] = 0.0;
				ABB_Library_Rob_1.Parameter.Joint[0].Q[2] = 0.0; ABB_Library_Rob_1.Parameter.Joint[0].Q[3] = 0.0;
				ABB_Library_Rob_1.Parameter.Joint[0].Q[4] = 90.0; ABB_Library_Rob_1.Parameter.Joint[0].Q[5] = 0.0;
				ABB_Library_Rob_1.Parameter.Speed[0] = vSPEED_50;
				ABB_Library_Rob_1.Parameter.Zone[0]  = zZone_fine;
				
				ABB_Library_Rob_1.Parameter.Trajectory_Size = 1;
				
				Global_VInRoS_Str.Rob_Id_1.Command.Update = TRUE;
				
				if(Global_VInRoS_Str.Rob_Id_1.Info.Update_Done == FALSE){
					state_id = ROB_STATE_HOME_MOTION_1;
				}
			}
			break;
			
		case ROB_STATE_HOME_MOTION_1:
			{
				Global_VInRoS_Str.Rob_Id_1.Command.Start = TRUE;
				
				if(Global_VInRoS_Str.Rob_Id_1.Info.Move_Active == TRUE && Global_VInRoS_Str.Rob_Id_1.Info.Update_Done == TRUE){
					Global_VInRoS_Str.Rob_Id_1.Info.Home = FALSE;
					state_id = ROB_STATE_HOME_MOTION_2;
				}
			}
			break;
			
		case ROB_STATE_HOME_MOTION_2:
			{
				if(Global_VInRoS_Str.Rob_Id_1.Command.Stop == TRUE){
					ABB_Library_Rob_1.Command.STOP = TRUE;
					state_id = ROB_STATE_STOP;
				}else{
					if(Global_VInRoS_Str.Rob_Id_1.Info.In_Position == TRUE){
						Global_VInRoS_Str.Rob_Id_1.Info.Home = TRUE;
						state_id = ROB_STATE_WAIT;
					}
				}
			}
			break;
			
		case ROB_STATE_STOP:
			{
				Global_VInRoS_Str.Rob_Id_1.Command.Home  = FALSE;
				Global_VInRoS_Str.Rob_Id_1.Command.Start = FALSE;
				Global_VInRoS_Str.Rob_Id_1.Command.Stop  = FALSE;
				
				if(ABB_Library_Rob_1.Internal.actual_state == ABBt_STATE_WAIT && ABB_Library_Rob_1.Status.Robot.ID.Motion == ABBr_STATE_WAIT){
					state_id = ROB_STATE_WAIT;
				}
			}
			break;
			
		case ROB_STATE_SAFETY:
			{
			}
			break;
			
		case ROB_STATE_ERROR:
			{	
			}
			break;
	}
	

	if(Global_VInRoS_Str.Rob_Id_1.Command.Power == TRUE){
		ABB_Library_Rob_1.Power_ON = TRUE;
		Global_VInRoS_Str.Rob_Id_1.Command.Power = FALSE;
	}
	
	if(Global_VInRoS_Str.Rob_Id_1.Command.Start == TRUE){
		ABB_Library_Rob_1.Command.ID.Motion = MAIN_ID_JOINT_ABSOLUTE;
		ABB_Library_Rob_1.Command.START = TRUE;
		Global_VInRoS_Str.Rob_Id_1.Command.Start = FALSE;
	}
	
	if(Global_VInRoS_Str.Rob_Id_1.Command.Update == TRUE){
		ABB_Library_Rob_1.Command.ID.Update = UPT_ID_TRAJECTORY_JOINT;
		ABB_Library_Rob_1.Command.UPDATE = TRUE;
		Global_VInRoS_Str.Rob_Id_1.Command.Update = FALSE;
	}
	
	ABB_Library(&ABB_Library_Rob_1);
	
	Global_VInRoS_Str.Rob_Id_1.Info.Active = ABB_Library_Rob_1.Status.Robot.Active;
	Global_VInRoS_Str.Rob_Id_1.Info.Power = ABB_Library_Rob_1.Status.Robot.System.MOTOR_ON;
	Global_VInRoS_Str.Rob_Id_1.Info.Update_Done = ABB_Library_Rob_1.Status.Robot.Update_Done;
	Global_VInRoS_Str.Rob_Id_1.Info.In_Position = ABB_Library_Rob_1.Status.Robot.In_Position;
	Global_VInRoS_Str.Rob_Id_1.Info.Error  = FALSE;
	Global_VInRoS_Str.Rob_Id_1.Info.Safety = FALSE;
	
	if(Global_VInRoS_Str.Rob_Id_1.Info.Power == TRUE){
		if(Global_VInRoS_Str.Rob_Id_1.Info.In_Position == FALSE){
			Global_VInRoS_Str.Rob_Id_1.Info.Move_Active = TRUE;
		}else{
			Global_VInRoS_Str.Rob_Id_1.Info.Move_Active = FALSE;
		}
	}
	
	memcpy(Global_VInRoS_Str.Rob_Id_1.Position.Q, ABB_Library_Rob_1.RT_Data.Q, 
		(sizeof(ABB_Library_Rob_1.RT_Data.Q) / sizeof(ABB_Library_Rob_1.RT_Data.Q[0])) * sizeof(REAL));
	
	if(Global_VInRoS_Str.Rob_Id_1.Info.Error == TRUE){
		state_id = ROB_STATE_ERROR;	
	}
	
	if(SAFETY_ACTIVE == FALSE || SAFETY_STATUS == FALSE){
		Global_VInRoS_Str.Rob_Id_1.Info.Safety = TRUE;
	}else{
		Global_VInRoS_Str.Rob_Id_1.Info.Safety = FALSE;
	}
	if(SAFETY_ACTIVE == TRUE || SAFETY_STATUS == FALSE){
		RESET_SAFETY = Global_VInRoS_Str.Rob_Id_1.Command.Reset_Safety;
	}
}

