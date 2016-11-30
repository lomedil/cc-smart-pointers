#ifndef _FILELOCKER_H_
#define _FILELOCKER_H_

#include <cstdio>

class FileLocker
{
public:
	FileLocker(const char *path);
	~FileLocker();

public:
	FILE *handler();
	void close();
	bool isClosed() const;
	bool isError() const;

private:
	FILE *m_handler;
	bool m_error;
};

#endif