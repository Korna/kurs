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

CTEST(equation_suite, search_of_rus_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	const char string[] = "...ÿקסלטנ.";
	const char ch = 'ÿ';
	
	//When
	rv = schr(string, ch);
	

	//Then
	const a = 3;

	ASSERT_EQUAL(rv, a);

}