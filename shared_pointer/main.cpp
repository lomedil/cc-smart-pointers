#include <LectorLineas.h>
#include <iostream>
#include <utiles_consola.h>
#include <tr1/memory>

using namespace std::tr1;

int main()
{

	shared_ptr<char> cabecera;
	{
		LectorLineas lector("archivo.txt");	
		shared_ptr<char> temp = lector.primeraLinea();
		logIt("Contador de instancias: ", temp.use_count());
		cabecera = temp;		
		logIt("Contador de instancias: ", cabecera.use_count());
	}
	logIt("Fuera de contexto. Contador: ", cabecera.use_count());
	logIt(cabecera.get());

}
