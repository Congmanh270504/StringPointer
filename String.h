#ifndef String_h
#define String_h

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MaxSize 100
void menu();

void Input(char*& s1, char*& s2);
void Output(char* s1, char* s2);

void deleteEndline(char*& s);

void fixScanf();
void getValueIndex(char*& s, int& n);
void Upper(char*& s, int& n);
void upperName(char*& s, int& n);

void readFile(const char* filename, char* s1, char* s2);
void writeFile(const char* filename, char* s1, char* s2);

int checkS1String(char*& s1);
void insertFirstName(char* s1, char* s2, int startPos);
#endif
