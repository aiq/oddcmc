#ifndef ODDCMC_CMC_INFO_H
#define ODDCMC_CMC_INFO_H

#include "clingo/type/cChars.h"
#include "oddcmc/apidecl.h"
#include "oddcmc/cmcdecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

struct oCmcInfo
{
   cChars title;
   cChars series;
   uint64_t number;
};
typedef struct oCmcInfo oCmcInfo;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

ODDCMC_API bool unmarshal_cmc_info_o( oEbmlElement const elem[static 1],
                                      oCmcInfo info[static 1],
                                      cErrorStack es[static 1] );

#endif