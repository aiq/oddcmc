#ifndef ODDCMC_OCMC_CREATOR_H
#define ODDCMC_OCMC_CREATOR_H

#include "clingo/container/CBitVec.h"
#include "clingo/container/vec.h"
#include "clingo/string/CString.h"
#include "clingo/type/cChars.h"
#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

ODDCMC_API extern cMeta const O_CmcCreatorMeta;

struct OCmcCreator
{
   CString* name;
   CString* job;
   CBitVec* pages;
};
typedef struct OCmcCreator OCmcCreator;

OBJ_VEC_DEF_C_(
   ODDCMC_API,       // LibApi
   OCmcCreators,     // VecType
   OCmcCreator,      // ObjType
   cmc_creators_o,   // FuncSuffix
   O_CmcCreatorsMeta // Meta
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define new_cmc_creator_o_()                                                   \
   new_object_c_( OCmcCreator, &O_CmcCreator )

#define let_cmc_creator_o_()                                                   \
   let_object_c_( OCmcCreator, &O_CmcCreator )

ODDCMC_API void mimic_cmc_creator_o( OCmcCreator story[static 1],
                                     OCmcCreator const src[static 1] );

ODDCMC_API bool unmarshal_cmc_creator_o( oEbmlElement const elem[static 1],
                                         OCmcCreator creator[static 1],
                                         cErrorStack es[static 1] );

#endif