#include "slrtappmapping.h"
#include "./maps/E_stopnew.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <E_stopnew> */
		{ /* SignalMapInfo */
			E_stopnew_BIOMAP,
			E_stopnew_LBLMAP,
			E_stopnew_SIDMAP,
			E_stopnew_SBIO,
			E_stopnew_SLBL,
			{0,2},
			3,
		},
		{ /* ParamMapInfo */
			E_stopnew_PTIDSMAP,
			E_stopnew_PTNAMESMAP,
			E_stopnew_SPTMAP,
			{0,16},
			17,
		},
		"E_stopnew",
		"",
		"E_stopnew",
		2,
		E_stopnew_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}