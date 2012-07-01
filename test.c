/**
 * \brief Circular Queue Logic Test Program<br>
 *			Implementes the examples to show how to use the 
 *			Circular Queue Implementations
 * \file test.c
 *
 * \author Abhijit Bose( info@adharlabs.in ) 
 *        A.D.H.A.R Labs (http://adharlabs.in) 
 *		      http://m8051.blogspot.com
 *
 * \version 0.0 - First Creation - 01,JULY,2012<br>
 *
 * \par License		: Creative Commons Attribution-ShareAlike 3.0 
 *						Unported License.
 * Software License Agreement<br>
 * http://creativecommons.org/licenses/by-sa/3.0/legalcode
 *
 * DISCLAIMER:
 * THIS SOFTWARE IS PROVIDED IN AN &quot;AS IS&quot; CONDITION. <br>
 * NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING,<br>
 * BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY <br>
 * AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.<br>
 * AUTHOR SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL,<br>
 * INCIDENTAL OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 */
/*-----------------------------------------------------------*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include "cq.h"

#define MAX 5
uint8_t dir[MAX],prn[MAX];
uint8_t temp[MAX]={0x11,0x22,0x33,0x44,0x55};
cqueue_t cqn;
int main()
{
	int ch=1,dt;
	uint16_t i,sz;
	uint8_t data;
	
	#ifndef WIN32
	system("clear");
	#else
	system("cls");
	#endif
	if(cqueue_init(&cqn,dir,MAX)!=STATUS_SUCCESS)
	{
		printf("\n Error in Initializing ");
		exit(1);
	}	
	while(ch!= 0)
	{
		printf("\n ");
		printf("\n 1. Circular Queue INSERT ");
		printf("\n 2. Circular Queue DELETE ");
		printf("\n 3. Circular Queue DISPLAY");
		printf("\n 4. Circular Queue Move");
		printf("\n 5. Circular Queue Move Into Queue(Excess)");
		printf("\n 6. Circular Queue Move Into Queue(Correct)");
		printf("\n 0. EXIT\n");

		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		fflush(stdin);
		switch(ch)
		{
			case 1:
				 printf("\n Enter the Data to be inserted: ");
				 scanf("%d",&dt);
				 fflush(stdin);
				 data = dt & 0x0FF;
				 dt = cqueue_push(&cqn,data);
				 if(dt!=STATUS_SUCCESS)
				 {
					 printf("\n Could not Insert data Due to %d status",
					 dt);
				 }
				 ch=0;
				 break;
			case 2:
				if(cqueue_empty(&cqn)==STATUS_SUCCESS)
					printf("\nqueue is empty\n");
				else
				{
					if(cqueue_pop(&cqn,&data)==STATUS_SUCCESS)
						printf("\n the deleted element is: 0x%02X",data);
					else
						printf("\n Error in Receiving Data \n");
				}
				break;
			case 3:
				if(cqueue_empty(&cqn)==STATUS_SUCCESS)
					printf("\nqueue is empty");
				else
				{
				  for(i=0;i<cqn.max;i++)prn[i]=0;
				  if(cqueue_copydata(&cqn,prn,&sz,cqn.max)==STATUS_SUCCESS)
				  {
					  for(i=0;i<sz;i++)
					  printf("\n (%2d)= 0x%02X",i+1,prn[i]);
				  }
				}
				break;
			case 4:
				if(cqueue_empty(&cqn)==STATUS_SUCCESS)
					printf("\nqueue is empty");
				else
				{
				  for(i=0;i<cqn.max;i++)prn[i]=0;
				  if(cqueue_movedata(&cqn,prn,&sz,cqn.max)==STATUS_SUCCESS)
				  {
					  printf("\n Size Copied: %d",sz);
					  for(i=0;i<sz;i++)
					  printf("\n (%2d)= 0x%02X",i+1,prn[i]);
				  }
				}
				break;
			case 5:
				printf("\n The following Data would be copied into Queue:");
				printf("\n uint8_t temp[5]={0x11,0x22,0x33,0x44,0x55};");
				printf("\nStatus would be 3 as only 4 bytes can be inserted");
				dt = cqueue_movetoqueue(&cqn,temp,&sz,cqn.max);
				printf("\n Data Copied: %d",sz);
				printf("\n Status Returned: %d",dt);
				break;
			case 6:
				printf("\n The following Data would be copied into Queue:");
				printf("\n uint8_t temp[5]={0x11,0x22,0x33,0x44,0x55};");
				printf("\nStatus would be 0 as only 4 bytes to insert");
				dt = cqueue_movetoqueue(&cqn,temp,&sz,cqn.max-1);
				printf("\n Data Copied: %d",sz);
				printf("\n Status Returned: %d",dt);
				break;
			}
		}
	getchar();
	return 0;
}