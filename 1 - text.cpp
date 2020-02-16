#include<stdio.h>
char num[11][4]={"零","一","二","三","四","五","六","七","八","九","十"};
void print(int n);
int main (){
    int n;
    n=5;print(n);printf("\n");
    n=10;print(n);printf("\n");
    n=-20;print(n);printf("\n");
    n=-51;print(n);printf("\n");
    n=1;print(n);printf("\n");
    n=-10;print(n);printf("\n");
    n=21;print(n);printf("\n");
    n=-11;print(n);printf("\n");
    n=13;print(n);printf("\n");
    n=-85;print(n);printf("\n");
    n=-36;print(n);printf("\n");
    getchar();
}
void print(int n)
{
    if(n<0){
    printf("负");
	n=-n;	
	}
    
    
    if(n>99)
    printf("数字过大这渣渣计算器办不到。。。");
    else{
        int x,y;
        x=n/10;
        y=n%10;
        if(x==0)//0-9阶段
        {
            printf("%s",num[y]);
        }
        else if(x!=0&&y==0)//几十
        {
            if(x==1)
            printf("十");
            else
            printf("%s十",num[x]);
        }
        else if(x==1&&y!=0)//十几
        {
            printf("十%s",num[y]);
        }
        else//几十几
        {
            printf("%s十%s",num[x],num[y]);
        }
    
    } 
 
}