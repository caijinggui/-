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
            printf("������󣬼����������˵�\n");
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
            printf("������󣬼����������˵�\n");
            sun();
            goit();
        }
    }
    void show()
    {
        cout<<sjj<<aa<<"��"<<"="<<jieguo<<endl;
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
            printf("������󣬼����������˵�\n");
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
            printf("������󣬼����������˵�\n");
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
        cout<<"10���Ƶ�"<<aa<<"ת��Ϊ"<<bb<<"���Ƶ���Ϊ";
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
    printf("����������ӭ������������򡪡�����\n");
    printf("����������ִ�мӼ��˳������Ǻ�������ͽ���ת��\n");
    printf("1.����Ӽ��˳�\n");
    printf("2.�������Ǻ���\n");
    printf("3.n�η��뿪���ļ���\n");
    printf("4.����ת��\n");
    printf("0.����������\n");
    printf("��������Ž��벻ͬ���ܣ�\n");
}

void back()
{
    printf("�밴�س��������˵���\n");
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
        printf("��������ʽ������3+5�������3��5����\n");
        double a,b;char fh;
        scanf("%lf%c%lf",&a,&fh,&b);
        jjcc js(a,fh,b);
        js.show();
        back();
    }
    else if(n==2)
    {
        printf("��������ʽ������cos 60�������cos60���ֵ����\n");
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
        printf("��������ʽ�����η���0.5���棨����9 3�������9��3�η���\n");
        double a,b;
        scanf("%lf%lf",&a,&b);
        cmjs js(a,b);
        js.show();
        back();
    }
    else if(n==4)
    {
        printf("����������ʮ�������ݡ���ת���Ľ��ƣ�����20 8����20��ʮ���ƣ�����תΪ8���ƣ���\n");
        int a,b;
        scanf("%d%d",&a,&b);
        jzzh js(a,b);
        js.show();
        back();
    }
    else if(n==0)
    {
        printf("����������ӭ���ٴ�ʹ�ñ������ټ���������");
        exit(0);
    }
    else
    {
        printf("�����������������\n");
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
