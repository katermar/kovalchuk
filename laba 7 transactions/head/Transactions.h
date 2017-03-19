#pragma once

template <class T2>
class Tran
{
	T2 *that;
	T2 *prev;
public:
	Tran() :prev(NULL), that(new T2){}
	~Tran() { delete that; delete prev; }

	T2* beginTrans()
	{		
		delete prev;
		prev = that;
		that = new T2(*prev);
		if (that) return that;
		else return NULL;
	}

	void commit()
	{
		delete prev;
		prev = NULL;
	}

	void deleteTrans()
	{
		if (prev != NULL) {
			delete that;
			that = prev;
			prev = NULL;
		}
	}

	T2* getPrev()
	{
		return prev;
	}

	T2* operator->() { return that; }

	Tran<T2>& operator=(const Tran<T2>& obj)
	{
		if (this != &obj)
		{
			delete that;
			that = new T2(*(obj.that));
		}
		return *this;
	}
};
