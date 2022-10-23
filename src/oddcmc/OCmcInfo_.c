#include "oddcmc/OCmcInfo.h"

#include "oddebml/error.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

static inline void cleanup( void* instance )
{
   OCmcInfo* info = instance;
   release_c( info->release );
}

cMeta const O_CmcInfoMeta = {
   .desc = stringify_c_( OCmcInfo ),
   .cleanup = &cleanup
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

void mimic_cmc_info_o( OCmcInfo info[static 1],
                       OCmcInfo const src[static 1] )
{
   replace_c_( info->release, src->release );
}

bool unmarshal_cmc_info_o( oEbmlElement const elem[static 1],
                           OCmcInfo* info,
                           cErrorStack es[static 1] )
{
   must_exist_c_( info );
   cleanup( info );
   *info = (OCmcInfo){0};

   if ( not eq_ebml_id_o( elem->id, O_CmcInfo.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcInfo.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   return sca->space == 0;
}