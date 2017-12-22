#include "stdafx.h"
#include <iostream>
#include "TListItem.h"

TListItem::TListItem(const Rectangle& rectangle) {
	this->rectangle = rectangle;
	this->next = nullptr;
	this->prev = nullptr;
	std::cout << "Список создан" << std::endl;
}

TListItem* TListItem::GetNext() {
	return this->next;
}

TListItem* TListItem::GetPrev()
{
	return this->prev;
}

void TListItem::SetNext(TListItem* item) {
	this->next = item;
}

void TListItem::SetPrev(TListItem *prev)
{
	this->prev = prev;
}

Rectangle TListItem::GetRectangle() const {
	return this->rectangle;
}

TListItem::~TListItem() {
	std::cout << "Фигура удалена" << std::endl;
}