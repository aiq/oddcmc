#ifndef ODDCMC_CMC_CREATOR_H
#define ODDCMC_CMC_CREATOR_H

#include "clingo/container/CBitVec.h"
#include "clingo/type/cChars.h"
#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

struct oCmcCreator
{
   cChars name;
   cChars job;
   CBitVec* pageSet;
};
typedef struct oCmcCreator oCmcCreator;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

ODDCMC_API bool unmarshal_cmc_creator_o( oEbmlElement const elem[static 1],
                                         oCmcCreator creator[static 1],
                                         cErrorStack es[static 1] );

#endif