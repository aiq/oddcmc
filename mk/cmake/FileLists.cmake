################################################################################
# INC_FILES
################################################################################
set( INC_FILES
   ${INC_DIR}/oddcmc/apidecl.h

   ${INC_DIR}/oddcmc/cmcdecl.h
   ${INC_DIR}/oddcmc/error.h
   ${INC_DIR}/oddcmc/OCmc.h
   ${INC_DIR}/oddcmc/OCmcCreator.h
   ${INC_DIR}/oddcmc/OCmcInfo.h
   ${INC_DIR}/oddcmc/OCmcIssue.h
   ${INC_DIR}/oddcmc/OCmcPage.h
   ${INC_DIR}/oddcmc/OCmcRelease.h
   ${INC_DIR}/oddcmc/OCmcStory.h
)

################################################################################
# SRC_FILES
################################################################################
set( SRC_FILES
   ${SRC_DIR}/oddcmc/cmcdecl.c
   ${SRC_DIR}/oddcmc/error.c
   ${SRC_DIR}/oddcmc/OCmc.c
   ${SRC_DIR}/oddcmc/OCmcCreator.c
   ${SRC_DIR}/oddcmc/OCmcInfo.c
   ${SRC_DIR}/oddcmc/OCmcIssue.c
   ${SRC_DIR}/oddcmc/OCmcPage.c
   ${SRC_DIR}/oddcmc/OCmcRelease.c
   ${SRC_DIR}/oddcmc/OCmcStory.c
)

################################################################################
# TEST_FILES
################################################################################
set( TEST_FILES
   # oCmcPage
)

################################################################################
# APP_FILES
################################################################################
set( APP_FILES
   ${APP_DIR}/cmc-editor/cmc-editor.c
   ${APP_DIR}/cmc/cmc.c
)
