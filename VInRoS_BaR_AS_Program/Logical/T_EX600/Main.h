#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

typedef enum EX600_State_ID_enum{
	EX600_STATE_ACTIVE,
	EX600_STATE_HOME,
	EX600_STATE_WAIT,
	EX600_STATE_ERROR
}EX600_State_ID_enum;
