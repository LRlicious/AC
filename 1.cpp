#include<stdio.h>
#include<string.h>
char key[6][20]={"����","Ǯ��","����","����","����","����"};
char num[11][4]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
int change(char a[20]);//ת��
void error();
void print(int n);
int main(){
    int flag=1,i=0,n=0,m;
    char a[20]={" "},b[20]={" "},c[20]={" "},d[20]={" "};
    while(1){
        if(flag==1){
                scanf("%s %s %s %s",a,b,c,d);
            if(strcmp(a,key[0])==0&&strcmp(b,key[1])==0&&strcmp(c,key[2])==0)//��ʼ��
            {
                flag=0;
                n=change(d);
                if(n==-1){
                    error();
                    flag=0;
                    continue;
                }
            }
            else error();
        }
        else{
            scanf("%s %s",a,b);
            if(strcmp(a,key[1])==0&&strcmp(b,key[3])==0)//����
            {
                scanf(" %s",c);
                m=change(c);
                if(m>=0)
                n=n+m;
                else {
                    error();
                    continue;
                }
            }
            else if(strcmp(a,key[1])==0&&strcmp(b,key[4])==0)//����
            {
                scanf(" %s",c);
                m=change(c);
                if(m>=0)
                n=n-m;
                else
                {
                    error();
                    continue;
                }
                
            }
            else if(strcmp(a,key[5])==0&&strcmp(b,key[1])==0)//���
            {
                print(n);
                //break;
            }
            else {
                error();
                scanf(" %s",c);
            }
            
        }
    }
}
void error(){
    printf("�������\n");
}//���뱨�����
int change(char a[20])
{
    int i,n,sum;
    char x[10],y[10];
    n=strlen(a);
    if(n==2)//0-10������ 
    {
        for(i=0;i<=11;i++)
        {
            if((strcmp(a,num[i])==0))
            return i;
            if(i==11)
            return -1;
        }
    }
    if(n==4)//11-20�Լ�10�ı���
    {
        for(i=0;i<2;i++){
            x[i]=a[i];
        } 
        for(i=2;i<4;i++){
            y[i-2]=a[i];
        }
        if(strcmp(x,"ʮ")==0){
            for(i=0;i<=11;i++){
                if(strcmp(y,num[i])==0)
                return 10+i;
                if(i==11)
                return -1;
            } 
        }
        else if(strcmp(y,"ʮ")==0){
            for(i=1;i<=11;i++){
                if(strcmp(x,num[i])==0)
                return i*10;
                if (i==11)
                return -1;
            }
        }
        else return -1;   
    }
    else if(n==6)//��ʮ��
    {
         for(i=2;i<4;i++){
            x[i-2]=a[i];
        } 
        if(strcmp(x,num[10])!=0)
        return -1;
        for(i=0;i<2;i++){
            x[i]=a[i];
        } 
        for(i=4;i<6;i++){
            y[i-4]=a[i];
        }
        for(i=0;i<=11;i++){
            if(strcmp(x,num[i])==0){
                sum=i*10;
                break;
            }
            if (i==11)
                return -1;
        }
        for(i=0;i<=11;i++){ 
            if(strcmp(y,num[i])==0){
                sum=sum+i;
                break;
            }
            if (i==11)
                return -1;
        }
        return sum;
    }
    else return -1;
}//����ת������
void print(int n)//���
{
    if(n<0)
    printf("��Ƿծ��");
    else if(n>99)
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
