#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
struct node {
   struct node *left,*right;
   int val, val1;
};
typedef struct node node;
node * addElement(node * root, int x);
node * addRandomElement(node *, int, int);

/* Write your custom functions here */
struct result {
    int height;
    int diameter;
};
typedef struct result result;


result recurse(node *root){
    result res;
    if (root == NULL) {
        res.height = 0;
        res.diameter = 0;
    } else {
        result res1 = recurse(root->left);
        result res2 = recurse(root->right);
        res.height = 1+max(res1.height, res2.height);
        res.diameter = max(max(res1.diameter, res2.diameter), 1+res1.height+res2.height);
    }
    return res;
}
    
int diameterOfTree(node * root) {
/* For your reference
  struct node {
   struct node *left,*right;
   int val;
};
*/
    result res = recurse(root);
    return res.diameter;
}

int main(){
   
   FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
   node * root = NULL;
   int a[1000],K,i = 0,j = 0;
   int isBst = 0; scanf("%d",&isBst);    
   
   scanf("%d",&K);
   for( j = 0; j < K;j++ ) {
       scanf("%d",&a[i++]);    
   }

   for( i = 0; i < K;i++ ){
       if( !isBst ){            
           root = addRandomElement(root,a[i],i);
       } else {
           root = addElement(root,a[i]);
       }            
   }
   fprintf(f, "%d\n", diameterOfTree(root));
   fclose(f);
   
return 0;
}
node * addElement(node * root, int x ){
   if( root == NULL ) {
       root = (node *) (malloc(sizeof(node))); 
       root->val = x;root->val1 = -1;
               root->left = NULL; root->right = NULL;
       return root;
   }
   if( x < root->val ) {
        root->left = addElement(root->left,x);
   }
   else {
       root->right = addElement(root->right,x);                            
   }
   return root;
}

node * addRandomElement(node *root, int x, int index){
   if( root == NULL ) {
       root = (node *) (malloc(sizeof(node))); 
       root->val = x;root->val1 = -1;
               root->left = NULL; root->right = NULL;
               return root;
   }

   if( index <=2 ){
       root->left = addRandomElement(root->left,x,index);
   } else {
       root->right = addRandomElement(root->right,x,index);
   }

   return root;
}