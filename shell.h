<<<<<<< HEAD
#ifndef SHELL_H
#define SHELL_H
=======
#ifndef SHELL
#define SHELL
>>>>>>> jose1

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
<<<<<<< HEAD
 *  struct list - linked list for environmental variables
 *  @var: holds environmental variable string
 *  @next: points to next node
=======
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
>>>>>>> jose1
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* function prototypes */
int prompt(char **env);
<<<<<<< HEAD
void *_realloc(void *p, unsigned int old_size, unsigned int new_size);
size_t get_line(char **str);
int toks_strlen(char *str, int p, char delim);
char *ignore_space(char *s);
char **_strtok(char *str, char *delim);
char **c_strtok(char *str, char *delim);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _cd(char **str, list_t *env, int num);
int _built_in(char **tok, list_t *env, int num, char **cmd);
void non_interactive(list_t *env);
char *_which(char *str, list_t *env);
int _exit_(char **str, list_t *env, int num, char **cmd);
int _execve(char **str, list_t *env, int n);
void free_ptr_ptr(char **str);
void free_linked_list(list_t *head);
int p_env(char **s, list_t *env);
char *get_env(char *str, list_t *env);
list_t *env_linked_list(char **env);
ssize_t print_list(list_t *list);
list_t *add_node_t_end(list_t **head, char *str);
int delete_nodeint_at_index(list_t **head, unsigned int index);
int _unset_env(list_t **env, char **str);
int _set_env(list_t **env, char **str);
int find_env(list_t *env, char *str);
void _notfound(char *s, int c_n, list_t *env);
void can_not_cd_to(char *s, int c_n, list_t *env);
void forbid_num(char *s, int c_n, list_t *env);
=======
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t get_line(char **str);
int t_strlen(char *str, int pos, char delm);
char *ignore_space(char *str);
char **_str_tok(char *str, char *delm);
char **c_str_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _cd(char **str, list_t *env, int num);
int built_in(char **token, list_t *env, int num, char **command);
void non_interactive(list_t *env);
char *_which(char *str, list_t *env);
int __exit(char **s, list_t *env, int num, char **command);
int _execve(char *argv[], list_t *env, int num);
void free_double_ptr(char **str);
void free_linked_list(list_t *list);
int _env(char **str, list_t *env);
char *get_env(char *str, list_t *env);
list_t *env_linked_list(char **env);
list_t *add_end_node(list_t **head, char *str);
size_t print_list(list_t *h);
int delete_nodeint_at_index(list_t **head, int index);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
int find_env(list_t *env, char *str);
void not_found(char *str, int num, list_t *env);
void cant_cd_to(char *str, int c_n, list_t *env);
void illegal_number(char *str, int c_n, list_t *env);
>>>>>>> jose1
char *int_to_string(int num);

#endif
