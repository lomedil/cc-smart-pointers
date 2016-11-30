#include <LectorLineas.h>
#include <iostream>
#include <utiles_consola.h>

int cuentaCaracteres(char c);

int main()
{
	logIt("Inicio de app");
	logIt("Repeticiones del caracter \"C\": ", cuentaCaracteres('C'));
	logIt("Fin de app");
}

int cuentaCaracteres(char c)
{
	LectorLineas *lector = new LectorLineas("archivo.txt");
	if(!LectorLineas::existeArchivo("archivo.txt"))
	{
		delete lector;
		return -1;
	}
	else
	{
		int cuenta = lector->cuentaRepeticiones(c);
		delete lector;
		return cuenta;
	}
}
