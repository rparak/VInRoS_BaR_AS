
TYPE
	Traj_Str : 	STRUCT 
		Targets : Targets_Str;
		Length : USINT;
		Iteration : USINT;
	END_STRUCT;
	Targets_Str : 	STRUCT 
		Position : ARRAY[0..100]OF LREAL;
		Velocity : ARRAY[0..100]OF REAL;
	END_STRUCT;
END_TYPE
