// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <math.h>

// // typedef struct node
// // {
// //     int coeff;
// //     struct node* next;
// //     int exp;
// // } nd;

// // nd* head1, *head2, *head3;
// // nd *ptr1, *ptr2, *ptr3;


// // nd* input(nd* head)
// // {
// //     char ch;
// //     printf("Do you wish to add terms y or n\n");
// //     scanf(" %c", &ch);
    
// //     while (ch == 'y')
// //     {
// //         nd* new_node = (nd*)malloc(sizeof(nd)); 
// //         printf("Enter coefficient\n");
// //         scanf("%d", &new_node->coeff);
// //         printf("Enter exponent\n");
// //         scanf("%d", &new_node->exp);
// //         new_node->next = NULL;

// //         if (head == NULL)
// //         {
// //             head = new_node;
// //         }
// //         else
// //         {
// //             nd* temp = head;
// //             while (temp->next != NULL)
// //             {
// //                 temp = temp->next;
// //             }
// //             temp->next = new_node;
// //         }

// //         printf("Do you wish to add terms y or n\n");
// //         scanf(" %c", &ch);
// //     }
// //     return head;
// // }


// // void display(nd* head)
// // {
// //     if (head == NULL)
// //     {
// //         printf("No terms\n");
// //     }
// //     else
// //     {
// //         nd* temp = head;
// //         printf("%dx^%d ", head->coeff, head->exp);
// //         temp = temp->next;
// //         while (temp != NULL)
// //         {
// //             printf("+ %dx^%d ", temp->coeff, temp->exp);
// //             temp = temp->next;
// //         }
// //         printf("\n");
// //     }
// // }


// // nd* add_poly(nd* head1, nd* head2)
// // {
// //     ptr1 = head1;
// //     ptr2 = head2;
// //     ptr3 = head3;

    
// //     if (head1 == NULL && head2 == NULL)
// //     {
// //         printf("Both polynomials have no terms\n");
// //     }
// //     else
// //     {
// //         while (ptr1 != NULL || ptr2 != NULL) 
// //         {
// //             nd* new_node = (nd*)malloc(sizeof(nd));
// //             new_node->next = NULL;

// //             if (ptr1 != NULL && ptr2 != NULL) 
// //             {
// //                 if (ptr1->exp == ptr2->exp)
// //                 {
// //                     new_node->exp = ptr1->exp;
// //                     new_node->coeff = ptr1->coeff + ptr2->coeff;
// //                     ptr1 = ptr1->next;
// //                     ptr2 = ptr2->next;
// //                 }
// //                 else if (ptr1->exp > ptr2->exp)
// //                 {
// //                     new_node->exp = ptr1->exp;
// //                     new_node->coeff = ptr1->coeff;
// //                     ptr1 = ptr1->next;
// //                 }
// //                 else if (ptr1->exp < ptr2->exp)
// //                 {
// //                     new_node->exp = ptr2->exp;
// //                     new_node->coeff = ptr2->coeff;
// //                     ptr2 = ptr2->next;
// //                 }
// //             }
// //             else if (ptr1 != NULL)
// //             {
// //                 new_node->exp = ptr1->exp;
// //                 new_node->coeff = ptr1->coeff;
// //                 ptr1 = ptr1->next;
// //             }
// //             else if (ptr2 != NULL)
// //             {
// //                 new_node->exp = ptr2->exp;
// //                 new_node->coeff = ptr2->coeff;
// //                 ptr2 = ptr2->next;
// //             }

// //             if (head3 == NULL)
// //             {
// //                 head3 = new_node;
// //                 ptr3 = head3;
// //             }
// //             else
// //             {
// //                 ptr3->next = new_node;
// //                 ptr3 = ptr3->next;
// //             }
// //         }
// //     }

// //     return head3;
// // }

// // // Main function
// // int main()
// // {
// //     printf("Polynomial 1\n");
// //     head1 = input(head1);
// //     display(head1);

// //     printf("Polynomial 2\n");
// //     head2 = input(head2);
// //     display(head2);

// //     head3 = add_poly(head1, head2);
// //     printf("Result is \n");
// //     display(head3);

// //     return 0;
// // }


// // // //Reverse the content of a queue using stack –Implement using SLL
// // // #include <stdio.h>
// // // #include <stdlib.h>
// // // typedef struct node
// // // {
// // //     int data;
// // //     struct node* next;
// // // }nd;
// // // nd* front;
// // // nd* end;
// // // nd* head;
// // // nd* create_node()
// // // {
// // //     nd* new_node=(nd*)malloc(sizeof(nd));
// // //     new_node->next=NULL;
// // //     printf("Enter node data\n");
// // //     scanf("%d",&new_node->data);
// // //     return new_node;
// // // }
// // // void enqueue()
// // // {
// // //     nd* new_node=create_node();
// // //     if(front==NULL)
// // //     {
// // //         front=new_node;
// // //         end=new_node;
// // //     }
// // //     else
// // //     {
// // //         end->next=new_node;
// // //         end=new_node;
// // //     }
// // // }
// // // void display()
// // // {
// // //     if(front==NULL)
// // //     {
// // //         printf("Oops Empty\n");
// // //     }
// // //     else
// // //     {
// // //         nd* temp=front;
// // //         while(temp!=NULL)
// // //         {
// // //             printf("%d ",temp->data);
// // //             temp=temp->next;
// // //         }
// // //         printf("\n");
// // //     }
// // // }
// // // // void push(nd* nod)
// // // // {
// // // //     if(head==NULL)
// // // //     {
// // // //         head=nod;
// // // //     }
// // // //     else
// // // //     {
// // // //         nd* temp=head;
// // // //         while(temp->next!=NULL)
// // // //         {
// // // //             temp=temp->next;
// // // //         }
// // // //         if(temp->next==NULL)
// // // //         {
// // // //             temp->next=nod;
// // // //         }
// // // //     }
// // // // }
// // // nd* push(nd *nod)
// // // {
// // //     if(head==NULL)
// // //     {
// // //         head=nod;
// // //     }
// // //     else
// // //     {
// // //         nod->next=head;
// // //         head=nod;
// // //     }
// // //     return head;
// // // }
// // // void to_stack()
// // // {
// // //     if(front==NULL)
// // //     {
// // //         printf("No elements in queue to perform reversing on\n");
// // //     }
// // //     else
// // //     {
// // //         nd* temp=front;
// // //         while(temp!=NULL)
// // //         {
// // //             head=push(temp);
// // //             temp=temp->next;
// // //         }
// // //     }
// // // }
// // // // void display_stack()
// // // // {
// // // //     if(head==NULL)
// // // //     {
// // // //         printf("Empty\n");
// // // //     }
// // // //     else
// // // //     {
// // // //         nd* temp=head;
// // // //         while(temp!=NULL)
// // // //         {
// // // //             printf("%d ",temp->data);
// // // //         }
// // // //         printf("\n");
// // // //     }
// // // // }
// // // void stack_pop()
// // // {
// // //     if(head==NULL)
// // //     {
// // //         printf("There were no elements to reverse\n");
// // //     }
// // //     else
// // //     {
// // //         nd* temp=head;
// // //         while(temp!=NULL)
// // //         {
// // //             printf("%d ",temp->data);
// // //             temp=temp->next;
// // //         }
// // //         printf("\n");
// // //     }
// // // }
// // // void main()
// // // {
// // //     int op;
// // //     printf("Enter \n1 to enter queue to be reversed\n2 to display queue\n");
// // //     char ch='y';
// // //     while(ch=='y')
// // //     {
// // //         printf("Enter choice 1 or 2\n");
// // //         scanf("%d",&op);
// // //         switch(op)
// // //         {
// // //             case 1:
// // //             enqueue();
// // //             break;
// // //             case 2:
// // //             display();
// // //             break;
// // //         }
// // //         printf("Continue y or n\n");
// // //         scanf(" %c",&ch);
// // //     }
// // //     to_stack();
// // //     //display_stack();
// // //     stack_pop();
// // // }



// // #include <stdio.h>
// // #include <stdlib.h>

// // typedef struct node
// // {
// //     int data;
// //     struct node *left;
// //     struct node *right;
// // } nd;

// // nd *root = NULL;
// // nd *create(nd *root, int data)
// // {
// //     if (root == NULL)
// //     {
// //         nd *new_node = (nd *)malloc(sizeof(nd));
// //         new_node->data = data;
// //         new_node->left = NULL;
// //         new_node->right = NULL;
// //         return new_node;
// //     }
// //     if (data < root->data)
// //     {
// //         root->left = create(root->left, data);
// //     }
// //     else if (data > root->data)
// //     {
// //         root->right = create(root->right, data);
// //     }

// //     return root;
// // }

// // void inorder(nd *root)
// // {
// //     if (root != NULL)
// //     {
// //         inorder(root->left);
// //         printf("%d ", root->data);
// //         inorder(root->right);
// //     }
// // }
// // nd *search(nd *root, int item)
// // {
// //     if (root == NULL)
// //     {
// //         return NULL; // Element not found
// //     }

// //     if (item == root->data)
// //     {
// //         return root;
// //     }
// //     else
// //     {
// //         if (item < root->data)
// //         {
// //             return search(root->left, item);
// //         }
// //         else if (item > root->data)
// //         {
// //             return search(root->right, item);
// //         }
// //     }
// // }
// // void delete(nd *root, int n)
// // {
// // }
// // void findMin(nd* root)
// // {

// // }
// // int main()
// // {
// //     char ch = 'y';
// //     while (ch == 'y')
// //     {
// //         int data;
// //         printf("Enter node data\n");
// //         scanf("%d", &data);
// //         root = create(root, data);
// //         printf("Continue\n");
// //         scanf(" %c", &ch);
// //         while (getchar() != '\n')
// //             ;
// //     }
// //     inorder(root);
// //     printf("Enter node to be deleted\n");
// //     int n;
// //     scanf("%d", &n);
// //     nd *found = search(root, n);
// //     if (found == NULL)
// //     {
// //         printf("No such element\n");
// //     }
// //     else
// //     {
// //         if (found->left == NULL && found->right == NULL)
// //         {
// //             found = NULL;
// //             return found;
// //         }
// //         else if ((found->right != NULL && found->left == NULL) || (found->left == NULL && found->right != NULL))
// //         {
// //             if (found->right == NULL)
// //             {
// //                 nd *temp = found->left;
// //                 found = found->left;
// //                 free(temp);
// //                 return found;
// //             }
// //             else
// //             {
// //                 if (found->left == NULL)
// //                 {
// //                     nd *temp = found->right;
// //                     found = found->right;
// //                     free(temp);
// //                     return found;
// //                 }
// //             }
// //         }
// //         else
// //         {
// //             struct node*temp=findMin(found->right); 
// //             found->data=temp->data; 
// //             found->right=Delete(found->right,temp->data);
// //         }
// //     }
// //     void delete (root, n);
// //     return 0;
// // }

// #include <stdio.h>
// void display(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
// int Partition(int arr[], int lb, int ub)
// {
//     int pivot = arr[lb];
//     int start = lb;
//     int end = ub;
//     while (start <= end)
//     {
//         while (arr[start] <= pivot)
//         {
//             start++;
//         }
//         while (arr[end] >= pivot)
//         {
//             end--;
//         }
//         if (start > end)
//         {
//             int temp = arr[start];
//             arr[start] = arr[end];
//             arr[end] = temp;
//         }
//     }
//     return end;
// }
// int QuickSort(int arr[], int lb, int ub)
// {
//     int loc;
//     if (lb < ub)
//     {
//         loc = Partition(arr, lb, ub);
//         QuickSort(arr, loc + 1, ub);
//         QuickSort(arr, lb, loc - 1);
//     }
// }
// void main()
// {
//     int n;
//     printf("Input size \n");
//     scanf("%d", &n);
//     int arr[n];
//     printf("Enter elements\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("Inputted array\n");
//     display(arr, n);
//     QuickSort(arr, 0, n - 1);
//     printf("Sorted\n");
//     display(arr, n);
// }
