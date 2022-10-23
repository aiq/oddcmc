#include "oddcmc/OCmc.h"

#include "oddebml/error.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

static inline void cleanup( void* instance )
{
   OCmc* cmc = instance;
   release_c( cmc->info );
}

cMeta const O_CmcMeta = {
   .desc = stringify_c_( OCmc ),
   .cleanup = &cleanup
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

void mimic_cmc_o( OCmc cmc[static 1], OCmc const src[static 1] )
{
   replace_c_( cmc->info, src->info );
   replace_c_( cmc->pages, src->pages );
}

bool unmarshal_cmc_o( oEbmlElement const elem[static 1],
                      OCmc cmc[static 1],
                      cErrorStack es[static 1] )
{
   cleanup( cmc );
   *cmc = (OCmc){0};

   if ( not eq_ebml_id_o( elem->id, O_Cmc.id ) )
      return push_missing_ebml_id_error_o( es, O_Cmc.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   return sca->space == 0;
}