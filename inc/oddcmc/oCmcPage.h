#ifndef ODDCMC_CMC_PAGE_H
#define ODDCMC_CMC_PAGE_H

#include "clingo/container/CByteVec.h"
#include "clingo/string/CStringList.h"
#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

struct oCmcPage
{
   CByteVec* data;
   uint64_t number;
   CStringList* content;
};
typedef struct oCmcPage oCmcPage;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

ODDCMC_API void deref_cmc_page_o( oCmcPage page[static 1] );

ODDCMC_API bool unmarshal_cmc_page_o( oEbmlElement const elem[static 1],
                                      oCmcPage page[static 1],
                                      cErrorStack es[static 1] );

#endif