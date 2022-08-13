#include "oddcmc/cmcdecl.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

#define mand_ true
#define opt_ false
#define mult_ true
#define single_ false

#define oCMC_DECL_LIST_                                                \
   XMAP_C_( O_Cmc, "CMC", 0x11cab572, mand_, single_, o_EbmlMaster ) \
   \
   XMAP_C_( O_CmcInfo, "Info", 0x11ab94c5, mand_, single_, o_EbmlMaster ) \
   \
   XMAP_C_( O_CmcRelease, "Release", 0x1, mand_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcTitle, "Title", 0x1, mand_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcType, "Type", 0x1, opt_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcReleaseYear, "ReleaseYear", 0x1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcReleaseMonth, "ReleaseMonth", 0x1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcReleaseDay, "ReleaseDay", 0x1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcPublisher, "Publisher", 0x1, opt_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcImprint, "Imprint", 0x1, opt_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcLanguage, "Language", 0x1, opt_, single_, o_EbmlString ) \
   \
   XMAP_C_( O_CmcCreators, "Creators", 0x14b658f4, opt_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcCreator, "Creator", 0x2c103f, mand_, mult_, o_EbmlMaster ) \
   XMAP_C_( O_CmcCreatorName, "CreatorName", 0x1, mand_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcCreatorJob, "CreatorJob", 0x1, mand_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcCreatorPages, "CreatorPages", 0x1, opt_, single_, o_EbmlString ) \
   \
   XMAP_C_( O_CmcIssues, "Issues", 0x3eef6c, opt_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcIssue, "Issue", 0x1, mand_, mult_, o_EbmlMaster ) \
   XMAP_C_( O_CmcIssueSeries, "IssueSeries", 0x1, mand_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcIssueVolume, "IssueVolume", 0x1, mand_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueNumber, "IssueNumber", 0x1, mand_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueVariant, "IssueVariant", 0x1, opt_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcIssueReleaseYear, "IssueReleaseYear", 0x1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueReleaseMonth, "IssueReleaseMonth", 0x1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueReleaseDay, "IssueReleaseDay", 0x1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueLanguage, "IssueLanguage", 0x1, opt_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcIssuePages, "IssuePages", 0x1, opt_, single_, o_EbmlString ) \
   \
   XMAP_C_( O_CmcStories, "Stories", 0x1bd8eb6f, opt_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcStory, "Story", 0x1, mand_, mult_, o_EbmlMaster ) \
   XMAP_C_( O_CmcStoryTitle, "StoryTitle", 0x1, mand_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcStoryPages, "StoryPages", 0x1, opt_, single_, o_EbmlString ) \
   \
   XMAP_C_( O_CmcPages, "Pages", 0x15e30a78, mand_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcPage, "Page", 0x1, mand_, mult_, o_EbmlMaster ) \
   XMAP_C_( O_CmcPageNumber, "PageNumber", 0x1, mand_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcPageContent, "PageContent", 0x1, opt_, mult_, o_EbmlString ) \
   XMAP_C_( O_CmcPageData, "PageData", 0x1, mand_, single_, o_EbmlBinary )

#define XMAP_C_( Var, Name, Id, Mand, Mult, Type )           \
oEbmlDecl const Var = ebml_decl_o_( Name, (oEbmlId){ .raw=Id }, Mand, Mult, Type );

oCMC_DECL_LIST_;
#undef XMAP_C_

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

oEbmlDeclSlice get_cmc_decl_o( oVarEbmlDeclSlice buf )
{
   oEbmlDeclSlice src = slice_c_( oEbmlDecl,
      O_Cmc,
         O_CmcInfo,
            O_CmcRelease,
               O_CmcTitle,
               O_CmcType,
               O_CmcReleaseYear,
               O_CmcReleaseMonth,
               O_CmcReleaseDay,
               O_CmcPublisher,
               O_CmcImprint,
               O_CmcLanguage,
            O_CmcCreators,
               O_CmcCreator,
                  O_CmcCreatorName,
                  O_CmcCreatorJob,
                  O_CmcCreatorPages,
            O_CmcIssues,
               O_CmcIssue,
                  O_CmcIssueSeries,
                  O_CmcIssueVolume,
                  O_CmcIssueNumber,
                  O_CmcIssueReleaseYear,
                  O_CmcIssueReleaseMonth,
                  O_CmcIssueReleaseDay,
                  O_CmcIssueLanguage,
                  O_CmcIssuePages,
         O_CmcPages,
            O_CmcPage,
               O_CmcPageNumber,
               O_CmcPageContent,
               O_CmcPageData
   );

   buf.s = set_ebml_decl_slice_c( buf, src );
   if ( buf.s != src.s )
   {
      return (oEbmlDeclSlice)invalid_slice_c_();
   }

   return as_ebml_decl_slice_c( buf );
}
