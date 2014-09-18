#include "CmpString.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int readFile(vector<CmpString *>& set)
{
	CmpStrCreator factory;
	fstream file;
	file.open(("datalist.txt"),ios::in);


	if(!file)
	{
		cerr<<"datalist.txt not found"<<endl;
	}
	string fn;

	while(file>>fn)
	{
		CmpString *add;
		add=factory.createCmpString(fn);  //将文件名传给工厂实例，工厂负责返回实例化好的类。
		if(!add)
		{
			continue;
		}
		set.push_back(add);
	}
	return set.size();
}

int main()
{
	CmpStrCreator fact;
	vector<CmpString *> set;
	
	cout<<"---------  作业相似度分析程序  ---------"<<endl;
	cout<<"1. 正在读取名单。。。"<<endl;

	cout<<"读取到了 "<<readFile(set)<<"个文件"<<endl;

	float maxpercent=-100;
	int posi,posj;
	vector<vector<float>> pct;

	pct.resize(set.size());
	for(int i=0;i<set.size();i++)
		pct[i].resize(set.size());

	cout<<"2. 开始分析中。。。。。。"<<endl;
	
	for(int i=0;i<set.size();i++)
	{
		for(int j=i+1;j<set.size();j++)
		{
			float percent = set[i]->CalcSimilar(*(set[j]));
			pct[i][j]=percent;
		}
	}

	cout<<"\n------------   相似率统计结果   ------------"<<endl;
	for(int i=0;i<set.size();i++)
	{
		for(int j=0;j<set.size();j++)
		{
			if(pct[i][j]!=0)
			printf("%.2f ",pct[i][j]);
			else
			printf("     ");
		}
		printf("\n");
	}

	cout<<"---------    以下作业被列入怀疑名单   ---------"<<endl;
	for(int i=0;i<set.size();i++)
		for(int j=0;j<set.size();j++)
		{
			if(pct[i][j]>=0.9)
			{
				float percent=pct[i][j];
				cout<<set[i]->getName()<<" 与 "<<set[j]->getName()<<" 相似度 "<<pct[i][j]<<"  "<<JudgePct(percent)<<endl;
			}
		}
	
		//最后交给工厂回收创建的对象
		for(int i=0;i<set.size();i++)
		fact.CmpRecovery(set[i]);

		system("pause");
	return 0;
}
