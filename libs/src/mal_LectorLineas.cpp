#include <mal/LectorLineas.h>
#include <utiles_consola.h>
#include <cstring>
#include <cstdio>

static void *( *const volatile memset_ptr)(void *, int, size_t) = memset;

static void secure_memzero(void *p, size_t len)
{
	(memset_ptr)(p, 0, len);
}

namespace mal{

LectorLineas::LectorLineas(const char *path) :
	m_pCabecera(0)
{ 
	strcpy(m_path, path);
}

LectorLineas::~LectorLineas()
{
	if(m_pCabecera != 0)
	{
		int len = strlen(m_pCabecera);
		secure_memzero(m_pCabecera, len);
		delete[] m_pCabecera;
		m_pCabecera = 0;
	}

	logIt("Dtor LectorLineas");
}

char *LectorLineas::primeraLinea()
{
	if(m_pCabecera != 0)
	{
		return m_pCabecera;
	}

	FILE *handle = fopen(m_path, "r");
	if(handle != 0)
	{
		char buffer[BUFFER_SIZE];
		if(fgets(buffer, BUFFER_SIZE, handle))
		{
			int len = strlen(buffer)+1;
			m_pCabecera = new char[len];
			memcpy(m_pCabecera, buffer, len);
		}
		else
		{
			return 0;
		}

		fclose(handle);
		return m_pCabecera;
	}
	else
	{
		perror("Error al abrir archivo");
		return 0;
	}
}
}