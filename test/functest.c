#include <ctest.h>
#include <functions.h>
#include <locale.h>

CTEST(equation_suite, crop_of_symbols)
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

CTEST(equation_suite, crop_of_symbols2)
{
	//Given
	const char string[] = "äèä";
	
	//When
	char fstring[260];
	crop(string, fstring);
	const int a = fstring[2]

	//Then
	const int ch = 'ä';
	ASSERT_EQUAL(a, ch);

}

CTEST(strings_process, search_of_rus_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	const char string[8] = "...ÿ÷ñìèð";
	const char ch = 'ÿ';
	
	//When
	int rv = schr(string, ch);
	

	//Then
	const int a = 3;

	ASSERT_EQUAL(rv, a);

}

CTEST(strings_process, search_of_rus_cap_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	const char string[8] = "ÀàààÀÀà";
	const char ch = 'À';
	
	//When
	int rv = schr(string, ch);
	

	//Then
	const int a = 0;

	ASSERT_EQUAL(rv, a);

}

CTEST(string_process, search_of_eng_word)
{
	//Given
	const char string[] = "twitter";
	const char ch = 'w';
	
	//When
	int rv = schr(string, ch);

	//Then
	const int a = 1;
	ASSERT_EQUAL(rv, a);

}