#include "get_next_line.h"
char    *get_next_line(int fd)
{
    static char     *store;
    char    buffer[BUFFER_SIZE + 1];//to prevent seg fualt
    ssize_t     read_bytes; // ssize_t is signed as read can retrun -1

    if (fd < 0 || BUFFER_SIZE <=0)
        return (NULL);
    while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)// read exploicitlly copies inot buffer 
    //it returns the number of bytes read and since it starts a t 0 the number of bytes read will be the '\0'
    {
        buffer[read_bytes] = '\0';
        *store = 'test'; 
        // todo add the buffer to the static var
        //check if \n is there 
        // return upthe string before \n
        // delete the returnd line including the /n from the static var.
    }
}