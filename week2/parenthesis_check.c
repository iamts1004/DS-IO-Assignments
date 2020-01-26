#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  struct node
  {
        int data;
        struct node *next;
  };

  struct node *top = NULL;

  struct node* create(int data)
  {
        struct node *p = (struct node *) malloc(sizeof (struct node));
        p->data = data;
        p->next = NULL;
  }


 void open(int data) // for insertion in case of opening bracket.
  {
        struct node *temp, *p = create(data);
        if (top == NULL)
        {
                top = p;
                return;
        }
        temp = top;
        p->next = temp;
        top = p;
  }


  int close() // for deletion in case of closing bracket.
  {
        int data;
        struct node *temp;
        if (top == NULL)
                return -1;
        data = top->data;
        temp = top;
        top = temp->next;
        free (temp);
        return (data);
  }

  int main()
  {
        char str[200];
        int i, f = 0, data = 0;

        printf("Enter an expression: ");
        fgets(str, 200, stdin);
        for (i = 0; i < strlen(str); i++) {
                // if opening bracket, push into stack.
                if (str[i] == '(' || str[i] == '{'
                        || str[i] == '[')
                {
                                open(str[i]);
                                continue;
                }
                if (str[i] == ')' || str[i] == '}' || str[i] == ']')
                    {
                // if closing bracket - pop top from stack.
                        data = close();
                        if ((str[i] == ')' && data != '(') || data == -1 ||
                                (str[i] == '}' && data != '{') ||
                                        (str[i] == ']' && data != '['))
                        {

                                f = 1;
                                break;
                        }

                    }
        }

        if (f == 1 || top != NULL) // if number and format of opening and closing brackets is right then,
                                     // there won't be any element left in the stack.
                printf("Unbalanced Expression. Check Parenthesis and try again.\n");
        else
                printf("Balanced Expression!\n");
        return 0;
  }
