#include "oddcmc/oCmc.h"

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

void deref_cmc_o( oCmc cmc[static 1] )
{
   *cmc = (oCmc){0};
}

bool unmarshal_cmc_o( oEbmlElement const elem[static 1],
                      oCmc cmc[static 1],
                      cErrorStack es[static 1] )
{
   if ( not eq_ebml_id_o( elem->id, O_Cmc.id ) )
      return push_missing_ebml_id_error_o( es, O_Cmc.id );

   cScanner* sca = &make_scanner_c_( elem->bytes.s, elem->bytes.v );
   return sca->space == 0;
}