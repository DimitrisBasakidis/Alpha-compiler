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

void free_stack(comment_stack* stack) {
    free(stack);
}

// int main() {
//     comment_stack *stack;
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
