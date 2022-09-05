#ifndef SHELL
#define SHELL

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
 *  * struct list - linked list for environmental variables
 *   * @var: holds environmental variable string
 *    * @next: points to next node
 *     */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* function prototypes */
int prompt(char **);
void *_realloc(void *, unsigned int, unsigned int);
size_t get_line(char **);
int t_strlen(char *str, int pos, char delm);
char *ignore_space(char *);
char **_str_tok(char *str, char *delm);
char **c_str_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _cd(char **str, list_t *env, int num);
int _built_in(char **, list_t *, int, char **);
void non_interactive(list_t *env);
char *_which(char *str, list_t *env);
int _exit_(char **, list_t *, int, char **);
int _execve(char **, list_t *, int);
void free_ptr_ptr(char **);
void free_linked_list(list_t *list);
int p_env(char **, list_t *);
char *get_env(char *, list_t *);
list_t *env_linked_list(char **);
list_t *add_end_node(list_t **head, char *str);
size_t print_list(list_t *h);
int delete_nodeint_at_index(list_t **head, int index);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
int find_env(list_t *env, char *str);
void _notfound(char *s, int, list_t *);
void can_not_cd_to(char *, int, list_t *);
void illegal_num(char *, int, list_t *);
char *int_to_string(int);

#endif
