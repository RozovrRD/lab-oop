#ifndef TLISTITEM_H
#define TLISTITEM_H

#include "rectangle.h"

class TListItem {
public:
	TListItem(const Rectangle& rectangle);
	TListItem* GetNext();
	TListItem* GetPrev();
	void SetNext(TListItem* item);
	void SetPrev(TListItem* prev);
	Rectangle GetRectangle() const;
	virtual ~TListItem();
private:
	Rectangle rectangle;
	TListItem *next;
	TListItem *prev;
};

#endif
