#include "oddcmc/oCmcIssue.h"

#include "clingo/io/c_ImpExpError.h"
#include "clingo/type/int32.h"
#include "clingo/type/int8.h"
#include "oddcmc/cmcdecl.h"
#include "oddebml/error.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

   XMAP_C_( O_CmcIssue, "Issue", 0x1, mand_, mult_, o_EbmlMaster ) \
   XMAP_C_( O_CmcIssueSeries, "IssueSeries", 0x1, mand_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcIssueVolume, "IssueVolume", 0x1, mand_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueNumber, "IssueNumber", 0x1, mand_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueReleaseYear, "IssueReleaseYear", 0x1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueReleaseMonth, "IssueReleaseMonth", 0x1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueReleaseDay, "IssueReleaseDay", 0x1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueLanguage, "IssueLanguage", 0x1, opt_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcIssuePages, "IssuePages", 0x1, opt_, single_, o_EbmlString ) \

*******************************************************************************/

void deref_cmc_issue_o( oCmcIssue issue[static 1] )
{

}

bool unmarshal_cmc_issue_o( oEbmlElement const elem[static 1],
                            oCmcIssue issue[static 1],
                            cErrorStack es[static 1] )
{
   *issue = (oCmcIssue){0};

   if ( not eq_ebml_id_o( elem->id, O_CmcIssue.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcIssue.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   // ------------------------------------------------------------------- Series
   if ( not on_ebml_id_o( sca, O_CmcIssueSeries.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcIssueSeries.id );

   cChars series;
   if ( not view_ebml_utf8_element_o( sca, &series ) )
      return push_imp_exp_error_c( es, sca->err ) or
             push_unmarshal_ebml_error_o( es, O_CmcIssueSeries.id, o_EbmlUtf8 );

   issue->series = retain_c( make_string_c( series ) );
   if ( issue->series == NULL )
      return push_errno_error_c( es, ENOMEM );

   // ------------------------------------------------------------------- Volume
   if ( not on_ebml_id_o( sca, O_CmcIssueVolume.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcIssueVolume.id );

   if ( not scan_ebml_uint_element_o( sca, &(issue->volume) ) )
      return push_imp_exp_error_c( es, sca->err ) or
             push_unmarshal_ebml_error_o( es, O_CmcIssueVolume.id, o_EbmlUint );

   // ------------------------------------------------------------------- Number
   if ( not on_ebml_id_o( sca, O_CmcIssueNumber.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcIssueNumber.id );

   if ( not scan_ebml_uint_element_o( sca, &(issue->number) ) )
      return push_imp_exp_error_c( es, sca->err ) or
             push_unmarshal_ebml_error_o( es, O_CmcIssueNumber.id, o_EbmlUint );

   // ------------------------------------------------------------------ Variant
   if ( on_ebml_id_o( sca, O_CmcIssueVariant.id ) )
   {
      cChars variant;
      if ( not view_ebml_string_element_o( sca, &variant ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcIssueVariant.id, o_EbmlString );

      issue->variant = retain_c( make_string_c( variant ) );
      if ( issue->variant == NULL )
         return push_errno_error_c( es, ENOMEM );
   }

   // --------------------------------------------------------------------- Year
   if ( on_ebml_id_o( sca, O_CmcIssueReleaseYear.id ) )
   {
      uint64_t year;
      if ( not scan_ebml_uint_element_o( sca, &year ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcIssueReleaseYear.id, o_EbmlUint );
   
      if ( not uint64_to_int32_c( year, &(issue->date.year) ) )
         return push_errno_error_c( es, ERANGE ) or
                push_lit_str_error_c( es, "CMCIssueReleaseYear value out of range" );
   }

   // -------------------------------------------------------------------- Month
   if ( on_ebml_id_o( sca, O_CmcIssueReleaseMonth.id ) )
   {
      uint64_t month;
      if ( not scan_ebml_uint_element_o( sca, &month ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcIssueReleaseMonth.id, o_EbmlUint );

      uint8_t monthVal;
      if ( not uint64_to_uint8_c( month, &monthVal ) )
         return push_errno_error_c( es, ERANGE ) or
                push_lit_str_error_c( es, "CMCIssueReleaseMonth value out of range" );

      issue->date.month = monthVal;
   }

   // ---------------------------------------------------------------------- Day
   if ( on_ebml_id_o( sca, O_CmcIssueReleaseDay.id ) )
   {
      uint64_t day;
      if ( not scan_ebml_uint_element_o( sca, &day ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcIssueReleaseDay.id, o_EbmlUint );

      if ( not uint64_to_int8_c( day, &(issue->date.day) ) )
         return push_errno_error_c( es, ERANGE ) or
                push_lit_str_error_c( es, "CMCIssueReleaseDay value out of range" );
   }



   return false;
}