#ifndef ODDCMC_CMC_CREATOR_H
#define ODDCMC_CMC_CREATOR_H

#include "clingo/container/CBitVec.h"
#include "clingo/string/CString.h"
#include "clingo/type/cChars.h"
#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

struct oCmcCreator
{
   CString* name;
   CString* job;
   CBitVec* pages;
};
typedef struct oCmcCreator oCmcCreator;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

ODDCMC_API void deref_cmc_creator_o( oCmcCreator creator[static 1] );

ODDCMC_API bool unmarshal_cmc_creator_o( oEbmlElement const elem[static 1],
                                         oCmcCreator creator[static 1],
                                         cErrorStack es[static 1] );

#endif