//wordBook.h
#ifndef _WORDBOOK_H
#define _WORDBOOK_H
#define MAX 6
#define _CRT_SECURE_NO_WARNINGS

typedef signed long int Long;
typedef struct _word {
	char spelling[12];
	char wordClass[12];
	char meaning[12];
	char exampleSentence[32];
}Word;

typedef struct _wordBook {
	Word words[MAX];
	Long capacity;
	Long length;
}WordBook;

//함수선언
	
Long Record(WordBook* wordBook, char(*spelling), char(*wordCLass), char(*meaning), char(*exampleSentence));
void FindBySpelling(WordBook* wordBook, char(*spelling), Long(*indexes), long* count);
void FindByMeaning(WordBook* wordBook, char(*meaning), Long(*indexes), long* count);
Long Correct(WordBook* wordBook, Long index, char(*wordClass), char(*meaning), char(*exampleSentence));
Long Erase(WordBook* wordBook, Long index);
void Arrange(WordBook* wordBook);
Long Load(WordBook* wordBook);
Long Save(WordBook* wordBook);

#endif //_WORDBOOK_H
