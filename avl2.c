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


void check(struct node* t,struct node* temp)
{                               //function to check if tree is unbalanced

    
int flag=0;
   if(t==NULL)                 //return for NULL node
    return;
    
    else if(abs((height(t->left)-height(t->right)))<=1) 
    {           
                //balance factor = height(left sub-tree) - height(right sub-tree)
                //for a node to be balanced 
                //balance factor must be in { -1, 0, 1 }

        check(t->left,temp);         //check further nodes
        check(t->right,temp);
    }

    else
    {
                //if node is unbalanced put its value in the unbalanced_nodes array
        // unbalanced_nodes[k++]=t->data;
        temp=t;
    flag=1;
        check(t->left,temp);         //check further elements
        check(t->right,temp);

    }    
    if(flag==0)
    temp=NULL;
}
void insert(struct node* t,int x)
{
    // struct node* t=(struct node*)malloc(sizeof(struct node));
    // t=rt;

    if(t)
    {
        if(t->data<x)
        {
            if(t->right)
            insert(t->right,x);
            else
            {
                t->right=newnode(x);
            }
            
        }
        else
        {
            if(t->left)
            insert(t->left,x);
            else
            {
                t->left=newnode(x);
            }
            
        }
        
    }
    else 
    {
        t=newnode(x);
    }

}
int k=0;
char arr[2];
void search(struct node* rt, int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t=rt;
    // while(t->data!=x)
    // {
        if(x>t->data)
        {
            // t=t->right;
            
            arr[k++]='R';
            printf("R ");
            if(k>2)
            return;
            search(t->right,x);
        }
        // else if(x<t->data)
        // {
        //     // t=t->left;
        //     arr[k++]='L';
        //     printf("L ");
        //     if(k>=2)
        //     return;
        //     search(t->left,x);
        // }
    // }
    // printf("\n");
}
void anti_clock(struct node* t)
{
    int flag=0;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(!t->right->left)
    {
        
            new=t->right->left;
        t->right->left=NULL;
        flag=1;
    }
    t->right->left=t;
    t->right=NULL;
    
    if(flag==1)
    insert(root,new->data);
}
void balance(int* a)
{
    root=newnode(a[0]);
    for(int i=1;i<6;i++)
    {
        insert(root,a[i]);
        
        while(1)
        {
        struct node* tempa=(struct node*)malloc(sizeof(struct node));
        check(root,tempa);

        if(tempa==NULL)
            break;

        else
        {
            k=0;
            arr[0]='\0';
            search(tempa,a[i]);
            printf("\n");
            if(arr[0]='R' && arr[1]=='R')
            anti_clock(tempa);
            // else if(type[0]='L' && type[1]=='L')
            // clock(tempa);
            
        }
        }
    }
    
}


void main()                    //main function
{

    int input[]={1,2,3,4,5,6};
    
    printf("\n Type of rotation needed for balancing the given BST are:\n");
    balance(input);

    printf("\n Height of the balanced tree is: %d",height(root)-1);


}