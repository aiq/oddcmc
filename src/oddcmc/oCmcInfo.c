#include "oddcmc/oCmcInfo.h"

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

void deref_cmc_info_o( oCmcInfo info[static 1] )
{
   *info = (oCmcInfo){0};
}

bool unmarshal_cmc_info_o( oEbmlElement const elem[static 1],
                           oCmcInfo info[static 1],
                           cErrorStack es[static 1] )
{
   if ( not eq_ebml_id_o( elem->id, O_CmcInfo.id ) )
      return push_missing_ebml_id_error_o( es, O_CmcInfo.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   return sca->space == 0;
}