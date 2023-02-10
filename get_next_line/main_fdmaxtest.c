# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>


int main(){
  int t;

  for(;;){
    t = open("TEST.txt", O_RDONLY);
    if (t < 0){
      perror("open");
      exit(1);
    }
    printf("%d: ok\n", t);
  }
}
// d apres test max open simultane semble = 1048575
// Preferable d utiliser FOPEN_MAX ou 1024