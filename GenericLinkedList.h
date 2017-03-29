#pragme once
#ifndef GENERICLISTLIST_H_
#define GENERICLISTLIST_H_
	template<typename T> struct Node
	{
		Node<T>* nextPointer;
		Node<T>* backPointer;
		T        Value;
	};
	template<typename T, typename U> struct SameType
	{
		static const bool result = false;
	};
	template<typename T> struct SameType<T, T>
	{
		static const bool result = true;
	};
	struct ID
	{
		enum class _ID
		{
			INT           ,
			FLOAT         ,
			CHAR          ,
			DOUBLE        ,
			BOOL          ,
			STRING        ,
			INT_VECTOR    ,
			ANY_THING_ELSE,
		};
		static int EnumToInt(const _ID& enumerationIDs);
	};
	template<typename T> class List
	{
		private:
			static int  index;
			Node<T>*    beginnerNode;
			Node<T>*    firstDanglingNode;
			Node<T>*    currentNode;
			void        EmptyNode();
			const char* TypeID() const;
		public:
			explicit    List<T>();
			void        assign(const T&);
			void        printList() const;
			void        freeResource();
			template<int Size>
			void        assignMore_decimalTypes_(T value, ...);
			template<typename U, U first, U... args>
			void        assignMore_intergralTypes_();
	};
	template<typename T> int List<T>::index = 1;
	template<typename T, T first, T...args> struct _AssignMore_
	{
		void internallyFunction(List<T>*);
	};
	template<typename T, T last> struct _AssignMore_<T, last>
	{
		void internallyFunction(List<T>*);
	};
	template<typename T, typename...U> struct TypeGeneratorOfListHead
	{
		typedef T Head;
	};
	template<typename T> struct TypeGeneratorOfListHead<T>
	{
		typedef T Head;
	};
	template<typename T, typename...U> struct HashTable
	{
		HashTable(const T&, const U&...);
		template<typename V, typename...W>
		void generate(const typename TypeGeneratorOfListHead<V, W...>::Head&, const W&...);
		template<typename V, typename...W>
		void generate(const typename TypeGeneratorOfListHead<V, W...>::Head&);
		template<typename AsListType>
		void printIt(const AsListType* const);
	};
#endif
