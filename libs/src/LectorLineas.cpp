#include <LectorLineas.h>
#include <utiles_consola.h>
#include <FileLocker.h>
#include <cstring>
#include <cstdio>
#include <exception>

struct Destructor
{
	void operator()(char *p)
	{
		if(p == 0) return;
		logIt("[shared_ptr] Borrada la cadena");
		delete[] p;
	}
};

LectorLineas::LectorLineas(const char *path)
{
	strcpy(m_path, path);
}

LectorLineas::~LectorLineas()
{
	logIt("Dtor LectorLineas");
}

shared_ptr<char> LectorLineas::primeraLinea()
{
	asegurarPrimeraLinea();
	return m_pCabecera;
}

int LectorLineas::cuentaRepeticiones(char caracter)
{
	FileLocker file(m_path);
	if(file.isClosed())
		throw std::exception();
	int cuenta = 0;
	char buffer[BUFFER_SIZE];
	while(fgets(buffer, BUFFER_SIZE, file.handler()))
	{
		int len = strlen(buffer);
		for(int i = 0; i < len && i < BUFFER_SIZE; ++i)
		{
			if(caracter == buffer[i])
				cuenta++;
		}
	}

	return cuenta;
}

bool LectorLineas::existeArchivo(const char *path)
{
	FileLocker file(path);
	return !file.isClosed();
}

void LectorLineas::asegurarPrimeraLinea()
{
	FILE *handle = fopen(m_path, "r");
	if(handle != 0)
	{
		char buffer[BUFFER_SIZE];
		if(fgets(buffer, BUFFER_SIZE, handle))
		{
			int len = strlen(buffer)+1;
			char *pTemp = new char[len];
			memcpy(pTemp, buffer, len);
			m_pCabecera = shared_ptr<char>(pTemp, Destructor());
		}

		fclose(handle);
	}
	else
	{
		perror("Error al abrir archivo");
	}
}
