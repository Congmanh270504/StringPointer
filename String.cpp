#include"string.h"

void menu()
{
	printf("=============================Menu================================\n");
	printf("|| **************************Init***************************** ||\n");
	printf("|| * 1.Nhap S1,S2 va xuat ra man hinh                        * ||\n");
	printf("|| * 2.Doc S1,S2 tu File va xuat ra man hinh                 * ||\n");
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
	/*printf("|| **************************Sum***************************  * ||\n");
	printf("|| * 3.Liet ke cac so hoan thien trong mang                  * ||\n");
	printf("|| * 5.Tong cac so co chu so dau la chu so le                * ||\n");
	printf("|| * 6.Tong cac so lon hon tri tuyet doi sau no              * ||\n");
	printf("|| * 7.Tong cac phan tu tren dong k                          * ||\n");
	printf("|| * 8.Tong cac phan tu o vi tri bien                        * ||\n");
	printf("|| **************************Count**************************** ||\n");
	printf("|| * 9.So lan xuat cua gia tri K                             * ||\n");
	printf("|| * 8.Tong cac phan tu o vi tri bien                        * ||\n");
	printf("|| * 10.Dem cac phan tu chan,le,am,duong,nguyen to           * ||\n");
	printf("|| **************************Lised**************************** ||\n");
	printf("|| * 11.Liet ke cac cot co tong nho nhat trong mang 2 chieu  * ||\n");
	printf("|| * 12.Liet ke cac dong co nhieu so hoan thien nhat         * ||\n");
	printf("|| * 13.Liet ke cac dong chi co chan                         * ||\n");
	printf("|| ***************************FindNumber********************** ||\n");
	printf("|| * 14.Tim gia tri xuat hien nhieu nhat trong mang 2 chieu  * ||\n");
	printf("|| * 15.Tim so nguyen to nho nhat trong mang                 * ||\n");
	printf("|| * 16.Tim so lon nhat trong dong K                         * ||\n");
	printf("|| * 17.Tim so nho nhat trong dong K                         * ||\n");
	printf("|| * 18.Tim so lon nhat trong cot  K                         * ||\n");
	printf("|| * 19.Tim so nho nhat trong cot  K                         * ||\n");
	printf("|| ***************************Sort**************************** ||\n");
	printf("|| * 20.Sap xep dong chan tang, dong le giam                 * ||\n");
	printf("|| * 21.Sap xep cot chan tang, cot le giam                   * ||\n");
	printf("|| * 22.Sap xep Zic-Zac                                      * ||\n");
	printf("|| ***************************Delete************************** ||\n");
	printf("|| * 23.Xoa dong K                                           * ||\n");
	printf("|| * 24.Xoa cot  K                                           * ||\n");
	printf("|| * 25.Xoa dong co phan tu X                                * ||\n");
	printf("|| * 26.Xoa cot  co phan tu X                                * ||\n");
	printf("|| ***************************Swap**************************** ||\n");
	printf("|| * 27.Doi vi tri 2 dong i va j                             * ||\n");
	printf("|| * 28.Doi vi tri 2 cot  i va j                             * ||\n");*/
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
void Input(char*& s2)
{
	printf("Nhap ten cho Character 2: ");
	fgets(s2, MaxSize, stdin);
	fflush(stdin);
	deleteEndline(s2);
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

void init(char **s, int &m)
{
	/*
	s = (char**)calloc(m, sizeof(char*));
	for (int i = 0; i < m; i++)
	{
		s[i] = (char*)calloc(MaxSize, sizeof(char));
	}*/
	s = (char **)malloc(m * sizeof(char **));
	for (int i = 0; i < m; i++)
	{
		s[i] = (char*)malloc(MaxSize * sizeof(char));
		strcpy(s[i], "Hello");
		puts(s[i]);
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
		//fscanf(fi, "%s", &s[i]);
	}

	fclose(fi);
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


int  checkS1String(char*& s1)
{
	int len = strlen(s1);
	for (int i = 0; i < len; i++)
	{
		if (s1[i] >= '1' && s1[i] <= '9')
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
	char *p = strstr(s, s1);// tra ve vi tri dau tien cua s1
	/*printf("Dia chi cua s : %p\n", s);
	printf("Dia chi cua s1 : %p\n", s1);
	printf("Dia chi cua p : %p\n", p);
	for (int i = 0; i < strlen(s); i++)
	{
		printf("Dia chi cua s[%d] : %p\n", i, s[i]);

	}*/
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
