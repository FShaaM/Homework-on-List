template< class T >
struct BiList {
	T val;
	BiList<T>* next;
	BiList<T>* prev;

	BiList() : next(nullptr), prev(nullptr) {}
};

template< class T > // добавить перед
BiList<T>* add(BiList<T>* h, const T& d)
{
	BiList<T>* newNode = new BiList<T>;
	try
	{
		newNode->val = d; // Оператор копирующего присваивания
	}
	catch (...)
	{
		delete newNode;
		throw;
	}

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
	try
	{
		newNode->val = d; // Оператор копирующего присваивания
	}
	catch (...)
	{
		delete newNode;
		throw;
	}

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
	if (!h) return nullptr;

	if (h->next == nullptr)
	{
		delete h;
		return nullptr;
	}

	BiList<T>* newhead = h->next;
	newhead->prev = nullptr;

	delete h;

	return newhead;
}

template< class T > // удалить после
BiList<T>* erase(BiList<T>* h) noexcept
{
	if (!h || h->next == nullptr) return h;

	BiList<T>* node = h->next;
	h->next = node->next;

	if (h->next != nullptr)
		h->next->prev = h;

	delete node;
	return h;
}

template< class T > // очистить
BiList<T>* clear(BiList<T>* h, BiList<T>* e) noexcept
{
	if (h == e) return e;

	BiList<T>* after = e;
	BiList<T>* before = h->prev;

	while (h != e)
	{
		BiList<T>* next = h->next;
		delete h;
		h = next;
	}

	if (before) before->next = after;
	if (after) after->prev = before;

	return after;
}

template< class T, class F > // обход
F traverse(F f, BiList<T>* h, BiList<T>* e)
{
	BiList<T>* cur = h;

	while (cur != nullptr)
	{
		f(cur->val);
		if (cur == e) break;
		cur = cur->next;
	}

	return f;
}

template <class T>
BiList<T>* arrayToList(const T* arr, size_t size)
{
	if (!arr || !size) return nullptr;

	BiList<T>* head = nullptr;
	BiList<T>* tail = nullptr;

	try
	{
		head = add(head, arr[0]);
		tail = head;

		for (size_t i = 1; i < size; ++i)
		{
			tail = insert(tail, arr[i]);
		}
	}
	catch (...)
	{
		clear(head, nullptr);
		throw;
	}

	return head;
}

int main()
{
	try
	{
		int arr[5] = { 0, 1, 2, 3, 4 };
		BiList<int>* head = arrayToList(arr, 5);
		head = clear<int>(head, nullptr);
	}
	catch (...)
	{
		return 1;
	}

	return 0;
}
