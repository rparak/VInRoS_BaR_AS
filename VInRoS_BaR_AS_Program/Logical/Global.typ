
TYPE
	MV_Str : 	STRUCT 
		Mech_Id_1 : MV_Mechanism_Str;
		Mech_Id_2 : MV_Mechanism_Str;
		Mech_Id_3 : MV_Mechanism_Str;
		Rob_Id_1 : USINT;
		Rob_Id_2_L : USINT;
		Rob_Id_2_R : USINT;
	END_STRUCT;
	MV_Mechanism_Str : 	STRUCT 
		Command : MV_Mechanism_Command_Str;
		Info : MV_Mechanism_Info_Str;
		Position : LREAL;
	END_STRUCT;
	MV_Mechanism_Info_Str : 	STRUCT 
		Active : BOOL;
		Power : BOOL;
		Home : BOOL;
		Safety : BOOL;
		Error : BOOL;
	END_STRUCT;
	MV_Mechanism_Command_Str : 	STRUCT 
		Power : BOOL;
		Home : BOOL;
		Start : BOOL;
		Stop : BOOL;
		Reset_Error : BOOL;
		Reset_Safety : USINT;
	END_STRUCT;
END_TYPE
