#include "FormatOutputSpy.h"

static char * buffer =0;
static size_t buffer_size = 0;
static int buffer_offset = 0;
static int buffer_used = 0;

void FormatOutputSpy_Create(int size)
{

}
void FormatOutputSpy_Destroy(void)
{
}
char* FormatOutputSpy_GetOutput()
{
	return "Hello,World\n";
}

int FormatOutputSpy(const char *format,...)
{

	return 0;
}


