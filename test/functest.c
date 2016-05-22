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

CTEST(equation_suite, cropofsymbols)
{
	//Given
	const char string[] = "sad";
	
	//When
	char fstring[260];
	crop(string, fstring);
	int ch = 'd';
	int a = fstring[2];

	//Then
	ASSERT_EQUAL(a, ch);

}

CTEST(equation_suite, searchofrusword)
{
	setlocale(LC_ALL, "Rus");
	//Given
	const char string[] = "...ˇ˜ÒÏË.";
	const char ch = 'ˇ';
	
	//When
	rv = schr(string, ch);
	a = 3;

	//Then
	ASSERT_EQUAL(rv, a);

}

CTEST(equation_suite, searchofruscapitalword)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[] = "¿‡¿¿‡‡‡‡‡‡‡";
	char ch = '¿';
	
	//When
	int rv = schr(string, ch);
	int a = 0;

	//Then
	ASSERT_EQUAL(rv, a);

}

CTEST(equation_suite, searchofempty)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[] = "123456789";
	char ch = 's';
	
	//When
	int rv = schr(string, ch);
	int a = -1;

	//Then
	ASSERT_EQUAL(rv, a);

}

CTEST(equation_suite, searchofengword)
{
	//Given
	int char string[] = "zwitter";
	int char ch = 'w';
	
	//When
	int rv = schr(string, ch);
	int a = 1;

	//Then
	ASSERT_EQUAL(rv, a);

}

CTEST(equation_suite, searchofsymbol)
{
	//Given
	char string[] = "twitteerr";
	const int char ch = '-';
	
	//When
	int rv = schr(string, ch);
	int a = -1;

	//Then
	ASSERT_EQUAL(rv, a);

}

CTEST(equation_suite, exchange1)
{
	//Given
	char string[]= "lmaaao aaaayyy";
	char *ptr[2];
	stok(string, ptr);
	exchange(ptr, 0);
	char *tmp1 = ptr[0];
	char *tmp2 = ptr[1];
	//When
	
	int a = tmp1[0];
	int b = 'l';

	//Then
	ASSERT_EQUAL(b, a);

}

CTEST(equation_suite, exchange2)
{
	//Given
	char string[]= "lmaaao aaaayyy sshhhhh";
	char *ptr[2];
	stok(string, ptr);
	exchange(ptr, 1);
	char *tmp1 = ptr[0];
	char *tmp2 = ptr[1];
	//When
	
	int a = tmp2[0];
	int b = 's';
	int c = 'l';
	int d = tmp1[0];

	//Then
	ASSERT_EQUAL(b, a);
	ASSERT_EQUAL(d, c);
}
