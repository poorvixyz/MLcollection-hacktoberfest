#include<iostream.h>
#include<conio.h>
void main()
{ 
  int i,j,a[3][3],b[3][3],c[3][3];

  clrscr();

 cout<<"ENter First Matrice"<<'\n';

 {
   for(i=0;i<3;i++)
  {
     for(j=0;j<3;j++)
   {
	cin>>a[i][j];
   }
  }
 }

 cout<<"Enter Second MAtrice"<<'\n';

 {
   for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
   {
    cin>>b[i][j];
   }
  }
 }
cout<<"Resultant Matrice"<<'\n';

 for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
   {
c[i][j]=a[i][j]+b[i][j];
     }
   }

for(i=0;i<3;i++)
  {cout<<'\n';

  for(j=0;j<3;j++)
   {cout<<'\t';

   cout<<c[i][j];

  }
}
getch();
}