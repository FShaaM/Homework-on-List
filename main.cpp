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

template< class T > // удалить голову
BiList<T>* cut(BiList<T>* h) noexcept
{
	if (!h)
	{
		return nullptr;
	}
	else if (h->next == nullptr)
	{
		delete h; // Деструктор
		return nullptr;
	}
	else
	{
		BiList<T>* newhead = h->next;
		newhead->prev = nullptr;
		delete h; // Деструктор
		return newhead;
	}
}

template< class T > // удалить после
BiList<T>* erase(BiList<T>* h) noexcept
{
	if (!h || h->next == nullptr)
	{
		return h;
	}
	else
	{
		BiList<T>* node = h->next;
		h->next = node->next;

		if (h->next != nullptr)
			h->next->prev = h;

		delete node; // Деструктор
		return h;
	}
}

int main()
{}
