#include <iostream>
#include <string>
#include "NodeList.h"

NodeList::NodeList() {
	head = nullptr;
}

void NodeList::appendNode(Circle* node) {
	if (!head) { // If NodeList is empty, no need to search any further.
		head = node;
	} else {
		Circle* nodeIt = head; // Starts the iteration from first node.

		// Iterates until the last node is reached i.e. when
		// nextNodeLink = nullptr
		while (nodeIt->nextNodeLink) {
			// Advances to the next node in the list.
			nodeIt = nodeIt->nextNodeLink;
		}

		// Assigns the node being appended to nextNodeLink of the current
		// last node.
		nodeIt->nextNodeLink = node;
	}
}

void NodeList::prependNode(Circle* node) {

}

void NodeList::insertNodeAscending(Circle* node) {

}

void NodeList::insertNodeDescending(Circle* node) {

}

void NodeList::displayNodes() {
	std::cout << "The values of the radii of the circles in the list are:\n";

	// Iterates through every node in the list starting at head.
	for (Circle* nodeIt = head; !nodeIt->nextNodeLink; nodeIt = nodeIt->nextNodeLink) {
		std::string delim = "";

		// Prints a delimiter for every node following the first.
		if (nodeIt != head) {
			delim = ", ";
		}

		std::cout << delim << nodeIt->getCircleRadius();
	}

	std::cout << '\n';
}

bool NodeList::searchNode(int radius) {
	return false;
}

void NodeList::destroyList() {

}

NodeList::NodeList(const NodeList& list) {

}

NodeList::~NodeList() {

}
