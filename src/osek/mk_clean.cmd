
echo off 

del /Q *.rxe 
make -f Makefile_osek clean

IF EXIST *.rxe sh rxeflash.sh