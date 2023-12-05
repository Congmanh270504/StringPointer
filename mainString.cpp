#include"String.h"

int main()
{

	char string1[] = "   tRaN   COnG   mAnH ";
	char* s1 = string1;
	char* s2 = new char[MaxSize];
	char *tmp = new char[MaxSize];
	const char* fi = "input-String.txt";
	const char* fo = "output-String.txt";
	int startPos, choose, check, index, c, m;
	memset(s1, 0, MaxSize);// memory setting ( khoi tao chuoi do vs toan bo gia tri 0 trong bang ma~ ASII)
	memset(s2, 0, MaxSize);
	char **s = NULL;

	menu();
	do
	{
		printf("Nhap bai muon lam: ");
		scanf("%d", &choose);
		fixScanf();
		switch (choose)
		{
		case 1:
			Input(s2);
			Output(s2);
			break;
		case 2:
			readFile(fi, s, m);
			OutputArrayString(s, m);
			break;
		case 3:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				if (checkString(s1))
				{
					printf("Trong chuoi khong co chua so!!\n");
				}
				else
				{
					printf("Chuoi co chua so!!\n");
				}
			}
			break;
		case 4:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				realForm(s1);
				printf("Sau khi chinh sua: %s\n", s1);

			}
			break;
		case 5:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				deleteExtraWhiteSpace(s1);
				printf("Sau khi xoa trang thua:%s\n", s1);
				/*printf("Count: %d\n", strlen(s1));*/
			}
			break;
		case 6:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{

			}
			break;
		case 7:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				devideFisrtSecondName(s1);
			}
			break;
		case 8:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				printf("Nhap chuoi can tim: ");
				fgets(tmp, MaxSize, stdin);
				fflush(stdin);
				realForm(tmp);
				deleteEndline(tmp);
				check = findName(s1, tmp);
				if (check)
				{
					printf("Co ten \"%s\" trong chuoi \"%s\"!!\n", tmp, s1);
				}
				else
				{
					printf("Ten khong ton tai trong chuoi \"%s\"!!\n", s1);
				}
			}
			break;
		case 9:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				/*
				printf("Nhap chuoi: ");
				fgets(tmp, MaxSize, stdin);
				fflush(stdin);

				deleteEndline(tmp);
				check = checkOpposite(tmp);
				if (check)
				{
					printf("Chuoi \"%s\" doi xung!!\n", tmp);
				}
				else
				{
					printf("Chuoi \"%s\" khong doi xung!!\n", tmp);
				}*/

				check = checkOpposite(s1);
				if (check)
				{
					printf("Chuoi \"%s\" doi xung!!\n", s1);
				}
				else
				{
					printf("Chuoi \"%s\" khong doi xung!!\n", s1);
				}
			}
			break;
		case 10:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				printf("Nhap chuoi: ");
				fgets(tmp, MaxSize, stdin);
				fflush(stdin);
				deleteEndline(tmp);

				if (strstr(s1, tmp) == NULL)
				{
					strcat(s1, tmp);
					printf("Chuoi sau khi duoc them:%s\n", s1);
				}
				else
				{
					/*check = getIndexS1InS(s1, tmp);
					if (check != -1)
					{
						printf("Vi tri xuat hien cua \"%s\" trong chuoi \"%s\" la: %d\n", tmp, s1, check);
					}*/
					getIndexS1InS(s1, tmp);
				}
			}
			break;
		case 11:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				printf("Nhap chuoi: ");
				fgets(tmp, MaxSize, stdin);
				fflush(stdin);
				deleteEndline(tmp);
				do
				{
					printf("Nhap vi tri can chen: ");
					scanf("%d", &index);
					if (index < 0)
					{
						printf("Khong the chen tai vi tri %d !!\n", index);
					}
				} while (index < 0);
				insertStringIndex(s1, tmp, index);
				printf("Chuoi S1 sau khi chen: %s\n", s1);
			}
			break;
		case 12:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				printf("Nhap ki tu can xoa: ");
				scanf("%c", &c);
				deleleAllChar(s1, c);
				Output(s1);
			}
			break;
		case 13:
			if (s == NULL)
			{
				printf("Please! Choose option 2 \n ");
			}
			else
			{
				printf("Chuoi khong chua ky so la:\n");
				getStringNoNumber(s, m);
			}
			break;
		case 14:
			
				Input(s1);
				Input(s2);
				countTransformation(s1, s2);
				printf("Chuoi S1 sau khi thay doi: ");
				puts(s1);
			break;
		case 30:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				writeFile(fo, s1, s2);
				printf("Ghi File thanh cong!!\n");
			}
			break;
		case 0:
			

			printf("HAVE A NICE DAY SIR!!\n");
			break;
		default:
			break;
		}
	} while (choose != 0);
	_getch();
}
