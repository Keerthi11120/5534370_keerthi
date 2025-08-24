#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[100];  
    
    scanf("%s", s);   
    struct Node {
    int freq;
    char data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(char data, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Decode function
void decode_huff(struct Node* root, char* s) {
    struct Node* current = root;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0')
            current = current->left;
        else
            current = current->right;

        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root;
        }
    }
    printf("\n");
}
    printf("%s\n", s);

    return 0;
}