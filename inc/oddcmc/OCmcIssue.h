#ifndef ODDCMC_OCMC_ISSUE_H
#define ODDCMC_OCMC_ISSUE_H

#include "clingo/container/CBitVec.h"
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

ODDCMC_API extern cMeta const O_CmcIssueMeta;

struct OCmcIssue
{
   CString* series;
   uint64_t volume;
   uint64_t number;
   CString* variant;
   cIso639 language;
   CBitVec* pages;
   cYmd date;
};
typedef struct OCmcIssue OCmcIssue;

OBJ_VEC_DEF_C_(
   ODDCMC_API,       // LipApi
   OCmcIssues,       // VecType
   OCmcIssue,        // ObjType
   cmc_issues_o,     // FuncSuffix
   O_CmcIssuesMeta   // Meta
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define new_cmc_issue_o_()                                                     \
   new_object_c_( OCmcIssue, &O_CmcIssueMeta )

#define let_cmc_issue_o_()                                                     \
   let_object_c_( OCmcIssue, &O_CmcIssueMeta )

ODDCMC_API void mimic_cmc_issue_o( OCmcIssue issue[static 1],
                                   OCmcIssue const src[static 1] );

ODDCMC_API bool unmarshal_cmc_issue_o( oEbmlElement const elem[static 1],
                                       OCmcIssue issue[static 1],
                                       cErrorStack es[static 1] );

#endif