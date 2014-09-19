#define _AFXDLL
#include "CmpString.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <afx.h>

using namespace std;


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

/*产生测试报告，并且保存成文件
* @param set 作业数组
* @param pct 相似率
*/
void createReport(vector<CmpString *>& set,vector<vector<float>>& pct)
{
	string OutputInfo;
	
	OutputInfo.append("\n------------   相似率统计结果(总表)   ------------\n");

	//cout<<"\n------------   相似率统计结果   ------------"<<endl;
	for(int i=0;i<set.size();i++)
	{
		for(int j=0;j<set.size();j++)
		{
			CString tmp;
			
			if(pct[i][j]!=0)
				tmp.Format("%.2f ",pct[i][j]);
			else
			tmp.Format("     ");
			OutputInfo.append(tmp);
		}
		OutputInfo.append("\n");
	}

	OutputInfo.append("---------    以下作业被列入怀疑名单   ---------\n");
	//cout<<"---------    以下作业被列入怀疑名单   ---------"<<endl;
	for(int i=0;i<set.size();i++)
	{
		for(int j=0;j<set.size();j++)
		{
			if(pct[i][j]>=0.9)
			{
				CString tmp;
				float percent=pct[i][j];
				string work1=set[i]->getName();
				string work2=set[j]->getName();
				float simipct=pct[i][j];
				string answer=JudgePct(percent);
				tmp.Format("%s 与 %s 的相似度为 %f 判断结果为 %s\n",work1.c_str(),work2.c_str(),simipct,answer.c_str());
	//			cout<<set[i]->getName()<<" 与 "<<set[j]->getName()<<" 相似度 "<<pct[i][j]<<"  "<<JudgePct(percent)<<endl;
				OutputInfo.append(tmp);
			}
		}
	}
	cout<<OutputInfo<<endl;
	ToFile(OutputInfo);
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
	
	for(int i=0;i<allWorks.size();i++)
	{
		for(int j=i+1;j<allWorks.size();j++)
		{
			float percent = allWorks[i]->CalcSimilar(*(allWorks[j]));
			pct[i][j]=percent;
		}
	}

	createReport(allWorks,pct); // 将结果输出到报告文件

	//最后交给工厂回收创建的对象
	for(int i=0;i<allWorks.size();i++)
	fact.CmpRecovery(allWorks[i]);

	system("pause");

	return 0;
}
