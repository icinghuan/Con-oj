//http://blog.csdn.net/lovemylife1234/article/details/54918096

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100001]={0};
int my_cnt=0;
bool expression_bool();
bool term_bool();
bool factor_bool();

bool expression_bool(){//��һ�����ʽ��ֵ
    bool result=term_bool();//���һ���ֵ
    bool more=true;
    while(more){
        char op=s[my_cnt];//��һ���ַ�,��ȡ��
        if(op=='&'||op=='|'){
            my_cnt++;//��������ȡ��һ���ַ�
            bool value=term_bool();
            if(op=='&') result=result&value;
            else result=result|value;
        }else{
            more=false;
        }
    }

    return result;
}

bool term_bool(){//��Ϊ!���������ȼ�����,���԰�!xxxҲ����һ����
    bool result;
    char op=s[my_cnt];
    if(op=='!'){
        my_cnt++;
        result=!factor_bool();
    }else{
        result=factor_bool();
    }

    return result;
}

bool factor_bool(){//��һ�����ӵ�ֵ
    bool result;
    char c=s[my_cnt];
    if(c=='('){//������������������������ı��ʽ��ɵĻ�
        my_cnt++;
        result=expression_bool();
        my_cnt++;
    }else if(c=='V'){
        result=true;
        my_cnt++;
    }else if(c=='F'){
        result=false;
        my_cnt++;
    }else if(c=='!'){//������!,˵����ȡ����һ������
        result=term_bool();
    }

    return result;
}

void oj_3_1(){
    int k=0;
    while(cin.getline(s,100000)){
        char t[100001]={0};
        int len=strlen(s);
        for(int i=0,k=0;i<len;++i){
            if(s[i]!=' '){
                t[k++]=s[i];
            }
        }

        len=strlen(t);
        for(int i=0;i<len;++i){
            s[i]=t[i];
        }
        s[len]='\0';

        //�����������еĿո��Ѿ���ȥ���ɾ���
        //cout<<"Expression "<<++k<<": "<<(expression_bool()?"V":"F")<<endl;
        cout<<(expression_bool()?"V":"F")<<endl;
        //��ʼ������
        my_cnt=0;
        memset(s,0,100000);
    }

}

int main(){
    oj_3_1();
    return 0;
}
