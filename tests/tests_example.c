#include "example.h"
#include "tests.h"

void sanity_check_zero ( void )
{
  ASSERT ( 0 == 0, "Zero failed to be equal to zero." );
}

void sanity_check_one ( void )
{
  ASSERT ( 1 == 1, "One failed to be equal to one." );
}

void sanity_check_false ( void )
{
  ASSERT ( 1 == 0, "One failed to be equal to zero." );
}

void test_plus_two ( void )
{
  ASSERT ( n_plus_two ( 3 ) == 5, "Failed to add two." );
}

void force_segfault ( void )
{
  char * monkey = NULL;

  *monkey = 99;

  ASSERT (*monkey == 99, "Monkey does not equal 99." );
}

void another_test ( void )
{
  ASSERT ( NULL == NULL, "NULL does not equal NULL." );
}

void do_tests ( void )
{
  TEST ( sanity_check_zero );
  TEST ( sanity_check_false );
  TEST ( force_segfault );
  TEST ( sanity_check_one );
  TEST ( test_plus_two );
  TEST ( another_test );
}

