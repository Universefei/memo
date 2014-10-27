About
=====

This is a simple example of using automake and autoconf to generate makefile and configure
SEE:http://www.laruence.com/2009/11/18/1154.html

configure
---------

file configure depend on configure.in and aclocal.m4, using autoconf to generate it.

makefile
--------

using configure to generate makefile, but makefile.in was needed
another way to avoid to depend on makefile.in is to write GNUmakefile and include another 
file ,which include the env var.(like GDAL)
