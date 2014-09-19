#pragma once
#define _AFXDLL

#include "CmpString.h"
#include <vector>

#include <afx.h>

using namespace std;

class ReportMaker
{
private:
	vector<CmpString *> set;
	vector<vector<float>> pct;
	int sampleSize;

	string report;

	/*生成相似率的表格*/
	string createPctTable();
	/*生成怀疑列表报告*/
	string createDoubtList();
	
	/*找出set中的所有结果为levelString的组*/
	string findLevel(string levelString);

public:
	ReportMaker(vector<CmpString *>& set,vector<vector<float>>& pct);
	
	/*生成结果报告*/
	bool createReport();
	/*返回结果报告*/
	string getReport();

};