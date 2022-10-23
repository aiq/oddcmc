#ifndef ODDCMC_OCMC_STORY_H
#define ODDCMC_OCMC_STORY_H

#include "clingo/container/CBitVec.h"
#include "clingo/container/vec.h"
#include "clingo/string/CString.h"
#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

ODDCMC_API extern cMeta const O_CmcStoryMeta;

struct OCmcStory
{
   CString* title;
   CBitVec* pages;
};
typedef struct OCmcStory OCmcStory;

OBJ_VEC_DEF_C_(
   ODDCMC_API,       // LibApi
   OCmcStory,        // VecType
   OCmcStory,        // ObjType
   cmc_stories_c,    // FuncSuffix
   O_CmcStoriesMeta  // Meta
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

#define new_cmc_story_o_()                                                     \
   new_object_c_( OCmcStory, &O_CmcStoryMeta )

#define let_cmc_story_o_()                                                     \
   let_object_c_( OCmcStory, &O_CmcStoryMeta )

ODDCMC_API void mimic_cmc_story_o( OCmcStory story[static 1],
                                   OCmcStory const src[static 1] );

ODDCMC_API bool unmarshal_cmc_story_o( oEbmlElement const elem[static 1],
                                       OCmcStory story[static 1],
                                       cErrorStack es[static 1] );

#endif