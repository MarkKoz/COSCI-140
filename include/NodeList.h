#ifndef CH17_QUIZ_NODELIST_H
#define CH17_QUIZ_NODELIST_H

#include "Circle.h"

class NodeList {
public:
	/**
	 * Constructs an empty linked list of Circle objects.
	 */
	NodeList();

	/**
	 * Copy constructor. Constructs a linked list of Circle objects which are
	 * copied from the given NodeList and prepended to this list.
	 *
	 * @param   list        const lvalue reference to the NodeList to be copied
	 */
	NodeList(const NodeList& list);

	/**
	 * Destroys the Circle objects in all nodes in this list and sets head to
	 * nullptr.
	 */
	~NodeList();

	/**
	 * Adds the given Circle object as a new node at the end of this list.
	 *
	 * @param   node        a pointer to the Circle object to be appended
	 */
	void appendNode(Circle* node);

	/**
	 * Adds the given Circle object as a new node at the start of this list.
	 *
	 * @param   node        a pointer to the Circle object to be prepended
	 */
	void prependNode(Circle* node);

	/**
	 * Inserts the given Circle object as a new node at a position in which
	 * its radius is greater than that of the Circle object in the node
	 * preceding the node to be inserted but less than that of the Circle
	 * object in the node proceeding the node to be inserted.
	 *
	 * @param   node        a pointer to the Circle object to be inserted
	 */
	void insertNodeAscending(Circle* node);

	/**
	 * Inserts the given Circle object as a new node at a position in which
	 * its radius is less than that of the Circle object in the node
	 * preceding the node to be inserted but greater than that of the Circle
	 * object in the node proceeding the node to be inserted.
	 *
	 * @param   node        a pointer to the Circle object to be inserted
	 */
	void insertNodeDescending(Circle* node);

	/**
	 * Prints to console a comma-delimited list of the radius of every Circle
	 * object in this list.
	 */
	void displayNodes() const;

	/**
	 * Searches the nodes in this list to determine if a Circle object with the
	 * given radius exists in this list.
	 *
	 * @param   radius      the radius with which to search for Circle objects
	 * @return              true if a Circle object with the radius exists in
	 *                      this list; false otherwise
	 */
	bool searchNode(int radius) const;

	/**
	 * Calls this list's destructor.
	 */
	void destroyList() const;

	/**
	 * Assignment operator overload. Copies the Circle objects in the nodes
	 * of the NodeList right of the operator and prepends them to this list.
	 *
	 * @param   rvalue      const lvalue reference to the NodeList right of
	 *                      the operator
	 * @return              lvalue reference to this list (i.e. the NodeList
	 *                      left of the operator)
	 */
	NodeList& operator=(const NodeList& rvalue);

private:
	Circle* head; // Pointer to the first node in the linked list.
};

#endif
