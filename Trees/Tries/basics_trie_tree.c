#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHAR 256

typedef struct trienode trienode;

struct trienode{
    trienode *children[NUM_CHAR];
    bool is_terminal;
};

trienode *create_trinenode(){
    trienode *temp = (trienode*)malloc(sizeof(trienode));
    temp->is_terminal = false;
    for(int i = 0; i < NUM_CHAR; i++){
        temp->children[i] = NULL;
    }
    return temp;
}


// If the word is inserted it will return true false if the word is already present 
// in it
// Double pointer because sometimes we may actualy want to change the root
bool insert_in_trie(trienode **root, char *signedtext){
    if(*root == NULL){
        *root = create_trinenode();
    }
    // To avoid the issues we will convert the text to unsigned character pointer
    unsigned char *text = (unsigned char*)signedtext;
    trienode *temp = *root; // going to be used for traversing tree and it will start at root
    int length_of_text = strlen(signedtext);
    for(int i = 0; i < length_of_text; i++){
        if(temp->children[text[i]] == NULL){// Child for that symbol is NULL
            // Create a new node
            temp->children[text[i]] = create_trinenode();
        }
        // Move temp to its child
        temp = temp->children[text[i]];
    }
    if(temp->is_terminal){
        return false; // the word is alrady in trie
    }
    else{
        temp->is_terminal = true;
        return true;
    }
}

void print_trie_recursive(trienode *node,unsigned char *prefix, int length){
    unsigned char new_prefix[length + 2];
    memcpy(new_prefix,prefix,length);
    new_prefix[length + 1] = 0;

    if(node->is_terminal){
        printf("WORD: %s\n",prefix);
    }
    
    for(int i = 0; i < NUM_CHAR; i++){
        if(node->children[i] != NULL){
            new_prefix[length] = i;
            print_trie_recursive(node->children[i],new_prefix,length + 1);
        }
    }
}

bool searchtrie(trienode *root, char *signedtext){
    unsigned char *text = (unsigned char*)signedtext;
    int length = strlen(signedtext);
    trienode *temp = root;
    
    for(int i = 0; i < length; i++){
        if(temp->children[text[i]] == NULL){
            return false;
        }
        temp = temp->children[text[i]];
    }
    return temp->is_terminal;
}


bool node_has_children(trienode *node){
    if(node == NULL){
        return false;
    }
    for(int i = 0; i < NUM_CHAR; i++){
        if(node->children[i] != NULL){
            // there is at least one child
            return true;
        }
    }
    return false;
}

trienode *deletestring_rec(trienode *node, unsigned char *text, bool *deleted){
    if(node == NULL){
        return node;
    }
    if(*text == '\0'){// We are going to remove each character from the string
        if(node->is_terminal){
            node->is_terminal = false;
            *deleted = true;

            if(node_has_children(node) == false){// Node with no children
                free(node);
                node = NULL;
            }
        }
        return node;
    }
    node->children[text[0]] = deletestring_rec(node->children[text[0]], text + 1, deleted);
    // text + 1 will start the string one character after and will be done resursively
    if(*deleted && node_has_children(node) == false && node->is_terminal == false){
        free(node);
        node = NULL;
    }
    return node;
}

bool deletestring(trienode **root, char *signedtext){
    unsigned char *text = (unsigned char*)signedtext;
    bool result = false;
    if(root == NULL){
        return false;
    }
    *root = deletestring_rec(*root, text, &result);
    return result;
}

void print_trie(trienode *root){
    if(root == NULL){
        printf("Trie is empty \n");
        return;
    }
    print_trie_recursive(root,NULL,0);
}

int main(){
    trienode *root = NULL;
    insert_in_trie(&root, "KIT");
    insert_in_trie(&root, "CATTLE");
    insert_in_trie(&root, "KIN");
    insert_in_trie(&root, "CAT");
    insert_in_trie(&root, "HAPPY");
    print_trie(root);

    printf("Searching for CATTLE: %d\n", searchtrie(root, "CATTLE"));
    printf("Searching for CAT: %d\n", searchtrie(root, "CAT"));
    printf("Searching for KITTEN: %d\n", searchtrie(root, "KITTEN"));


    deletestring(&root,"KIN");
    deletestring(&root, "CAT");
    print_trie(root);
}