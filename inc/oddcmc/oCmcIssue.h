#ifndef ODDCMC_CMC_ISSUE_H
#define ODDCMC_CMC_ISSUE_H

#include "clingo/container/CBitVec.h"
#include "clingo/string/CString.h"
#include "clingo/time/cYmd.h"
#include "iso639/cIso639.h"
#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

struct oCmcIssue
{
   CString* series;
   uint64_t volume;
   uint64_t number;
   CString* variant;
   cIso639 language;
   CBitVec* pages;
   cYmd date;
};
typedef struct oCmcIssue oCmcIssue;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

ODDCMC_API void deref_cmc_issue_o( oCmcIssue issue[static 1] );

ODDCMC_API bool unmarshal_cmc_issue_o( oEbmlElement const elem[static 1],
                                       oCmcIssue issue[static 1],
                                       cErrorStack es[static 1] );

#endif