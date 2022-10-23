#ifndef ODDCMC_OCMC_H
#define ODDCMC_OCMC_H

#include "oddcmc/apidecl.h"
#include "oddcmc/OCmcInfo.h"
#include "oddcmc/OCmcPage.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

ODDCMC_API extern cMeta const O_CmcMeta;

struct OCmc
{
   OCmcInfo* info;
   OCmcPages* pages;
};
typedef struct OCmc OCmc;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

#define new_cmc_o_()                                                           \
   new_object_c_( OCmc, &O_CmcMeta )

#define let_cmc_o_()                                                           \
   let_object_c_( OCmc, &O_CmcMeta )

ODDCMC_API void mimic_cmc_o( OCmc cmc[static 1], OCmc const src[static 1] );

ODDCMC_API bool unmarshal_cmc_o( oEbmlElement const elem[static 1],
                                 OCmc cmc[static 1],
                                 cErrorStack es[static 1] );

#endif