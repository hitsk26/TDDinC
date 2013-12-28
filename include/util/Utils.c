#include "Utils.h"

static int FormatOutput_Imple(const char* format,...)
{

return 0;
}

int (*FormatOutput)(const char *format,...) = FormatOutput_Imple;
