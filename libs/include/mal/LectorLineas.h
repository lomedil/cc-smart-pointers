#ifndef _LECTORLINEAS_H_
#define _LECTORLINEAS_H_

namespace mal{
class LectorLineas
{
public:
	LectorLineas(const char *path);
	~LectorLineas();

	char *primeraLinea();

	static const int BUFFER_SIZE = 256;

private:
	char m_path[512];
	char *m_pCabecera;
};

} //end namespace
#endif