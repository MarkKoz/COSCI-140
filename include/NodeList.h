#ifndef CH17_QUIZ_NODELIST_H
#define CH17_QUIZ_NODELIST_H

#include "Circle.h"

class NodeList {
public:
	NodeList();

	NodeList(const NodeList& list);

	~NodeList();

	void appendNode(Circle* node);

	void prependNode(Circle* node);

	void insertNodeAscending(Circle* node);

	void insertNodeDescending(Circle* node);

	void displayNodes() const;

	bool searchNode(int radius) const;

	void destroyList() const;

	NodeList& operator=(const NodeList& rvalue);

private:
	Circle* head;
};

#endif
