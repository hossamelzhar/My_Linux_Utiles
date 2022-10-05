#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "../HeaderFiles/Return_Dest_Path.h"

int main(int argc, char *argv[])
{
    char buff[100];
    char *dest      = NULL;
    int  RetVal     = 1;
    int  index1     = 0;
    int  tempIndex  =-1;
    int  counter    = 0;
    int  index2     = 0;
    int  detector   = 0;
    int  dest_fd    = 0;

	
    if(argc != 3)
    {
    	write(1,"usage: ./m1mv src dest\n", 22);
    	exit(1);
    }
    else
    {
    	int src_fd = open(argv[1], O_RDONLY);
		if (-1 == src_fd) 
		{
			write(1, "Failed To Open The Src File\n", 28);
		} 
		else 
		{
			/*check if argv[2] is a Path */
			if ((argv[2][index1] == '/') || ((argv[2][index1] == '.') && (argv[2][index1 + 1] == '/'))) 
			{
				dest = dest_path(argv[1], argv[2]);
				if(dest == NULL)
				{			
					dest_fd = open(argv[2], O_CREAT | O_RDWR, 0777);
				}
				else
				{
					dest_fd = open(dest, O_CREAT | O_RDWR, 0777);
				}
			}
			else
			{
				dest_fd = open(argv[2], O_CREAT | O_RDWR, 0777);
			}
			
			

			if (-1 == dest_fd) 
			{
				write(1, "Failed To Move The File\n", 25);
			} 
			else 
			{
				/*Set The Buffer Elements By Zero */
				memset(buff, 0, strlen(buff));

				while ((RetVal = read(src_fd, buff, 100)) > 0) 
				{
					write(dest_fd, buff, RetVal);
				}
				
				RetVal = close(src_fd);
				if(-1 == RetVal)
				{
					write(1, "Failed To Close Src File\n", 25);
				}else{}
				
				RetVal = close(dest_fd);
				if(-1 == RetVal)
				{
					write(1, "Failed To Close dest File\n", 25);
				}else{}
				
				// remove The Source File
				RetVal = unlink(argv[1]);
				if (-1 == RetVal) 
				{
					if ((EBUSY == errno) || (EACCES == errno)) 
					{
						write(1, "Failed To Remove Src File\n", 27);
					} else {}

				} else {}
				
			}

		}
    }
	
    

    return 0;
}
