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

	//Then
	const int exp = fstring[0];
	const int real = 's';
	ASSERT_EQUAL(exp, real);

}

CTEST(equation_suite, crop_of_symbols_rus)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[] = "���";
	
	//When
	char fstring[260];
	crop(string, fstring);
	const int exp = fstring[2];

	//Then
	const int real = '�';
	ASSERT_EQUAL(exp, real);

}

CTEST(strings_process, search_of_rus_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[] = "...������";
	char ch = '�';
	
	//When
	const int real = schr(string, ch);
	

	//Then
	const int exp = 3;

	ASSERT_EQUAL(real, exp);

}

CTEST(strings_process, search_of_rus_cap_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[8] = "�������";
	char ch = '�';
	
	//When
	int real = schr(string, ch);
	

	//Then
	const int exp = 0;

	ASSERT_EQUAL(real, exp);

}

CTEST(string_process, search_of_eng_word)
{
	//Given
	char string[] = "twitter";
	char ch = 'w';
	
	//When
	int real = schr(string, ch);

	//Then
	const int exp = 1;
	ASSERT_EQUAL(real, exp);

}

CTEST(equation_suite, search_of_empty)
{
	
	//Given
	char string[] = "123456789";
	char ch = 'Z';
	
	//When
	int real = schr(string, ch);

	//Then
	const int exp = -1;

	ASSERT_EQUAL(real, exp);

}

CTEST(equation_suite, search_of_eng_word2)
{
	//Given
	char string[] = "TTT";
	char ch = 'T';
	
	//When
	int real = schr(string, ch);
	const int exp = 0;

	//Then
	ASSERT_EQUAL(real, exp);

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
	const int real_1 = tmp2[0];
	const int exp_1 = 'l';
	const int exp_2 = 'a';//change
	const int real_2 = tmp1[0];
	const int exp_size = 2;

	//Then
	ASSERT_EQUAL(exp_1, real_1);
	ASSERT_EQUAL(real_2, exp_2);
	ASSERT_EQUAL(exp_size, size);
}

CTEST(equation_suite, stok_single)
{
	//Given
	char string[]= "haallo";
	char *ptr[1];
	stok(string, ptr);
	char *tmp1 = ptr[0];
	//When
	
	const int expct = 'h';
	const int real = tmp1[0];

	//Then
	ASSERT_EQUAL(real, expct);
}

CTEST(equation_suite, sort_eng)
{
	//Given
	char string[]= "b a c";
	char *ptr[3];
	stok(string, ptr);
	sort(ptr, 3);
	char *tmpa = ptr[0];
	char *tmpb = ptr[1];
	char *tmpc = ptr[2];
	//When
	
	const int expct_a = 'a';
	const int real_a = tmpa[0];
	const int expct_b = 'b';
	const int real_b = tmpb[0];
	const int expct_c = 'c';
	const int real_c = tmpc[0];

	//Then
	ASSERT_EQUAL(expct_a, real_a);
	ASSERT_EQUAL(expct_b, real_b);
	ASSERT_EQUAL(expct_c, real_c);
}

CTEST(equation_suite, exchange_of_eng_words)
{
	//Given
	char *ptr[1];
	ptr[0]="lmao";
	ptr[1]="ay";
	exchange(ptr, 0);
	char *tmp1 = ptr[0];
	char *tmp2 = ptr[1];

	//When
	const int real_1 = tmp1[0];
	const int real_2 = tmp2[0];

	//Then
	const int expct_1 = 'a';
	const int expct_2 = 'l';
	ASSERT_EQUAL(expct_1, real_1);
	ASSERT_EQUAL(expct_2, real_2);

}

CTEST(equation_suite, exchange_of_rus_words)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char *ptr[2];
	ptr[0]="��";
	ptr[1]="���";
	ptr[2]="�";

	//When
	exchange(ptr, 0);
	char *tmp1 = ptr[1];
	char *tmp = ptr[0];
	const int real = tmp[0];
	const int real_1 = tmp1[0];

	//Then
	const int expct_1 = '�';
	const int expct = '�';

	ASSERT_EQUAL(real_1, expct_1);
	ASSERT_EQUAL(real, expct);
}