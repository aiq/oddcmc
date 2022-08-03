#include "oddcmc/oCmcRelease.h"

#include "clingo/io/c_ImpExpError.h"
#include "clingo/type/int32.h"
#include "clingo/type/int8.h"
#include "oddcmc/cmcdecl.h"
#include "oddebml/error.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

void deref_cmc_release_o( oCmcRelease rel[static 1] )
{
   release_c( rel->title );
   release_c( rel->type );
   release_c( rel->publisher );
   release_c( rel->imprint );
   release_c( rel->language );
   *rel = (oCmcRelease){0};
}

bool unmarshal_cmc_release_o( oEbmlElement const elem[static 1],
                              oCmcRelease rel[static 1],
                              cErrorStack es[static 1] )
{
   *rel = (oCmcRelease){0};

   if ( not eq_ebml_id_o( elem->id, O_CmcRelease.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcInfo.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   // -------------------------------------------------------------------- Title
   if ( not on_ebml_id_o( sca, O_CmcTitle.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcTitle.id );

   cChars title;
   if ( not view_ebml_utf8_element_o( sca, &title ) )
      return push_imp_exp_error_c( es, sca->err ) or
             push_unmarshal_ebml_error_o( es, O_CmcTitle.id, o_EbmlUtf8 );

   rel->title = retain_c( make_string_c( title ) );
   if ( rel->title == NULL )
      return push_errno_error_c( es, ENOMEM );

   // --------------------------------------------------------------------- Type
   if ( not on_ebml_id_o( sca, O_CmcType.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcType.id );

   cChars type;
   if ( not view_ebml_string_element_o( sca, &type ) )
      return push_imp_exp_error_c( es, sca->err ) or
             push_unmarshal_ebml_error_o( es, O_CmcType.id, o_EbmlString );

   rel->type = retain_c( make_string_c( type ) );
   if ( rel->type == NULL )
      return push_errno_error_c( es, ENOMEM );

   // --------------------------------------------------------------------- Year
   if ( on_ebml_id_o( sca, O_CmcReleaseYear.id ) )
   {
      uint64_t year;
      if ( not scan_ebml_uint_element_o( sca, &year ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcReleaseYear.id, o_EbmlUint );
   
      if ( not uint64_to_int32_c( year, &(rel->date.year) ) )
         return push_errno_error_c( es, ERANGE ) or
                push_lit_str_error_c( es, "CMCReleaseYear value out of range" );
   }

   // -------------------------------------------------------------------- Month
   if ( on_ebml_id_o( sca, O_CmcReleaseMonth.id ) )
   {
      uint64_t month;
      if ( not scan_ebml_uint_element_o( sca, &month ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcReleaseMonth.id, o_EbmlUint );

      if ( not uint64_to_month_c( month, &(rel->date.month ) ) )
         return push_errno_error_c( es, ERANGE ) or
                push_lit_str_error_c( es, "CMCReleaseMonth value out of range" );
   }

   // ---------------------------------------------------------------------- Day
   if ( on_ebml_id_o( sca, O_CmcReleaseDay.id ) )
   {
      uint64_t day;
      if ( not scan_ebml_uint_element_o( sca, &day ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcReleaseDay.id, o_EbmlUint );

      if ( not uint64_to_int8_c( day, &(rel->date.day) ) )
         return push_errno_error_c( es, ERANGE ) or
                push_lit_str_error_c( es, "CMCReleaseDay value out of range" );
   }

   // ---------------------------------------------------------------- Publisher
   if ( on_ebml_id_o( sca, O_CmcPublisher.id ) )
   {
      cChars publisher;
      if ( not view_ebml_utf8_element_o( sca, &publisher ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcPublisher.id, o_EbmlUtf8 );

      rel->publisher = retain_c( make_string_c( publisher ) );
      if ( rel->publisher == NULL )
         return push_errno_error_c( es, ENOMEM );
   }

   // ------------------------------------------------------------------ Imprint
   if ( on_ebml_id_o( sca, O_CmcImprint.id ) )
   {
      cChars imprint;
      if ( not view_ebml_utf8_element_o( sca, &imprint ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcImprint.id, o_EbmlUtf8 );
   
      rel->imprint = retain_c( make_string_c( imprint ) );
      if ( rel->imprint == NULL )
         return push_errno_error_c( es, ENOMEM );
   }

   // ----------------------------------------------------------------- Language
   if ( on_ebml_id_o( sca, O_CmcLanguage.id ) )
   {
      cChars language;
      if ( not view_ebml_string_element_o( sca, &language ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, O_CmcLanguage.id, o_EbmlString );

      rel->language = retain_c( make_string_c( language ) );
      if ( rel->language == NULL )
         return push_errno_error_c( es, ENOMEM );
   }

   return sca->space == 0;
}