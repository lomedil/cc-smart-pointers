#include <LectorLineas.h>
#include <iostream>
#include <utiles_consola.h>
#include <memory>

using namespace std;

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
	unique_ptr<LectorLineas> lector(new LectorLineas("cosa.txt"));
	return  lector->cuentaRepeticiones(c);
}
