#include <iostream>
#include <iomanip>
#include "NodeList.h"

using namespace std;

int main() {
	// Declare pointers to Circle objects.
	Circle* circle1 = 0;
	Circle* circle2 = 0;
	Circle* circle3 = 0;
	Circle* circle4 = 0;

	// No Circle object may be created with a negative value for a radius.
	try {
		// A zero is allowed; the circle degenerates to a point.
		circle1 = new Circle(-10);
	} catch (Circle::ErrorAllocatingMemory e) {
		cout << "You entered the following value for the radius of  a circle "
		     << e.getValue() << endl;
		cout << "you want created; this is an illegal value " << endl;
		cout << "and the circle was not created, but the rest of the " << endl;
		cout << "program continues... " << endl << endl;
	}

	// Allocates memory for three Circle objects.
	circle2 = new Circle(20);
	cout << "There is " << circle2->getCircleCount() << " circle in the list"
	     << endl;

	circle3 = new Circle(30);
	cout << "There are " << circle2->getCircleCount() << " circles in the list"
	     << endl;

	circle4 = new Circle(40);
	cout << "There are " << circle2->getCircleCount() << " circles in the list"
	     << endl;

	// Creates am empty list to store Circle objects.
	NodeList circleList_1;

	// Calls appendNode().
	circleList_1.appendNode(circle2);
	circleList_1.appendNode(circle4);
	circleList_1.appendNode(circle1);
	circleList_1.appendNode(circle3);

	// Nodes (Circle objects) should be displayed in the order entered.
	cout << "Display circleList_1\n";
	circleList_1.displayNodes();
	system("pause");

	// destroyList() should call the destructor of NodeList, which will destroy
	// all the Circle objects in the list and set head = NULL.
	circleList_1.destroyList();
	system("pause");

	// After destroying circleList_1, it should be possible to create new
	// Circle objects using the same variable names as before.
	circle1 = new Circle(10);
	circle2 = new Circle(20);
	circle3 = new Circle(30);
	circle4 = new Circle(40);

	// Creates a new list.
	NodeList circleList_2;

	// Calls prependNode(); means last in, first out.
	circleList_2.prependNode(circle2); // Last node in the list.
	circleList_2.prependNode(circle4);
	circleList_2.prependNode(circle3);
	circleList_2.prependNode(circle1); // First node in the list.

	// Displays circleList_2.
	cout << "Display circleList_2\n";
	circleList_2.displayNodes();
	system("pause");

	// Calls prependNode() to copy circleList_2's elements to circleList_3.
	// This means circleList_3 will have the same elements as circleList_2,
	// but in reverse order.
	NodeList circleList_3(circleList_2);

	// destroyList() should call the destructor of NodeList, which will destroy
	// all the Circle objects in the list and set head = NULL.
	circleList_2.destroyList();
	cout << "circleList_2 destroyed\n";
	system("pause");

	// Displays circleList_3.
	cout << "Display circleList_3\n";
	circleList_3.displayNodes();
	system("pause");

	// Creates more Circle objects.
	Circle* circle11 = new Circle(11);
	Circle* circle22 = new Circle(22);
	Circle* circle33 = new Circle(33);
	Circle* circle44 = new Circle(44);

	// Regardless of the value of the radius of each Circle and the order
	// in which circles are added to the list, each Circle address MUST be
	// placed in the list at the EXACT and correct position so that
	// ALL inserted Circle objects end up in SORTED fashion from smallest to
	// largest.
	circleList_1.insertNodeAscending(circle33);
	circleList_1.insertNodeAscending(circle22);
	circleList_1.insertNodeAscending(circle44);
	circleList_1.insertNodeAscending(circle11);

	cout << "Display circleList_1\n";
	circleList_1.displayNodes();
	system("pause");

	NodeList circleList_4;

	// Calls overloaded operator=.
	// Calls prependNode() to copy the list.
	circleList_4 = circleList_1;
	// The above statement is equivalent to:
	// circleList_4.operator=(circleList_1);

	cout << "Display circleList_4\n";
	circleList_4.displayNodes();
	system("pause");

	// Creates more Circle objects.
	Circle* circle50 = new Circle(50);
	Circle* circle51 = new Circle(51);
	Circle* circle52 = new Circle(52);
	Circle* circle53 = new Circle(53);

	// Creates a list to store the Circle objects just created.
	NodeList circleList_5;

	// Regardless of the value of the radius of each Circle and the order
	// in which circles are added to the list, each Circle address MUST be
	// placed in the list at the EXACT and correct position so that
	// ALL inserted Circle objects end up in SORTED fashion from largest to
	// smallest.
	circleList_5.insertNodeDescending(circle50);
	circleList_5.insertNodeDescending(circle52);
	circleList_5.insertNodeDescending(circle51);
	circleList_5.insertNodeDescending(circle53);

	cout << "Display circleList_5\n";
	circleList_5.displayNodes();
	system("pause");

	// searchNode() takes an int which represents the value of the radius of a
	// Circle object. Returns true if the circle is in the list; false
	// otherwise.
	if (circleList_5.searchNode(50)) {
		cout << "There is a circle with radius value equal to 50" << endl;
	} else {
		cout << "There is no circle with radius value equal to 50" << endl;
	}

	if (circleList_5.searchNode(35)) {
		cout << "There is a circle with radius value equal to 35" << endl;
	} else {
		cout << "There is no circle with radius value equal to 35" << endl;
	}

	system("pause");

	return 0;
}
