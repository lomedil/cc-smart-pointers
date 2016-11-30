#include <utiles_consola.h>
#include <mal/LectorLineas.h>

int main()
{
	char *cabecera = 0;
	if(true)
	{
		mal::LectorLineas lector("archivo.txt");
		char *temp = lector.primeraLinea();
		logIt(temp);
		cabecera = temp;
	}
	logIt(cabecera);
}