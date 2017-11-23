//
// Created by and22 on 11/22/2017.
//

#ifndef DIRMONCLIENT_CONFFILE_H
#define DIRMONCLIENT_CONFFILE_H
//struct corresponding to a line in configuration file
typedef struct conf_line {
    //directory path to monitor
    char* directory;
    //linked list pointer
    struct conf_line* next;
} conf_line, *pconf_line;

/**
 * Read conf file line per line
 * @param conf_file
 * @return pconf_line to first element of file
 */
pconf_line read_conf_file(FILE* conf_file);
/**
 * Return length of a pconf_line linked list
 * @param start
 * @return int length
 */
int pconf_line_list_length(pconf_line start);
#endif //DIRMONCLIENT_CONFFILE_H
