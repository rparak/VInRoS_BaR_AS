
TYPE
	Traj_Str : 	STRUCT 
		Targets : Targets_Str;
		Length : USINT;
		Iteration : USINT;
	END_STRUCT;
	Targets_Str : 	STRUCT 
		Position : ARRAY[0..99]OF Targets_Position_Str;
		Speed : ARRAY[0..99]OF USINT;
		Zone : ARRAY[0..99]OF USINT;
	END_STRUCT;
	Targets_Position_Str : 	STRUCT 
		Q : ARRAY[0..5]OF REAL;
		Q_Ex : ARRAY[0..5]OF REAL;
	END_STRUCT;
END_TYPE
