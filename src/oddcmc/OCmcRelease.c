#include "oddcmc/OCmcRelease.h"

#include "_/unmarshal.h"
#include "clingo/container/CBitVec.h"
#include "clingo/io/c_ImpExpError.h"
#include "clingo/type/int32.h"
#include "clingo/type/int8.h"
#include "oddcmc/cmcdecl.h"
#include "oddebml/error.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

static inline void cleanup( void* instance )
{
   OCmcRelease* rel = instance;
   release_c( rel->title );
   release_c( rel->type );
   release_c( rel->publisher );
   release_c( rel->imprint );
}

cMeta const O_CmcReleaseMeta = {
   .desc = stringify_c_( OCmcRelease ),
   .cleanup = &cleanup
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

void mimic_cmc_release_o( OCmcRelease rel[static 1],
                          OCmcRelease const src[static 1] )
{
   replace_c_( rel->title, src->title );
   replace_c_( rel->type, src->type );
   rel->language = src->language;
   rel->date = src->date;
   replace_c_( rel->publisher, src->publisher );
}

bool unmarshal_cmc_release_o( oEbmlElement const elem[static 1],
                              OCmcRelease rel[static 1],
                              cErrorStack es[static 1] )
{
   must_exist_c_( rel );
   cleanup( rel );
   *rel = (OCmcRelease){0};

   if ( not eq_ebml_id_o( elem->id, O_CmcRelease.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcRelease.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   if ( not unmarshal_req_ebml_utf8_o( // -------------------------------- Title
      sca, &(rel->title), O_CmcTitle.id, es
   ) )
      return false;

   if ( not unmarshal_req_ebml_string_o( // ------------------------------- Type
      sca, &(rel->type), O_CmcType.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_iso639_o( // --------------------------- Language
      sca, &(rel->language), O_CmcLanguage.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_year_o( // --------------------------------- Year
      sca, &(rel->date.year), O_CmcReleaseYear.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_month_o( // ------------------------------- Month
      sca, &(rel->date.month), O_CmcReleaseMonth.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_day_o( // ----------------------------------- Day
      sca, &(rel->date.day), O_CmcReleaseDay.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_utf8_o( // ---------------------------- Publisher
      sca, &(rel->publisher), O_CmcPublisher.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_utf8_o( // ------------------------------ Imprint
      sca, &(rel->imprint), O_CmcImprint.id, es
   ) )
      return false;

   return sca->space == 0;
}