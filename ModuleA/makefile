allc:operatec.o initc.o handinc.o autoinc.o addc.o deletec.o revisec.o findc.o 
	gcc -o allc -c operatec.o initc.o handinc.o autoinc.o addc.o deletec.o revisec.o findc.o
	ar -rvs ../release/libclass.a *.o
operatec.o:operatec.c *.h 
	gcc -c -o operatec.o operatec.c
initc.o:initc.c *.h
	gcc -c -o initc.o initc.c
handinc.o:handinc.c *.h
	gcc -c -o handinc.o handinc.c
autoinc.o:autoinc.c *.h
	gcc -c -o autoinc.o autoinc.c
addc.o:addc.c *.h
	gcc -c -o addc.o addc.c
deletec.o:deletec.c *.h
	gcc -c -o deletec.o deletec.c
revisec.o:revisec.c *.h
	gcc -c -o revisec.o revisec.c
findc.o:findc.c *.h
	gcc -c -o findc.o findc.c
clean:
	#mv *.o ../release/
	rm *.o
