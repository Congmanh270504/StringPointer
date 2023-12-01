#include"string.h"

void menu()
{
	printf("=============================Menu================================\n");
	printf("|| **************************Init***************************** ||\n");
	printf("|| * 1.Nhap S1,S2 va xuat ra man hinh                        * ||\n");
	printf("|| * 2.Doc S1,S2 tu File va xuat ra man hinh                 * ||\n");
	printf("|| **************************Sum***************************  * ||\n");
	printf("|| * 3.Xem chuoi S1 co chua so khong                         * ||\n");
	printf("|| * 5.Tong cac so co chu so dau la chu so le                * ||\n");
	printf("|| * 6.Tong cac so lon hon tri tuyet doi sau no              * ||\n");
	printf("|| * 7.Tong cac phan tu tren dong k                          * ||\n");
	printf("|| * 8.Tong cac phan tu o vi tri bien                        * ||\n");
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
void Input(char*& s1, char*& s2)
{
	printf("Nhap ten cho Character 1: ");
	fgets(s1, MaxSize, stdin);
	fflush(stdin);
	deleteEndline(s1);
	printf("Nhap ten cho Character 2: ");
	fgets(s2, MaxSize, stdin);
	fflush(stdin);
	deleteEndline(s2);
}
void Output(char* s1, char* s2)
{
	printf("Character 1 is: %s\n", s1);
	printf("Character 2 is: %s\n", s2);
}
void getvalueindex(char*& s, int& n)
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
void insertFirstName(char* s1, char* s2, int startPos)
{
	int lenFirstName = strlen(s1), lenSecondName = strlen(s2);
	if (lenFirstName + lenSecondName > MaxSize) return;
	if (startPos > lenFirstName)	startPos = lenFirstName;

	if (startPos < lenFirstName)
	{
		char* temp = new char[lenFirstName - startPos + 1];
		strcpy(temp, s1 + startPos);
		puts(temp);

		strcpy(s1 + startPos, s2);
		puts(s1);

		strcpy(s1 + startPos + lenSecondName, temp);
		puts(s1);
	}
	else
	{
		strcpy(s1 + startPos, s2);
		puts(s1);
	}
}
void readFile(const char* filename, char* s1, char* s2)
{
	FILE* fi = fopen(filename, "rt");
	if (!fi)
	{
		printf("Loi mo File!!\n");
		return;
	}

	fgets(s1, MaxSize, fi);
	fgets(s2, MaxSize, fi);
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
int checkS1String(char*& s1)
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
