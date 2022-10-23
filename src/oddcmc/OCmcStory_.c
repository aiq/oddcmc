#include "oddcmc/OCmcStory.h"

#include "_/unmarshal.h"
#include "clingo/io/c_ImpExpError.h"
#include "oddcmc/cmcdecl.h"
#include "oddebml/error.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

static inline void cleanup( void* instance )
{
   OCmcStory* story = instance;
   release_c( story->title );
   release_c( story->pages );
}

cMeta const O_CmcStoryMeta = {
   .desc = stringify_c_( O_CmcStory ),
   .cleanup = &cleanup
};

OBJ_VEC_IMPL_C_(
   ,//optional       // Static
   OCmcStories,      // VecType
   OCmcStory,        // ObjType
   cmc_stories_o,    // FuncSuffix
   O_CmcStoriesMeta  // Meta
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

void mimic_cmc_story_o( OCmcStory story[static 1],
                        OCmcStory const src[static 1] )
{
   replace_c_( story->title, src->title );
   replace_c_( story->pages, src->pages );
}

bool unmarshal_cmc_story_o( oEbmlElement const elem[static 1],
                            OCmcStory story[static 1],
                            cErrorStack es[static 1] )
{
   cleanup( story );
   *story = (OCmcStory){0};

   return false;
}