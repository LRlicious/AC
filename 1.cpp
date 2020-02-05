#include<stdio.h>
#include<string.h>
char key[6][20]={"整数","钱包","等于","增加","减少","看看"};
char num[11][4]={"零","一","二","三","四","五","六","七","八","九","十"};
int change(char a[20]);//转换
void error();
void print(int n);
int main(){
    int flag=1,i=0,n=0,m;
    char a[20]={" "},b[20]={" "},c[20]={" "},d[20]={" "};
    while(1){
        if(flag==1){
                scanf("%s %s %s %s",a,b,c,d);
            if(strcmp(a,key[0])==0&&strcmp(b,key[1])==0&&strcmp(c,key[2])==0)//初始化
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
            if(strcmp(a,key[1])==0&&strcmp(b,key[3])==0)//增加
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
            else if(strcmp(a,key[1])==0&&strcmp(b,key[4])==0)//减少
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
            else if(strcmp(a,key[5])==0&&strcmp(b,key[1])==0)//输出
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
    printf("输入错误\n");
}//输入报错情况
int change(char a[20])
{
    int i,n,sum;
    char x[10],y[10];
    n=strlen(a);
    if(n==2)//0-10的输入 
    {
        for(i=0;i<=11;i++)
        {
            if((strcmp(a,num[i])==0))
            return i;
            if(i==11)
            return -1;
        }
    }
    if(n==4)//11-20以及10的倍数
    {
        for(i=0;i<2;i++){
            x[i]=a[i];
        } 
        for(i=2;i<4;i++){
            y[i-2]=a[i];
        }
        if(strcmp(x,"十")==0){
            for(i=0;i<=11;i++){
                if(strcmp(y,num[i])==0)
                return 10+i;
                if(i==11)
                return -1;
            } 
        }
        else if(strcmp(y,"十")==0){
            for(i=1;i<=11;i++){
                if(strcmp(x,num[i])==0)
                return i*10;
                if (i==11)
                return -1;
            }
        }
        else return -1;   
    }
    else if(n==6)//几十几
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
}//文字转换数字
void print(int n)//输出
{
    if(n<0)
    printf("你欠债了");
    else if(n>99)
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
