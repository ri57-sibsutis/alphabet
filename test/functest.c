#include <ctest.h>
#include <functions.h>
#include <locale.h>

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