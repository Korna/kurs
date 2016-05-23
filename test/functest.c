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
	const char string[] = "���";
	
	//When
	char fstring[260];
	crop(string, fstring);
	const int a = fstring[2];

	//Then
	const int ch = '�';
	ASSERT_EQUAL(a, ch);

}

CTEST(strings_process, search_of_rus_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	const char string[8] = "...������";
	const char ch = '�';
	
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
	const char string[8] = "�������";
	const char ch = '�';
	
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

CTEST(equation_suite, search_of_empty)
{
	
	//Given
	const char string[] = "123456789";
	const char ch = 'Z';
	
	//When
	int rv = schr(string, ch);

	//Then
	const int a = -1;

	ASSERT_EQUAL(rv, a);

}

CTEST(equation_suite, search_of_eng_word2)
{
	//Given
	const int char string[] = "TTT";
	const int char ch = 'T';
	
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
	stok(string, ptr);
	char *tmp1 = ptr[0];
	char *tmp2 = ptr[1];
	//When
	
	const int a = tmp2[0];
	const int b = 'a';
	const int c = 'l';
	const int d = tmp1[0];

	//Then
	ASSERT_EQUAL(b, a);
	ASSERT_EQUAL(d, c);
}