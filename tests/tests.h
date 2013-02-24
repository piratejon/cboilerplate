#ifndef _JWS_TEST_H
#define _JWS_TEST_H

#include <stdlib.h>
#include <stdio.h>

int execute_test ( char *, void(*)(void) );
void do_tests ( void );
void test_succeeded ( void );
void test_failed ( char * );
void wait_attach ( );

#define ASSERT(x, msg) do { if (!(x)) { char buf[200]; snprintf(buf, sizeof(buf), "%s:%d:%s(): %s", __FILE__, __LINE__, __func__, msg); test_failed(buf); } else { test_succeeded(); } } while(0)

#define TEST(x) do { if ( !execute_test(#x, x) ) { return; } } while(0)

#endif // _JWS_TEST_H

