#include "stdafx.h"
#include "TList.h"

TList::TList() :head(nullptr), size(0) {
}

std::ostream& operator<<(std::ostream& os, const TList& list) {
	if (!list.head)
	{
		os << "Список пуст." << std::endl;
	}
	TListItem *item = list.head;
	while (item != nullptr) {
		os << item->GetRectangle();
		item = item->GetNext();
	}
	return os;
}

void TList::Insert(Rectangle &tr) {
	int n;
	std::cout << "Введите индекс: ";
	std::cin >> n;
	if (n < 0 || n > this->GetSize()) {
		std::cout << "Такого индекса нет.\n";
		return;
	}
	if (n == 0) {
		this->PushFirst(tr);
	}
	else if (n == this->GetSize() - 1) {
		this->PushLast(tr);
	}
	else {
		this->PushAtIndex(tr, n);
	}
	++size;
}

void TList::PushLast(Rectangle &tr)
{
	TListItem *newItem = new TListItem(tr);
	TListItem *tmp = this->head;

	while (tmp->GetNext() != nullptr) {
		tmp = tmp->GetNext();
	}
	tmp->SetNext(newItem);
	newItem->SetPrev(tmp);
	newItem->SetNext(nullptr);
}

void TList::PushFirst(Rectangle &tr)
{
	TListItem *newItem = new TListItem(tr);
	TListItem *oldHead = this->head;
	this->head = newItem;
	if (oldHead != nullptr) {
		newItem->SetNext(oldHead);
		oldHead->SetPrev(newItem);
	}
}


void TList::PushAtIndex(Rectangle &triangle, int n) {
	TListItem *p = new TListItem(triangle);
	TListItem *tmp = this->head;
	for (int i = 1; i < n; i++) {
		tmp = tmp->GetNext();
	}
	p->SetNext(tmp->GetNext());
	p->SetPrev(tmp);
	tmp->SetNext(p);
	tmp->GetNext()->SetPrev(p);
}


Rectangle TList::Delete()
{
	int n = 0;
	Rectangle rec;
	std::cout << "Введите индекс: ";
	std::cin >> n;
	if (n > this->GetSize() - 1 || n < 0 || this->IsEmpty()) {
		std::cout << "Неверный ввод.\n";
		return rec;
	}
	if (n == 0) {
		rec = this->PopFirst();
	}
	else if (n == this->GetSize() - 1) {
		rec = this->PopLast();
	}
	else {
		rec = this->PopAtIndex(n);
	}
	--size;
	return rec;
}

Rectangle TList::PopAtIndex(int n)
{
	TListItem *tmp = this->head;
	for (int i = 0; i < n - 1; ++i) {
		tmp = tmp->GetNext();
	}
	TListItem *rem = tmp->GetNext();
	Rectangle res = rem->GetRectangle();
	TListItem *nextItem = rem->GetNext();
	tmp->SetNext(nextItem);
	nextItem->SetPrev(tmp);
	delete rem;
	return res;
}

Rectangle TList::PopFirst()
{
	if (this->GetSize() == 1) {
		Rectangle res = this->head->GetRectangle();
		delete this->head;
		this->head = nullptr;
		return res;
	}
	TListItem *tmp = this->head;
	Rectangle res = tmp->GetRectangle();
	this->head = this->head->GetNext();
	this->head->SetPrev(nullptr);
	delete tmp;
	return res;
}

Rectangle TList::PopLast()
{
	if (this->GetSize() == 1) {
		Rectangle res = this->head->GetRectangle();
		delete this->head;
		this->head = nullptr;
		return res;
	}
	TListItem *tmp = this->head;
	while (tmp->GetNext()->GetNext()) {
		tmp = tmp->GetNext();
	}
	TListItem *rem = tmp->GetNext();
	Rectangle res = rem->GetRectangle();
	tmp->SetNext(rem->GetNext());
	delete rem;
	return res;
}

int TList::GetSize()
{
	return this->size;
}

bool TList::IsEmpty() const
{
	return head == nullptr;
}

TList::~TList() {
	TListItem* tmp;
	while (head) {
		tmp = head;
		head = head->GetNext();
		delete tmp;
	}
}

