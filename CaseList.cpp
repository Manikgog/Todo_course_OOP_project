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

void CaseList::DeleteCase(int numCase)
{
	_caseList.erase(_caseList.begin() + numCase);
}

CaseList::~CaseList()
{
	
	Clear();
}

size_t CaseList::Size()
{
	return this->_caseList.size();
}

Case& CaseList::GetCase(size_t index)
{
	return *(this->_caseList.at(index));
}

void CaseList::Clear()
{
	for (const auto& el : _caseList)
		delete el;
}

std::vector<Case*> CaseList::GetCaseList() const
{
	return _caseList;
}

