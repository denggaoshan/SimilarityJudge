#include "ReportMaker.h"

ReportMaker::ReportMaker(vector<CmpString *>& set,vector<vector<float>>& pct)
{
	this->set = set;
	this->pct = pct;
	sampleSize = set.size();
}

string ReportMaker::findLevel(string levelString)
{
	string ret="";

	for(int i=0;i<sampleSize;i++)
	{
		for(int j=0;j<sampleSize;j++)
		{
			if(CmpString::JudgePct(pct[i][j]) ==levelString)
			{
				CString tmp;
				string work1 = set[i]->getName();
				string work2 = set[j]->getName();
				tmp.Format("%s 与 %s 的相似度为 %f \n",work1.c_str(),work2.c_str(),pct[i][j]);
				ret.append(tmp);
			}
		}
	}
	return ret;
}

string ReportMaker::createPctTable()
{
	CString tmp ;
	string ret;
	for(int i=0;i<set.size();i++)
	{
		for(int j=0;j<set.size();j++)
		{
			CString tmp;
			
			if(pct[i][j]!=0)
				tmp.Format("%.2f ",pct[i][j]);
			else
			tmp.Format("     ");
			ret.append(tmp);
		}
		ret.append("\n");
	}
	return ret;
}

string ReportMaker::createDoubtList()
{
	string ret="";
	string tmp;
	
	tmp = findLevel("一模一样");
	if(tmp!="")
	{
		ret.append(" # 一模一样 # \n (pct = 1.2)\n");
		ret.append("     "+tmp);
	}

	tmp = findLevel("几乎完全相似");
	if(tmp!="")
	{
		ret.append(" # 几乎完全相似 # \n (1.2>= pct >= 1.15)\n");
		ret.append("     "+tmp);
	}

	tmp = findLevel("非常相似");
	if(tmp!="")
	{
		ret.append(" # 非常相似 # \n (1.15>= pct >= 1.0 )\n");
		ret.append("     "+tmp);
	}

	tmp = findLevel("比较相似");
	if(tmp!="")
	{
		ret.append(" # 比较相似 # \n (1.0>= pct >= 0.95 ) \n");
		ret.append("     "+tmp);
	}

	tmp = findLevel("存在小部分相似");
	if(tmp!="")
	{
		ret.append(" # 存在小部分相似 # \n (0.95>= pct >= 0.88) \n");
		ret.append("     "+tmp);
	}

	return ret;
}

bool ReportMaker::createReport()
{
	report.clear();
	
	report.append("\n------------   相似率统计结果(总表)   ------------\n");
	report.append(createPctTable()); 
	
	report.append("---------    以下作业被列入怀疑名单   ---------\n\n");
	report.append(createDoubtList());

	return true;
}

string ReportMaker::getReport()
{
	return report;
}