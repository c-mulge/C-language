#include<stdio.h>
#include<stdlib.h>
#define maxsz 50
struct node
{
  int info;
  struct node *left;
  struct node *right;
};

int
isright (struct node *root)
{
  return root->right != NULL;
}

int
isleft (struct node *root)
{
  return root->left != NULL;
}

struct node * maketree (int value)
{
  struct node *temp;
  temp = (struct node *) malloc (sizeof (struct node));
  temp->info=value;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void
setleft (struct node *root, int value)
{
  if (isleft (root))
    {
      printf ("Left subtree is already exist\n");
      exit (1);
    }
  root->left = maketree(value);
}

void
setright (struct node *root, int value)
{
  if (isright (root))
    {
      printf ("right sub tree already exist\n");
      exit (1);
    }
  root->right = maketree(value);
}
struct node *bst (int a[], int n)
{
  struct node *tree = maketree(a[0]);
  struct node *p = NULL;
  int i;
  for (i = 1; i < n; i++)
    {
      p = tree;
      while (1)
	    {
	      if (p->info<=a[i])
	      {
	        if (isright (p))
		        p = p->right;
	        else
		      {
		        setright (p, a[i]);
		        break;
		      }
	      }
	      else
	      {
	        if (isleft (p))
		        p = p->left;
          else
		      {
		        setleft (p,a[i]);
		        break;
		      }
	      }
	    }
    }
  return tree;
}

void preorder(struct node *root)
{
  if(root==NULL) return;
  printf("%d ",root->info);
  preorder(root->left);
  preorder(root->right);
}

void inorder(struct node *root)
{
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ",root->info);
  inorder(root->right);
}

void postorder(struct node *root)
{
  if(root==NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->info);
}


int main()
{
  int n, i;
  struct node *root = NULL;

  printf("Enter how much size you want: ");
  scanf("%d", &n);

  int a[maxsz];
  for (i = 0; i < n; i++)
    {
      printf("Enter number: ");
      scanf("%d", &a[i]);
    }

  root = bst(a, n);
  printf("\nPreorder: ");
  preorder(root);
  printf("\nInorder: ");
  inorder(root);
  printf("\nPostorder: ");
  postorder(root);

  return 0;

}