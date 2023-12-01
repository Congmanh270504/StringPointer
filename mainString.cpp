#include"String.h"

int main()
{
	char* s1 = new char[MaxSize];
	char* s2 = new char[MaxSize];
	const char* fi = "input-String.txt";
	const char* fo = "output-String.txt";
	int startPos, choose, check;

	int a = strlen(s1);
	memset(s1, 0, MaxSize);// memory setting ( khoi tao chuoi do vs toan bo gia tri 0 trong bang ma~ ASII)
	memset(s2, 0, MaxSize);

	menu();
	do
	{
		printf("Nhap bai muon lam: ");
		scanf("%d", &choose);
		fixScanf();
		switch (choose)
		{
		case 1:
			Input(s1, s2);
			Output(s1, s2);
			break;
		case 2:
			readFile(fi, s1, s2);
			Output(s1, s2);
		case 3:
			if (s1[0] == '\0' || s2 == '\0')
			{
				printf("Please! Choose option 1,2 or 3 \n ");
			}
			else
			{
				check = checkS1String(s1);
				if (check)
				{
					printf("Trong chuoi khong co chua so!!\n");
				}
				else
				{
					printf("Chuoi co chua so!!\n");
				}

			}

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
