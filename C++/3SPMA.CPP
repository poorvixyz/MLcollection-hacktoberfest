#include<stdio.h>
#include<conio.h>
struct sparse
{ int arr[3][3];
}s;
void main()
{
int i,j, count=0, coun=0;
clrscr();
printf ("Input element \n");
for(i=0;i<3;i++)
{ for(j=0;j<3;j++)
 { scanf("%d", &s.arr[i][j]);
 }
}
for(i=0;i<3;i++)
{ for (j=0;j<3;j++)
 { printf("%d", s.arr[i][j]);
  printf("\t");
 }
 printf("\n");
 }
 for (i=0;i<3;i++)
 { for (j=0;j<3;j++)
 { if(s.arr[i][j]==0)
 { count++;
 }
 else
 { coun++;
 }
 }}
 if(count>coun)
 { printf("Matrix is sparse \n");
} else
 { printf(" Matrix is normal \n");
 }
 getch();
 }