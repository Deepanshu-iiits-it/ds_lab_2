/*-----------------------------------------------------------------------------------------------------------------------
    Coded by DEEPANSHU MITTAL 11912056 I.T.
------------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node{            //structure of the node of the tree
    int data;
    struct node* left;
    struct node* right;
}* root;            //declare root of the tree

struct node* newnode(int x)         //funtion to create a new node of type sruct node
{
    struct node* new=(struct node*)malloc(sizeof(struct node));             //define a new node
   
    new->data=x;                            //initialise the new node with the given value of data
    new->right=NULL;                        //initialise the left and right part of the new node to be NULL
    new->left=NULL;

}

void initialise()                       //function to create the structure of the tree as given in the ques
{

    root=newnode(1);                    //create root of the tree
    root->right=newnode(2);             //create further elements of the tree
    root->right->right=newnode(3);                      
    root->right->right->right=newnode(4);
    root->right->right->right->right=newnode(5);
    root->right->right->right->right->right=newnode(6);

}

/* the tree will be:

        1
         \
          2
           \
            3
             \
              4
               \
                5
                 \
                  6

 as per the data given in the question
*/


int height(struct node* t)              //function to calculate height of any node
{

    if(t==NULL)                         //height of null node will be zero
    return 0;

    else if(t->left==NULL && t->right==NULL)    //height of leaf node will be 1 here
    return 1;

    else
    {
        return(1 + (height(t->left)>height(t->right)?height(t->left):height(t->right)));
        // height= 1+ max(height(left sub-tree),height(right sub-tree))
    }
    
}

//declare an array to store the unbalanced nodes
int unbalanced_nodes[6];
int k=0;            //k is the counter for storing nodes in the array


void check(struct node* t)
{                               //function to check if tree is unbalanced

    if(t==NULL)                 //return for NULL node
    return;
    
    else if(abs((height(t->left)-height(t->right)))<=1) 
    {           
                //balance factor = height(left sub-tree) - height(right sub-tree)
                //for a node to be balanced 
                //balance factor must be in { -1, 0, 1 }

        check(t->left);         //check further nodes
        check(t->right);
    }

    else
    {
                //if node is unbalanced put its value in the unbalanced_nodes array
        unbalanced_nodes[k++]=t->data;

        check(t->left);         //check further elements
        check(t->right);

    }
    
}


void main()                    //main function
{

    initialise();       //function to create the binary tree


    check(root);        //function to check for unbalanced nodes

    if(k>0)
    {               //print unbalanced nodes if k>0

        printf("\n The tree is not balanced.\n The unbalanced nodes are: ");

        for(int i=0;i<k;i++)
        printf("%d ",unbalanced_nodes[i]);

    }
            //else print that the tree is balanced
    else
    {

        printf("\n The tree is a balanced BST");

    }



}