Shell  : back_check.o background_proc.o dir_change.o echo.o get_permissions.o get_user.o input.o list.o loop.o pinfo.o pwd.o shell.o
	gcc $^ -o Shell

back_check.o  : functions/back_check.c 
	gcc -c functions/back_check.c 

background_proc.o  : functions/background_proc.c 
	gcc -c functions/background_proc.c

dir_change.o : functions/dir_change.c 
	gcc -c functions/dir_change.c 

echo.o : functions/echo.c 
	gcc -c functions/echo.c 

get_permissions.o : functions/get_permissions.c 
	gcc -c functions/get_permissions.c

get_user.o : functions/get_user.c 
	gcc -c functions/get_user.c 

input.o : functions/input.c 
	gcc -c functions/input.c 

list.o : functions/list.c 
	gcc -c functions/list.c 

loop.o : functions/loop.c
	gcc -c functions/loop.c

pinfo.o : functions/pinfo.c 
	gcc -c functions/pinfo.c 

pwd.o : functions/pwd.c 
	gcc -c functions/pwd.c 

shell.o : shell.c 
	gcc -c shell.c 

clean  :
	rm -f back_check.o background_proc.o dir_change.o echo.o get_permissions.o get_user.o input.o list.o loop.o pinfo.o pwd.o shell.o