#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000   // enough space for text

typedef struct {
    int type;   // 1 for append, 2 for delete
    char *data; // store deleted string or appended length info
} Operation;

int main() {
    int Q;
    scanf("%d", &Q);

    char *S = malloc(MAX * sizeof(char));
    S[0] = '\0'; // start with empty string

    Operation *stack = malloc(Q * sizeof(Operation));
    int top = -1;

    while (Q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {   // append
            char W[100000];
            scanf("%s", W);
            strcat(S, W);

            // record operation for undo
            top++;
            stack[top].type = 1;
            stack[top].data = malloc(sizeof(char) * (strlen(W) + 1));
            strcpy(stack[top].data, W);

        } else if (type == 2) {   // delete
            int k;
            scanf("%d", &k);
            int len = strlen(S);

            char *deleted = malloc((k + 1) * sizeof(char));
            strcpy(deleted, S + len - k);

            S[len - k] = '\0'; // truncate string

            // record operation
            top++;
            stack[top].type = 2;
            stack[top].data = deleted;

        } else if (type == 3) {   // print
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);

        } else if (type == 4) {   // undo
            if (top >= 0) {
                if (stack[top].type == 1) {
                    // undo append
                    int len = strlen(stack[top].data);
                    int currLen = strlen(S);
                    S[currLen - len] = '\0';
                } else if (stack[top].type == 2) {
                    // undo delete
                    strcat(S, stack[top].data);
                }
                free(stack[top].data);
                top--;
            }
        }
    }

    free(S);
    free(stack);
    return 0;
}