#include "oddcmc/OCmcCreator.h"

#include "_/unmarshal.h"
#include "oddcmc/cmcdecl.h"
#include "oddebml/error.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

static inline void cleanup( void* instance )
{
   OCmcCreator* creator = instance;
   release_c( creator->name );
   release_c( creator->job );
   release_c( creator->pages );
}

cMeta const O_CmcCreatorMeta = {
   .desc = stringify_c_( OCmcCreator ),
   .cleanup = &cleanup
};

OBJ_VEC_IMPL_C_(
   ,//optional       // Static
   OCmcCreators,     // VecType
   OCmcCreator,      // ObjType
   cmc_creators_o,   // FuncSuffix
   O_CmcCreatorsMeta // Meta
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

void mimic_cmc_creator_o( OCmcCreator creator[static 1],
                          OCmcCreator const src[static 1] )
{
   replace_c_( creator->name, src->name );
   replace_c_( creator->job, src->job );
   replace_c_( creator->pages, src->pages );
}

bool unmarshal_cmc_creator_o( oEbmlElement const elem[static 1],
                              OCmcCreator creator[static 1],
                              cErrorStack es[static 1] )
{
   cleanup( creator );
   *creator = (OCmcCreator){0};

   if ( not eq_ebml_id_o( elem->id, O_CmcCreator.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcCreator.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   if ( not unmarshal_req_ebml_utf8_o( // --------------------------------- Name
      sca, &(creator->name), O_CmcCreatorName.id, es
   ) )
      return false;

   if ( not unmarshal_req_ebml_string_o( // -------------------------------- Job
      sca, &(creator->job), O_CmcCreatorJob.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_pages_o( // ------------------------------- Pages
      sca, &(creator->pages), O_CmcCreatorPages.id, es
   ) )
      return false;

   return sca->space == 0;
}
