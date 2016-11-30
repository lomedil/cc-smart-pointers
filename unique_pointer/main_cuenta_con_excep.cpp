#include <LectorLineas.h>
#include <iostream>
#include <utiles_consola.h>

int cuentaCaracteres(char c);

int main()
{
	logIt("Inicio de app");
	try
	{
		logIt("Repeticiones del caracter \"C\": ", cuentaCaracteres('C'));
	}
	catch(std::exception &ex)
	{
		logIt("No existe el archivo");
	}
	logIt("Fin de app");
}

int cuentaCaracteres(char c)
{
	LectorLineas *lector = new LectorLineas("cosa.txt");	
	int cuenta = lector->cuentaRepeticiones(c);
	delete lector;
	return cuenta;
}
