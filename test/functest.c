#include <ctest.h>
#include <functions.h>
#include <locale.h>

CTEST(equation_suite, cropofsymbols)
{
	//Given
	char string[] = "...sad";
	
	//When
	char fstring[260];
	crop(string, fstring);
	const int a = fstring[0];

	//Then
	const int ch = 's';


	ASSERT_EQUAL(a, ch);

}

CTEST(strings_process, search_of_rus_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	const char string[] = "...������.";
	const char ch = '�';
	
	//When
	int rv = schr(string, ch);
	

	//Then
	const a = 3;

	ASSERT_EQUAL(rv, a);

}

CTEST(string_process, search_of_eng_word)
{
	//Given
	const int char string[] = "twitter";
	const int char ch = 'w';
	
	//When
	int rv = schr(string, ch);

	//Then
	const int a = 1;
	ASSERT_EQUAL(rv, a);

}