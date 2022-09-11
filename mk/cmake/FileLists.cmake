################################################################################
# INC_FILES
################################################################################
set( INC_FILES
   ${INC_DIR}/oddcmc/apidecl.h

   ${INC_DIR}/oddcmc/cmcdecl.h
   ${INC_DIR}/oddcmc/error.h
   ${INC_DIR}/oddcmc/oCmc.h
   ${INC_DIR}/oddcmc/oCmcCreator.h
   ${INC_DIR}/oddcmc/oCmcInfo.h
   ${INC_DIR}/oddcmc/oCmcIssue.h
   ${INC_DIR}/oddcmc/oCmcPage.h
   ${INC_DIR}/oddcmc/oCmcRelease.h
)

################################################################################
# SRC_FILES
################################################################################
set( SRC_FILES
   ${SRC_DIR}/oddcmc/cmcdecl.c
   ${SRC_DIR}/oddcmc/error.c
   ${SRC_DIR}/oddcmc/oCmc.c
   ${SRC_DIR}/oddcmc/oCmcCreator.c
   ${SRC_DIR}/oddcmc/oCmcInfo.c
   ${SRC_DIR}/oddcmc/oCmcIssue.c
   ${SRC_DIR}/oddcmc/oCmcPage.c
   ${SRC_DIR}/oddcmc/oCmcRelease.c
)

################################################################################
# TEST_FILES
################################################################################
set( TEST_FILES
   # oCmcPage
   ${TEST_DIR}/oddcmc/oCmcPage/cmc_page_bool_value.c
)
