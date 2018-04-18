#include "slrtappmapping.h"
#include "./maps/dc_motor_encoder_hardware_simulated.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <dc_motor_encoder_hardware_simulated> */
		{ /* SignalMapInfo */
			dc_motor_encoder_hardware_simulated_BIOMAP,
			dc_motor_encoder_hardware_simulated_LBLMAP,
			dc_motor_encoder_hardware_simulated_SIDMAP,
			dc_motor_encoder_hardware_simulated_SBIO,
			dc_motor_encoder_hardware_simulated_SLBL,
			{0,38},
			37,
		},
		{ /* ParamMapInfo */
			dc_motor_encoder_hardware_simulated_PTIDSMAP,
			dc_motor_encoder_hardware_simulated_PTNAMESMAP,
			dc_motor_encoder_hardware_simulated_SPTMAP,
			{0,52},
			53,
		},
		"dc_motor_encoder_hardware_simulated",
		"",
		"dc_motor_encoder_hardware_simulated",
		3,
		dc_motor_encoder_hardware_simulated_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}