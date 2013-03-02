cboilerplate
============

License
-------
MIT (see LICENSE in repository root)

cboilerplate allows me to quickly initialize a C project with autotools and testing. It includes a test framework that fills the gap between MinUnit (http://www.jera.com/techinfo/jtns/jtn002.html) and Check (http://check.sf.net).

Usage
-----
Here is a basic workflow:
```bash
$ autoreconf -i -f
$ ./configure
$ make check
```

The "example" tests include two intentional failures that illustrate the behavior of the test framework when a segfault occurs and when an assert fails. Therefore it is normal and expected to see 4/6 passing when you run this. You may not want or need to keep those when you write your own tests.

Codename
--------
shiny-tyrion (no one actually calls it this but github suggested it to "inspire" me LOL)

