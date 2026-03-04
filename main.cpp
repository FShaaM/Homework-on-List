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

template< class T > // добавить перед
BiList<T>* add(BiList<T>* h, const T& d)
{
	BiList<T>* newNode = new BiList<T>;
	newNode->val = d; // Оператор копирующего присваивания

	if (h)
	{
		newNode->next = h;
		h->prev = newNode;
	}

	return newNode;
}

template< class T > // добавить после
BiList<T>* insert(BiList<T>* h, const T& d)
{
	BiList<T>* newNode = new BiList<T>; // Конструктор по умолчанию обнулил next и prev
	newNode->val = d; // Оператор копирующего присваивания

	if (h)
	{
		newNode->next = h->next;
		newNode->prev = h;

		if (h->next != nullptr)
			h->next->prev = newNode;

		h->next = newNode;
	}

	return newNode;
}


int main()
{}
