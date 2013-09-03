
echo off 
set path = C:\cygwin\usr\local\bin;C:\cygwin\usr\bin;C:\cygwin\bin 
del /Q *.rxe 
 
make -f Makefile_osek all 

IF EXIST *.rxe sh rxeflash.sh

