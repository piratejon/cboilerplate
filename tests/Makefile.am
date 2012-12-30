## Process this file with automake to produce Makefile.in

TESTS = tests_example
check_PROGRAMS = tests_example
tests_example_SOURCES = tests_main.c tests_example.c $(top_builddir)/src/example.h
tests_example_CFLAGS = -Wall -g3 -std=c99 -I$(top_builddir)/src -I$(top_builddir)/tests
tests_example_LDADD = $(top_builddir)/src/libexample.la
tests_example_LDFLAGS = -no-install

noinst_PROGRAMS = $(TESTS)

