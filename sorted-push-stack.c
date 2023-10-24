/*Maintain a sorted push so that the stack is always maintained in sorted order*/
// #include <stdio.h>
// #define maxsize 3
// void main()
// {
//     int arr[maxsize];
//     int min[1];
//     int top=-1;
//     int min_top=-1;
//     int ele;
//     //it push is choice
//     printf("Enter the element\n");
//     scanf("%d",&ele);
//     if(top==-1)
//     {
//         arr[top+1]=ele;
//     }
//     else if(arr[top]>ele)
//     {
//         int item=arr[top];
//         arr[top]=ele;
//         arr[top+1]=item;
//         top++;
//     }
// }


// #include <stdio.h>
// #define maxsize 3
// int push(int arr[],int top,int min[],int min_top)
// {
//     if(top<maxsize-1)
//     {
//         // int ele;
//         // printf("Enter element to be pushed\n");
//         // scanf("%d",&ele);
//         // arr[top+1]=ele;
//         // top++;//7 6 2
//         int ele;
//         printf("Enter the element\n");
//         scanf("%d",&ele);
//         if(top==-1)
//         {
//             arr[top+1]=ele;
//             top++;
//         }
//         else
//         {
//             // for(int i=0;i<=top;i++)
//             // {
//                 int n=top;
//                 while(n!=-1)
//                 {
//                     if(arr[n]>ele)
//                     {
//                     int item=arr[n];
//                     min[min_top]=item;
//                     min_top++;
//                     }
//                     n--;
//                 }
//                     arr[n]=ele;
//                     top++;
//                     // if(arr[n]<ele)
//                     // {
//                         if(min_top!=-1)
//                         {
//                             arr[top+1]=min[min_top];
//                             min_top--;
//                             top++;
//                         }
//                     // }
//                 // int item=arr[n];
//                 // arr[top]=ele;
//                 // arr[top+1]=item;
//             // }
//             // top++;
//         }
//     }
//     else
//     {
//         printf("Element can't be pushed\n");
//     }
//     return top;
// }
// int pop(int arr[],int top)
// {
//     if(top!=-1)
//     {
//         printf("Element poped is %d\n",arr[top]);
//         top=top-1;
//     }
//     else
//     {
//         printf("Empty\n");
//     }
// }
// void peek(int arr[],int top)
// {
//     if(top!=-1)
//         printf("Top element is %d \n",arr[top]);
//     else
//         printf("Empty\n");
// }
// void display(int arr[],int top)
// {
//     if(top!=-1)
//     {
//         for(int i=0;i<=top;i++)
//         {
//             printf("%d \n",arr[i]);
//         }
//     }
//     else
//         printf("Empty\n");
// }
// void main()
// {
//     int arr[maxsize];
//     int top=-1;
//     int min[maxsize];
//     int min_top=-1;
//     int choice;
//     char ch='y';
//     while(ch=='y')
//     {
//         printf("Enter 1 to push\n2 to pop\n3to peek\n4to display\n");
//         scanf("%d",&choice);
//         switch(choice)
//         {
//             case 1:
//             top=push(arr,top,min,min_top);
//             break;
//             case 2:
//             top=pop(arr,top);
//             break;
//             case 3:
//             peek(arr,top);
//             break;
//             case 4:
//             display(arr,top);
//             break;
//             default:
//             printf("Invalid choice\n");
//         }
//         printf("Do you wish to continue enter y to continue n to stop\n");
//         scanf(" %c",&ch);
//     }
// }


// #include <stdio.h>
// #define maxsize 3
// int push(int arr[],int top,int min[],int min_top)
// {
//     if(top+min_top+1<maxsize-1)//top+1<maxsize
//     {
//         int ele;
//         printf("Enter the element\n");
//         scanf("%d",&ele);
//         if(top==-1)
//         {
//             arr[top+1]=ele;
//             top++;
//         }
//         else
//         {
//                 int n=top;
//                 while(n!=-1)
//                 {
//                     if(arr[n]>ele)
//                     {
//                     int item=arr[n];
//                     min[min_top+1]=item;
//                     min_top++;
//                     }
//                     n--;
//                 }
//                 arr[n]=ele;
//                 top=n;
//                 if(min_top!=-1)
//                 {
//                     arr[top+1]=min[min_top];
//                     min_top--;
//                     top++;
//                 }
//         }
//     }
//     else
//     {
//         printf("Element can't be pushed\n");
//     }
//     return top;
// }
// int pop(int arr[],int top)
// {
//     if(top!=-1)
//     {
//         printf("Element poped is %d\n",arr[top]);
//         top=top-1;
//     }
//     else
//     {
//         printf("Empty\n");
//     }
// }
// void peek(int arr[],int top)
// {
//     if(top!=-1)
//         printf("Top element is %d \n",arr[top]);
//     else
//         printf("Empty\n");
// }
// void display(int arr[],int top)
// {
//     if(top!=-1)
//     {
//         for(int i=0;i<=top;i++)
//         {
//             printf("%d \n",arr[i]);
//         }
//     }
//     else
//         printf("Empty\n");
// }
// void main()
// {
//     int arr[maxsize];
//     int top=-1;
//     int min[maxsize];
//     int min_top=-1;
//     int choice;
//     char ch='y';
//     while(ch=='y')
//     {
//         printf("Enter 1 to push\n2 to pop\n3to peek\n4to display\n");
//         scanf("%d",&choice);
//         switch(choice)
//         {
//             case 1:
//             top=push(arr,top,min,min_top);
//             break;
//             case 2:
//             top=pop(arr,top);
//             break;
//             case 3:
//             peek(arr,top);
//             break;
//             case 4:
//             display(arr,top);
//             break;
//             default:
//             printf("Invalid choice\n");
//         }
//         printf("Do you wish to continue enter y to continue n to stop\n");
//         scanf(" %c",&ch);
//     }
// }


// #include <stdio.h>
// #define maxsize 3

// int push(int arr[], int top, int min[], int min_top) {
//     if (top < maxsize - 1) {
//         int ele;
//         printf("Enter the element: ");
//         scanf("%d", &ele);

//         // Push elements from min stack to main stack if they are greater than the new element.
//         while (min_top >= 0 && min[min_top] > ele) {
//             top++;
//             arr[top] = min[min_top];
//             min_top--;
//         }

//         // Push the new element to the main stack.
//         top++;
//         arr[top] = ele;

//         return top;
//     } else {
//         printf("Element can't be pushed\n");
//         return top;
//     }
// }

// // The rest of your code remains the same.

// int main() {
//     int arr[maxsize];
//     int top = -1;
//     int min[maxsize];
//     int min_top = -1;
//     int choice;
//     char ch = 'y';

//     while (ch == 'y') {
//         printf("Enter 1 to push\n2 to pop\n3 to peek\n4 to display\n");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 top = push(arr, top, min, min_top);
//                 break;
//             case 2:
//                 // Implement pop logic here.
//                 break;
//             case 3:
//                 // Implement peek logic here.
//                 break;
//             case 4:
//                 // Implement display logic here.
//                 break;
//             default:
//                 printf("Invalid choice\n");
//         }

//         printf("Do you wish to continue? Enter 'y' to continue, 'n' to stop\n");
//         scanf(" %c", &ch);
//     }

//     return 0;
// }



// #include <stdio.h>
// #define maxsize 3

// int push(int arr[], int top, int min[], int min_top) {
//     if (top < maxsize - 1) {
//         int ele;
//         printf("Enter the element: ");
//         scanf("%d", &ele);

//         // Push elements from min stack to main stack if they are greater than the new element.
//         while (min_top >= 0 && min[min_top] > ele) {
//             top++;
//             arr[top] = min[min_top];
//             min_top--;
//         }

//         // Push the new element to the main stack.
//         top++;
//         arr[top] = ele;

//         return top;
//     } else {
//         printf("Element can't be pushed. Stack is full.\n");
//         return top;
//     }
// }

// void pop(int arr[], int* top, int min[], int* min_top) {
//     if (*top >= 0) {
//         printf("Element popped is %d\n", arr[*top]);
//         (*top)--;

//         // If min stack is not empty and the popped element matches the top of the min stack, pop from min stack too.
//         if (*min_top >= 0 && min[*min_top] == arr[*top + 1]) {
//             (*min_top)--;
//         }
//     } else {
//         printf("Empty stack. Cannot pop.\n");
//     }
// }

// void peek(int arr[], int top) {
//     if (top >= 0) {
//         printf("Top element is %d\n", arr[top]);
//     } else {
//         printf("Empty stack. No top element.\n");
//     }
// }

// void display(int arr[], int top) {
//     if (top >= 0) {
//         printf("Stack elements: ");
//         for (int i = 0; i <= top; i++) {
//             printf("%d ", arr[i]);
//         }
//         printf("\n");
//     } else {
//         printf("Empty stack.\n");
//     }
// }

// int main() {
//     int arr[maxsize];
//     int top = -1;
//     int min[maxsize];
//     int min_top = -1;
//     int choice;
//     char ch = 'y';

//     while (ch == 'y') {
//         printf("Enter 1 to push\n2 to pop\n3 to peek\n4 to display\n");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 top = push(arr, top, min, min_top);
//                 break;
//             case 2:
//                 pop(arr, &top, min, &min_top);
//                 break;
//             case 3:
//                 peek(arr, top);
//                 break;
//             case 4:
//                 display(arr, top);
//                 break;
//             default:
//                 printf("Invalid choice\n");
//         }

//         printf("Do you wish to continue? Enter 'y' to continue, 'n' to stop\n");
//         scanf(" %c", &ch);
//     }

//     return 0;
// }




