#ifndef _LECTORLINEAS_H_
#define _LECTORLINEAS_H_
#include <tr1/memory>

using namespace std::tr1;

class LectorLineas
{
public:
	LectorLineas(const char *path);
	~LectorLineas();

	shared_ptr<char> primeraLinea();

	int cuentaRepeticiones(char caracter);

	static bool existeArchivo(const char *path);

private:
	void asegurarPrimeraLinea();

private:
	static const int BUFFER_SIZE = 256;
	char m_path[512];
	shared_ptr<char> m_pCabecera;
};

#endif