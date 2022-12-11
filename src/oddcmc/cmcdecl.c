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
   XMAP_C_( O_CmcRelease, "Release", 0x2a4b8c, mand_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcTitle, "Title", 0x81, mand_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcType, "Type", 0x82, opt_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcLanguage, "Language", 0x83, opt_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcReleaseYear, "ReleaseYear", 0x91, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcReleaseMonth, "ReleaseMonth", 0x92, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcReleaseDay, "ReleaseDay", 0x93, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcPublisher, "Publisher", 0x95, opt_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcImprint, "Imprint", 0x96, opt_, single_, o_EbmlUtf8 ) \
   \
   XMAP_C_( O_CmcCreators, "Creators", 0x2c103f, opt_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcCreator, "Creator", 0x5ee1, mand_, mult_, o_EbmlMaster ) \
   XMAP_C_( O_CmcCreatorName, "CreatorName", 0xc1, mand_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcCreatorJob, "CreatorJob", 0xc2, mand_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcCreatorPages, "CreatorPages", 0xc3, opt_, single_, o_EbmlString ) \
   \
   XMAP_C_( O_CmcIssues, "Issues", 0x3eef6c, opt_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcIssue, "Issue", 0x47eb, mand_, mult_, o_EbmlMaster ) \
   XMAP_C_( O_CmcIssueSeries, "IssueSeries", 0xd1, mand_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcIssueVolume, "IssueVolume", 0xd2, mand_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueNumber, "IssueNumber", 0xd3, mand_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueVariant, "IssueVariant", 0xd4, opt_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcIssueLanguage, "IssueLanguage", 0xd8, opt_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcIssuePages, "IssuePages", 0xd9, opt_, single_, o_EbmlString ) \
   XMAP_C_( O_CmcIssueReleaseYear, "IssueReleaseYear", 0xe1, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueReleaseMonth, "IssueReleaseMonth", 0xe2, opt_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcIssueReleaseDay, "IssueReleaseDay", 0xe3, opt_, single_, o_EbmlUint ) \
   \
   XMAP_C_( O_CmcStories, "Stories", 0x23086d, opt_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcStory, "Story", 0x47c3, mand_, mult_, o_EbmlMaster ) \
   XMAP_C_( O_CmcStoryTitle, "StoryTitle", 0xa1, mand_, single_, o_EbmlUtf8 ) \
   XMAP_C_( O_CmcStoryPages, "StoryPages", 0xa2, opt_, single_, o_EbmlString ) \
   \
   XMAP_C_( O_CmcPages, "Pages", 0x15e30a78, mand_, single_, o_EbmlMaster ) \
   XMAP_C_( O_CmcPage, "Page", 0x2f1206, mand_, mult_, o_EbmlMaster ) \
   XMAP_C_( O_CmcPageNumber, "PageNumber", 0xf1, mand_, single_, o_EbmlUint ) \
   XMAP_C_( O_CmcPageContent, "PageContent", 0xf3, opt_, mult_, o_EbmlString ) \
   XMAP_C_( O_CmcPageData, "PageData", 0xf2, mand_, single_, o_EbmlBinary )

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
               O_CmcLanguage,
               O_CmcReleaseYear,
               O_CmcReleaseMonth,
               O_CmcReleaseDay,
               O_CmcPublisher,
               O_CmcImprint,
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
                  O_CmcIssueVariant,
                  O_CmcIssueLanguage,
                  O_CmcIssuePages,
                  O_CmcIssueReleaseYear,
                  O_CmcIssueReleaseMonth,
                  O_CmcIssueReleaseDay,
            O_CmcStories,
               O_CmcStory,
                  O_CmcStoryTitle,
                  O_CmcStoryPages,
         O_CmcPages,
            O_CmcPage,
               O_CmcPageNumber,
               O_CmcPageContent,
               O_CmcPageData
   );

   buf.s = set_ebml_decl_slice_c( buf, src );
   if ( buf.s != src.s )
   {
      return (oEbmlDeclSlice)invalid_c_();
   }

   return as_c_( oEbmlDeclSlice, buf );
}
