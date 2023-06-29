#include<bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define RFOR(i,l,r) for(int i=r;i>=l;i--)
#define p(x,y) pair<x,y>
#define mkp make_pair

#ifdef DEBUG
#define cin fs
#endif 

/*
中国使用斤、两、钱来表示重量，其中1斤=10两，1两=10钱
中国计重单位与克的关系为：1斤=500克，1两=50克，1钱=5克
*/


class CN; //提前声明
class EN; //提前声明

// 抽象类
class Weight
{
protected:
	char kind[20]; //计重类型
	int gram; // 克
public:
	Weight(const char tk[] = "no name", int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void print(ostream& out) = 0; // 输出不同类型的计重信息
};

// 中国计重
class CN : public Weight
{
    private:
        mutable int money;
        mutable int gramm;
        mutable int kilos;
    public:
		CN(int a,int b,int c,int d, const char* const tk):Weight(tk){;}
		//"<< <<"
		void Convert(int var){
			kilos=var/500;var%=500;
			gramm=var/50;var%=50;
			money=var/5;var%=5;
			gram=var;
		}
		friend class EN;

		CN& operator=(const EN &var);

        void print(ostream& out)override{out<<kind<<":"<<kilos<<"斤"<<gramm<<"两"<<money<<"钱"<<gram<<"克\n";}
};

// 英国计重

/*
英国使用磅、盎司、打兰来表示重量，其中1磅=16盎司，1盎司=16打兰
英国计重单位与克的关系为：1磅=512克，1盎司=32克，1打兰=2克
*/

class EN : public Weight
{
    private:
        mutable int pound;
        mutable int angus;
        mutable int daelant;
    public:
		EN(int a,int b,int c,int d, const char* const tk):Weight(tk){;}
		
		void Convert(int var)
		{
			pound=var/512;var%=512;
			angus=var/32;var%=32;
			daelant=var/2;var%=2;
			gram=var;
		}

		friend  class CN;

		EN& operator=(const CN &var);

        void print(ostream& out)override{out<<kind<<":"<<pound<<"磅"<<angus<<"盎司"<<daelant<<"打兰"<<gram<<"克\n";}
};


EN& EN::operator=(const CN &var)
{
	int temp;
	temp=var.gram+var.kilos*500+var.gramm*50+var.money*5;
	Convert(temp);
	return *this;
}

CN& CN::operator=(const EN &var)
{
	int temp;
	temp=var.pound*512+var.angus*32+var.daelant*2+var.gram;
	Convert(temp);
	return *this;
}


// 以全局函数方式重载输出运算符，代码3-5行....自行编写
// 重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
// 重载函数必须调用参数Weight对象的print方法

// 主函数
int main()
{
	int tw;
	// 创建一个中国计重类对象cn
	// 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
	CN cn(0, 0, 0, 0, "中国计重");
	cin >> tw;
	cn.Convert(tw); // 把输入的克数转成中国计重
	cn.print(cout);

	// 创建英国计重类对象en
	// 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
	EN en(0, 0, 0, 0, "英国计重");
	cin >> tw;
	en.Convert(tw); // 把输入的克数转成英国计重
	// cout << en;
	en.print(cout);
	cn = en; // 把英国计重转成中国计重
	cn.print(cout);
	return 0;
}