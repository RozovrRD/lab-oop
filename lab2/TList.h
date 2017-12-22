#ifndef TLIST_H
#define TLIST_H 
#include "rectangle.h"
#include "TListItem.h" 
class TList {
public:
	TList();
	void Insert(Rectangle &rectangle);
	bool IsEmpty() const;
	Rectangle Delete();
	friend std::ostream& operator<<(std::ostream& os, const TList& stack);
	virtual ~TList();
	int GetSize();
private:
	TListItem *head;
	int size;

	void PushFirst(Rectangle &tr);
	void PushLast(Rectangle &tr);
	void PushAtIndex(Rectangle &tr, int n);
	Rectangle PopFirst();
	Rectangle PopLast();
	Rectangle PopAtIndex(int n);
};
#endif
