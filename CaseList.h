#ifndef _CASELIST_H_
#define _CASELIST_H_

#include "Case.h"
#include <vector>

class CaseList
{
private:
	std::vector<Case*> _caseList;

public:
	CaseList() {}
	CaseList(const CaseList& cList);
	~CaseList();
	void AddCase(const Case& case_);
	void Clear();
	const std::vector<Case*>& GetCaseList();
};

#endif
