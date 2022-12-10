#include "clingo/io/print.h"
#include "clingo/type/cCharsSlice.h"

int main( int argc, char* argv[] )
{
   if ( argc < 2 )
   {
      println_c_( "not enough arguments" );
      return EXIT_FAILURE;
   }

   cVarCharsSlice args = heap_slice_c_( argc, cChars );
   for ( int i = 0; i < argc; ++i )
   {
      args.v[i] = c_c( argv[i] );
   }

   for_each_c_( cChars const*, itr, mid_c_(cVarCharsSlice, args, 1 ) )
   {
      println_c_( "{i64} - {cs}", index_of_c_( args, itr ), *itr );
   }

   free( args.v );
   return EXIT_SUCCESS;
}