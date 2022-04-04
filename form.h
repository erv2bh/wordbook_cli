//Form.h
#ifndef _FORM_H
#define _FORM_H
typedef struct _wordBook WordBook;

void DisplayMenu();
void FindMenu(WordBook* wordBook);
void DisplayFindMenu();
void FormForRecording(WordBook* wordBook);
void FormForFindingBySpelling(WordBook* wordBook);
void FormForFindingByMeaning(WordBook* wordBook);
void FormForCorrecting(WordBook* wordBook);
void FormForErasing(WordBook* wordBook);
void FormForArranging(WordBook* wordBook);
void FormForViewAll(WordBook* wordBook);

#endif //_FORM_H