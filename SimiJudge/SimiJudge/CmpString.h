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
public:
	virtual void getCmpStr(string filename)=0;
	const string getName(){return fname;};  //获得文件名
	const string getCmpStr(){return CmpStr;};//获得等效代码
	float CalcSimilar(const CmpString& other);
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


string JudgePct(float percent);