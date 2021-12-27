/*******************************************************************/
/*********** Date: 24/12/2021 **************************************/
/*********** Project: Stack Data Structure using linked list *******/
/*********** Author: Mohamed Alaa **********************************/
/*********** Version: 1.0 ******************************************/
/*******************************************************************/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define size 10 //define the size of the stack array

typedef struct StackDataStructure
{
	uint8_t u8_value;
	uint8_t* u8_Sptr;
}stackD;//struct of value and pointer to hold next vlaue.

void Push(uint8_t u8_data);//Declaration of push function to add element to stack
uint8_t Pull(void);//Declaration of pull function to remove element to stack
void PrintStack(void);//Declaration of print function to print all elements in the stack

uint8_t* gu8_head=NULL;
int8_t gu8_Top=-1;// signed char to declare the position of the top of the pointer

void main(void)
{
	uint8_t u8_choise,u8_data,u8_flag=0;
	while(1)
	{
		printf("1-Push.\n2-Pull.\n3-Print\n4-Exit.\n");// print options of the program to the user
		printf("Please make your choise:");
		scanf("%d",&u8_choise);//ask user to choose
	
		switch(u8_choise)
		{
			/*if the user select push*/
			case 1:printf("Please enter your data:");
				   scanf("%d",&u8_data);//ask the user to enter data
				   Push(u8_data);//call push function
				   break;
			/*if the user select pull*/
			case 2:u8_data=Pull();//elemenate the element from the stack and keep it in char data
			       if(u8_data!=0)
			       {
				       printf("Pulled Data is:%d\n",u8_data);
			       }
				   else{}
			       break;
			   
			case 3:PrintStack();break;//print all elements in the stack
			
			case 4:u8_flag=1;break;//if the user want to exit program
			
			default: printf("Wrong choice\n");//if the user select out of program choisses
		}
		if(u8_flag==1)//if the user select to exit the pragram
		{
			break;
		}
		else{}
	}
}

/*Implementation of push function*/
void Push(uint8_t u8_data)
{
	stackD* u8_lptr=(stackD*)malloc(sizeof(stackD));
	/*check top is max or not*/
	if(gu8_Top<(size-1))
	{
		gu8_Top++;
		u8_lptr->u8_Sptr=gu8_head;
		gu8_head=u8_lptr;
		u8_lptr->u8_value=u8_data;
	}
	else{printf("Stack over flow\n");}// if the top is max print it is stack over flow
}

/*Implementation of pull function*/
uint8_t Pull(void)
{
	uint8_t u8_FuncReturn;
	stackD* u8_temp=NULL;
	/*Check stack is empty or not*/
	if(gu8_Top>-1)
	{
		u8_temp=gu8_head;
		gu8_head=u8_temp->u8_Sptr;
		u8_FuncReturn=u8_temp->u8_value;
		free(u8_temp);
		gu8_Top--;
	}
	else
	{
		printf("Stack is empty\n");
		u8_FuncReturn=0;
	}
	return u8_FuncReturn;
}

/*Implementation of print the stack elements*/
void PrintStack(void)
{
	uint8_t i;
	stackD* j;
	
	if((gu8_Top>-1)&&(gu8_Top<=(size-1)))
	{
		j=gu8_head;
		for(i=0;i<=gu8_Top;i++)
		{
			printf("%d\n",j->u8_value);
			j=j->u8_Sptr;
		}
	}
	else{printf("Stack is empty\n");}
}