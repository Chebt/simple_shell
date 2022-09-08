#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* if using system getline() */
#define _GETLINE 0
#define _STRTOK 0

#define INFO_FILE	".simple_shell_history"
#define INFO_MAX         4096
extern char **environ;


/**
 * struct list - linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct list
{
	int num;
	char *str;
	struct list *next;
} list_t;

/**
 *struct parseredir - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@error_num: the error code for exit()s
 *@_flag_count: if on count this line of input
 *@file_name: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@pathnode: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@stat: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@read_fd: the fd from which to read line input
 *@count: the history line number count
 */
typedef struct parseredir
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int error_num;
	int _flag_count;
	char *file_name;
	list_t *env;
	list_t *previous;
	list_t *alias;
	char **environ;
	int env_changed;
	int stat;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int read_fd;
	int count;
} parse_t;

#define SPACE_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct built_in - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct built_in
{
	char *type;
	int (*func)(parse_t *);
} built_in_t;

int hsh(parse_t *, char **);
int find_builtin(parse_t *);
void find_cmd(parse_t *);
void fork_cmd(parse_t *);

/* parser.c */
int _cmd(parse_t *, char *);
char *dup_char(char *, int, int);
char *find_path(parse_t *, char *, char *);

/* traverse.c */
int trav(char **);

/* perrors.c */
void er_puts(char *);
int er_putchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string len, cmp cat and start.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *strst_with(const char *, const char *);
char *_strcat(char *, char *);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/*_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* tokenization */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* reallocation of memory */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory freeing */
int c_free(void **);

/* atoi */
int inter_active(parse_t *);
int delim(char, char *);
int is_alphabet(int);
int str_to_int(char *);

/* errors handling and write output */

int _err_atoi(char *);
void print_error(parse_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* built_in functions */
int __exit(parse_t *);
int _cd(parse_t *);
int c_cd(parse_t *);
int _info(parse_t *);
int c_alias(parse_t *);

/* getline functions */
ssize_t get_input(parse_t *);
int _getline(parse_t *, char **, size_t *);
void sigintHandler(int);

/* getenv function*/
void clear_en(parse_t *);
void set_en(parse_t *, char **);
void free_en(parse_t *, int);

/* environ function */
char *_getenv(parse_t *, const char *);
int _env(parse_t *);
int _set_env(parse_t *);
int _unset_env(parse_t *);
int p_env_list(parse_t *);

/* getenv functions */
char **get_environ(parse_t *);
int _unsetenv(parse_t *, char *);
int _setenv(parse_t *, char *, char *);

/* syste info */
char *get_file(parse_t *info);
int write_(parse_t *info);
int read_(parse_t *info);
int build_list(parse_t *info, char *buf, int linecount);
int renum(parse_t *info);

/* linked lists */
ssize_t get_input(parse_t *);
int _getline(parse_t *, char **, size_t *);
void sigintHandler(int);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);

void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* variables */
int is_link(parse_t *, char *, size_t *);
void check_link(parse_t *, char *, size_t *, size_t, size_t);
int replace_alias(parse_t *);
int replace_vars(parse_t *);
int replace_string(char **, char *);

#endif
