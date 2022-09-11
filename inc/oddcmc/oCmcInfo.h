#ifndef ODDCMC_CMC_INFO_H
#define ODDCMC_CMC_INFO_H

#include "oddcmc/apidecl.h"
#include "oddcmc/cmcdecl.h"
#include "oddcmc/oCmcRelease.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

struct oCmcInfo
{
   oCmcRelease release;
};
typedef struct oCmcInfo oCmcInfo;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

ODDCMC_API void deref_cmc_info_o( oCmcInfo info[static 1] );

ODDCMC_API bool unmarshal_cmc_info_o( oEbmlElement const elem[static 1],
                                      oCmcInfo info[static 1],
                                      cErrorStack es[static 1] );

#endif