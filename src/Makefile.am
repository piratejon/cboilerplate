## Process this file with automake to produce Makefile.in

lib_LTLIBRARIES = libexample.la
libexample_la_SOURCES = example.c example.h

bin_PROGRAMS = example
example_SOURCES = example_main.c
example_CFLAGS = -std=c99 -Wall -g3
example_LDADD = libexample.la
