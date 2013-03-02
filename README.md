cboilerplate
============

About
-----
cboilerplate allows me to quickly initialize a C project with autotools and testing. It includes a test framework that fills the gap between MinUnit (http://www.jera.com/techinfo/jtns/jtn002.html) and Check (http://check.sf.net).

Usage
-----
Here is what I use after I check this out:
```bash
$ autoreconf -i -f
$ ./configure
$ make check
...
Parent PID: 28229
tests_example.c:16:sanity_check_false(): One failed to be equal to zero.
  PID 28231 exited with status 1
Test force_segfault (28232): terminated by signal 11
4/6 assertions held (66.67%)
FAIL: tests_example
========================================
1 of 1 test failed
Please report to js AT piratejon DOT com
========================================
... 
```

The "example" tests include two intentional failures that illustrate the behavior of the test framework when a segfault occurs and when an assert fails. Therefore it is normal and expected to see 4/6 passing when you run this. You may not want or need to keep those when you write your own tests.

License
-------
MIT (see LICENSE in repository root)

Codename
--------
shiny-tyrion (no one actually calls it this but github suggested it to "inspire" me LOL)

