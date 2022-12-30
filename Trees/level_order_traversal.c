#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *right;
    struct Node *left;
};

struct Node *front = NULL;
struct Node *rear = NULL;



void enq(struct Node *temproot)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->right = NULL;
    temp->left = temproot;
    temp->data = 'Z';

    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->right = temp;
        rear = temp;
    }
}

struct Node *deq(void)
{
    struct Node *temp = front;
    if (front == NULL)
    {
        printf("The queue is empty!\n");
    }
    else if (rear == front)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->right;
    }
    struct Node *next = (temp == NULL) ? NULL : temp->left;
    free(temp);
    return next;
}


/*===============Binary Tree Section===============*/

struct Node *newNode(char x)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->right = NULL;
    temp1->left = NULL;
    return temp1;
}

struct Node *Insert(struct Node *root, char x)
{
    if (root == NULL)
    {
        root = newNode(x);
    }
    else if (x <= root->data)
    {
        root->left = Insert(root->left, x);
    }

    else
    {
        root->right = Insert(root->right, x);
    }
    return root;
}

void LevelOrder(struct Node *root)
{
    struct Node *temproot = root;

    while (temproot != NULL)
    {
        printf("%c ", temproot->data);
        if (temproot->left != NULL)
        {
            enq(temproot->left);
        }
        if (temproot->right != NULL)
        {
            enq(temproot->right);
        }
        temproot = deq();
    }
    putchar('\n');
}


int main(){
    /*Code To Test the logic
	  Creating an example tree
	            1
			   / \
			  2   3
			 / \   \
			4   5   6
    */
	struct Node *root = NULL;
    root = Insert(root, 'F');
    root = Insert(root, 'B');
    root = Insert(root, 'C');
    root = Insert(root, 'D');
    root = Insert(root, 'E');
    root = Insert(root, 'G');
    root = Insert(root, 'A');
    root = Insert(root, 'H');
    root = Insert(root, 'I');
    LevelOrder(root);

    return 0;
}