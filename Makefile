##############################################################################
#Create data : 2022/5/29
#Last modify date : 2022/5/29
#Usage: Makefile for this project
#Enviroment:	Linux 5.13.0-51-generic 
#		Ubuntu 20.04.1 
#		Intel(R) Core(TM) i5-10210U CPU @ 1.60GHz
#		gcc 9.4.0
#		make 4.2.1
##############################################################################

.PHONY:main
main:main.c misc.c
	$(CC) -o main main.c misc.c -lpthread
