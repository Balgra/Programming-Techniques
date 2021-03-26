#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct  node {
    float data;
    struct node* left;
    struct node* right;
};

struct node* root=NULL;
const float eps = 0.001;

float readNumbers()
{
    float number;
    printf("Enter the float number: ");
    scanf(" %f", &number);
    return number;
}

int checkNumbers(float data, float new_number)
{
    if (fabs(new_number-data) < eps)
        return 0;
    else
        return 1;
}

struct node *search(struct node* roots, float number)
{
    if (checkNumbers(roots->data, number))
    {
        if (roots->data > number)
        {
            if (roots->left == NULL)
            {
                return roots;
            }
            else
                return search(roots->left, number);
        }
        else
        {
            if (roots->right == NULL)
            {
                return roots;
            }
            else
                return search(roots->right, number);
        }
    }
    else
        return NULL;
}
int insert(struct node* found, float number)
{
    if (found == NULL)
        return 0;
    struct  node* points = (struct node*)malloc(sizeof(struct node));

    points->data = number;
    points->left = NULL;
    points->right = NULL;

    if (found->data > number)
    {
        found->left = points;
    }
    else
    {
        found->right = points;
    }
    return 1;
}
void counstructBirTree(int n)
{
    struct node *start = (struct node*)malloc(sizeof(struct node));
    start->data = readNumbers();
    start->left = NULL;
    start->right = NULL;
    root = start;
    n--;
    while (n!=0)
    {
        float nr=readNumbers();
        insert(search(root,nr),nr);
        n--;
    }
}

void printlist(struct node* pointer) //preorder
{
    if (pointer != NULL) {
        printf("%f ", pointer->data);
        printlist(pointer->left);
        printlist(pointer->right);
    }
}

void freeMemory(struct node* pointer)
{
    if(pointer!=NULL)
    {
        freeMemory(pointer->left);
        freeMemory(pointer->right);
        free(pointer);
    }
}

int main()
{   
    int n;
    printf("Enter the number of floating points: ");
    scanf(" %d",&n);
    counstructBirTree(n);
    printlist(root);
    freeMemory(root);
    return 0;
}
