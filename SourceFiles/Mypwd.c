#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define PATH_SIZE 10



int main()
{

    int counter = 0;
    char *buff = (char*) calloc(PATH_SIZE, sizeof(char));
    if(buff)//if buff is not equal NULL
    {
	 while (1)
        {
            getcwd(buff, (PATH_SIZE + counter));
            if (ERANGE == errno)
            {
                counter += 10;
                buff = (char*) realloc(buff, (PATH_SIZE + counter) * sizeof(char));
                errno = 0;
            }
            else
            {
                break;
            }
    	}

    }
    else
    {
	write(1, "Failed\n", 7);
    }

    write(1, buff, strlen(buff));
    write(1, "\n", 1);


    free(buff);

    return 0;
}
