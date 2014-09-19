#include "CmpString.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

string CmpString::JudgePct(float percent)
{
	string result;
	if(percent<=0.88)
	{
		result="不相似";
	}
	else if(percent<=0.95)
	{
		result="存在小部分相似";
	}
	else if(percent<=1)
	{
		result="比较相似";
	}
	else if(percent<=1.15)
	{
		result="非常相似";
	}
	else if(percent<1.2)
	{
		result="几乎完全相似";
	}
	else 
	{
		result="一模一样";
	}
	return result;
}

//根据相差率来返回怀疑率 相差率越小 怀疑值越大 
float DoubtPct(float pecent)
{
	if(pecent<=0.01)
	{
		return 1.2;
	}
	if(pecent<=0.05)
	{
		return 1.15;
	}
	if(pecent<=0.1)
	{
		return 1.1;
	}
	if(pecent<=0.15)
	{
		return 1.05;
	}
	if(pecent<=0.2)
	{
		return 1;
	}
	if(pecent<=0.25)
	{
		return 0.95;
	}
	if(pecent<=0.3)
	{
		return 0.9;
	}
	return 0.8;
}

float CmpString::CalcSimilar(const CmpString& other)
{
	string a=this->CmpStr;
	string b=other.CmpStr;
	float distancePct;     //代码的相差率
	int line=a.length(),row=b.length();

	vector<vector<int>>data;
	data.resize(line+1);

	cout<<"\n正在对"<<getName()<<" 与 "<<other.fname<<"等效代码进行编辑距离分析。。。。"<<endl;

	for(int i=0;i<line+1;i++)
		data[i].resize(row+1);

	for(int i=0;i<line+1;i++)
		data[i][0]=i;
	for(int i=0;i<row+1;i++)
		data[0][i]=i;

	for(int i=1;i<line+1;i++)
	{
		for(int j=1;j<row+1;j++)
		{
			char sa=a[i-1];
			char sb=b[j-1];
			int cost = !(sa==sb);
			data[i][j]=min(data[i-1][j-1]+cost,min(data[i-1][j]+1,data[i][j-1]+1));
		}
	}
	
	float times = data[line][row];
	int distance=a.length()-b.length();
	int sum=a.length()+b.length();
	distance=abs(distance);
	float percent;

	percent=1-((times-distance)/(sum-distance));
	distancePct=(float)distance/sum;

	cout<<"-------"<<"对"<<getName()<<" 与 "<<other.fname<<"的分析报告  -------"<<endl;

//	cout<<"字符串a的等效代码结构长度为 ：" <<a.length()<<endl;
//	cout<<"字符串b的等效代码结构长度为 ：" <<b.length()<<endl;
//	cout<<"字符串a,b的等效代码结构长度之差为 ：" <<distance<<"  对应 100% 完全相关"<<endl;
//	cout<<"字符串a,b的等效代码结构长度之和为 ：" <<sum<<"  对应0% 毫不相关"<<endl; 
//	cout<<"由字符串a修改到字符串b需要的步长:"<<times<<endl;

	cout<<"编辑距离相似率 "<<percent<<endl;
	cout<<"相差率 "<<distancePct<<endl;

	float pct2=percent*DoubtPct(distancePct);
	cout<<"作业相似率 "<<percent*DoubtPct(distancePct)<<endl;

	string result;

	result=JudgePct(pct2);
	
	cout<<"分析结果："<<endl;
	cout<<result<<endl;

	return pct2;
};

//删除cpp中注释语句
void DelCppNotes(string& source)
{
	string NoteMark="//";
	int posBegin;
	int posEnd;

	//第一步 删掉所有//形式的注释
	while(posBegin=source.find(NoteMark))
	{
		if(posBegin == string::npos)
		{
			break;
		}
		int posEnd= source.find('\n',posBegin);
		string::iterator end=source.begin();
		string::iterator beg=source.begin();

		while(posEnd--)
			end++;
		while(posBegin--)
			beg++;
		source.erase(beg,end);
	}
	//第二步 删除所有/* */ 形式的注释

	string Mark1="/*";
	string Mark2="*/";
	while(posBegin=source.find(Mark1))
	{
		if(posBegin == string::npos)
		{
			break;
		}
		int posEnd= source.find(Mark2,posBegin);
		string::iterator end=source.begin();
		string::iterator beg=source.begin();

		while(posEnd--)
			end++;
		while(posBegin--)
			beg++;
		end+=2;
		source.erase(beg,end);
	}
}

//删除HTML中的注释语句
void DelHtmlNotes(string& source)
{
	int posBegin;
	int posEnd;

	//删除所有<!--   --> 形式的注释

	string Mark1="<!--";
	string Mark2="-->";
	while(posBegin=source.find(Mark1))
	{
		if(posBegin == string::npos)
		{
			break;
		}
		int posEnd= source.find(Mark2,posBegin);
		string::iterator end=source.begin();
		string::iterator beg=source.begin();

		while(posEnd--)
			end++;
		while(posBegin--)
			beg++;
		end+=2;
		source.erase(beg,end);
	}
}


//删掉所有回车空格换行
void DelBlank(string& source)
{

		bool flag =false;

		char delSet[4]={'\n',' ','\a','\t'}; //要删除的字符
		int pos[4];

		for(int i=0;i<4;i++)
		{
			while(true)
			{
				pos[i]=source.find(delSet[i]);
				if(pos[i]==string::npos)break;
				else{source.erase(pos[i],1);}
			}
		}

}

void TxtWork::getCmpStr(string filename)
{
	fstream file;
	string tmp;
	file.open(filename,ios::in);
	fname=filename;
	if(!file)
	{
		cerr<<" can not open "<<filename<<endl;
		return ;

	}

	while(true)
	{
		file>>tmp;
		CmpStr= CmpStr + tmp;
		if(file.eof())
			break;
	}
}

void CppWork::getCmpStr(string filename)
{
	fstream file;
	file.open(filename,ios::in);
	fname=filename;
	if(!file)
	{
		cerr<<filename<<" can not open "<<filename<<endl;
		return;
	}

	while(true)
	{
		char ch=file.get() ;
		CmpStr= CmpStr + ch;
		if(file.eof())
			break;
	}

	DelCppNotes(CmpStr);  //删掉所有注释
	
	DelBlank(CmpStr);     //删除所有空白格

	file.close();
}

void HtmlWork::getCmpStr(string filename)
{
	fstream file;
	file.open(filename,ios::in);
	fname=filename;
	if(!file)
	{
		cerr<<" can not open "<<filename<<endl;
		return ;
	}

	while(true)
	{
		char ch=file.get() ;

		CmpStr= CmpStr + ch;

		if(file.eof())
			break;
	}

	DelHtmlNotes(CmpStr); 
	
	DelBlank(CmpStr);   

	file.close();
}


//根据文件名推测格式类型
Format JudgeFormat(const string& filename)
{
	if(string::npos!=filename.find(".cpp")||string::npos!=filename.find(".c")){return CPP;}
	if(string::npos!=filename.find(".txt")){return TXT;}
	if(string::npos!=filename.find(".html") || string::npos!=filename.find(".htm")){return HTML;}
	return NO_FOUND;
}

void CmpStrCreator::CmpRecovery(CmpString* rec)
{
	delete(rec);
}


CmpString* CmpStrCreator::createCmpString(const string& filename)
{
	Format fmt=JudgeFormat(filename);
		
	CmpString *ret=NULL;
	
		switch (fmt)
		{
		case CPP:
			ret=new(CppWork);   //简单工厂模式 ： 根据文件名决定具体实例化哪个类
		break;
		case TXT:
			ret=new(TxtWork);
		break;
		case HTML:
			ret=new(HtmlWork);
		break;
		case NO_FOUND:
			cerr<<filename<<" the format can not be found"<<endl;
			return NULL;
		default:	
		break;
		}


	ret->getCmpStr(filename);

	return ret;
}
