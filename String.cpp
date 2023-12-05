#include"string.h"

void menu()
{
	printf("=============================Menu================================\n");
	printf("|| **************************Init***************************** ||\n");
	printf("|| * 1.Nhap S1,S2 va xuat ra man hinh                        * ||\n");
	printf("|| * 2.Doc mang chuoi tu File va xuat ra man hinh            * ||\n");
	printf("|| **************************Format*************************** ||\n");
	printf("|| * 3.Xem chuoi S1 co chua so khong                         * ||\n");
	printf("|| * 4.Chinh ve dung chuan form                              * ||\n");
	printf("|| * 5.Xoa khoang trang thua                                 * ||\n");
	printf("|| * 7.Chia cat chuoi ho va ten                              * ||\n");
	printf("|| * 8.Tim ten trong chuoi ho ten                            * ||\n");
	printf("|| * 9.Kiem tra chuoi co doi xung khong                      * ||\n");
	printf("|| * 10.Tim vi tri cua S2 trong S1, khong co thi chen cuoi   * ||\n");
	printf("|| * 11.Chen chuoi S2 vao chuoi S1 tai vi tri X              * ||\n");
	printf("|| * 12.Xoa ki tu X trong chuoi S1                           * ||\n");
	printf("|| * 13.Xuat chuoi khong chua cac ky so                      * ||\n");
	printf("|| * 14.Dem so lan thay doi cua chuoi S1 thanh chuoi S2      * ||\n");
	printf("|| **************************WriteFile************************ ||\n");
	printf("|| * 30.Ghi mang so phan so tu File                          * ||\n");
	printf("|| * 0.Thoat chuong trinh			             * ||\n");
	printf("|| ***************************End***************************** ||\n");
	printf("=================================================================\n");
}
void deleteEndline(char*& s)
{
	int len = strlen(s);
	if (s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
	}
}
void fixScanf()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}
void Input(char*& s)
{
	printf("Name Character: ");
	fgets(s, MaxSize, stdin);
	fflush(stdin);
	deleteEndline(s);
}
void Output(char* s)
{
	printf("Character is: %s\n", s);
}
void OutputArrayString(char **s, int &m)
{
	printf("Chuoi mang:\n");
	for (int i = 0; i < m; i++)
	{
		printf("%s\n", s[i]);
	}
}
void getValueIndex(char*& s, int& n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%c\n", s[i]);
	}
}
void upper(char*& s, int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 97)
		{
			s[i] -= 32;
		}
	}
}

void uppername(char*& s, int& n)
{
	if (s[0] >= 97)
	{
		s[0] -= 32;
	}
	for (int i = 1; i < n; i++)
	{
		if (s[i - 1] == ' ' && s[i] >= 97)
		{
			s[i] -= 32;
		}

	}
}

void init(char **&s, int &m)
{
	//s = (char **)malloc(m * sizeof(char **));
	s = new char*[m];
	for (int i = 0; i < m; i++)
	{
		s[i] = new char[MaxSize];
	}
}
void readFile(const char* filename, char** &s, int &m)
{
	FILE* fi = fopen(filename, "rt");
	if (!fi)
	{
		printf("Loi mo File!!\n");
		return;
	}
	fscanf(fi, "%d\n", &m);
	init(s, m);
	for (int i = 0; i < m; i++)
	{
		fgets(s[i], MaxSize, fi);
		fflush(stdin);
		deleteEndline(s[i]);
		//fscanf(fi, "%s", &s[i]);
	}
	fclose(fi);
	printf("Doc File thanh cong\n");
}
void writeFile(const char* filename, char* s1, char* s2)
{
	FILE* fo = fopen(filename, "wt");
	if (!fo)
	{
		printf("Loi mo File!!\n");
		return;
	}
	/*fprintf(fo, "%s", s1);
	fprintf(fo, "%s", s2);*/
	fputs(s1, fo);
	fputs(s2, fo);
	fclose(fo);
}

void deleteChar(char *&s, int index)
{
	int len = strlen(s);
	for (int i = index; i < len; i++)
	{
		s[i] = s[i + 1];
	}
	s[len - 1] = '\0';
}
void deleteExtraWhiteSpace(char *&s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			deleteChar(s, i);
			i--;
		}
		else if (s[i] == '\0')
		{
			break;
		}
	}
	if (s[0] == ' ')
	{
		deleteChar(s, 0);
	}
	if (s[strlen(s) - 1] == ' ')
	{
		deleteChar(s, strlen(s));
	}
}
void realForm(char *&s)
{
	int len = strlen(s);
	if (s[0] >= 'a' && s[0] <= 'z')
	{
		s[0] -= 32;
	}
	for (int i = 1; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' && s[i - 1] == ' ')
		{
			s[i] -= 32;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i - 1] == ' ')
			{
				continue;
			}
			s[i] += 32;
		}
	}
}
int  checkString(char*& s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '1' && s[i] <= '9')
		{
			return 0;
		}
	}
	return 1;
}
int  getLastSpace(char *&s)
{
	int len = strlen(s);
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			return i;
		}
	}
	return 0;
}
void devideFisrtSecondName(char *&s)
{
	int startPos = getLastSpace(s);
	int len = strlen(s);
	char *tmp = new char[MaxSize];

	strcpy(tmp, s + startPos + 1);
	for (int i = startPos; i < len; i++)
	{
		s[i] = '\0';
	}
	printf("First name Character:%s\n", tmp);
	printf("Seconde name Character:%s\n", s);
}
int  findName(char *&s, char *s1)
{
	if (strstr(s, s1))
	{
		return 1;
	}
	return 0;
}
int  checkOpposite(char *&s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] != s[len - 1 - i])
		{
			return 0;
		}
	}
	return 1;
}
int  getIndexS1InS(char *&s, char *&s1)
{
	char *p = strstr(s, s1);
	if (p != NULL)
	{
		return p - s;// 
	}
	return -1;
}
void insertStringIndex(char* str, char* strInsert, int index)
{
	int lenStr = strlen(str), lenStrInsert = strlen(strInsert);
	if (lenStr + lenStrInsert > MaxSize) return;
	if (index > lenStr)	index = lenStr;

	if (index < lenStr)
	{
		char* temp = new char[lenStr - index + 1];
		strcpy(temp, str + index);// copy cua chuoi str tu vi tri index vao cai tmp
		// Luu vet
		strcpy(str + index, strInsert);// copy cai chuoi can them vao cai vi tri

		strcpy(str + index + lenStrInsert, temp);// gan cai luu vet vao cuoi chuoi sau khi chen 
	}
	else
	{
		//strcpy(str + index, strInsert);
		strcat(str, strInsert);
		puts(str);
	}
}
void deleleAllChar(char *&s, char c)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == c)
		{
			deleteChar(s, i);
		}
	}
}
void getStringNoNumber(char **&s, int &m)
{
	for (int i = 0; i < m; i++)
	{
		if (checkString(s[i]))
		{
			puts(s[i]);
		}
	}
}
void countTransformation(char *&s1, char *&s2)
{
	int insertChar = 0, deleteChar = 0, changeChar = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (strcmp(s1, s2) == 0)
	{
		printf("2 Chuoi giong nhau!!\n");
		return;
	}
	if (strlen(s1) < strlen(s2))
	{
		insertChar = strlen(s2) - strlen(s1);
		for (int i = 0; i < len1; i++)
		{
			if (s1[i] != s2[i])
			{
				s1[i] = s2[i];
				changeChar++;
			}
		}
	}
	else
	{
		deleteChar = strlen(s1) - strlen(s2);
		for (int i = 0; i < len2; i++)
		{
			if (s1[i] != s2[i])
			{
				s1[i] = s2[i];
				changeChar++;
			}
		}
		s1[len1 - deleteChar] = '\0';
	}
	
	printf("So lan them ki tu: %d\nSo lan xoa ki tu: %d\nSo lan thay doi ki tu: %d\n", insertChar, deleteChar, changeChar);
}
void deletePointer(int **&s,int m, char *&s1, char *&s2, char *&tmp)
{
	delete s1;
	delete s2;
	delete tmp;
	for (int i = 0; i < m; i++)
	{
		delete s[i];
	}
	delete s;
}
