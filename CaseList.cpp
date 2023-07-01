#include "CaseList.h"




CaseList::CaseList(const CaseList& cList)
{
	for (const auto& el : cList._caseList)
	{
		Case* tmp = new Case(*el);
		_caseList.push_back(tmp);
	}
}

void CaseList::AddCase(const Case& case_)
{
	Case* tmp = new Case(case_);
	_caseList.push_back(tmp);
}

CaseList::~CaseList()
{
	Clear();
}

void CaseList::Clear()
{
	for (const auto& el : _caseList)
		delete el;
}

const std::vector<Case*>& CaseList::GetCaseList()
{
	return _caseList;
}

