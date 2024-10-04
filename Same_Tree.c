#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL)
    {
        printf("Same\n");
        return true;
    }

    if(p == NULL || q == NULL )
    {
        printf("Not Same\n");
        return  false;
    }


    if(p->val != q->val )
    {
        printf("Not Same\n");
        return  false;
    }
    return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
    printf("same\n");
}


int main()
{
    struct TreeNode* p = malloc(sizeof(struct TreeNode));
    if(p == NULL)
    {
        printf("Alllocation Failed\n");
        exit(1);
    }

    struct TreeNode* q = malloc(sizeof(struct TreeNode));
    if(q == NULL)
    {
        printf("Alllocation Failed\n");
        exit(1);
    }

    p->val = 1;
    p->right = NULL;
    p->left = NULL;

    q->val = 1;
    q->right = NULL;
    q->left = NULL;

    bool res = isSameTree(p,q);
    printf(res ? "Same\n" : "Not Same\n");
    free(p);
    free(q);
    return 0;
}
