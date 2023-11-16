#ifndef MONTY
#define MONTY

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct commons - stuff
 * @n: t
 * @o: t
 * @x: t
 * @y: t
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct commons
{
		int n;
		int o;
		FILE *x;
		char *y;
} commons_t;

extern commons_t comms;

int search_for(char *s, char c);
char *_strtoky(char *s, char *d);
int _strlen(char *s);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);
char **_splitString(char *input, const char *delimiters, int *count);
int check_stuff(char ***s, int buf_size);
int str_cmp(const char *str1, const char *str2);
int is_digit(char *c);

void endall(const char *msg);
void PFS(const char *format, ...);
int process_line(char *s, stack_t **st, unsigned int line_number);
int process_line_cont(int i, int flag, int ind, char **tokens,
	void (*f)(stack_t **stack, unsigned int line_number),
	int needs_completion, stack_t **st, unsigned int line_number);
int get_na(const char *opcode);
void f_d(stack_t **arr);

void process_push(stack_t **stack, unsigned int line_number);
void process_pall(stack_t **stack, unsigned int line_number);
void process_pint(stack_t **stack, unsigned int line_number);

#endif
