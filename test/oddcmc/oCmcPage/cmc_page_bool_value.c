#include "clingo/lang/expect.h"
#include "oddcmc/oCmcPage.h"

int main( void )
{
   init_tap_c_();

   expect_c_( cmc_page_bool_value_o() );

   return finish_tap_c_();
}
