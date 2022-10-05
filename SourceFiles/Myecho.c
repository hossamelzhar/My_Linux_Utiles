#include <unistd.h>
#include <string.h>



int main(int argc, char* argv[])
{
    int index = 0;

    for(index = 1; index<argc; index++)
	{
	    write(1, argv[index], strlen(argv[index]));
	    write(1, " ", 1);
	}
    write(1, "\n", 1);

    return 0;
}
