#include "Globals.h"
#include "Application.h"


void Log(const char file[], int line, const char* format, ...)
{
	static char tmp_string[MAX_BUF_SIZE];
	static char tmp_string2[MAX_BUF_SIZE];
	static va_list  ap;

	// Construct the string from variable arguments
	va_start(ap, format);
	vsprintf_s(tmp_string, MAX_BUF_SIZE, format, ap);
	va_end(ap);
	sprintf_s(tmp_string2, MAX_BUF_SIZE, "\n%s(%d) : %s", file, line, tmp_string);
	OutputDebugString(tmp_string2);

	// Send the string to the console
	if (App != nullptr)
	{
		sprintf_s(tmp_string2, MAX_BUF_SIZE, "%s\n", tmp_string);
	}
}