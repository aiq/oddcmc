#ifndef ODDCMC_OCMC_H
#define ODDCMC_OCMC_H

#include "oddcmc/apidecl.h"
#include "oddcmc/OCmcInfo.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

ODDCMC_API extern cMeta const O_CmcMeta;

struct OCmc
{
   OCmcInfo* info;
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

ODDCMC_API bool unmarshal_cmc_o( oEbmlElement const elem[static 1],
                                 OCmc* cmc,
                                 cErrorStack es[static 1] );

#endif