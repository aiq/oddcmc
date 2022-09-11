#ifndef ODDCMC_CMC_RELEASE_H
#define ODDCMC_CMC_RELEASE_H

#include "clingo/string/CString.h"
#include "clingo/time/cYmd.h"
#include "iso639/cIso639.h"
#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

struct oCmcRelease
{
   CString* title;
   CString* type;
   cIso639 language;
   cYmd date;
   CString* publisher;
   CString* imprint;
};
typedef struct oCmcRelease oCmcRelease;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

ODDCMC_API void deref_cmc_release_o( oCmcRelease rel[static 1] );

ODDCMC_API bool unmarshal_cmc_release_o( oEbmlElement const elem[static 1],
                                         oCmcRelease rel[static 1],
                                         cErrorStack es[static 1] );

#endif