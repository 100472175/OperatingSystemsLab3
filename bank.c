//OS-P3 2022-2023

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include <pthread.h>
#include "queue.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>

#define MAX_OPERATIONS 200
#define OPERATION_SIZE 10000

/**
 * Entry point
 * @param argc
 * @param argv
 * @return
 */

int main (int argc, const char * argv[] ) {
    //Check if arguments number is correct
    if (argc != 6){
        printf("Invalid number of arguments\n");
        return -1;
    }
    int lines;
    lines = atoi(argv[4]);
    if (lines > 200){
        perror("Too many operations requested");
        return -1;
    }
    //Open file with file descriptor
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1){
        printf("Error opening %s\n", argv[1]);
        return -1;
    }
    FILE *file;
    char line[256];

    file = fopen(argv[1], "r");
    if (file) {
        fgets(line, sizeof(line), file);
        // Removes the\n from the EOL (End of line)
        line[strlen(line) - 1] = '\0';
        printf("%s lectura de la primera linea\n", line);
        fclose(file);
    }

    //Get file size
    struct stat list_client_o;
    stat(argv[1], &list_client_ops);

    //Map file
    char *addr;
    addr = mmap(NULL, list_client_ops.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

    //Close file
    close(fd);

    char str = addr[0];
    // Esto te lo lee entero
    for (int i = 0; i < list_client_ops.st_size; i++){
        printf("%c", addr[i]);
    }


    //str = malloc(sizeof(char) * 256);
    //strcpy(str, addr[1]);
    //printf("%d heyy\n", str);

    //2. Reserving the maximum allowed operations, 200
    void *queueu = malloc(sizeof(OPERATION_SIZE) * atoi(line));

    // TODO, too many things




    return 0;
}
