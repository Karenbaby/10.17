alls:operates.o inits.o handins.o autoins.o adds.o deletes.o revises.o finds.o 
	gcc -o alls -c operates.o inits.o handins.o autoins.o adds.o deletes.o revises.o finds.o
	ar -rvs ../release/libstudent.a *.o
operates.o:operates.c *.h
	gcc -c -o operates.o operates.c
inits.o:inits.c *.h
	gcc -c -o inits.o inits.c
handins.o:handins.c *.h
	gcc -c -o handins.o handins.c
autoins.o:autoins.c *.h
	gcc -c -o autoins.o autoins.c
adds.o:adds.c *.h
	gcc -c -o adds.o adds.c
deletes.o:deletes.c *.h
	gcc -c -o deletes.o deletes.c
revises.o:revises.c *.h
	gcc -c -o revises.o revises.c
finds.o:finds.c *.h
	gcc -c -o finds.o finds.c 
clean:
	mv *.o ../release/
	rm *.o
