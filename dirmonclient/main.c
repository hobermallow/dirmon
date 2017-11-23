#include <stdio.h>
#include <winsock2.h>

/* dirmon is an application useful to remotely monitor the content of a directory
 * for which the client is registered upon a server program.
 * Usage: dirmon [ -c configuration_file ] COMMAND
 * NOTE: if no configuration file is give, /etc/dirmon/dirmon.conf is read
 */
int main(int argc, const char** argv) {
    //BEGIN VARIABLES SECTION
    // configuration file descriptor
    FILE* configuration_file;
    //END VARIABLES SECTION

    //BEGIN READ CONFIGURATION FILE SECTION

    //configuration file given
    if(argv[1] != NULL && strcmp("-c", argv[1]) == 0) {
        //checking argv[2] is a file
        if(argv[2] == NULL) {
            printf("No configuration file specified\n");
            exit(1);
        }
        else if(access(argv[2], F_OK) == -1) {
            //file doesn't exist
            configuration_file = fopen(argv[2], "w+");
        }
        else {
            //opening custom conf file
            configuration_file = fopen(argv[2], "rw");
        }
        //checking error in opening file
        if(configuration_file == NULL) {
            printf("Error reading ");
        }
    }
    else {
        //opening /etc/dirmon/dirmon.conf
        configuration_file = fopen("/etc/dirmon/dirmon.conf", "w+");
        if(configuration_file == NULL){
            printf("Error reading /etc/dirmon/dirmon.conf\n");
            exit(1);
        }
    }
    //END READ CONFIGURATION FILE SECTION

    //BEGIN READ COMMAND SECTION
    //END READ COMMAND SECTION
    printf("Hello, World!\n");
    return 0;
}