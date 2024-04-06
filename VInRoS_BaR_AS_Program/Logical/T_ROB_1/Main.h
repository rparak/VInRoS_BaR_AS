#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include "ABB_Library.h"

// Custom Lib.: Base conversion between data.
#include "Converter.h"

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
