#include <FileLocker.h>

FileLocker::FileLocker(const char* path) :
	m_handler(0), m_error(false)
{
	m_handler = fopen(path, "r");
	if(m_handler == 0)
	{
		perror("Error opening file");
		m_error = true;
	}
}

FileLocker::~FileLocker()
{
	close();
}

FILE *FileLocker::handler()
{
	return m_handler;
}

void FileLocker::close()
{
	if(m_handler == 0) return;
	fclose(m_handler);
	m_handler = 0;
}

bool FileLocker::isClosed() const
{
	return m_handler == 0;
}

bool FileLocker::isError() const
{
	return m_error;
}