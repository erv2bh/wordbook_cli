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
	printf("\t\t\t    단어장version0.05\n");
	printf("\t\t\t    ===================\n");
	printf("\t\t\t    [1] 기재하기\n");
	printf("\t\t\t    [2] 찾    기\n");
	printf("\t\t\t    [3] 고 치 기\n");
	printf("\t\t\t    [4] 지 우 기\n");
	printf("\t\t\t    [5] 정리하기\n");
	printf("\t\t\t    [6] 전체보기\n");
	printf("\t\t\t    [0] 끝 내 기\n");
	printf("\t\t\t    -------------------\n");
	printf("\t\t\t    메뉴를 선택하십시오 ");
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
		printf("\t단어장version0.05-기재하기\n");
		printf("\t======================================================================================\n");
		printf("\t철    자 : "); rewind(stdin); scanf("%s", spelling);
		printf("\t품    사 : [1]명사 [2]대명사 [3]동사 [4]형용사 [5]부사 [6]접속사 [7]전치사 [8]감탄사 "); rewind(stdin); scanf("%d", &index);
		switch (index) {
		case 1: strcpy(wordClass, "명사");
			break;
		case 2: strcpy(wordClass, "대명사");
			break;
		case 3: strcpy(wordClass, "동사");
			break;
		case 4: strcpy(wordClass, "형용사");
			break;
		case 5: strcpy(wordClass, "부사");
			break;
		case 6: strcpy(wordClass, "접속사");
			break;
		case 7: strcpy(wordClass, "전치사");
			break;
		case 8: strcpy(wordClass, "감탄사");
			break;
		default: break;
		}
		printf("\t의    미 : "); rewind(stdin); scanf("%s", meaning);
		printf("\t예    문 : "); rewind(stdin); gets(exampleSentence);
		printf("\t--------------------------------------------------------------------------------------\n");
		printf("\t기재하시겠습니까?(Yes/No) "); rewind(stdin); recording = getchar();
		if (recording == 'Y' || recording == 'y') {
			index = Record(wordBook, spelling, wordClass, meaning, exampleSentence);
			printf("\t======================================================================================\n");
			printf("\t번호    철자\t품사\t의미\t예문\n");
			printf("\t--------------------------------------------------------------------------------------\n");
			printf("\t%d      %s\t%s\t%s\t%s\n",
				index + 1,
				wordBook->words[index].spelling,
				wordBook->words[index].wordClass,
				wordBook->words[index].meaning,
				wordBook->words[index].exampleSentence);
		}
		printf("\t==============================================\n");
		printf("\t계속하시겠습니까?(Yes/No) "); rewind(stdin); going = getchar();
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
	printf("\t\t\t    주소록version0.05-찾기\n");
	printf("\t\t\t    ======================\n");
	printf("\t\t\t    [1] 철자로      찾기\n");
	printf("\t\t\t    [2] 의미로      찾기\n");
	printf("\t\t\t    [0] 상위메뉴로  가기\n");
	printf("\t\t\t    ----------------------\n");
	printf("\t\t\t    메뉴를 선택하십시오 ");
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
		printf("\t  단어장version0.05-철자로 찾기\n");
		printf("\t  ==================================================\n");
		printf("\t  철      자 : "); rewind(stdin); scanf("%s",spelling);

		FindBySpelling(wordBook, spelling, indexes, &count);
		printf("\t  --------------------------------------------------\n");
		printf("\t  번호    철자\t품사\t의미\t예문\n");
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
		printf("\t  계속하시겠습니까?(Yes/No) "); rewind(stdin); going = getchar();
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
		printf("\t  단어장version0.05-의미로 찾기\n");
		printf("\t  ==================================================\n");
		printf("\t  의      미 : "); rewind(stdin); scanf("%s",meaning);

		FindByMeaning(wordBook, meaning, indexes, &count);
		printf("\t  --------------------------------------------------\n");
		printf("\t  번호    철자\t품사\t의미\t예문\n");
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
		printf("\t  계속하시겠습니까?(Yes/No) "); rewind(stdin); going = getchar();
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
		printf("\t단어장version0.05-고치기\n");
		printf("\t========================\n");
		printf("\t철      자 : "); rewind(stdin); scanf("%s", spelling);

		FindBySpelling(wordBook, spelling, indexes, &count);
		printf("\t--------------------------------------------------\n");
		printf("\t번호    철자\t품사\t의미\t예문\n");
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
			printf("\t번      호 : "); rewind(stdin); scanf("%d", &index);
			printf("\t품      사 : %s ",wordBook->words[indexes[index-1]].wordClass); rewind(stdin); gets(wordClass);
			if (strcmp(wordClass, "") == 0) {
				strcpy(wordClass, wordBook->words[indexes[index - 1]].meaning);
			}
			printf("\t의      미 : %s ",wordBook->words[indexes[index-1]].meaning); rewind(stdin); gets(meaning);
			if (strcmp(meaning, "") == 0) {
				strcpy(meaning, wordBook->words[indexes[index - 1]].meaning);
			}
			printf("\t예      문 : %s ",wordBook->words[indexes[index-1]].exampleSentence); rewind(stdin); gets(exampleSentence);
			if (strcmp(exampleSentence, "") == 0) {
				strcpy(exampleSentence, wordBook->words[indexes[index - 1]].exampleSentence);
			}
			printf("\t--------------------------------------------------\n");
			printf("\t고치시겠습니까?(Yes/No) "); rewind(stdin); correcting = getchar();
			if (correcting == 'Y' || correcting == 'y') {
				index = Correct(wordBook, indexes[index - 1], wordClass, meaning, exampleSentence);
				printf("\t--------------------------------------------------\n");
				printf("\t번호    철자\t품사\t의미\t예문\n");
				printf("\t--------------------------------------------------\n");
				printf("\t%d      %s\t%s\t%s\t%s\n",
					index + 1,
					wordBook->words[index].spelling,
					wordBook->words[index].wordClass,
					wordBook->words[index].meaning,
					wordBook->words[index].exampleSentence);
			}
			printf("\t==================================================\n");
			printf("\t계속하시겠습니까?(Yes/No) "); rewind(stdin); going = getchar();
		}
	}
}


void FormForViewAll(WordBook* wordBook) {
	Long i = 0;
	Long j;

	while (i < wordBook->length) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t단어장version0.05-전체보기\n");
		printf("\t==================================================\n");
		printf("\t번호    철자\t품사\t의미\t예문\n");
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
		printf("\t아무키나 누르시오! "); rewind(stdin);  getchar();
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
		printf("\t단어장version0.05-지우기\n");
		printf("\t========================\n");
		printf("\t철      자 : "); rewind(stdin); scanf("%s", spelling);

		FindBySpelling(wordBook, spelling, indexes, &count);
		printf("\t--------------------------------------------------\n");
		printf("\t번호    철자\t품사\t의미\t예문\n");
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
			printf("\t번      호 : "); rewind(stdin); scanf("%d", &index);
			printf("\t--------------------------------------------------\n");
			printf("\t번호    철자\t품사\t의미\t예문\n");
			printf("\t--------------------------------------------------\n");
			printf("\t%d      %s\t%s\t%s\t%s\n",
				indexes[index - 1] + 1,
				wordBook->words[indexes[index - 1]].spelling,
				wordBook->words[indexes[index - 1]].wordClass,
				wordBook->words[indexes[index - 1]].meaning,
				wordBook->words[indexes[index - 1]].exampleSentence);
			printf("\t--------------------------------------------------\n");
			printf("\t지우시겠습니까?(Yes/No) "); rewind(stdin); erasing = getchar();

			if (erasing == 'Y' || erasing == 'y') {
				index = Erase(wordBook, indexes[index - 1]);
				if (index == -1) {
					printf("\t==================================================\n");
					printf("\t지워졌습니다! \n");
				}
			}
		}
		printf("\t==================================================\n");
		printf("\t계속하시겠습니까?(Yes/No) "); rewind(stdin); going = getchar();
	}
}

void FormForArranging(WordBook* wordBook) {
	Long i = 0;
	Long j;
	
	Arrange(wordBook);
	while (i < wordBook->length) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t단어장version0.05-전체보기\n");
		printf("\t==================================================\n");
		printf("\t번호    철자\t품사\t의미\t예문\n");
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
		printf("\t아무키나 누르시오! "); rewind(stdin);  getchar();
	}
}
