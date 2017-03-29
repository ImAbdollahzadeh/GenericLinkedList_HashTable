#include <iostream>
#include "GenericLinkedList.h"

int main()
{
	List<char> mylist_char;
	mylist_char.assign('i');
	mylist_char.assign('m');
	mylist_char.assignMore_intergralTypes_<char, 'a', 'n'>();

	List<int> mylist_int;
	mylist_int.assign(12);
	mylist_int.assignMore_intergralTypes_<int, 56, 44, 1>();
	mylist_int.assign(4568);

	List<float> mylist_float;
	mylist_float.assign(4.01f);
	mylist_float.assignMore_decimalTypes_<2>(0.13f, 78.156f);
	mylist_float.assign(22.22f);

	List<double> mylist_double;
	mylist_double.assign(89.145);
	mylist_double.assign(0.021);
	mylist_double.assignMore_decimalTypes_<3>(18.01, 66.66, 14.023);
	mylist_double.assign(22.22);
	mylist_double.assignMore_decimalTypes_<2>(94.31, 0.05);

	HashTable<
		List<char>,  List<int>,
		List<float>, List<double>
	> hashT(mylist_char, mylist_int, mylist_float, mylist_double);

	mylist_char.freeResource();
	mylist_int.freeResource();
	mylist_float.freeResource();
	mylist_double.freeResource();
}