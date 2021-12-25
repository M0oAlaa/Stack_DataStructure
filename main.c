/*******************************************************************/
/******************** Date: 24/12/2021 *****************************/
/******************** Project: Stack Data Structure ****************/
/******************** Author: Mohamed Alaa *************************/
/******************** Version: 1.0 *********************************/
/*******************************************************************/

#include<stdio.h>
#include<stdint.h>

#define size 10

void Push(uint8_t u8_data);
uint8_t Pull(void);
void PrintStack(void);

uint8_t gu8arr_Stackarr[size],gu8_Top=-1;

void main(void)
{
	uint8_t u8_choise,u8_data,u8_flag=0;
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
			
			case 4:u8_flag=1;break;
			
			default: printf("Wrong choice");
		}
		if(u8_flag==1)
		{
			break;
		}
		else{}
	}
}

void Push(uint8_t u8_data)
{
	if(gu8_Top<(size-1))
	{
		gu8_Top++;
		gu8arr_Stackarr[gu8_Top]=u8_data;
		printf("top=%d\n",gu8_Top);
	}
	else{printf("Stack over flow\n");}
}

uint8_t Pull(void)
{
	uint8_t FuncReturn;
	if(gu8_Top>-1)
	{
		FuncReturn=gu8arr_Stackarr[gu8_Top];
		gu8_Top--;
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
	uint8_t i;
	if((gu8_Top>-1)&&(gu8_Top<=(size-1)))
	{
		for(i=0;i<=gu8_Top;i++)
		{
			printf("%d\n",gu8arr_Stackarr[i]);
		}
	}
	else{printf("Stack is empty\n");}
}