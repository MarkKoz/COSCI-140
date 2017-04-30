#include "NodeList.h"

NodeList::NodeList() {
	head = nullptr;
}

void NodeList::appendNode(Circle* node) {
	if (!head) { // If NodeList is empty, no need to search any further.
		head = node;
	} else {
		Circle* searchNode = head; // Starts the search from first node.

		// Iterates through every node to find the last node i.e. when
		// nextNodeLink = nullptr
		while (searchNode->nextNodeLink) {
			searchNode = searchNode->nextNodeLink;
		}

		// Assigns the node being appended to nextNodeLink of the current
		// last node.
		searchNode->nextNodeLink = node;
	}
}

void NodeList::prependNode(Circle* node) {

}

void NodeList::insertNodeAscending(Circle* node) {

}

void NodeList::insertNodeDescending(Circle* node) {

}

void NodeList::displayNodes() {

}

bool NodeList::searchNode(int radius) {

}

void NodeList::destroyList() {

}

NodeList::NodeList(const NodeList& list) {

}

NodeList::~NodeList() {

}
