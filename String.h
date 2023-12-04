#ifndef String_h
#define String_h

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MaxSize 100
#define Col 20
void menu();

void Input( char*& s2);
void Output(char* s);
void OutputArrayString(char **s, int &m);

void deleteEndline(char*& s);

void fixScanf();
void getValueIndex(char*& s, int& n);
void Upper(char*& s, int& n);
void upperName(char*& s, int& n);

void init(char **s, int &m);

void readFile(const char* filename, char** &s, int &m);
void writeFile(const char* filename, char* s1, char* s2);

int checkS1String(char*& s1);
void realForm(char *&s);
void deleteExtraWhiteSpace(char *&s);
void devideFisrtSecondName(char *&s);
int findName(char *&s, char *s1);
int checkOpposite(char *&s);
int getIndexS1InS(char *&s, char *&s1);
void insertStringIndex(char* str, char* strInsert, int index);
void deleleAllChar(char *&s, char c);
#endif
