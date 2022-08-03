#ifndef ODDCMC_APIDECL_H
#define ODDCMC_APIDECL_H

#ifdef ODDCMC_STATIC_DEFINE
#  define ODDCMC_API
#  define ODDCMC_NO_EXPORT
#else
#  ifdef _WIN32
#    ifndef ODDCMC_API
#      ifdef oddcmc_EXPORTS
#        define ODDCMC_API __declspec(dllexport)
#      else
#        define ODDCMC_API __declspec(dllimport)
#      endif
#    endif
#  else
#    define ODDCMC_API
#    define ODDCMC_NO_EXPORT
#  endif
#
#  ifndef ODDCMC_NO_EXPORT
#    define ODDCMC_NO_EXPORT 
#  endif
#endif

#endif