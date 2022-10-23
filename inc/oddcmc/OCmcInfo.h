#ifndef ODDCMC_OCMC_INFO_H
#define ODDCMC_OCMC_INFO_H

#include "oddcmc/apidecl.h"
#include "oddcmc/cmcdecl.h"
#include "oddcmc/OCmcRelease.h"
#include "oddebml/oEbmlElement.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

ODDCMC_API extern cMeta const O_CmcInfoMeta;

struct OCmcInfo
{
   OCmcRelease* release;
};
typedef struct OCmcInfo OCmcInfo;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

#define new_cmc_info_o_()                                                      \
   new_object_c_( OCmcInfo, &O_CmcInfoMeta )

#define let_cmc_info_o_()                                                      \
   let_object_c_( OCmcInfo, &O_CmcInfoMeta )

ODDCMC_API void mimic_cmc_info_o( OCmcInfo info[static 1],
                                  OCmcInfo const src[static 1] );

ODDCMC_API bool unmarshal_cmc_info_o( oEbmlElement const elem[static 1],
                                      OCmcInfo* info,
                                      cErrorStack es[static 1] );

#endif