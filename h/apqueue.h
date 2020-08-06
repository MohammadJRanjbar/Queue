#ifndef apqueue_h
#define apqueue_h
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <memory>
#include"normalstudent.h"
#include"exponentialstudent.h"
#include"student.h"
template<typename T>
class APQueue
{
	public : 
		//constructor for making a queue out of a vector

		APQueue(std::vector<T>&);
		APQueue(std::vector<T>&&);
		//copy constructor
		APQueue(APQueue&);
		//default constructor
		APQueue()=default;
		//push to queue
		APQueue<T>* enqueue(T&);
		//push to queue for l values
		APQueue<T>* enqueue(T&&);
		//pop from queue
		T dequeue();
		//destructor
		~APQueue();
		T* Dequeue();
		
		T operator[](size_t);
		void show();
	private:
		//Node clas
		struct Item
		{	
			Item(T &item);
			Item(Item*);
			Item(Item& item);
			Item* pnext{ nullptr };
			T* pvalue{ nullptr };

		};
		Item* phead{ nullptr };
		Item* ptial{ nullptr };
		size_t size{ 0 };
};
#include"apqueue.hpp"
#endif
