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
	const int a = fstring[0];

	//Then
	const int ch = 's';


	ASSERT_EQUAL(a, ch);

}

CTEST(equation_suite, cropofsymbols)
{
	//Given
	const char string[] = "sad";
	
	//When
	char fstring[260];
	crop(string, fstring);
	const int a = fstring[2];

	//Then
	const int ch = 'd';


	ASSERT_EQUAL(a, ch);
}