#include<stdio.h>
char num[11][4]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
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
    printf("��");
	n=-n;	
	}
    
    
    if(n>99)
    printf("���ֹ����������������첻��������");
    else{
        int x,y;
        x=n/10;
        y=n%10;
        if(x==0)//0-9�׶�
        {
            printf("%s",num[y]);
        }
        else if(x!=0&&y==0)//��ʮ
        {
            if(x==1)
            printf("ʮ");
            else
            printf("%sʮ",num[x]);
        }
        else if(x==1&&y!=0)//ʮ��
        {
            printf("ʮ%s",num[y]);
        }
        else//��ʮ��
        {
            printf("%sʮ%s",num[x],num[y]);
        }
    
    } 
 
}