#ifndef ODDCMC_OCMC_PAGE_H
#define ODDCMC_OCMC_PAGE_H

#include "clingo/container/CByteVec.h"
#include "clingo/string/CStringList.h"
#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

ODDCMC_API extern cMeta const O_CmcPageMeta;

struct OCmcPage
{
   CByteVec* data;
   uint64_t number;
   CStringList* content;
};
typedef struct OCmcPage OCmcPage;

OBJ_VEC_DEF_C_(
   ODDCMC_API,    // LibApi
   OCmcPages,     // VecType
   OCmcPage,      // ObjType
   cmc_pages_o,   // FuncSuffix
   O_CmcPagesMeta // Meta
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

#define new_cmc_page_o_()                                                      \
   new_object_c_( OCmcPage, &O_CmcPageMeta )

#define let_cmc_page_o_()                                                      \
   let_object_c_( OCmcPage, &O_CmcPageMeta )

ODDCMC_API void mimic_cmc_page_o( OCmcPage page[static 1],
                                  OCmcPage const src[static 1] );

ODDCMC_API bool unmarshal_cmc_page_o( oEbmlElement const elem[static 1],
                                      OCmcPage page[static 1],
                                      cErrorStack es[static 1] );

#endif