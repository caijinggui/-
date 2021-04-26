#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void sun();
void goit();

class jisuanqi
{
protected:
    double jieguo;
public:
    virtual void show()=0;
};

class jjcc:public jisuanqi
{
private:
    double aa;
    double bb;
    char fhh;
public:
    jjcc(double a,char fh,double b)
    {
        aa=a;
        bb=b;
        fhh=fh;
        if(fh=='+')
        {
            jieguo=a+b;
        }
        else if(fh=='-')
        {
            jieguo=a-b;
        }
        else if(fh=='*')
        {
            jieguo=a*b;
        }
        else if(fh=='/')
        {
            jieguo=a/b;
        }
        else
        {
            printf("输入错误，即将返回主菜单\n");
            sun();
            goit();
        }
    }
    void show()
    {
        cout<<aa<<fhh<<bb<<"="<<jieguo<<endl;
    }
};

class sjhs:public jisuanqi
{
private:
    char sjj[50];
    double aa;
public:
    sjhs(char sj[],double a)
    {
        strcpy(sjj,sj);
        aa=a;
        a=a*3.141592653589/180;
        if(strcmp(sj,"sin")==0)
        {
            jieguo=sin(a);
        }
        else if(strcmp(sj,"cos")==0)
        {
            jieguo=cos(a);
        }
        else if(strcmp(sj,"tan")==0)
        {
            jieguo=tan(a);
        }
        else
        {
            printf("输入错误，即将返回主菜单\n");
            sun();
            goit();
        }
    }
    void show()
    {
        cout<<sjj<<aa<<"°"<<"="<<jieguo<<endl;
    }
};

class cmjs:public jisuanqi
{
private:
    double aa;
    double bb;
public:
    cmjs(double a,double b)
    {
        aa=a;
        bb=b;
        if(b==0.5)
            jieguo=sqrt(a);
        else if(b==int(b))
            jieguo=pow(a,int(b));
        else
        {
            printf("输入错误，即将返回主菜单\n");
            sun();
            goit();
        }
    }
    void show()
    {
        cout<<aa<<"^"<<bb<<"="<<jieguo<<endl;
    }
};

class jzzh:public jisuanqi
{
private:
    int aa,bb,jishu;
    int sf16=0;
    int p[50]={0};
public:
    jzzh(int a,int b)
    {
        aa=a;
        bb=b;
        if((b>10&&b!=16)||b<=1)
        {
            printf("输入错误，即将返回主菜单\n");
            sun();
            goit();
        }
        if(b==16)
            sf16=1;
        int i;
        for(i=0;a!=0;i++)
        {
            p[i]=a%b;
            a=a/b;
        }
        jishu=i;
    }
    void show()
    {
        cout<<"10进制的"<<aa<<"转换为"<<bb<<"进制的数为";
        while(jishu--)
        {
            if(sf16==1)
            {
                if(p[jishu]==10)
                {
                    cout<<"A";
                    continue;
                }
                if(p[jishu]==11)
                {
                    cout<<"B";
                    continue;
                }
                if(p[jishu]==12)
                {
                   cout<<"C";
                   continue;
                }
                if(p[jishu]==13)
                {
                    cout<<"D";
                    continue;
                }
                if(p[jishu]==14)
                {
                    cout<<"E";
                    continue;
                }
                if(p[jishu]==15)
                {
                    cout<<"F";
                    continue;
                }
            }
            cout<<p[jishu];
        }
        cout<<endl;
    }
};

void sun()
{
    printf("————欢迎进入计算器程序————\n");
    printf("本计算器可执行加减乘除、三角函数计算和进制转换\n");
    printf("1.计算加减乘除\n");
    printf("2.计算三角函数\n");
    printf("3.n次方与开方的计算\n");
    printf("4.进制转换\n");
    printf("0.结束本程序\n");
    printf("请输入序号进入不同功能：\n");
}

void back()
{
    printf("请按回车返回主菜单：\n");
    char c,k;
    c=getchar();
    k=getchar();
    sun();
    goit();
}

void goit()
{
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        printf("请输入算式（例：3+5代表计算3加5）：\n");
        double a,b;char fh;
        scanf("%lf%c%lf",&a,&fh,&b);
        jjcc js(a,fh,b);
        js.show();
        back();
    }
    else if(n==2)
    {
        printf("请输入算式（例：cos 60代表计算cos60°的值）：\n");
        double a;
        char fh[50];
        scanf("%s",fh);
        scanf("%lf",&a);
        sjhs js(fh,a);
        js.show();
        back();
    }
    else if(n==3)
    {
        printf("请输入算式，开次方用0.5代替（例：9 3代表计算9的3次方）\n");
        double a,b;
        scanf("%lf%lf",&a,&b);
        cmjs js(a,b);
        js.show();
        back();
    }
    else if(n==4)
    {
        printf("请依次输入十进制数据、想转换的进制（例：20 8代表20是十进制，我想转为8进制）：\n");
        int a,b;
        scanf("%d%d",&a,&b);
        jzzh js(a,b);
        js.show();
        back();
    }
    else if(n==0)
    {
        printf("————欢迎您再次使用本程序，再见————");
        exit(0);
    }
    else
    {
        printf("输入错误，请重新输入\n");
        sun();
        goit();
    }
}

int main()
{
    sun();
    goit();
    return 0;
}
