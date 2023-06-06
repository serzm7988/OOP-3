
#include <iostream>

template <typename T>
class list
{
public:
	class iterator;
	friend class iterator;

private:
	class node;
	friend class node;

	class node
	{
	public:
		friend class list<T>;
		friend class iterator;

		node(T node_val) : val(node_val) {}
		node() {}
		~node() {}

		void print_val() { std::cout << val << " "; }

		node* next;
		T val;

	};

public:
	class iterator
	{
		friend class list<T>;

	public:


		iterator() :the_node(0) {}

		iterator(node* dn) : the_node(dn) {}

		iterator(const iterator& it) : the_node(it.the_node) {}

		iterator& operator=(const iterator& it)
		{
			the_node = it.the_node;
			return *this;
		}


		bool operator == (const iterator& it) const
		{
			return (the_node == it.the_node);
		}


		bool operator!=(const iterator& it) const
		{
			return !(it == *this);
		}

		iterator& operator++()
		{
			the_node = the_node->next;
			return *this;
		}

		T& operator*() const
		{
			return the_node->val;
		}
	private:
		node* the_node;


	};

private:
	node* head;
	node* tail;

	iterator head_iterator;
	iterator tail_iterator;
public:
	list()
	{
		head = tail = new node;
		tail->next = nullptr;

		head_iterator = iterator(head);
		tail_iterator = iterator(tail);
	}

	list(T node_val)
	{
		head = tail = new node;
		tail->next = nullptr;

		head_iterator = iterator(head);
		tail_iterator = iterator(tail);
		add_front(node_val);
	}

	~list()
	{
		node* node_to_delete = head;
		for (node* sn = head; sn != tail;)
		{
			sn = sn->next;
			delete node_to_delete;
			node_to_delete = sn;
		}

		delete node_to_delete;
	}

	bool is_empty() { return head == tail; }


	iterator begin() { return head_iterator; }
	iterator end() { return tail_iterator; }

	void add(T node_val)
	{
		node* node_to_add = new node(node_val);
		node_to_add->next = head;
		head = node_to_add;
		head_iterator = iterator(head);
	}

	T remove()
	{
		node* node_to_remove = head;
		T return_val = node_to_remove->val;
		head = node_to_remove->next;
		head_iterator = iterator(head);

		delete node_to_remove;
		return return_val;

	}

	iterator find(T node_val) const
	{
		for (node* dn = head; dn != tail; dn = dn->next)
		{
			if (dn->val == node_val)
				return iterator(dn);
		}

		return tail_iterator;
	}

	iterator get_nth(const int element_num) const
	{
		if (element_num < 1)
			return head_iterator;

		int count = 1;
		for (node* dn = head; dn != tail; dn = dn->next)
		{
			if (count++ == element_num)
				return iterator(dn);
		}

		return tail_iterator;
	}

	int size() const
	{
		int count = 0;
		for (node* dn = head; dn != tail; dn = dn->next)
			++count;
		return count;
	}

	void print() const {
		for (node* dn = head; dn != tail; dn = dn->next)
		{
			dn->print_val();
		}

		std::cout << std::endl;
	}
	void swap(list x) const {
		list y = x;
		x = this;
		this = y;
	}
};