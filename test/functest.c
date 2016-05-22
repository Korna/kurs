#include <ctest.h>
#include <functions.h>
#include <locale.h>

CTEST(equation_suite, cropofsymbols)
{
	//Given
	const char string[] = "...sad";
	
	//When
	char fstring[260];
	crop(string, fstring);
	int ch = 's';
	int a = fstring[0];

	//Then
	ASSERT_EQUAL(a, ch);

}
