#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include <Main.h>

_LOCAL enum Robot_State_ID_enum state_id;


/*
if(Global_VInRoS_Str.Rob_Id_1.Command.Start == TRUE){
	ABB_Library_Rob_1.Command.ID.Motion = MAIN_ID_JOINT_ABSOLUTE;
	ABB_Library_Rob_1.Command.START = TRUE;
	Global_VInRoS_Str.Rob_Id_1.Command.Start = FALSE;
}
   */

/*
if(Global_VInRoS_Str.Rob_Id_1.Command.STOP == TRUE){
	ABB_Library_Rob_1.Command.STOP = TRUE;
	Global_VInRoS_Str.Rob_Id_1.Command.STOP = FALSE;
}
*/

void _INIT ProgramInit(void)
{
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
	
	
	ABB_Library_Rob_1.Parameter.Position[0].Q[0] = 0.0; ABB_Library_Rob_1.Parameter.Position[0].Q[1] = 0.0;
	ABB_Library_Rob_1.Parameter.Position[0].Q[2] = 0.0; ABB_Library_Rob_1.Parameter.Position[0].Q[3] = 0.0;
	ABB_Library_Rob_1.Parameter.Position[0].Q[4] = 0.0; ABB_Library_Rob_1.Parameter.Position[0].Q[5] = 0.0;
	ABB_Library_Rob_1.Parameter.Speed[0] = 8;
	ABB_Library_Rob_1.Parameter.Zone[0]  = 0;
	
	// 
	ABB_Library_Rob_1.Parameter.Position[1].Q[0] = 90.0; ABB_Library_Rob_1.Parameter.Position[1].Q[1] = 0.0;
	ABB_Library_Rob_1.Parameter.Position[1].Q[2] = 0.0; ABB_Library_Rob_1.Parameter.Position[1].Q[3] = 0.0;
	ABB_Library_Rob_1.Parameter.Position[1].Q[4] = 0.0; ABB_Library_Rob_1.Parameter.Position[1].Q[5] = 0.0;
	ABB_Library_Rob_1.Parameter.Speed[1] = 8;
	ABB_Library_Rob_1.Parameter.Zone[1]  = 0;
	
	ABB_Library_Rob_1.Parameter.Trajectory_Size = 2;
	
	/*
	// 
	Trajectory_Str.Targets.Position[0].Q[0] = 0.0; Trajectory_Str.Targets.Position[0].Q[1] = 0.0;
	Trajectory_Str.Targets.Position[0].Q[2] = 0.0; Trajectory_Str.Targets.Position[0].Q[3] = 0.0;
	Trajectory_Str.Targets.Position[0].Q[4] = 0.0; Trajectory_Str.Targets.Position[0].Q[5] = 0.0;
	Trajectory_Str.Targets.Speed[0] = 8;
	Trajectory_Str.Targets.Zone[0]  = 0;
	// 
	Trajectory_Str.Targets.Position[1].Q[0] = 0.0; Trajectory_Str.Targets.Position[1].Q[1] = 0.0;
	Trajectory_Str.Targets.Position[1].Q[2] = 0.0; Trajectory_Str.Targets.Position[1].Q[3] = 0.0;
	Trajectory_Str.Targets.Position[1].Q[4] = 90.0; Trajectory_Str.Targets.Position[1].Q[5] = 0.0;
	Trajectory_Str.Targets.Speed[1] = 8;
	Trajectory_Str.Targets.Zone[1]  = 0;
	// 
	Trajectory_Str.Targets.Position[2].Q[0] = 90.0; Trajectory_Str.Targets.Position[2].Q[1] = 0.0;
	Trajectory_Str.Targets.Position[2].Q[2] = 0.0; Trajectory_Str.Targets.Position[2].Q[3] = 0.0;
	Trajectory_Str.Targets.Position[2].Q[4] = 90.0; Trajectory_Str.Targets.Position[2].Q[5] = 0.0;
	Trajectory_Str.Targets.Speed[2] = 8;
	Trajectory_Str.Targets.Zone[2]  = 0;
	// 
	Trajectory_Str.Targets.Position[3].Q[0] = 90.0; Trajectory_Str.Targets.Position[3].Q[1] = 0.0;
	Trajectory_Str.Targets.Position[3].Q[2] = 0.0; Trajectory_Str.Targets.Position[3].Q[3] = 45.0;
	Trajectory_Str.Targets.Position[3].Q[4] = 90.0; Trajectory_Str.Targets.Position[3].Q[5] = 0.0;
	Trajectory_Str.Targets.Speed[3] = 8;
	Trajectory_Str.Targets.Zone[3]  = 0;
	// 
	Trajectory_Str.Targets.Position[4].Q[0] = 0.0; Trajectory_Str.Targets.Position[4].Q[1] = 0.0;
	Trajectory_Str.Targets.Position[4].Q[2] = 0.0; Trajectory_Str.Targets.Position[4].Q[3] = 45.0;
	Trajectory_Str.Targets.Position[4].Q[4] = 90.0; Trajectory_Str.Targets.Position[4].Q[5] = 0.0;
	Trajectory_Str.Targets.Speed[4] = 8;
	Trajectory_Str.Targets.Zone[4]  = 0;
	
	//
	Trajectory_Str.Length = 5;
	*/
}

void _CYCLIC ProgramCyclic(void)
{
	/*
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
				Global_VInRoS_Str.Rob_Id_1.Info.Move_Active = FALSE;
				
				if(Global_VInRoS_Str.Rob_Id_1.Command.Home == TRUE){
					state_id = ROB_STATE_UPD_PARAMETERS;
				}
				
				if(Global_VInRoS_Str.Rob_Id_1.Command.Start == TRUE){
					Trajectory_Str.Iteration = FALSE;
					state_id = ROB_STATE_HOME_UPD_PARAMETERS;
				}
			}
			break;
			
		case ROB_STATE_UPD_PARAMETERS:
			{
				memcpy(ABB_Library_Rob_1.Parameter.Position, Trajectory_Str.Targets.Position, 
					  (sizeof(Trajectory_Str.Targets.Position) / sizeof(Trajectory_Str.Targets.Position[0])) * sizeof(REAL));
				memcpy(ABB_Library_Rob_1.Parameter.Speed, Trajectory_Str.Targets.Speed, 
					   (sizeof(Trajectory_Str.Targets.Speed) / sizeof(Trajectory_Str.Targets.Speed[0])) * sizeof(REAL));
				memcpy(ABB_Library_Rob_1.Parameter.Zone, Trajectory_Str.Targets.Zone, 
					   (sizeof(Trajectory_Str.Targets.Zone) / sizeof(Trajectory_Str.Targets.Zone[0])) * sizeof(REAL));
				
				ABB_Library_Rob_1.Parameter.Trajectory_Size = Trajectory_Str.Length;
				
				Global_VInRoS_Str.Rob_Id_1.Command.Update = TRUE;
				
				if(Global_VInRoS_Str.Rob_Id_1.Info.Update_Done == TRUE){
					state_id = ROB_STATE_MOTION_1;
				}
			}
			break;
			
		case ROB_STATE_MOTION_1:
			{
				Global_VInRoS_Str.Rob_Id_1.Info.Move_Active = TRUE;
			}
			break;
			
		case ROB_STATE_MOTION_2:
			{
				
			}
			break;
			
		case ROB_STATE_HOME_UPD_PARAMETERS:
			{
				Global_VInRoS_Str.Rob_Id_1.Info.Home = FALSE;
				
				ABB_Library_Rob_1.Parameter.Position[0].Q[0] = 0.0; ABB_Library_Rob_1.Parameter.Position[0].Q[1] = 0.0;
				ABB_Library_Rob_1.Parameter.Position[0].Q[2] = 0.0; ABB_Library_Rob_1.Parameter.Position[0].Q[3] = 0.0;
				ABB_Library_Rob_1.Parameter.Position[0].Q[4] = 0.0; ABB_Library_Rob_1.Parameter.Position[0].Q[5] = 0.0;
				ABB_Library_Rob_1.Parameter.Speed[0] = 5;
				ABB_Library_Rob_1.Parameter.Zone[0]  = 0;
				
				ABB_Library_Rob_1.Parameter.Trajectory_Size = 1;
				
				Global_VInRoS_Str.Rob_Id_1.Command.Update = TRUE;
				
				if(Global_VInRoS_Str.Rob_Id_1.Info.Update_Done == TRUE){
					state_id = ROB_STATE_HOME_MOTION_1;
				}
			}
			break;
			
		case ROB_STATE_HOME_MOTION_1:
			{
				
			}
			break;
			
		case ROB_STATE_HOME_MOTION_2:
			{
				Global_VInRoS_Str.Rob_Id_1.Info.Home = TRUE;
			}
			break;
			
		case ROB_STATE_STOP:
			{
				Global_VInRoS_Str.Rob_Id_1.Info.Move_Active = FALSE;
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
		
	memcpy(Global_VInRoS_Str.Rob_Id_1.Position.Q, ABB_Library_Rob_1.RT_Data.Q, 
		(sizeof(ABB_Library_Rob_1.RT_Data.Q) / sizeof(ABB_Library_Rob_1.RT_Data.Q[0])) * sizeof(REAL));
	memcpy(Global_VInRoS_Str.Rob_Id_1.Position.Q_Ex, ABB_Library_Rob_1.RT_Data.Q_Ex, 
		(sizeof(ABB_Library_Rob_1.RT_Data.Q_Ex) / sizeof(ABB_Library_Rob_1.RT_Data.Q_Ex[0])) * sizeof(REAL));
	
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
*/
	
	ABB_Library(&ABB_Library_Rob_1);
}

