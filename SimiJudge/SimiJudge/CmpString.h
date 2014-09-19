#pragma once
#define _AFXDLL
#include <string>

using namespace std;

enum Format
{
	CPP,HTML,TXT,NO_FOUND
};

class CmpString
{
protected:
	string CmpStr;
	string fname;

	string OutputInfo;

public:
	float CalcSimilar(const CmpString& other); //计算相似率

	virtual void getCmpStr(string filename)=0;
	string getName(){return fname;};  //获得文件名
	string getCmpStr(){return CmpStr;};//获得等效代码

	static string JudgePct(float percent); //获得判断结果

};

class CppWork:public CmpString
{
public:
	void getCmpStr(string filename);
	
};

class TxtWork:public CmpString
{

public:
	void getCmpStr(string filename);
};

class HtmlWork:public CmpString
{
public:
	void getCmpStr(string filename);
};


class CmpStrCreator
{
public:
	CmpString* createCmpString(const string& filename);	
	void CmpRecovery(CmpString* rec); 
};


