#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <poll.h>

int main(int argc, char *argv[])
{

     int fd = 0;
     char buf[11];
     int ret, pret;

     struct pollfd fds[1];

     int timeout = 10000;
     while(1){

          fds[0].fd = 0;
          fds[0].events = 0;
          fds[0].events |= POLLIN;

          pret = poll(fds, 1, timeout);

          printf("event trigger or time out, event = %d\n", fds[0].events);
          
          if(pret == 0){
               printf("timeout, ret = %d, buf = %s\n", ret, buf);

          } else{
               memset( (void *) buf, 0, 11);
               ret = read(fd, (void *) buf, 10);
               printf("event trigger, ret = %d, fd = %d\n", ret, fd);
               
               if(ret != -1){
                   printf("   buf = %s\n", buf);
     	     }
          } 
     } 
     

     return 0;

}
