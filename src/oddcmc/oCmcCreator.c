#include "oddcmc/oCmcCreator.h"

#include "_/unmarshal.h"
#include "oddcmc/cmcdecl.h"
#include "oddebml/error.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

void deref_cmc_creator_o( oCmcCreator creator[static 1] )
{
   release_c( creator->name );
   release_c( creator->job );
   release_c( creator->pages );
   *creator = (oCmcCreator){0};
}

bool unmarshal_cmc_creator_o( oEbmlElement const elem[static 1],
                              oCmcCreator creator[static 1],
                              cErrorStack es[static 1] )
{
   deref_cmc_creator_o( creator );

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