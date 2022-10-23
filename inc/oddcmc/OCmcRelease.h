#ifndef ODDCMC_CMC_RELEASE_H
#define ODDCMC_CMC_RELEASE_H

#include "clingo/container/vec.h"
#include "clingo/string/CString.h"
#include "clingo/time/cYmd.h"
#include "iso639/cIso639.h"
#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

ODDCMC_API extern cMeta const O_CmcReleaseMeta;

struct OCmcRelease
{
   CString* title;
   CString* type;
   cIso639 language;
   cYmd date;
   CString* publisher;
   CString* imprint;
};
typedef struct OCmcRelease OCmcRelease;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define new_cmc_release_o_()                                                   \
   new_object_c_( OCmcRelease, &O_CmcReleaseMeta )

#define let_cmc_release_o_()                                                   \
   let_object_c_( OCmcRelease, &O_CmcReleaseMeta )

ODDCMC_API void mimic_cmc_release_o( OCmcRelease rel[static 1],
                                     OCmcRelease const src[static 1] );

ODDCMC_API bool unmarshal_cmc_release_o( oEbmlElement const elem[static 1],
                                         OCmcRelease rel[static 1],
                                         cErrorStack es[static 1] );

#endif