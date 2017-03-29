#include <iostream>
#include "GenericLinkedList.h"

int ID::_ID::EnumToInt(const _ID& enumerationIDs)
{
	return static_cast<int>(enumerationIDs);
}
template<typename T> int List<T>::index = 1;
template<typename T, T first, T...args>
void _AssignMore_<T, first, args...>::internallyFunction(List<T>* obj)
{
	obj->assign(first);
	_AssignMore_<T, args...>* laterPointer = nullptr;
	laterPointer->internallyFunction(obj);
	return;
}
template<typename T, T last>
void _AssignMore_<T, last>::internallyFunction(List<T>* obj)
{
	obj->assign(last);
	return;
}
template<typename T> List<T>::List()
{
	beginnerNode = new Node<T>;
	beginnerNode->nextPointer = nullptr;
	beginnerNode->backPointer = nullptr;
	beginnerNode->Value = 0;
	firstDanglingNode = new Node<T>;
	firstDanglingNode->nextPointer = beginnerNode;
	beginnerNode->backPointer = firstDanglingNode;
	firstDanglingNode->backPointer = nullptr;
	firstDanglingNode->Value = 0;
}
template<typename T> void List<T>::assign(const T& val)
{
	currentNode = new Node<T>;
	currentNode->nextPointer = nullptr;
	currentNode->Value = val;
	beginnerNode->nextPointer = currentNode;
	currentNode->backPointer = beginnerNode;
	beginnerNode = currentNode;
	++index;
	return;
}
template<typename T>
template<int Size> void List<T>::assignMore_decimalTypes_(T value, ...)
{
	const int universalFunctionArgumentSize = 0x04;
	char* startingPointer = (char*)&value;
	if (SameType<T, float>::result)
	{
		const float& next = *(float*)startingPointer;
		assign(next);
		startingPointer += universalFunctionArgumentSize;
		for (int i = 0; i != Size - 1; ++i)
		{
			startingPointer += i*sizeof(double);
			const double& next = *(double*)startingPointer;
			assign(next);
		}
	}
	if (SameType<T, double>::result)
	{
		for (int i = 0; i != Size; ++i)
		{
			startingPointer = (char*)&value + i*sizeof(T);
			const T& next = *(T*)startingPointer;
			assign(next);
		}
	}
	return;
}
template<typename T> const char* List<T>::TypeID() const
{
	int temp =
		SameType<T, int>::result         ? ID::EnumToInt(ID::_ID::INT)        :
		SameType<T, float>::result       ? ID::EnumToInt(ID::_ID::FLOAT)      :
		SameType<T, double>::result      ? ID::EnumToInt(ID::_ID::DOUBLE)     :
		SameType<T, bool>::result        ? ID::EnumToInt(ID::_ID::BOOL)       :
		SameType<T, char>::result        ? ID::EnumToInt(ID::_ID::CHAR)       :
		SameType<T, const char*>::result ? ID::EnumToInt(ID::_ID::STRING)     :
		SameType<T, int*>::result        ? ID::EnumToInt(ID::_ID::INT_VECTOR) :
		ID::EnumToInt(ID::_ID::ANY_THING_ELSE);
	return
		temp == 0 ? "integer"                :
		temp == 1 ? "floating point"         :
		temp == 2 ? "character"              :
		temp == 3 ? "double"                 :
		temp == 4 ? "boolean"                :
		temp == 5 ? "string"                 :
		temp == 6 ? "integer_array (vector)" :
		"any custom type"
	;
}
template<typename T> void List<T>::printList() const
{
	std::cout << "List of <" << TypeID() << ">" << '\n';
	std::cout << "************" << '\n';
	Node<T>* temporaryNode = firstDanglingNode->nextPointer;
	while (temporaryNode->nextPointer != nullptr)
	{
		std::cout << temporaryNode->nextPointer->Value << '\n';
		temporaryNode = temporaryNode->nextPointer;
	}
	return;
}
template<typename T> void List<T>::freeResource()
{
	while (index != 1)
	{
		beginnerNode = currentNode->backPointer;
		delete currentNode;
		currentNode = beginnerNode;
		--index;
	}
	EmptyNode();
	return;
}
template<typename T> void List<T>::EmptyNode()
{
	firstDanglingNode = currentNode->backPointer;
	delete currentNode;
	firstDanglingNode->nextPointer = nullptr;
	--index;
	if (firstDanglingNode->nextPointer == nullptr && firstDanglingNode->backPointer == nullptr)
		delete firstDanglingNode;
	std::cout << "all resources freed and Node index is = " << index << '\n';
	std::cout << "--------------------------------" << '\n';
	std::cout << '\n';
	return;
}
template<typename T>
template<typename U, U first, U... args> 
void List<T>::assignMore_intergralTypes_()
{
	_AssignMore_<U, first, args...>* internalStructurePointer = nullptr;
	internalStructurePointer->internallyFunction(this);
	return;
}
template<typename T, typename...U> HashTable<T, U...>::HashTable(const T& t, const U&...u)
{
	generate<T, U...>(t, u...);
	return;
}
template<typename T, typename...U>
template<typename V, typename...W> void HashTable<T, U...>::generate (
	const typename TypeGeneratorOfListHead<V, W...>::Head& first, const W&...w
)
{
	printIt<typename TypeGeneratorOfListHead<V, W...>::Head>(&first);
	generate<W...>(w...);
	return;
}
template<typename T, typename...U>
template<typename V, typename...W> void HashTable<T, U...>::generate (
	const typename TypeGeneratorOfListHead<V, W...>::Head& first
)
{
	printIt<typename TypeGeneratorOfListHead<V, W...>::Head>(&first);
	return;
}
template<typename T, typename...U>
template<typename AsListType> void HashTable<T, U...>::printIt(const AsListType* const argument)
{
	argument->printList();
	return;
}