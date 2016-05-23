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
	const int a = fstring[0];
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
	const int rv = schr(string, ch);
	

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
	char *tmp1 = ptr[0];
	char *tmp2 = ptr[1];
	char *tmp3 = ptr[2];
	//When
	
	const int expct_a = 'a';
	const int real_a = tmp1[0];
	const int expct_b = 'b';
	const int real_b = tmp2[0];
	const int expct_c = 'c';
	const int real_c = tmp3[0];

	//Then
	ASSERT_EQUAL(expct_a, real_a);
	ASSERT_EQUAL(expct_b, real_b);
	ASSERT_EQUAL(expct_c, real_c);
}

CTEST(equation_suite, exchange_of_eng_words)
{
	//Given
	char string[]= "lmao ay";
	char *ptr[2];
	stok(string, ptr);
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
	ptr[0]="áî";
	ptr[1]="ÿçü";
	ptr[2]="ø";

	//When
	exchange(ptr, 0);
	char *tmp1 = ptr[1];
	char *tmp = ptr[0];
	const int real = tmp[0];
	const int real_1 = tmp1[0];

	//Then
	const int expct_1 = 'á';
	const int expct = 'ÿ';

	ASSERT_EQUAL(real_1, expct_1);
	ASSERT_EQUAL(real, expct);
}