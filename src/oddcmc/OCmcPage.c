#include "oddcmc/OCmcPage.h"

#include "_/unmarshal.h"
#include "oddcmc/cmcdecl.h"
#include "oddebml/error.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

static inline void cleanup( void* instance )
{
   OCmcPage* page = instance;
   release_c( page->data );
   release_c( page->content );
}

cMeta const O_CmcPageMeta = {
   .desc = stringify_c_( OCmcPage ),
   .cleanup = &cleanup
};

OBJ_VEC_IMPL_C_(
   ,//optional    // Static
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

void mimic_cmc_page_p( OCmcPage page[static 1], OCmcPage const src[static 1] )
{
   replace_c_( page->data, src->data );
   page->number = src->number;
   replace_c_( page->content, src->content );
}

bool unmarshal_cmc_page_o( oEbmlElement const elem[static 1],
                           OCmcPage* page,
                           cErrorStack es[static 1] )
{
   must_exist_c_( page );
   cleanup( page );
   *page = (OCmcPage){0};

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