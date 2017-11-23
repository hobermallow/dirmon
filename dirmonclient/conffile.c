//
// Created by and22 on 11/22/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "conffile.h"
/**
 * Function that reads from a file pointer the configuration
 * and return in a dedicated struct list
 * @param conf_file
 * @return directory struct list
 */
pconf_line read_conf_file(FILE* conf_file) {
    ssize_t read;
    size_t len = 0;
    char** line = NULL;
    pconf_line ret = NULL, ptr = NULL;
    // iterating over file lines
    while ((read = getline(line, &len, conf_file)) != -1) {
        // first iteration
        if(ret == NULL) {
            ret = (pconf_line) malloc(sizeof(conf_file));
            ptr = ret;
        }
        // allocating new struct
        else {
            ptr->next = (pconf_line) calloc(1, sizeof(conf_file));
            ptr = ptr->next;
        }
        // copying directory path
        ptr->directory = calloc(sizeof(char), len);
        memcpy(ptr->directory, line, len);
    }
    //returning first element of the list
    return ret;
}

int pconf_line_list_length(pconf_line start) {
    if(start == NULL)
        return 0;
    else
        return pconf_line_list_length(start->next)+1;
}
