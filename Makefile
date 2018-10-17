main:
	make -C ModuleA
	make -C ModuleB 
	gcc *.c -o main -L ./release/ -lstudent -lclass -I ./ModuleA/ -I ./ModuleB/ 
