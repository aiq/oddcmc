#include "oddcmc/OCmcIssue.h"

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
   OCmcIssue* issue = instance;
   release_c( issue->series );
   release_c( issue->variant );
   release_c( issue->pages );
}

cMeta const O_CmcIssueMeta = {
   .desc = stringify_c_( OCmcIssue ),
   .cleanup = &cleanup
};

OBJ_VEC_IMPL_C_(
   ,//optional       // Static
   OCmcIssues,       // VecType
   OCmcIssue,        // ObjType
   cmc_issues_o,     // FuncSuffix
   O_CmcIssuesMeta   // Meta
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

void mimic_cmc_issue_o( OCmcIssue issue[static 1],
                        OCmcIssue const src[static 1] )
{
   replace_c_( issue->series, src->series );
   issue->volume = src->volume;
   issue->number = src->number;
   replace_c_( issue->variant, src->variant );
   issue->language = src->language;
   replace_c_( issue->pages, src->pages );
   issue->date = src->date;
}

bool unmarshal_cmc_issue_o( oEbmlElement const elem[static 1],
                            OCmcIssue* issue,
                            cErrorStack es[static 1] )
{
   must_exist_c_( issue );
   cleanup( issue );
   *issue = (OCmcIssue){0};

   if ( not eq_ebml_id_o( elem->id, O_CmcIssue.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcIssue.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   if ( not unmarshal_req_ebml_utf8_o( // ------------------------------- Series
      sca, &(issue->series), O_CmcIssueSeries.id, es
   ) )
      return false;

   if ( not unmarshal_req_ebml_uint_o( // ------------------------------- Volume
      sca, &(issue->number), O_CmcIssueVolume.id, es
   ) )
      return false;

   if ( not unmarshal_req_ebml_uint_o( // ------------------------------- Number
      sca, &(issue->number), O_CmcIssueNumber.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_string_o( // ---------------------------- Variant
      sca, &(issue->variant), O_CmcIssueVariant.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_iso639_o( // --------------------------- Language
      sca, &(issue->language), O_CmcIssueLanguage.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_pages_o( // ------------------------------- Pages
      sca, &(issue->pages), O_CmcIssuePages.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_year_o( // --------------------------------- Year
      sca, &(issue->date.year), O_CmcIssueReleaseYear.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_month_o( // ------------------------------- Month
      sca, &(issue->date.month), O_CmcIssueReleaseMonth.id, es
   ) )
      return false;

   if ( not unmarshal_opt_ebml_day_o( // ----------------------------------- Day
      sca, &(issue->date.day), O_CmcIssueReleaseDay.id, es
   ) )
      return false;

   return sca->space == 0;
}