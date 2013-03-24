## Process this file with automake to produce Makefile.in

lib_LIBRARIES = libexample.a
libexample_a_SOURCES = example.c example.h

bin_PROGRAMS = example
example_SOURCES = example_main.c
example_CFLAGS = -std=c99 -Wall -g3
example_LDADD = libexample.a

