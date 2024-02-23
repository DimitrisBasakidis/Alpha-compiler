#include "comment_stack.h"
#include <stdio.h>
#include <stdlib.h>

stack_t *create_stack(void) {
    stack_t *new_stack = malloc(sizeof(struct stack_t));
    new_stack->top = NULL;

    return new_stack;
}

int is_empty(stack_t* stack) {
    return stack->top == NULL;
}

stack_t *insert_comment(stack_t* stack, unsigned int start_line, unsigned int end_line) {
    comment_t* new_comment = (comment_t*)malloc(sizeof(comment_t));
    if (new_comment == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    new_comment->start_line = start_line;
    new_comment->end_line = end_line;
    new_comment->next = stack->top;

    stack->top = new_comment;
}

comment_t* pop_comment(stack_t* stack, unsigned int end_line, int flag) {
    comment_t* comment = NULL;

    if (is_empty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    comment = stack->top;
    stack->top = comment->next;
    comment->next = NULL;
     
    if (flag == 0) {
        comment->end_line = end_line;
    }

    return comment;
}

void free_stack(stack_t* stack) {
    free(stack);
}

// int main() {
//     stack_t *stack;
//     stack = create_stack(stack);

//     stack = insert_comment(stack, 1);
//     stack = insert_comment(stack, 6);
//     stack = insert_comment(stack, 11);

//     displayStack(stack);

//     comment_t* comment = pop(stack, 14);
//     printf("Popped Comment: Start Line: %u, End Line: %u\n", comment->start_line, comment->end_line);
//     free(comment);

//      comment = pop(stack, 15);
//     printf("Popped Comment: Start Line: %u, End Line: %u\n", comment->start_line, comment->end_line);
//     free(comment);
    
//      comment = pop(stack, 20);
//     printf("Popped Comment: Start Line: %u, End Line: %u\n", comment->start_line, comment->end_line);
//     free(comment);

//     free_stack(stack);

//     return 0;
// }
