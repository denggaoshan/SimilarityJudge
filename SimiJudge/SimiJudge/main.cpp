#define _AFXDLL

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <afx.h>

#include "CmpString.h"
#include "ReportMaker.h"

using namespace std;

/*读取当前目录下的所有文件*/
int readFile(vector<CmpString *>& set)
{
	CmpStrCreator factory;
    CFileFind finder;

    BOOL bWorking = finder.FindFile(_T("*.*"));
  
	while(bWorking)
	{
		string fn;
		bWorking = finder.FindNextFile();
		fn=(LPCTSTR)finder.GetFileName();
		if(fn=="."||fn=="..")
		{
			continue;
		}
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

void ToFile(string report)
{
	fstream file("report.txt",ios::out);

	if(!file)
	{
		cerr<<"can not open file for writting"<<endl;
	}
	file<<report;

	file.close();
}

void createReport(vector<CmpString *>& set,vector<vector<float>>& pct)
{
	string OutputInfo;
	ReportMaker mk(set,pct);
	if(mk.createReport())
	{
		OutputInfo=mk.getReport();
	}
	cout<<OutputInfo<<endl;
	ToFile(OutputInfo);
}

//判断相似率 输出pct中
void JudegeSimilarity(vector<CmpString *>& allWorks,vector<vector<float>>& pct)
{
	for(int i=0;i<allWorks.size();i++)
	{
		for(int j=i+1;j<allWorks.size();j++)
		{
			float percent = allWorks[i]->CalcSimilar(*(allWorks[j]));
			pct[i][j]=percent;
		}
	}
}

int main()
{
	CmpStrCreator fact;
	vector<CmpString *> allWorks;  //每个样本对应一个CmpString ， 这里放所有的样本

	
	cout<<"---------  作业相似度分析程序  ---------"<<endl;
	cout<<"1. 正在读取名单。。。"<<endl;
	cout<<"读取到了 "<<readFile(allWorks)<<"个文件"<<endl;

	float maxpercent=-100;
	int posi,posj;

	vector<vector<float>> pct; //存放结果

	pct.resize(allWorks.size());
	for(int i=0;i<allWorks.size();i++)
		pct[i].resize(allWorks.size());

	cout<<"2. 开始分析中。。。。。。"<<endl;
	
	JudegeSimilarity(allWorks,pct); //交叉两两之间计算相似度 存到pct中

	createReport(allWorks,pct); // 将结果输出到报告文件

	//最后交给工厂回收创建的对象
	for(int i=0;i<allWorks.size();i++)
	fact.CmpRecovery(allWorks[i]);

	system("pause");

	return 0;
}
