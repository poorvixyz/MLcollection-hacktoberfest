#include<stdio.h>
#include<conio.h>
void main()
{ 
int data[11],item,i,loc=1,n,mid;
int beg=0,end=1;
clrscr();

printf("Enter number of element in the list");
scanf("%d",&n);
printf("Enter elements of the list \n");
for(i=0;i<n;i++)
{
printf("Elements %d",i+1);
scanf("%d",&data[i]);
}
printf("Enter element to be searched");
scanf("%d", &item);
end=n-1;
mid=int((beg-end)/2);
while(beg<=end& data[mid]!=item);
{
if(item < data[mid])
end=mid-1;
else
beg=mid+1;
mid=int((beg+end)/2);
}
if(data[mid]==item)
{
loc=mid;
printf("item found at location %d", loc+1);
else
printf("item not found");
}
getch();
}
