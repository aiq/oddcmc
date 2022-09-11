#ifndef ODDCMC_CMC_H
#define ODDCMC_CMC_H

#include "oddcmc/apidecl.h"
#include "oddcmc/oCmcInfo.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

struct oCmc
{
   oCmcInfo info;
};
typedef struct oCmc oCmc;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

ODDCMC_API void deref_cmc_o( oCmc cmc[static 1] );

ODDCMC_API bool unmarshal_cmc_o( oEbmlElement const elem[static 1],
                                 oCmc cmc[static 1],
                                 cErrorStack es[static 1] );

#endif