#Makefile: Este archivo compila y ejecuta su código al escribir make en consola en sistemas UNIX

all: compilar ejecutar

compilar: 
	@gcc -o tarea4 main.c arbol.c lectura.c rotaciones.c aux.c

ejecutar: compilar
	@./tarea4 notas.csv