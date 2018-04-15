#include "slrtappmapping.h"
#include "./maps/System.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <System> */
		{ /* SignalMapInfo */
			System_BIOMAP,
			System_LBLMAP,
			System_SIDMAP,
			System_SBIO,
			System_SLBL,
			{0,1},
			2,
		},
		{ /* ParamMapInfo */
			System_PTIDSMAP,
			System_PTNAMESMAP,
			System_SPTMAP,
			{0,15},
			16,
		},
		"System",
		"",
		"System",
		1,
		System_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}