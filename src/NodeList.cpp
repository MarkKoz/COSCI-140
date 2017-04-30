#include <iostream>
#include <string>
#include "NodeList.h"

NodeList::NodeList() {
	head = nullptr;
}

NodeList::NodeList(const NodeList& list) {
	head = nullptr;

	// Iterates through every node in the list starting at head.
	for (Circle* nodeIt = list.head; !nodeIt->nextNodeLink; nodeIt = nodeIt->nextNodeLink) {
		prependNode(nodeIt);
	}
}

void NodeList::appendNode(Circle* node) {
	if (node) {
		if (!head) { // If the list is empty, no need to iterate.
			head = node;
		} else {
			Circle* nodeIt = head; // Starts the iteration from first node.

			// Iterates until the last node is reached i.e. when
			// nextNodeLink = nullptr
			while (nodeIt->nextNodeLink) {
				// Advances to the next node in the list.
				nodeIt = nodeIt->nextNodeLink;
			}

			// Assigns the node being appended to the next of the current
			// last node.
			nodeIt->nextNodeLink = node;
		}
	}
}

void NodeList::prependNode(Circle* node) {
	if (node) {
		if (!head) { // If the list is empty, no need to iterate.
			head = node;
		} else {
			// Assigns the current head to the next of the node being prepended.
			node->nextNodeLink = head;
			head = node; // Assigns the node being prepended to the head.
		}
	}
}

void NodeList::insertNodeAscending(Circle* node) {
	if (node) {
		if (!head) { // If the list is empty, no need to iterate.
			head = node;
		} else {
			Circle* nodeIt = head; // Starts the iteration from first node.
			Circle* nodePrev = nullptr; // The previous node in the iteration.

			// Iterates until a radius larger than the radius of the node to
			// be inserted is reached.
			while (nodeIt->getCircleRadius() < node->getCircleRadius()) {
				// Saves the current node in the iteration before advancing.
				nodePrev = nodeIt;
				// Advances to the next node in the list.
				nodeIt = nodeIt->nextNodeLink;
			}

			if (!nodePrev) {
				// Prepends because the node is the smallest.
				prependNode(node);
			} else {
				// Inserts after nodePrev i.e. between nodePrev and nodeIt.
				node->nextNodeLink = nodePrev->nextNodeLink;
				nodePrev->nextNodeLink = node;
			}
		}
	}
}

void NodeList::insertNodeDescending(Circle* node) {
	if (node) {
		if (!head) { // If the list is empty, no need to iterate.
			head = node;
		} else {
			Circle* nodeIt = head; // Starts the iteration from first node.
			Circle* nodePrev = nullptr; // The previous node in the iteration.

			// Iterates until a radius smaller than the radius of the node to
			// be inserted is reached.
			while (nodeIt->getCircleRadius() > node->getCircleRadius()) {
				// Saves the current node in the iteration before advancing.
				nodePrev = nodeIt;
				// Advances to the next node in the list.
				nodeIt = nodeIt->nextNodeLink;
			}

			if (!nodePrev) {
				// Prepends because the node is the largest.
				prependNode(node);
			} else {
				// Inserts after nodePrev i.e. between nodePrev and nodeIt.
				node->nextNodeLink = nodePrev->nextNodeLink;
				nodePrev->nextNodeLink = node;
			}
		}
	}
}

void NodeList::displayNodes() {
	std::cout << "The values of the radii of the circles in the list are:\n";

	// Iterates through every node in the list starting at head.
	for (Circle* nodeIt = head;
	        !nodeIt->nextNodeLink;
	        nodeIt = nodeIt->nextNodeLink) {
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
	// Iterates through every node in the list starting at head.
	for (Circle* nodeIt = head;
	        !nodeIt->nextNodeLink;
	        nodeIt = nodeIt->nextNodeLink) {
		if (nodeIt->getCircleRadius() == radius) {
			return true;
		}
	}

	return false;
}

void NodeList::destroyList() {
	NodeList::~NodeList();
}

const NodeList* NodeList::operator=(const NodeList& rvalue) {
	if (&rvalue != this) { // Checks self assignment.
		this->destroyList();

		return new NodeList(rvalue);
	}

	return this;
}

NodeList::~NodeList() {
	Circle* nodeIt = head; // Starts the iteration from first node.
	Circle* nodeNext = nullptr;

	// Iterates until the last node is reached i.e. when
	// nodeIt = nullptr
	while (nodeIt) {
		nodeNext = nodeIt->nextNodeLink; // Stores the pointer to the next node.
		delete nodeIt;
		nodeIt = nodeNext; // Advances to the next node in the list.
	}
}
