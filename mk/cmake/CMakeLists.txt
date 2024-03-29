cmake_minimum_required( VERSION 3.2 )

project( oddcmc VERSION 0.1.0 LANGUAGES C )
set( CMAKE_C_STANDARD          11 )
set( CMAKE_C_STANDARD_REQUIRED ON )
set( CMAKE_C_EXTENSIONS        OFF )

if( WIN32 )
    set( CMAKE_C_VISIBILITY_PRESET hidden )
    set( CMAKE_VISIBILITY_INLINES_HIDDEN ON )
endif()

enable_testing()

set( LIB_NAME ${PROJECT_NAME} )

# where to look first for modules, before ${CMAKE_ROOT}/Modules/ is checked
set( ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../.. )
set( APP_DIR ${ROOT}/app )
set( DOC_DIR ${ROOT}/doc )
set( INC_DIR ${ROOT}/inc )
set( SRC_DIR ${ROOT}/src )
set( TEST_DIR ${ROOT}/test )

include( CTest )
include( FetchContent )
include( ${CMAKE_CURRENT_SOURCE_DIR}/Custom.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/FileLists.cmake )

################################################################################
# fetch
################################################################################

fetchcontent_declare(
    oddebml
    GIT_REPOSITORY "https://github.com/aiq/oddebml"
    GIT_TAG "main"
    SOURCE_SUBDIR "mk/cmake"
)
fetchcontent_makeavailable( oddebml )

fetchcontent_declare(
    oddjson
    GIT_REPOSITORY "https://github.com/aiq/oddjson"
    GIT_TAG "main"
    SOURCE_SUBDIR "mk/cmake"
)
fetchcontent_makeavailable( oddjson )

fetchcontent_declare(
    iso639
    GIT_REPOSITORY "https://github.com/aiq/iso639"
    GIT_TAG "main"
    SOURCE_SUBDIR "mk/cmake"
)
fetchcontent_makeavailable( iso639 )

fetchcontent_declare(
   raylib
   GIT_REPOSITORY https://github.com/raysan5/raylib.git
   GIT_TAG master
)
fetchcontent_makeavailable( raylib )

################################################################################
# build - make
################################################################################
add_library( ${LIB_NAME} SHARED ${SRC_FILES} )
set_default_flags( ${LIB_NAME} )
target_include_directories( ${LIB_NAME} PUBLIC ${INC_DIR} PRIVATE ${SRC_DIR} )
if( WIN32 )
    target_link_libraries( ${LIB_NAME} oddebml iso639 )
else()
    target_link_libraries( ${LIB_NAME} PUBLIC m oddebml iso639 )
endif()

set( TEST_INC_DIRS ${INC_DIR} ${SRC_DIR} )
if( WIN32 )
    set( TEST_LINK_LIBS ${LIB_NAME} oddebml iso639 )
else()
    set( TEST_LINK_LIBS ${LIB_NAME} m oddebml iso639 )
endif()
add_tests( "${TEST_FILES}" "${TEST_INC_DIRS}" "${TEST_LINK_LIBS}" )

set( APP_INC_DIRS ${INC_DIR} ${SRC_DIR} ${APP_DIR} )
if( WIN32 )
   set( APP_LINK_LIBS ${LIB_NAME} clingo )
else()
   set( APP_LINK_LIBS ${LIB_NAME} m clingo raylib )
endif()
add_apps( "${APP_FILES}" "${APP_INC_DIRS}" "${APP_LINK_LIBS}" )
