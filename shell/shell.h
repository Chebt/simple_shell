#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 *  struct list - linked list for environmental variables
 *  @var: holds environmental variable string
 *  @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* function prototypes */
int prompt(char **);
void *_realloc(void *, unsigned int, unsigned int);
size_t get_line(char **);
int toks_strlen(char *, int, char);
char *ignore_space(char *);

/* built in functions */
int _built_in(char **, list_t *, int, char **);
char **_strtok(char *, char *);
char **c_strtok(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);


int _cd(char **, list_t *, int);
void non_interactive(list_t *);
char *_which(char *, list_t *);
int _exit_(char **, list_t *, int, char **);
int _execve(char **, list_t *, int);
void free_ptr_ptr(char **);
void free_linked_list(list_t *);
int p_env(char **, list_t *);
char *get_env(char *, list_t *);
list_t *env_linked_list(char **);
list_t *add_node_t_end(list_t **, char *);
ssize_t print_list(list_t *);
int delete_nodeint_at_index(list_t **, unsigned int);
int _unset_env(list_t **, char **);
int _set_env(list_t **, char **);
int find_env(list_t *, char *);
void _notfound(char *, int, list_t *);
void can_not_cd_to(char *, int, list_t *);
void forbid_num(char *, int, list_t *);
char *int_to_string(int);

#endif
