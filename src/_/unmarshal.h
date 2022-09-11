#ifndef ODDCMC_INTERN_MISC_H
#define ODDCMC_INTERN_MISC_H

#include "clingo/container/CBitVec.h"
#include "clingo/container/CByteVec.h"
#include "clingo/io/c_ImpExpError.h"
#include "clingo/string/CString.h"
#include "clingo/string/CStringList.h"
#include "clingo/time/c_Month.h"
#include "clingo/type/int32.h"
#include "clingo/type/int8.h"
#include "iso639/cIso639.h"
#include "oddebml/error.h"
#include "oddebml/oEbmlId.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************

*******************************************************************************/

static __attribute__((unused))
bool unmarshal_req_ebml_data_o( cScanner sca[static 1],
                                CByteVec* vec[static 1],
                                oEbmlId id,
                                cErrorStack es[static 1] )
{
   if ( not on_ebml_id_o( sca, id ) )
      return push_missing_ebml_id_error_o( es, id );

   cBytes bytes;
   if ( not view_ebml_binary_element_o( sca, &bytes ) )
      return push_imp_exp_error_c( es, sca->err ) or
             push_unmarshal_ebml_error_o( es, id, o_EbmlBinary );

   *vec = retain_c( make_byte_vec_c( bytes.s ) );
   if ( *vec == NULL )
      return push_errno_error_c( es, ENOMEM );

   add_many_to_byte_vec_c( *vec, bytes );

   return true;
}

static __attribute__((unused))
bool unmarshal_req_ebml_string_o( cScanner sca[static 1],
                                  CString* str[static 1],
                                  oEbmlId id,
                                  cErrorStack es[static 1] )
{
   if ( not on_ebml_id_o( sca, id ) )
      return push_missing_ebml_id_error_o( es, id );

   cChars type;
   if ( not view_ebml_string_element_o( sca, &type ) )
      return push_imp_exp_error_c( es, sca->err ) or
             push_unmarshal_ebml_error_o( es, id, o_EbmlString );

   *str = retain_c( make_string_c( type ) );
   if ( *str == NULL )
      return push_errno_error_c( es, ENOMEM );

   return true;
}

static __attribute__((unused))
bool unmarshal_req_ebml_utf8_o( cScanner sca[static 1],
                                CString* str[static 1],
                                oEbmlId id,
                                cErrorStack es[static 1] )
{
   if ( not on_ebml_id_o( sca, id ) )
      return push_missing_ebml_id_error_o( es, id );

   cChars chars;
   if ( not view_ebml_utf8_element_o( sca, &chars ) )
      return push_imp_exp_error_c( es, sca->err ) or
             push_unmarshal_ebml_error_o( es, id, o_EbmlUtf8 );

   *str = retain_c( make_string_c( chars ) );
   if ( *str == NULL )
      return push_errno_error_c( es, ENOMEM );

   return true;
}

static __attribute__((unused))
bool unmarshal_req_ebml_uint_o( cScanner sca[static 1],
                                uint64_t val[static 1],
                                oEbmlId id,
                                cErrorStack es[static 1] )
{
   if ( not on_ebml_id_o( sca, id ) )
      return push_missing_ebml_id_error_o( es, id );

   if ( not scan_ebml_uint_element_o( sca, val ) )
      return push_imp_exp_error_c( es, sca->err ) or
             push_unmarshal_ebml_error_o( es, id, o_EbmlUint );

   return true;
}

static __attribute__((unused))
bool unmarshal_opt_ebml_string_o( cScanner sca[static 1],
                                  CString* str[static 1],
                                  oEbmlId id,
                                  cErrorStack es[static 1] )
{
   if ( on_ebml_id_o( sca, id ) )
   {
      cChars chars;
      if ( not view_ebml_string_element_o( sca, &chars ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, id, o_EbmlString );

      *str = retain_c( make_string_c( chars ) );
      if ( *str == NULL )
         return push_errno_error_c( es, ENOMEM );
   }

   return true;
}

static __attribute__((unused))
bool unmarshal_opt_ebml_string_list_o( cScanner sca[static 1],
                                       CStringList* list[static 1],
                                       oEbmlId id,
                                       cErrorStack es[static 1] )
{
   while ( on_ebml_id_o( sca, id ) )
   {
      if ( *list == NULL )
      {
         *list = make_string_list_c( 2 );
         if ( *list == NULL )
            return push_errno_error_c( es, ENOMEM );
      }
      cChars chars;
      if ( not view_ebml_string_element_o( sca, &chars ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, id, o_EbmlString );

      if ( not add_chars_to_string_list_c( *list, chars ) )
         return push_errno_error_c( es, ENOMEM );
   }

   return true;
}

static __attribute__((unused))
bool unmarshal_opt_ebml_iso639_o( cScanner sca[static 1],
                                  cIso639 language[static 1],
                                  oEbmlId id,
                                  cErrorStack es[static 1] )
{
   if ( on_ebml_id_o( sca, id ) )
   {
      cChars chars;
      if ( not view_ebml_string_element_o( sca, &chars ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, id, o_EbmlString );

      *language = iso639_c( chars );
      if ( not is_iso639_bib_c( *language ) )
         return push_errno_error_c( es, ENOMEM );
   }

   return true;
}

static __attribute__((unused))
bool unmarshal_opt_ebml_year_o( cScanner sca[static 1],
                                int32_t year[static 1],
                                oEbmlId id,
                                cErrorStack es[static 1] )
{
   if ( on_ebml_id_o( sca, id ) )
   {
      uint64_t val;
      if ( not scan_ebml_uint_element_o( sca, &val ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, id, o_EbmlUint );
   
      if ( not uint64_to_int32_c( val, year ) )
         return push_errno_error_c( es, ERANGE );
   }

   return true;
}

static __attribute__((unused))
bool unmarshal_opt_ebml_month_o( cScanner sca[static 1],
                                 c_Month month[static 1],
                                 oEbmlId id,
                                 cErrorStack es[static 1] )
{
   if ( on_ebml_id_o( sca, id ) )
   {
      uint64_t val;
      if ( not scan_ebml_uint_element_o( sca, &val ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, id, o_EbmlUint );

      if ( not uint64_to_month_c( val, month ) )
         return push_errno_error_c( es, ERANGE );
   }

   return true;
}

static __attribute__((unused))
bool unmarshal_opt_ebml_day_o( cScanner sca[static 1],
                               int8_t day[static 1],
                               oEbmlId id,
                               cErrorStack es[static 1] )
{
   if ( on_ebml_id_o( sca, id ) )
   {
      uint64_t val;
      if ( not scan_ebml_uint_element_o( sca, &val ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, id, o_EbmlUint );

      if ( not uint64_to_int8_c( val, day ) )
         return push_errno_error_c( es, ERANGE );
   }

   return true;
}

static __attribute__((unused))
bool unmarshal_opt_ebml_pages_o( cScanner sca[static 1],
                                 CBitVec* pages[static 1],
                                 oEbmlId id,
                                 cErrorStack es[static 1] )
{
   if ( on_ebml_id_o( sca, id ) )
   {
      cChars chars;
      if ( not view_ebml_string_element_o( sca, &chars ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, id, o_EbmlString );

      cScanner* bitVecSca = &make_scanner_c_( chars.s, chars.v );
      if ( not read_bit_vec_c( bitVecSca, pages, "list" ) )
         return push_imp_exp_error_c( es, bitVecSca->err );
   }

   return true;
}

static __attribute__((unused))
bool unmarshal_opt_ebml_utf8_o( cScanner sca[static 1],
                                CString* str[static 1],
                                oEbmlId id,
                                cErrorStack es[static 1] )
{
   if ( on_ebml_id_o( sca, id ) )
   {
      cChars chars;
      if ( not view_ebml_utf8_element_o( sca, &chars ) )
         return push_imp_exp_error_c( es, sca->err ) or
                push_unmarshal_ebml_error_o( es, id, o_EbmlUtf8 );

      *str = retain_c( make_string_c( chars ) );
      if ( *str == NULL )
         return push_errno_error_c( es, ENOMEM );
   }

   return true;
}

#endif