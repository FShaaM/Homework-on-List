template< class T >
struct BiList {
	T val;
	BiList<T>* next;
	BiList<T>* prev;

  BiList() :
		next(nullptr),
		prev(nullptr)
	{}
};

int main()
{}
