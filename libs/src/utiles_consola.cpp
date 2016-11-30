#include <utiles_consola.h>
#include <iostream>

void logIt(const char *message)
{
	std::cout << "[log] " << message << "\n";
}

void logIt(const char *message, int value)
{
	std::cout << "[log] " << message << " " 
			  << value << "\n";
}