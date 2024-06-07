#include "comment_stack.h"
#include <stdio.h>
#include <stdlib.h>

comment_stack *create_stack(void) {
    comment_stack *new_stack = malloc(sizeof(struct comment_stack));
    new_stack->top = NULL;

    return new_stack;
}

int is_empty(comment_stack* stack) {
    return stack->top == NULL;
}

comment_stack *insert_comment(comment_stack* stack, unsigned int start_line, unsigned int end_line) {
    comment_t* new_comment = (comment_t*)malloc(sizeof(comment_t));
    if (new_comment == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    new_comment->start_line = start_line;
    new_comment->end_line = end_line;
    new_comment->next = stack->top;

    stack->top = new_comment;

    return stack;
}

comment_t* pop_comment(comment_stack* stack, unsigned int end_line, int flag) {
    comment_t* comment = NULL;

    if (is_empty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        return NULL;
    }

    comment = stack->top;
    stack->top = comment->next;
    comment->next = NULL;
     
    if (flag == 0) {
        comment->end_line = end_line;
    }

    return comment;
}

void free_stack(comment_stack* stack) {
    free(stack);
}