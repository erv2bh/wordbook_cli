//Form.c
#include "form.h"
#include "wordbook.h"
#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int main(int argc, char* argv[]) {
	WordBook wordBook = { {{"","","",""},{"","","",""},{"","","",""},{"","","",""},{"","","",""},{"","","",""}},MAX,0 };
	
	int menu;


	Load(&wordBook);
	DisplayMenu(); rewind(stdin); scanf("%d", &menu);
	while (menu != 0) {
		switch (menu) {
		case 1: FormForRecording(&wordBook);
			break;
		case 2: FindMenu(&wordBook);
			break;
		case 3: FormForCorrecting(&wordBook);
			break;
		case 4: FormForErasing(&wordBook);
			break;
		case 5: FormForArranging(&wordBook);
			break;		
		case 6: FormForViewAll(&wordBook);
			break;
			
		default: break;
		}
		DisplayMenu(); rewind(stdin); scanf("%d", &menu);

	}


	Save(&wordBook);
	return 0;
}

void DisplayMenu() {
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t    �ܾ���version0.05\n");
	printf("\t\t\t    ===================\n");
	printf("\t\t\t    [1] �����ϱ�\n");
	printf("\t\t\t    [2] ã    ��\n");
	printf("\t\t\t    [3] �� ġ ��\n");
	printf("\t\t\t    [4] �� �� ��\n");
	printf("\t\t\t    [5] �����ϱ�\n");
	printf("\t\t\t    [6] ��ü����\n");
	printf("\t\t\t    [0] �� �� ��\n");
	printf("\t\t\t    -------------------\n");
	printf("\t\t\t    �޴��� �����Ͻʽÿ� ");
}

void FormForRecording(WordBook* wordBook) {
	char spelling[12];
	char wordClass[12];
	char meaning[12];
	char exampleSentence[32];
	char recording;
	char going = 'Y';
	Long index;

	while (going == 'Y' || going == 'y') {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t�ܾ���version0.05-�����ϱ�\n");
		printf("\t======================================================================================\n");
		printf("\tö    �� : "); rewind(stdin); scanf("%s", spelling);
		printf("\tǰ    �� : [1]��� [2]���� [3]���� [4]����� [5]�λ� [6]���ӻ� [7]��ġ�� [8]��ź�� "); rewind(stdin); scanf("%d", &index);
		switch (index) {
		case 1: strcpy(wordClass, "���");
			break;
		case 2: strcpy(wordClass, "����");
			break;
		case 3: strcpy(wordClass, "����");
			break;
		case 4: strcpy(wordClass, "�����");
			break;
		case 5: strcpy(wordClass, "�λ�");
			break;
		case 6: strcpy(wordClass, "���ӻ�");
			break;
		case 7: strcpy(wordClass, "��ġ��");
			break;
		case 8: strcpy(wordClass, "��ź��");
			break;
		default: break;
		}
		printf("\t��    �� : "); rewind(stdin); scanf("%s", meaning);
		printf("\t��    �� : "); rewind(stdin); gets(exampleSentence);
		printf("\t--------------------------------------------------------------------------------------\n");
		printf("\t�����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); recording = getchar();
		if (recording == 'Y' || recording == 'y') {
			index = Record(wordBook, spelling, wordClass, meaning, exampleSentence);
			printf("\t======================================================================================\n");
			printf("\t��ȣ    ö��\tǰ��\t�ǹ�\t����\n");
			printf("\t--------------------------------------------------------------------------------------\n");
			printf("\t%d      %s\t%s\t%s\t%s\n",
				index + 1,
				wordBook->words[index].spelling,
				wordBook->words[index].wordClass,
				wordBook->words[index].meaning,
				wordBook->words[index].exampleSentence);
		}
		printf("\t==============================================\n");
		printf("\t����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); going = getchar();
		}
	}

void FindMenu(WordBook* wordBook){
	int menu;

	DisplayFindMenu(); rewind(stdin); scanf("%d", &menu);
	while (menu != 0) {
		switch(menu) {
		case 1:FormForFindingBySpelling(wordBook);
			break;

		case 2:FormForFindingByMeaning(wordBook);
			break;

		default: break;
		}
		DisplayFindMenu(); rewind(stdin); scanf("%d", &menu);
	}
}

void DisplayFindMenu() {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t    �ּҷ�version0.05-ã��\n");
	printf("\t\t\t    ======================\n");
	printf("\t\t\t    [1] ö�ڷ�      ã��\n");
	printf("\t\t\t    [2] �ǹ̷�      ã��\n");
	printf("\t\t\t    [0] �����޴���  ����\n");
	printf("\t\t\t    ----------------------\n");
	printf("\t\t\t    �޴��� �����Ͻʽÿ� ");
}

void FormForFindingBySpelling(WordBook* wordBook) {
	char spelling[12];
	Long indexes[MAX];
	Long count;
	Long i;
	char going = 'Y';

	while (going == 'Y' || going == 'y') {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t  �ܾ���version0.05-ö�ڷ� ã��\n");
		printf("\t  ==================================================\n");
		printf("\t  ö      �� : "); rewind(stdin); scanf("%s",spelling);

		FindBySpelling(wordBook, spelling, indexes, &count);
		printf("\t  --------------------------------------------------\n");
		printf("\t  ��ȣ    ö��\tǰ��\t�ǹ�\t����\n");
		printf("\t  --------------------------------------------------\n");
		i = 0;
		while (i < count) {
			printf("\t  %d      %s\t%s\t%s\t%s\n",
				i + 1,
				wordBook->words[indexes[i]].spelling,
				wordBook->words[indexes[i]].wordClass,
				wordBook->words[indexes[i]].meaning,
				wordBook->words[indexes[i]].exampleSentence);
			i++;
		}
		printf("\t  ==================================================\n");
		printf("\t  ����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); going = getchar();
	}
}

void FormForFindingByMeaning(WordBook* wordBook) {
	char meaning[12];
	Long indexes[MAX];
	Long count;
	Long i;
	char going = 'Y';

	while (going == 'Y' || going == 'y') {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t  �ܾ���version0.05-�ǹ̷� ã��\n");
		printf("\t  ==================================================\n");
		printf("\t  ��      �� : "); rewind(stdin); scanf("%s",meaning);

		FindByMeaning(wordBook, meaning, indexes, &count);
		printf("\t  --------------------------------------------------\n");
		printf("\t  ��ȣ    ö��\tǰ��\t�ǹ�\t����\n");
		printf("\t  --------------------------------------------------\n");
		i = 0;
		while (i < count) {
			printf("\t  %d      %s\t%s\t%s\t%s\n",
				i + 1,
				wordBook->words[indexes[i]].spelling,
				wordBook->words[indexes[i]].wordClass,
				wordBook->words[indexes[i]].meaning,
				wordBook->words[indexes[i]].exampleSentence);
			i++;
		}
		printf("\t  ==================================================\n");
		printf("\t  ����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); going = getchar();
	}
}


void FormForCorrecting(WordBook* wordBook) {
	char spelling[12];
	char wordClass[12];
	char meaning[12];
	char exampleSentence[32];
	char correcting;
	char going = 'Y';
	Long indexes[MAX];
	Long i;
	Long index;
	Long count;

	while (going == 'Y' || going == 'y') {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t�ܾ���version0.05-��ġ��\n");
		printf("\t========================\n");
		printf("\tö      �� : "); rewind(stdin); scanf("%s", spelling);

		FindBySpelling(wordBook, spelling, indexes, &count);
		printf("\t--------------------------------------------------\n");
		printf("\t��ȣ    ö��\tǰ��\t�ǹ�\t����\n");
		printf("\t--------------------------------------------------\n");
		i = 0;
		while (i < count) {
			printf("\t%d      %s\t%s\t%s\t%s\n",
				i + 1,
				wordBook->words[indexes[i]].spelling,
				wordBook->words[indexes[i]].wordClass,
				wordBook->words[indexes[i]].meaning,
				wordBook->words[indexes[i]].exampleSentence);
			i++;
		}
		if (count > 0) {
			printf("\t--------------------------------------------------\n");
			printf("\t��      ȣ : "); rewind(stdin); scanf("%d", &index);
			printf("\tǰ      �� : %s ",wordBook->words[indexes[index-1]].wordClass); rewind(stdin); gets(wordClass);
			if (strcmp(wordClass, "") == 0) {
				strcpy(wordClass, wordBook->words[indexes[index - 1]].meaning);
			}
			printf("\t��      �� : %s ",wordBook->words[indexes[index-1]].meaning); rewind(stdin); gets(meaning);
			if (strcmp(meaning, "") == 0) {
				strcpy(meaning, wordBook->words[indexes[index - 1]].meaning);
			}
			printf("\t��      �� : %s ",wordBook->words[indexes[index-1]].exampleSentence); rewind(stdin); gets(exampleSentence);
			if (strcmp(exampleSentence, "") == 0) {
				strcpy(exampleSentence, wordBook->words[indexes[index - 1]].exampleSentence);
			}
			printf("\t--------------------------------------------------\n");
			printf("\t��ġ�ðڽ��ϱ�?(Yes/No) "); rewind(stdin); correcting = getchar();
			if (correcting == 'Y' || correcting == 'y') {
				index = Correct(wordBook, indexes[index - 1], wordClass, meaning, exampleSentence);
				printf("\t--------------------------------------------------\n");
				printf("\t��ȣ    ö��\tǰ��\t�ǹ�\t����\n");
				printf("\t--------------------------------------------------\n");
				printf("\t%d      %s\t%s\t%s\t%s\n",
					index + 1,
					wordBook->words[index].spelling,
					wordBook->words[index].wordClass,
					wordBook->words[index].meaning,
					wordBook->words[index].exampleSentence);
			}
			printf("\t==================================================\n");
			printf("\t����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); going = getchar();
		}
	}
}


void FormForViewAll(WordBook* wordBook) {
	Long i = 0;
	Long j;

	while (i < wordBook->length) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t�ܾ���version0.05-��ü����\n");
		printf("\t==================================================\n");
		printf("\t��ȣ    ö��\tǰ��\t�ǹ�\t����\n");
		printf("\t--------------------------------------------------\n");

		j = 1;
		while (j <= 5 && i < wordBook->length) {
			printf("\t%d    %s\t%s\t%s\t%s\n",
				i + 1,
				wordBook->words[i].spelling,
				wordBook->words[i].wordClass,
				wordBook->words[i].meaning,
				wordBook->words[i].exampleSentence);
			i++;
			j++;
		}
		printf("\t==================================================\n");
		printf("\t�ƹ�Ű�� �����ÿ�! "); rewind(stdin);  getchar();
	}
}

void FormForErasing(WordBook* wordBook) {
	Long indexes[MAX];
	Long index;
	Long i = 0;
	Long count;
	char spelling[12];
	char erasing;
	char going = 'Y';

	while (going == 'Y' || going == 'y') {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t�ܾ���version0.05-�����\n");
		printf("\t========================\n");
		printf("\tö      �� : "); rewind(stdin); scanf("%s", spelling);

		FindBySpelling(wordBook, spelling, indexes, &count);
		printf("\t--------------------------------------------------\n");
		printf("\t��ȣ    ö��\tǰ��\t�ǹ�\t����\n");
		printf("\t--------------------------------------------------\n");
		i = 0;
		while (i < count) {
			printf("\t%d      %s\t%s\t%s\t%s\n",
				i + 1,
				wordBook->words[indexes[i]].spelling,
				wordBook->words[indexes[i]].wordClass,
				wordBook->words[indexes[i]].meaning,
				wordBook->words[indexes[i]].exampleSentence);
			i++;
		}
		if (count > 0) {
			printf("\t--------------------------------------------------\n");
			printf("\t��      ȣ : "); rewind(stdin); scanf("%d", &index);
			printf("\t--------------------------------------------------\n");
			printf("\t��ȣ    ö��\tǰ��\t�ǹ�\t����\n");
			printf("\t--------------------------------------------------\n");
			printf("\t%d      %s\t%s\t%s\t%s\n",
				indexes[index - 1] + 1,
				wordBook->words[indexes[index - 1]].spelling,
				wordBook->words[indexes[index - 1]].wordClass,
				wordBook->words[indexes[index - 1]].meaning,
				wordBook->words[indexes[index - 1]].exampleSentence);
			printf("\t--------------------------------------------------\n");
			printf("\t����ðڽ��ϱ�?(Yes/No) "); rewind(stdin); erasing = getchar();

			if (erasing == 'Y' || erasing == 'y') {
				index = Erase(wordBook, indexes[index - 1]);
				if (index == -1) {
					printf("\t==================================================\n");
					printf("\t���������ϴ�! \n");
				}
			}
		}
		printf("\t==================================================\n");
		printf("\t����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); going = getchar();
	}
}

void FormForArranging(WordBook* wordBook) {
	Long i = 0;
	Long j;
	
	Arrange(wordBook);
	while (i < wordBook->length) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t�ܾ���version0.05-��ü����\n");
		printf("\t==================================================\n");
		printf("\t��ȣ    ö��\tǰ��\t�ǹ�\t����\n");
		printf("\t--------------------------------------------------\n");

		j = 1;
		while (j <= 5 && i < wordBook->length) {
			printf("\t%d    %s\t%s\t%s\t%s\n",
				i + 1,
				wordBook->words[i].spelling,
				wordBook->words[i].wordClass,
				wordBook->words[i].meaning,
				wordBook->words[i].exampleSentence);
			i++;
			j++;
		}
		printf("\t==================================================\n");
		printf("\t�ƹ�Ű�� �����ÿ�! "); rewind(stdin);  getchar();
	}
}
