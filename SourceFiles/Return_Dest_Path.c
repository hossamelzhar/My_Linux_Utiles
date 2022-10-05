#include "../HeaderFiles/Return_Dest_Path.h"

char *buff = NULL;
int index1     = 0;
int tempIndex  =-1;
int counter    = 0;
int index2     = 0;
int detector   = 0;

char* dest_path(char *src, char *dest)
{
	if( (NULL == src) || (NULL == dest) )
	{
		/*return NULL*/
	}
	else
	{
		buff = (char*) calloc( (strlen(dest)+30) , sizeof(char));
		if(NULL == buff)
		{
			/*Do NoThing, Return NULL*/
		}
		else
		{

			/*Copy The Path String To The Buffer, To Concatenate It With The File Name */
			while (dest[index2] != '\0') 
			{
				/*Check If The Last Char In Path Is Not '/' */
				if (dest[index2 + 1] == '\0') 
				{
					if (dest[index2] == '/') 
					{
						/*Then The User Did Not Type A File Name At End Of Path*/
						/*Then We Will Use The Buffer, We Will Not Use argv[2] */
						/*Put Detector Here To Continue And Get The File Name*/
						detector = 1;
						
					} 
					else 
					{
						free(buff);
						buff = NULL;
						detector = 0;
						/*if there any thing after last slash, then return NULL*/
						/*its a ful path with file name*/
						break; 
					}
							
				} else{}

					
				buff[index2] = dest[index2];
				index2++;
				
			}
	

			/*Get The File Name */
			index1 = 0;
			while ( (src[index1] != '\0') && (detector == 1) ) 
			{
				/*The Last Slash index will be saved in tempIndex */
				if (src[index1] == '/') 
				{
					tempIndex = index1;
				} else {}
				
				/*Is The Next Char Is Null Termination? *//*Then The Current Char Is The Last Char */
				if (src[index1 + 1] == '\0') 
				{
					/*In The Last cycle in while loop, We Now Have Index of last char in Path String */
					/*tempIndex have The index of The Last Slash '/' */
	
					/*check if the User Entered a File Name In Current Directory */
					if (tempIndex == -1)	//Default Value
					{
						/*Then User Typed The File Name Only */
						counter = 0;
					} 
					else 
					{
						counter = tempIndex + 1;	//index of The First Char After Last Slash
					}

					/*Append The File Name To The Buffer */
					for (counter; counter <= src[index1]; counter++) 
					{
					
						/*Notice That Value Of Index2 is pointed To The Next Place After The Path Name */
						buff[index2] = src[counter];
						index2++;
					}
	
					buff[index2] = '\0';	/*Put NULL Termination */
	
					break;		/*Break while Loop, We Have Made What We Need */
				}
				else
				{
					index1++;
				}

	         	}
        	}
		
	}
	
	return buff;
}
