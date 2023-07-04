#include "CaseList.h"


size_t CaseList::MaxLength()
{
	size_t maxLength = 0;
	for (const auto& el : _caseList)
	{
		if (maxLength < el->GetTitle().size())
			maxLength = el->GetTitle().size();
	}
	return maxLength;
}

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
	delete _caseList.at(numCase);
	_caseList.erase(_caseList.begin() + numCase);
}

CaseList::~CaseList()
{
	Clear();
}

size_t CaseList::Size() const
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
	_caseList.clear();
}

std::vector<Case*> CaseList::GetCaseList() const
{
	return _caseList;
}

void CaseList::SortListByDate()
{
	for (size_t i = 0; i < this->Size()-1; i++)
	{
		Case* tmp_case = nullptr;
		size_t index = i;
		for (size_t j = i + 1; j < this->Size(); j++)
		{
			if (_caseList.at(i)->GetDate() > _caseList.at(j)->GetDate())
			{
				tmp_case = _caseList.at(j);
				index = j;
			}
		}
		if (index != i)
		{
			_caseList.at(index) = _caseList.at(i);
			_caseList.at(i) = tmp_case;
		}
	}
}

void CaseList::PrintList()
{
	size_t maxLength = MaxLength();
	size_t elLength = 0;
	for (size_t i = 0; i < Size(); i++)
	{
		PrintCaseByIndex(i);
		std::cout << std::endl;
	}
}

void CaseList::PrintCaseByIndex(size_t index)
{
	size_t maxLength = MaxLength();
	size_t elLength = 0;
	std::cout << _caseList.at(index)->GetTitle();
	elLength = maxLength - _caseList.at(index)->GetTitle().size();
	while (elLength-- > 0)
		std::cout << ' ';
	std::cout << ' ';
	std::cout << _caseList.at(index)->GetDate().GetDay() << '.' 
				<< _caseList.at(index)->GetDate().GetMonth() << '.' 
				<< _caseList.at(index)->GetDate().GetYear();
}

