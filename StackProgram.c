/*******************************************************************/
/******************** Date: 24/12/2021 *****************************/
/******************** Project: Stack Data Structure ****************/
/******************** Author: Mohamed Alaa *************************/
/******************** Version: 1.0 *********************************/
/*******************************************************************/

#include<stdio.h>
#include<stdint.h>

#define size 10 //size of the stack

/*Declaration of some functions*/
void Push(uint8_t u8_data);
uint8_t Pull(void);
void PrintStack(void);
uint8_t* balancedparentheses(uint8_t* u8arr_expression);
/*global stack array and its top*/
uint8_t gu8arr_Stackarr[size];
int8_t gu8_Top=-1;

void main(void)
{
	uint8_t u8arr_expression[20],*u8_status=NULL;
	printf("Please enter your script: ");
	gets(u8arr_expression);//ask user to enter the string
	u8_status=balancedparentheses(u8arr_expression);//call balancedparentheses function and save the address of its return in status pointer
	printf("%s",u8_status);//print status
}

uint8_t* balancedparentheses(uint8_t* u8arr_expression)
{
	/*Declare some local variables "iteration variables, count parentheses"*/
	uint8_t u8_i,u8_j,u8_count1=0,u8_count2=0;
	int8_t z=-1;
	/*check the expression element by element*/
	for(u8_i=0;(*(u8arr_expression+u8_i))!='\0';u8_i++)
	{
		/*select all parentheses and push them into stack*/
		if((*(u8arr_expression+u8_i)=='{')||(*(u8arr_expression+u8_i)=='(')||(*(u8arr_expression+u8_i)==')')||(*(u8arr_expression+u8_i)=='}'))
			{
				Push(*(u8arr_expression+u8_i));
			}
	}
	/*define the number of iterations we need to count the parentheses*/
	u8_j=((gu8_Top+1)/2)-1;
	for(u8_i=0;u8_i<=u8_j;u8_i++)
	{
		z++;gu8_Top--;
		if((gu8arr_Stackarr[gu8_Top+1]=='}' && gu8arr_Stackarr[z]=='{') || (gu8arr_Stackarr[gu8_Top+1]=='{' && gu8arr_Stackarr[z]=='}'))
		{
			u8_count1=1;
		}
		else if((gu8arr_Stackarr[gu8_Top+1]==')' && gu8arr_Stackarr[z]=='(') || (gu8arr_Stackarr[gu8_Top+1]=='(' && gu8arr_Stackarr[z]==')'))
		{
			u8_count2=1;
		}
	}
	/*check if the parentheses balanced or not*/
	if((u8_count1==1)&&(u8_count2==1))
	{
		return "Balanced";
	}
	else{return "UnBalanced";}
}
/*Implementation of push function*/
void Push(uint8_t u8_data)
{
	if(gu8_Top<(size-1))
	{
		gu8_Top++;
		gu8arr_Stackarr[gu8_Top]=u8_data;
	}
	else{printf("Stack over flow\n");}
}
/*Implementation of pull function*/
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
