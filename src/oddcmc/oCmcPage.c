#include "oddcmc/oCmcPage.h"

#include "_/unmarshal.h"
#include "oddcmc/cmcdecl.h"
#include "oddebml/error.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/



/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

void deref_cmc_page_o( oCmcPage page[static 1] )
{
   release_c( page->data );
   release_c( page->content );
   *page = (oCmcPage){0};
}

bool unmarshal_cmc_page_o( oEbmlElement const elem[static 1],
                           oCmcPage page[static 1],
                           cErrorStack es[static 1] )
{
   deref_cmc_page_o( page );

   if ( not eq_ebml_id_o( elem->id, O_CmcPage.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcPage.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   if ( not unmarshal_req_ebml_uint_o( // ------------------------------- number
      sca, &(page->number), O_CmcPageNumber.id, es
   ) )
      return false;

   if ( not unmarshal_req_ebml_data_o( // --------------------------------- data
      sca, &(page->data), O_CmcPageData.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_string_list_o( // ----------------------- content
      sca, &(page->content), O_CmcPageContent.id, es
   ) )
      return false;

   return sca->pos == 0;
}