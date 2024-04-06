#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include "ABB_Library.h"

// Custom Lib.: Base conversion between data.
#include "Converter.h"

void Sim_PROFINET_Mapping_IO_Data(struct ABB_Library* inst);

typedef enum Robot_State_ID_enum{
	ROB_STATE_ACTIVE,
	ROB_STATE_POWER,
	ROB_STATE_WAIT,
	ROB_STATE_UPD_PARAMETERS,
	ROB_STATE_MOTION_1,
	ROB_STATE_MOTION_2,
	ROB_STATE_HOME_UPD_PARAMETERS,
	ROB_STATE_HOME_MOTION_1,
	ROB_STATE_HOME_MOTION_2,
	ROB_STATE_STOP,
	ROB_STATE_SAFETY,
	ROB_STATE_ERROR
}Robot_State_ID_enum;

_LOCAL struct ABB_Library ABB_Library_Rob_1;

_LOCAL USINT Sim_PROFINET_Mapping_IN[256];
_LOCAL USINT Sim_PROFINET_Mapping_OUT[256];

void Sim_PROFINET_Mapping_IO_Data(struct ABB_Library* inst){
	// Mapping Input Data.
	Sim_PROFINET_Mapping_IN[0] = inst->PROFINET_Mapping_IN.SYSTEM.INPUT;
	Sim_PROFINET_Mapping_IN[1] = Sim_PROFINET_Mapping_OUT[1];
	Sim_PROFINET_Mapping_IN[2] = Sim_PROFINET_Mapping_OUT[2];
	Sim_PROFINET_Mapping_IN[3] = Sim_PROFINET_Mapping_OUT[3];
	Sim_PROFINET_Mapping_IN[4] = Sim_PROFINET_Mapping_OUT[4];
	Sim_PROFINET_Mapping_IN[5] = Sim_PROFINET_Mapping_OUT[5];
	Sim_PROFINET_Mapping_IN[6] = Sim_PROFINET_Mapping_OUT[6];
	Sim_PROFINET_Mapping_IN[7] = Sim_PROFINET_Mapping_OUT[7];
	Sim_PROFINET_Mapping_IN[8] = Sim_PROFINET_Mapping_OUT[8];
	Sim_PROFINET_Mapping_IN[9] = Sim_PROFINET_Mapping_OUT[9];
	Sim_PROFINET_Mapping_IN[10] = Sim_PROFINET_Mapping_OUT[10];
	Sim_PROFINET_Mapping_IN[11] = Sim_PROFINET_Mapping_OUT[11];
	Sim_PROFINET_Mapping_IN[12] = Sim_PROFINET_Mapping_OUT[12];
	Sim_PROFINET_Mapping_IN[13] = Sim_PROFINET_Mapping_OUT[13];
	Sim_PROFINET_Mapping_IN[14] = Sim_PROFINET_Mapping_OUT[14];
	Sim_PROFINET_Mapping_IN[15] = Sim_PROFINET_Mapping_OUT[15];
	Sim_PROFINET_Mapping_IN[16] = Sim_PROFINET_Mapping_OUT[16];
	Sim_PROFINET_Mapping_IN[17] = Sim_PROFINET_Mapping_OUT[17];
	Sim_PROFINET_Mapping_IN[18] = Sim_PROFINET_Mapping_OUT[18];
	Sim_PROFINET_Mapping_IN[19] = Sim_PROFINET_Mapping_OUT[19];
	Sim_PROFINET_Mapping_IN[20] = Sim_PROFINET_Mapping_OUT[20];
	Sim_PROFINET_Mapping_IN[21] = Sim_PROFINET_Mapping_OUT[21];
	Sim_PROFINET_Mapping_IN[22] = Sim_PROFINET_Mapping_OUT[22];
	Sim_PROFINET_Mapping_IN[23] = Sim_PROFINET_Mapping_OUT[23];
	Sim_PROFINET_Mapping_IN[24] = Sim_PROFINET_Mapping_OUT[24];
	Sim_PROFINET_Mapping_IN[25] = Sim_PROFINET_Mapping_OUT[25];
	Sim_PROFINET_Mapping_IN[26] = Sim_PROFINET_Mapping_OUT[26];
	Sim_PROFINET_Mapping_IN[27] = Sim_PROFINET_Mapping_OUT[27];
	Sim_PROFINET_Mapping_IN[28] = Sim_PROFINET_Mapping_OUT[28];
	Sim_PROFINET_Mapping_IN[29] = Sim_PROFINET_Mapping_OUT[29];
	Sim_PROFINET_Mapping_IN[30] = Sim_PROFINET_Mapping_OUT[30];
	Sim_PROFINET_Mapping_IN[31] = Sim_PROFINET_Mapping_OUT[31];
	Sim_PROFINET_Mapping_IN[32] = Sim_PROFINET_Mapping_OUT[32];
	Sim_PROFINET_Mapping_IN[33] = Sim_PROFINET_Mapping_OUT[33];
	Sim_PROFINET_Mapping_IN[34] = Sim_PROFINET_Mapping_OUT[34];
	Sim_PROFINET_Mapping_IN[35] = Sim_PROFINET_Mapping_OUT[35];
	Sim_PROFINET_Mapping_IN[36] = Sim_PROFINET_Mapping_OUT[36];
	Sim_PROFINET_Mapping_IN[37] = Sim_PROFINET_Mapping_OUT[37];
	Sim_PROFINET_Mapping_IN[38] = Sim_PROFINET_Mapping_OUT[38];
	Sim_PROFINET_Mapping_IN[39] = Sim_PROFINET_Mapping_OUT[39];
	Sim_PROFINET_Mapping_IN[40] = Sim_PROFINET_Mapping_OUT[40];
	Sim_PROFINET_Mapping_IN[41] = Sim_PROFINET_Mapping_OUT[41];
	Sim_PROFINET_Mapping_IN[42] = Sim_PROFINET_Mapping_OUT[42];
	Sim_PROFINET_Mapping_IN[43] = Sim_PROFINET_Mapping_OUT[43];
	Sim_PROFINET_Mapping_IN[44] = Sim_PROFINET_Mapping_OUT[44];
	Sim_PROFINET_Mapping_IN[45] = Sim_PROFINET_Mapping_OUT[45];
	Sim_PROFINET_Mapping_IN[46] = Sim_PROFINET_Mapping_OUT[46];

	// Mapping Output Data.
	Sim_PROFINET_Mapping_OUT[0] = 0;
	Sim_PROFINET_Mapping_OUT[1] = 0;
	Sim_PROFINET_Mapping_OUT[2] = 0;
	Sim_PROFINET_Mapping_OUT[3] = 0;
	Sim_PROFINET_Mapping_OUT[4] = 0;
	Sim_PROFINET_Mapping_OUT[5] = 0;
	Sim_PROFINET_Mapping_OUT[6] = 0;
	Sim_PROFINET_Mapping_OUT[7] = 0;
	Sim_PROFINET_Mapping_OUT[8] = 0;
	Sim_PROFINET_Mapping_OUT[9] = 0;
	Sim_PROFINET_Mapping_OUT[10] = 0;
	Sim_PROFINET_Mapping_OUT[11] = 0;
	Sim_PROFINET_Mapping_OUT[12] = 0;
	Sim_PROFINET_Mapping_OUT[13] = 0;
	Sim_PROFINET_Mapping_OUT[14] = 0;
	Sim_PROFINET_Mapping_OUT[15] = 0;
	Sim_PROFINET_Mapping_OUT[16] = 0;
	Sim_PROFINET_Mapping_OUT[17] = 0;
	Sim_PROFINET_Mapping_OUT[18] = 0;
	Sim_PROFINET_Mapping_OUT[19] = 0;
	Sim_PROFINET_Mapping_OUT[20] = 0;
	Sim_PROFINET_Mapping_OUT[21] = 0;
	Sim_PROFINET_Mapping_OUT[22] = 0;
	Sim_PROFINET_Mapping_OUT[23] = 0;
	Sim_PROFINET_Mapping_OUT[24] = 0;
	Sim_PROFINET_Mapping_OUT[25] = 0;
	Sim_PROFINET_Mapping_OUT[26] = 0;
	Sim_PROFINET_Mapping_OUT[27] = 0;
	Sim_PROFINET_Mapping_OUT[28] = 0;
	Sim_PROFINET_Mapping_OUT[29] = 0;
	Sim_PROFINET_Mapping_OUT[30] = 0;
	Sim_PROFINET_Mapping_OUT[31] = 0;
	Sim_PROFINET_Mapping_OUT[32] = 0;
	Sim_PROFINET_Mapping_OUT[33] = 0;
	Sim_PROFINET_Mapping_OUT[34] = 0;
	Sim_PROFINET_Mapping_OUT[35] = 0;
	Sim_PROFINET_Mapping_OUT[36] = 0;
	Sim_PROFINET_Mapping_OUT[37] = 0;
	Sim_PROFINET_Mapping_OUT[38] = 0;
	Sim_PROFINET_Mapping_OUT[39] = 0;
	Sim_PROFINET_Mapping_OUT[40] = 0;
	Sim_PROFINET_Mapping_OUT[41] = 0;
	Sim_PROFINET_Mapping_OUT[42] = 0;
	Sim_PROFINET_Mapping_OUT[43] = 0;
	Sim_PROFINET_Mapping_OUT[44] = 0;
	Sim_PROFINET_Mapping_OUT[45] = 0;
	Sim_PROFINET_Mapping_OUT[46] = 0;
	Sim_PROFINET_Mapping_OUT[47] = 0;
	Sim_PROFINET_Mapping_OUT[48] = 0;
	Sim_PROFINET_Mapping_OUT[49] = 0;
	Sim_PROFINET_Mapping_OUT[50] = 0;
	Sim_PROFINET_Mapping_OUT[51] = 0;
	Sim_PROFINET_Mapping_OUT[52] = 0;
	Sim_PROFINET_Mapping_OUT[53] = 0;
	Sim_PROFINET_Mapping_OUT[54] = 0;
	Sim_PROFINET_Mapping_OUT[55] = 0;
	Sim_PROFINET_Mapping_OUT[56] = 0;
	Sim_PROFINET_Mapping_OUT[57] = 0;
	Sim_PROFINET_Mapping_OUT[58] = 0;
	Sim_PROFINET_Mapping_OUT[59] = 0;
	Sim_PROFINET_Mapping_OUT[60] = 0;
	Sim_PROFINET_Mapping_OUT[61] = 0;
	Sim_PROFINET_Mapping_OUT[62] = 0;
	Sim_PROFINET_Mapping_OUT[63] = 0;
	Sim_PROFINET_Mapping_OUT[64] = 0;
	Sim_PROFINET_Mapping_OUT[65] = 0;
	Sim_PROFINET_Mapping_OUT[66] = 0;
	Sim_PROFINET_Mapping_OUT[67] = 0;
	Sim_PROFINET_Mapping_OUT[68] = 0;
	Sim_PROFINET_Mapping_OUT[69] = 0;
	Sim_PROFINET_Mapping_OUT[70] = 0;
	Sim_PROFINET_Mapping_OUT[71] = 0;
	Sim_PROFINET_Mapping_OUT[72] = 0;
	Sim_PROFINET_Mapping_OUT[73] = 0;
	Sim_PROFINET_Mapping_OUT[74] = 0;
	Sim_PROFINET_Mapping_OUT[75] = 0;
	Sim_PROFINET_Mapping_OUT[76] = 0;
	Sim_PROFINET_Mapping_OUT[77] = 0;
	Sim_PROFINET_Mapping_OUT[78] = 0;
	Sim_PROFINET_Mapping_OUT[79] = 0;
	Sim_PROFINET_Mapping_OUT[80] = 0;
	Sim_PROFINET_Mapping_OUT[81] = 0;
	Sim_PROFINET_Mapping_OUT[82] = 0;
	Sim_PROFINET_Mapping_OUT[83] = 0;
	Sim_PROFINET_Mapping_OUT[84] = 0;
	Sim_PROFINET_Mapping_OUT[85] = 0;
	Sim_PROFINET_Mapping_OUT[86] = 0;
	Sim_PROFINET_Mapping_OUT[87] = 0;
	Sim_PROFINET_Mapping_OUT[88] = 0;
	Sim_PROFINET_Mapping_OUT[89] = 0;
	Sim_PROFINET_Mapping_OUT[90] = 0;
	Sim_PROFINET_Mapping_OUT[91] = 0;
	Sim_PROFINET_Mapping_OUT[92] = 0;
	Sim_PROFINET_Mapping_OUT[93] = 0;
	Sim_PROFINET_Mapping_OUT[94] = 0;
	Sim_PROFINET_Mapping_OUT[95] = 0;
	Sim_PROFINET_Mapping_OUT[96] = 0;
	Sim_PROFINET_Mapping_OUT[97] = 0;
	Sim_PROFINET_Mapping_OUT[98] = 0;
	Sim_PROFINET_Mapping_OUT[99] = 0;
	Sim_PROFINET_Mapping_OUT[100] = 0;
	Sim_PROFINET_Mapping_OUT[101] = 0;
	Sim_PROFINET_Mapping_OUT[102] = 0;
	Sim_PROFINET_Mapping_OUT[103] = 0;
	Sim_PROFINET_Mapping_OUT[104] = 0;
	Sim_PROFINET_Mapping_OUT[105] = 0;
	Sim_PROFINET_Mapping_OUT[106] = 0;
	Sim_PROFINET_Mapping_OUT[107] = 0;
	Sim_PROFINET_Mapping_OUT[108] = 0;
	Sim_PROFINET_Mapping_OUT[109] = 0;
	Sim_PROFINET_Mapping_OUT[110] = 0;
	Sim_PROFINET_Mapping_OUT[111] = 0;
	Sim_PROFINET_Mapping_OUT[112] = 0;
	Sim_PROFINET_Mapping_OUT[113] = 0;
	Sim_PROFINET_Mapping_OUT[114] = 0;
	Sim_PROFINET_Mapping_OUT[115] = 0;
	Sim_PROFINET_Mapping_OUT[116] = 0;
	Sim_PROFINET_Mapping_OUT[117] = 0;
	Sim_PROFINET_Mapping_OUT[118] = 0;
}
