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

CTEST(equation_suite, crop_of_symbols_rus)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[] = "äèä";
	
	//When
	char fstring[260];
	crop(string, fstring);
	const int a = fstring[2];

	//Then
	const int ch = 'ä';
	ASSERT_EQUAL(a, ch);

}

CTEST(strings_process, search_of_rus_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[] = "...ÿ÷ñìèð";
	char ch = 'ÿ';
	
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
	char string[8] = "ÀàààÀÀà";
	char ch = 'À';
	
	//When
	int rv = schr(string, ch);
	

	//Then
	const int a = 0;

	ASSERT_EQUAL(rv, a);

}

CTEST(string_process, search_of_eng_word)
{
	//Given
	char string[] = "twitter";
	char ch = 'w';
	
	//When
	int rv = schr(string, ch);

	//Then
	const int a = 1;
	ASSERT_EQUAL(rv, a);

}

CTEST(equation_suite, search_of_empty)
{
	
	//Given
	char string[] = "123456789";
	char ch = 'Z';
	
	//When
	int rv = schr(string, ch);

	//Then
	const int a = -1;

	ASSERT_EQUAL(rv, a);

}

CTEST(equation_suite, search_of_eng_word2)
{
	//Given
	char string[] = "TTT";
	char ch = 'T';
	
	//When
	int rv = schr(string, ch);
	const int a = 0;

	//Then
	ASSERT_EQUAL(rv, a);

}

CTEST(equation_suite, stok_multiple)
{
	//Given
	char string[]= "aaaay lmaaao";
	char *ptr[2];
	int size = stok(string, ptr);
	char *tmp1 = ptr[0];
	char *tmp2 = ptr[1];

	//When
	const int a = tmp2[0];
	const int b = 'l';
	const int c = 'a';//change
	const int d = tmp1[0];
	const int exp_size = 2;

	//Then
	ASSERT_EQUAL(b, a);
	ASSERT_EQUAL(d, c);
	ASSERT_EQUAL(exp_size, size);
}