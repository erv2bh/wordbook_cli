/*
���ϸ�: wordBook.c
���: �ܾ��忡 �ܾ �����ϰ�, ã��, ��ġ��, ����� �����Ѵ�
�ۼ���: �����
�ۼ�����: 2021/04/17
*/

#include "wordBook.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

#if 0
//�Լ�����

int main(int agrc, char* argv[]) {
	WordBook wordBook = { {{"","","",""},{"","","",""},{"","","",""},{"","","",""},{"","","",""},{"","","",""}},MAX,0 };
	
	Long count;
	Long index;
	Long indexes[MAX];
	Long i;

	count = Load(&wordBook);
	i = 0;
	while (i < count) {
		printf("%s%s%s%s\n", wordBook.words[i].spelling, wordBook.words[i].wordClass, wordBook.words[i].meaning, wordBook.words[i].exampleSentence);
		i++;
	}

	index = Record(&wordBook, (char*)"apple", (char*)"���", (char*)"���", (char*) "Apple is a fruit");
	printf("%s%s%s%s\n", wordBook.words[index].spelling, wordBook.words[index].wordClass, wordBook.words[index].meaning, wordBook.words[index].exampleSentence);

	index = Record(&wordBook, (char*)"go", (char*)"����", (char*)"����", (char*)"I am going home");
	printf("%s%s%s%s\n", wordBook.words[index].spelling, wordBook.words[index].wordClass, wordBook.words[index].meaning, wordBook.words[index].exampleSentence);

	index = Record(&wordBook, (char*)"happy", (char*)"�����", (char*)"�ູ��", (char*)"He is happy");
	printf("%s%s%s%s\n", wordBook.words[index].spelling, wordBook.words[index].wordClass, wordBook.words[index].meaning, wordBook.words[index].exampleSentence);

	index = Record(&wordBook, (char*)"work", (char*)"����", (char*)"���ϴ�", (char*)"He is working at home");
	printf("%s%s%s%s\n", wordBook.words[index].spelling, wordBook.words[index].wordClass, wordBook.words[index].meaning, wordBook.words[index].exampleSentence);

	index = Record(&wordBook, (char*)"work", (char*)"���", (char*)"��", (char*)"I have a lot of work to do");
	printf("%s%s%s%s\n", wordBook.words[index].spelling, wordBook.words[index].wordClass, wordBook.words[index].meaning, wordBook.words[index].exampleSentence);

	index = Record(&wordBook, (char*)"joyful", (char*)"�����", (char*)"�ູ��", (char*)"They were joyful of the news");
	printf("%s%s%s%s\n", wordBook.words[index].spelling, wordBook.words[index].wordClass, wordBook.words[index].meaning, wordBook.words[index].exampleSentence);

	FindBySpelling(&wordBook, (char*)"apple", indexes, &count);
	i = 0;
	while (i < count) {
		printf("%s%s%s%s\n", wordBook.words[indexes[i]].spelling, wordBook.words[indexes[i]].wordClass, wordBook.words[indexes[i]].meaning, wordBook.words[indexes[i]].exampleSentence);
		i++;
	}

	FindByMeaning(&wordBook, (char*)"�ູ��", indexes, &count);
	i = 0;
	while (i < count) {
		printf("%s%s%s%s\n", wordBook.words[indexes[i]].spelling, wordBook.words[indexes[i]].wordClass, wordBook.words[indexes[i]].meaning, wordBook.words[indexes[i]].exampleSentence);
		i++;
	}

	index = Correct(&wordBook, 1, (char*)"���", (char*)"����", (char*)"Whose go is it?");
	printf("%s%s%s%s\n", wordBook.words[index].spelling, wordBook.words[index].wordClass, wordBook.words[index].meaning, wordBook.words[index].exampleSentence);


	index = Erase(&wordBook, 2);
	if (index == -1) {
		printf("���������ϴ�\n");
	}

	Arrange(&wordBook);
	i = 0;
	while (i < wordBook.length) {
		printf("%s%s%s%s\n", wordBook.words[i].spelling, wordBook.words[i].wordClass, wordBook.words[i].meaning, wordBook.words[i].exampleSentence);
		i++;
	}

	Save(&wordBook);

	return 0;
}
#endif

/*
�Լ��̸�: Record
���: ö��, ǰ��, �ǹ�, ������ �����Ѵ�
�Է�: ö��, ǰ��, �ǹ�, ����
���: ��ġ
*/

Long Record(WordBook* wordBook, char(*spelling), char(*wordClass), char(*meaning), char(*exampleSentence)) {
	Long index = -1;
	Long i = 0;
	while (i < wordBook->capacity && strcmp(wordBook->words[i].spelling, "") != 0) {
		i++;
	}
	if (i < wordBook->capacity) {
		index = i;
		strcpy(wordBook->words[index].spelling, spelling);
		strcpy(wordBook->words[index].wordClass, wordClass);
		strcpy(wordBook->words[index].meaning, meaning);
		strcpy(wordBook->words[index].exampleSentence, exampleSentence);
		wordBook->length = wordBook->length + 1;
	}
	return index;
}

/*
�Լ��̸�: FindBySpelling
���: ö�ڸ� �Է¹޾� ��ġ��, ������ ���Ѵ�
�Է�: ö��
���: ��ġ��, ����
*/

void FindBySpelling(WordBook* wordBook, char(*spelling), Long(*indexes), Long* count) {
	Long i = 0;
	Long j = 0;
	*count = 0;
	while (i < wordBook->length) {
		if (strcmp(wordBook->words[i].spelling, spelling) == 0) {
			indexes[j] = i;
			j++;
			(*count)++;
		}
		i++;
	}
}

/*
�Լ��̸�: FindByMeaning
���: �ǹ̸� �Է¹޾� ��ġ��, ������ ���Ѵ�
�Է�: �ǹ�
���: ��ġ��, ����
*/

void FindByMeaning(WordBook* wordBook, char(*meaning), Long(*indexes), Long* count) {
	Long i = 0;
	Long j = 0;
	*count = 0;
	while (i < wordBook->length) {
		if (strcmp(wordBook->words[i].meaning, meaning) == 0) {
			indexes[j] = i;
			j++;
			(*count)++;
		}
		i++;
	}
}

/*
�Լ��̸�: Correct
���: ��ġ, ǰ��, �ǹ�, ������ �Է¹޾� ��ģ��
�Է�: ��ġ, ǰ��, �ǹ�, ����
���: ��ġ
*/

Long Correct(WordBook* wordBook, Long index, char(*wordClass), char(*meaning), char(*exampleSentence)) {
	strcpy(wordBook->words[index].wordClass, wordClass);
	strcpy(wordBook->words[index].meaning, meaning);
	strcpy(wordBook->words[index].exampleSentence, exampleSentence);
	return index;
}

/*
�Լ��̸�: Erase
���: ��ġ�� �Է¹޾� ����Ѵ�
�Է�: ��ġ
���: ��ġ
*/

Long Erase(WordBook* wordBook, Long index) {
	strcpy(wordBook->words[index].spelling, "-");
	index = -1;
	return index;
}

/*
�Լ��̸�: Arrange
���: ö�ڵ��� ������������ �����Ѵ�
�Է�: ����
���: ����
*/

void Arrange(WordBook* wordBook) {
	Long i=0;
	Long j;
	Long count = 0;
	Long position;
	Word word;

	while (i < wordBook->length-1) {
		position = i;
		j = i + 1;
		while (j < wordBook->length) {
			if (strcmp(wordBook->words[j].spelling, wordBook->words[position].spelling) > 0) {
				position = j;
			}
			j++;
		}
		word = wordBook->words[position];
		wordBook->words[position] = wordBook->words[i];
		wordBook->words[i] = word;
		i++;
	}
	i = 0;
	while (i < wordBook->length && strcmp(wordBook->words[i].spelling, "=") != 0) {
		count++;
		i++;
	}
	i = 1;
	while(i<count){
		word = wordBook->words[i];
		j = i - 1;
		while (j >-1 && strcmp(wordBook->words[j].spelling, word.spelling) > 0) {
			wordBook->words[j + 1] = wordBook->words[j];
			j--;
		}
		wordBook->words[j + 1] = word;
		i++;
	}
}

Long Load(WordBook* wordBook) {
	Word word;
	Long i = 0;

	FILE* file = fopen("wordBook.dat", "rb");
	size_t flag;
	if (file != NULL) {
		flag = fread(&word, sizeof(Word), 1, file);
		while (!feof(file) && flag != 0) {
			wordBook->words[i] = word;
			i++;
			wordBook->length = wordBook->length + 1;
			flag = fread(&word, sizeof(Word), 1, file);
		}
		fclose(file);
	}
	return wordBook->length;
}

Long Save(WordBook* wordBook) {
	Long i = 0;
	FILE* file = fopen("wordBook.dat", "wb");
	if (file != NULL) {
		while (i < wordBook->length) {
			fwrite(wordBook->words + i, sizeof(Word), 1, file);
			i++;
		}
		fclose(file);
	}
	return wordBook->length;
}
