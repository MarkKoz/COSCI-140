#ifndef CH17_QUIZ_NODELIST_H
#define CH17_QUIZ_NODELIST_H

#include "Circle.h"

class NodeList {
public:
	NodeList();

	void appendNode(Circle* node);

	void prependNode(Circle* node);

	void insertNodeAscending(Circle* node);

	void insertNodeDescending(Circle* node);

	void displayNodes();

	bool searchNode(int radius);

	void destroyList();

private:
	NodeList(const NodeList& list);

	~NodeList();

	Circle* head;
};

#endif
