/*******************************************************************/
/******************** Date: 24/12/2021 *****************************/
/******************** Project: Stack Data Structure ****************/
/******************** Author: Mohamed Alaa *************************/
/******************** Version: 1.0 *********************************/
/*******************************************************************/

#include<stdio.h>

#define size 10

void Push(char u8_data);
char Pull(void);
void PrintStack(void);

char Stackarr[size],Top=-1;

void main(void)
{
	char u8_choise,u8_data,flag=0;
	while(1)
	{
		printf("1-Push.\n2-Pull.\n3-Print\n4-Exit.\n");
		printf("Please make your choise:");
		scanf("%d",&u8_choise);
		switch(u8_choise)
		{
			case 1:printf("Please enter your data:");
				   scanf("%d",&u8_data);
				   Push(u8_data);
				   break;
			   
			case 2:u8_data=Pull();
			       if(u8_data!=0)
			       {
				       printf("Pulled Data is:",u8_data);
			       }
				   else{}
			       break;
			   
			case 3:PrintStack();break;
			
			case 4:flag=1;break;
			
			default: printf("Wrong choice");
		}
		if(flag==1)
		{
			break;
		}
		else{}
	}
}

void Push(char u8_data)
{
	if(Top<(size-1))
	{
		Top++;
		Stackarr[Top]=u8_data;
		printf("top=%d\n",Top);
	}
	else{printf("Stack over flow\n");}
}

char Pull(void)
{
	char FuncReturn;
	if(Top>-1)
	{
		FuncReturn=Stackarr[Top];
		Top--;
	}
	else
	{
		printf("Stack is empty\n");
		FuncReturn=0;
	}
	return FuncReturn;
}

void PrintStack(void)
{
	char i;
	if((Top>-1)&&(Top<=(size-1)))
	{
		for(i=0;i<=Top;i++)
		{
			printf("%d\n",Stackarr[i]);
		}
	}
	else{printf("Stack is empty\n");}
}