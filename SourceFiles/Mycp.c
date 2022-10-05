#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    char buff[100];
    int RetVal = 1;
    int dest_fd = open(argv[2], O_CREAT | O_WRONLY);
    if(-1 == dest_fd)
    {
		write(1, "Failed To Open Or Create Dest File\n", 35);
	}
	else
	{
		 
		int src_fd  = open(argv[1], O_RDONLY);
		if(-1 == src_fd)   
		{
			write(1, "Failed To Open Src File\n", 25);
		}
		else
		{
		         while( ( RetVal = read(src_fd, buff, 100) ) != 0 )
				 {		 
				 	write(dest_fd, buff, RetVal);
				 }
		}


		close(dest_fd);
		close(src_fd );
    }

    return 0;
}
