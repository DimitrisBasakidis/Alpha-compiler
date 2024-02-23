#ifndef COMMENT_STACK  
#define COMMENT_STACK

typedef struct comment_t {
    unsigned int start_line;
    unsigned int end_line;
    struct comment_t *next;
} comment_t;

typedef struct comment_stack {
    comment_t *top;  
} comment_stack;

comment_stack *create_stack(void);

int is_empty(comment_stack* stack);

comment_stack *insert_comment(comment_stack *stack, unsigned int start_line, unsigned int end_line);

comment_t *pop_comment(comment_stack *stack, unsigned int end_line, int flag);

void free_stack(comment_stack *stack);

void print(comment_stack *stack);

#endif
