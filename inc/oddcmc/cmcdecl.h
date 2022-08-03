#ifndef ODDCMC_CMCDECL_H
#define ODDCMC_CMCDECL_H

#include "oddcmc/apidecl.h"
#include "oddebml/oEbmlDecl.h"

/*******************************************************************************
********************************************************* Types and Definitions
*******************************************************************************/

ODDCMC_API extern oEbmlDecl const O_Cmc;

ODDCMC_API extern oEbmlDecl const O_CmcInfo;

ODDCMC_API extern oEbmlDecl const O_CmcRelease;
ODDCMC_API extern oEbmlDecl const O_CmcTitle;
ODDCMC_API extern oEbmlDecl const O_CmcType;
ODDCMC_API extern oEbmlDecl const O_CmcReleaseYear;
ODDCMC_API extern oEbmlDecl const O_CmcReleaseMonth;
ODDCMC_API extern oEbmlDecl const O_CmcReleaseDay;
ODDCMC_API extern oEbmlDecl const O_CmcPublisher;
ODDCMC_API extern oEbmlDecl const O_CmcImprint;
ODDCMC_API extern oEbmlDecl const O_CmcLanguage;

ODDCMC_API extern oEbmlDecl const O_CmcCreators;
ODDCMC_API extern oEbmlDecl const O_CmcCreator;
ODDCMC_API extern oEbmlDecl const O_CmcCreatorName;
ODDCMC_API extern oEbmlDecl const O_CmcCreatorJob;
ODDCMC_API extern oEbmlDecl const O_CmcCreatorPages;

ODDCMC_API extern oEbmlDecl const O_CmcIssues;
ODDCMC_API extern oEbmlDecl const O_CmcIssue;
ODDCMC_API extern oEbmlDecl const O_CmcIssueSeries;
ODDCMC_API extern oEbmlDecl const O_CmcIssueVolume;
ODDCMC_API extern oEbmlDecl const O_CmcIssueNumber;
ODDCMC_API extern oEbmlDecl const O_CmcIssueVariant;
ODDCMC_API extern oEbmlDecl const O_CmcIssueReleaseYear;
ODDCMC_API extern oEbmlDecl const O_CmcIssueReleaseMonth;
ODDCMC_API extern oEbmlDecl const O_CmcIssueReleaseDay;
ODDCMC_API extern oEbmlDecl const O_CmcIssueLanguage;
ODDCMC_API extern oEbmlDecl const O_CmcIssuePages;

ODDCMC_API extern oEbmlDecl const O_CmcStories;
ODDCMC_API extern oEbmlDecl const O_CmcStory;
ODDCMC_API extern oEbmlDecl const O_CmcStoryTitle;
ODDCMC_API extern oEbmlDecl const O_CmcStoryPages;

ODDCMC_API extern oEbmlDecl const O_CmcPages;
ODDCMC_API extern oEbmlDecl const O_CmcPage;
ODDCMC_API extern oEbmlDecl const O_CmcPageNumber;
ODDCMC_API extern oEbmlDecl const O_CmcPageContent;
ODDCMC_API extern oEbmlDecl const O_CmcPageData;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

ODDCMC_API oEbmlDeclSlice get_cmc_decl_o( oVarEbmlDeclSlice buf );

#endif