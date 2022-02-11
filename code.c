#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int i,ch,j,l,addr=100;
char ex[10], exp[10] ,exp1[10],exp2[10],id1[5],op[5],id2[5];
void pm()
{
     strrev(exp);
     j=l-i-1;
     strncat(exp1,exp,j);
     strrev(exp1);
     printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n",exp1,exp[j+1],exp[j]);
}
void divs()
{
     strncat(exp1,exp,i+2);
     printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,exp[i+2],exp[i+3]);
}
void plus()
{
     strncat(exp1,exp,i+2);
     printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,exp[i+2],exp[i+3]);
}

void main()
{
 while(1)
 {
      printf("\n1.assignment operation \n2.arithmetic operation \n3.Exit program\n");
      scanf("%d",&ch);
           switch(ch)
           {
           case 1:
                printf("\nExpression with = operand\n");
                scanf("%s",exp);
                l=strlen(exp);
                exp2[0]='\0';
                i=0;
                while(exp[i]!='=')
                {
                    i++;
                }
                strncat(exp2,exp,i);
                strrev(exp);
                exp1[0]='\0';
                strncat(exp1,exp,l-(i+1));
                strrev(exp1);
                printf("Three address code:\ntemp=%s\n%s=temp\n",exp1,exp2);
                break;
           case 2:
                printf("\nExpresion with arithematic operand\n");
                scanf("%s",ex);
                strcpy(exp,ex);
                l=strlen(exp);
                exp1[0]='\0';
                for(i=0;i<l;i++)
                     {
                     if(exp[i]=='+'||exp[i]=='-')
                     {
                          if(exp[i+2]=='/'||exp[i+2]=='*')
                          {
                          pm();
                          break;
                          }
                          else
                          {
                          plus();
                          break;
                          }
                     }
                     else if(exp[i]=='/'||exp[i]=='*')
                     {
                          divs();
                          break;
                     }
                     }
                break;
           case 3:
               exit(0);
           }
 }
}
