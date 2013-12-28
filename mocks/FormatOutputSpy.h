#ifndef FORMATOUTPUTSPY
#define FORMATOUTPUTSPY

#include "../include/util/Utils.h"


void FormatOutputSpy_Create(int length);
void FormatOutputSpy_Destroy(void);
char* FormatOutputSpy_GetOutput(void);

int FormatOutputSpy(const char *format,...);

#endif
