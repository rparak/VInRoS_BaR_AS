
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

/// Function block for controlling all basic functions of a single axis
_LOCAL struct MpAxisBasic MpAxisBasic_0;
_LOCAL struct MpAxisCyclicSet MpAxisCyclicSet_0;
/// Standard parameters for controlling axes (position, velocity, etc.)
_LOCAL struct MpAxisBasicParType AxisParameters;
_LOCAL struct MpAxisCyclicSetParType AxisCyclicParameters;

_LOCAL USINT actual_state;
_LOCAL LREAL dt_position;

// add start/stop of the streaming!!!

void _INIT ProgramInit(void)
{
	/// Declaration of function block inputs
	MpAxisBasic_0.Enable     = 1;			    ///< Enables the function block
	MpAxisBasic_0.MpLink     = &gAxis_Mech_02;		///< Connection to mapp (MpLink of an MpAxisBasic configuration)
	MpAxisBasic_0.Parameters = &AxisParameters;	///< Function block parameters
	// ...
	AxisParameters.Velocity     = 500;
	AxisParameters.Acceleration = 2000;
	AxisParameters.Deceleration = 2000;
	
	MpAxisCyclicSet_0.Enable = 1;
	MpAxisCyclicSet_0.MpLink = &gAxis_Mech_02;
	MpAxisCyclicSet_0.Parameters = &AxisCyclicParameters;
	AxisCyclicParameters.MoveCyclicVelocity.Mode = mcAXIS_MCV_MODE_MOVE_CYC_VEL;
	AxisCyclicParameters.MoveCyclicVelocity.InterpolationMode = mcIPLM_DEFAULT;
	AxisCyclicParameters.MoveCyclicVelocity.Acceleration = 20000;
	AxisCyclicParameters.MoveCyclicVelocity.Deceleration = 20000;

	actual_state = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	switch(actual_state){
		case 0:
			{
				if(MpAxisBasic_0.Active == 1 && GLOBAL_START == 1){
					actual_state = 1;
				}
			}
			break;
		case 1:
			{
				MpAxisBasic_0.Power = 1;
			
				if(MpAxisBasic_0.PowerOn == 1){
					actual_state = 2;
					
				}
			}
			break;
		case 2:
			{
				MpAxisBasic_0.Home = 1;
			
				if(MpAxisBasic_0.IsHomed == 1){
					MpAxisBasic_0.Home = 0;
					actual_state = 6;
					
				}
			}
			break;
		
		case 6:
			{
				MpAxisCyclicSet_0.MoveCyclicVelocity = 1;

				if(MpAxisCyclicSet_0.MoveCyclicVelocityActive == 1){
					actual_state = 7;
				}
			}
			break;
		
		case 7:
			{
				MpAxisCyclicSet_0.CyclicVelocity = GLOBAL_VEL;
			}
			break;
		
	}
	
	/// call MpAxisBasic function block
	MpAxisBasic(&MpAxisBasic_0);
	MpAxisCyclicSet(&MpAxisCyclicSet_0);
	
	dt_position = MpAxisBasic_0.Position;
}

