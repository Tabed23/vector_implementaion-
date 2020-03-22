#include<iostream>
using namespace std;
template<typename tm>
class vector
{
private:
	tm * ptr;
    int capicity;
	int size;
protected:

	tm * Allocate(int);
	void Copy(tm *&,tm*);
public:
	vector();
	vector(int);
	~vector();
	tm at(int)const;
	tm operator[](int)const;
	tm front()const;
	tm back()const;
	bool empty()const;
	int Size()const;
	void push_back(tm);
	void pop_back();
	void print();
};

template<typename tm>
vector<tm>::vector()
{
    size = 0;
    capicity = 1;
    ptr = new tm[capicity];
}
template<typename tm>
vector<tm>::vector(int n)
{
	cout << "Constructor has been called..\n";
	this->size = this->capicity= n;
	this->ptr = Allocate(n);
}
template<typename tm>
vector<tm>::~vector()
{
		cout << " Distructor......!!!!!\n";
        if(size !=0 && ptr)
        {
            delete[] ptr;
            ptr= nullptr;
        }
		
}
template<typename tm>
tm vector<tm>::at(int index)const
{
	if (index >= this->size){ throw invalid_argument("out of range... ending the program"); exit(1); }
	return this->ptr[index];
}
template<typename tm>
tm* vector<tm>::Allocate(int n)
{
	return new tm[n];
}
template<typename tm>
 tm vector<tm>::operator[](int n)const
{
	if (n >= this->size){ throw invalid_argument("out of range... ending the program"); exit(1); }
	return this->ptr[n];
}
template<typename tm>
tm vector<tm>::front()const
{
	if (this->size == 0){ throw invalid_argument("vector is not initalize"); };
	return this->ptr[0];
}
template<typename tm>
void vector<tm>::Copy(tm *& v, tm * n)
{
	int i = 0;
	while(v[i]=n[i])i++;
}
template<typename tm>
tm vector<tm>::back()const
{
	if (this->size == 0){ throw invalid_argument("vector is not initalize"); };
	return this->ptr[this->size - 1];
}
template<typename tm>
int vector<tm>::Size()const
{
	return this->size;
}
template<typename tm>
bool vector<tm>::empty()const
{
	if(this->size == 0)
    {
        return true;
    }
    return false;
}
template<typename tm>
void vector<tm>::push_back(tm n)
{
	if(size ==  capicity)
	{
		tm * newptr = Allocate(size +1);
		Copy(newptr, this->ptr);
		if(size!=0)
		{
			delete [] ptr;
			ptr =  nullptr;
		}
		capicity =  capicity *2;
		ptr = Allocate(capicity);
		Copy(ptr, newptr);
	}
	ptr[size]= n;
	size ++;
}
template<typename tm>
void vector<tm>::pop_back()
{
	if(size == 0)
	{
		throw invalid_argument("vector is empty cannot do pop back \n");
		return;
	}
	tm * newptr = Allocate(this->size-1);
    int i =0 ;
   Copy(newptr,this->ptr);
    if(size!= 0)
    {
        delete[] this->ptr;
        ptr =  nullptr;
    }
    this->ptr = newptr;
    size--;
}
template<typename tm>
void vector<tm>::print()
{
	for(int i=0; i<size; i++)
	{
		cout << ptr[i] << " ";
	}
	cout <<endl;
}