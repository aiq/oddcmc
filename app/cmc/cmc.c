#include "clingo/io/print.h"
#include "clingo/type/cCharsSlice.h"

#include "pack.h"

int main( int argc, char* argv[] )
{
   if ( argc < 2 )
   {
      println_c_( "not enough arguments" );
      return EXIT_FAILURE;
   }

   cErrorStack* es = &error_stack_c_( 256 );

   cVarCharsSlice args = heap_slice_c_( argc, cChars );
   for ( int i = 0; i < argc; ++i )
   {
      args.v[i] = c_c( argv[i] );
   }

   cChars subcmd = args.v[1];
   cCharsSlice subargs = mid_c_( cCharsSlice, args, 2 );
   if ( chars_is_c( subcmd, "pack" ) )
   {
      pack_cmc( subargs, es );
   }
   else
   {
      println_c_( "unknown subcmd {cs:Q}", subcmd );
   }

   free( args.v );
   return EXIT_SUCCESS;
}