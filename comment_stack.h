#ifndef COMMENT_STACK  
#define COMMENT_STACK

typedef struct comment_t {
    unsigned int start_line;
    unsigned int end_line;
    struct comment_t *next;
} comment_t;

typedef struct stack_t {
    comment_t *top;  
} stack_t;

stack_t *create_stack(void);

int is_empty(stack_t* stack);

stack_t *insert_comment(stack_t *stack, unsigned int start_line, unsigned int end_line);

comment_t *pop_comment(stack_t *stack, unsigned int end_line, int flag);

void free_stack(stack_t *stack);

void print(stack_t *stack);

#endif