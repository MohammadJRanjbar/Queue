
template<typename T>
void APQueue<T>::show()
{
	//to show simple queue like int bector
	std::cout << "APQueue of size: " << size << std::endl;
	if(size!=0)
	{	Item temp{ *phead };
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "No: " << i+1 << "    " << *(temp.pvalue) << std::endl;
			//do it until the tail
			if (temp.pnext != nullptr)
				temp = *(temp.pnext);
		}
	}
}
template<typename T>
APQueue<T>::APQueue(std::vector<T>&vec)
{
	//it will push all the elements to the queue
	for (size_t i = 0; i < vec.size(); i++)
	{
		enqueue(vec[i]);
	}
}
template<typename T>
APQueue<T>::APQueue(std::vector<T>&&vec)
{		
	//it will push all the elements to the queue
	for (size_t i = 0; i < vec.size(); i++)
	{
		this->enqueue(vec[i]);
	}
}
template<typename T>
APQueue<T>::APQueue(APQueue& ap)
{
	//copy constructor
	this->phead=ap.phead;
	this->ptial=ap.ptial;
	this->size=ap.size;
}
template<typename T>
APQueue<T>* APQueue<T>::enqueue(T &item)
{
	//define a new pointer
	Item* new_item = new Item{ item };
	if (phead == nullptr)
	{
		
		//the first element the head and tail are the same
		phead = new_item;
		ptial = new_item;
		phead->pnext = nullptr;
		ptial->pnext = nullptr;
		//new_item->pvalue = &item;
		size++;
	}
	else
	{
		//adding a new tail
		ptial->pnext = new_item;
		ptial = new_item;

		//new_item->pvalue = &item;
		size++;
	}
	return this;
}
template<typename T>
APQueue<T>* APQueue <T>::enqueue(T &&item)
{
	Item* new_item = new Item{ item };
	if (phead == nullptr)
	{
		
		//the first element the head and tail are the same
		phead = new_item;
		ptial = new_item;
		phead->pnext = nullptr;
		ptial->pnext = nullptr;
		size++;
	}
	else
	{
		//adding a new tail
		ptial->pnext = new_item;
		ptial = new_item;
		size++;
	}
	//return the queue
	return this;
}
template<typename T>
APQueue<T>::Item::Item(T &item)
{

	pvalue = std::move(new T{ item });
	pnext = nullptr;

}

template<>
APQueue<std::unique_ptr<Student>>::Item::Item(std::unique_ptr<Student> &item)
{
	pvalue = std::move(&item);
	pnext = nullptr;

}

template<typename T>
APQueue<T>::Item::Item(Item* item)
{
	pvalue = item->pvalue;
	pnext = item->pnext;

}
template<typename T>
APQueue<T>::Item::Item(Item& item)
{
	
	pvalue = item.pvalue;

	pnext = item.pnext;

}
template<typename T>
T APQueue<T>:: dequeue()
{
	if(size!=0)
	{	T temp{ *(phead->pvalue) };
		Item * next = phead->pnext;
		delete phead->pvalue;
		delete phead;
		size--;
		phead = next;
		return temp;
	}
	else
	{
		return 0;
	}
	if(size==0)
	{	
		phead=nullptr;
		ptial=nullptr;
	}
	
}
template<>
void APQueue<std::unique_ptr<Student>>::show()
{
	std::cout << "APQueue of size: " << size << std::endl;
	if(size!=0)
	{	
		Item temp{ this->phead };
		for (size_t i = 0; i < size; i++)
		{
			
			std::cout << "No: " << i + 1 << "  ,  "<<"Name:  " << temp.pvalue->get()->GetName() << std::endl;
			std::cout<<"            " << "Pr{A Grade} = " << std::fixed <<std::setprecision(6) << temp.pvalue->get()->between(17,20) ;
			std::cout<<"      "<<"Pr{B Grade} = "<< std::fixed <<std::setprecision(6) << temp.pvalue->get()->between(14,17) ;
			std::cout<<"      "<<"Pr{C Grade} = "<< std::fixed <<std::setprecision(6) << temp.pvalue->get()->between(10,14) ;
			std::cout<<"      "<<"Pr{D Grade} = "<< std::fixed <<std::setprecision(6) << temp.pvalue->get()->between(0,10) <<std::endl<<std::endl;
			if (temp.pnext != nullptr)
				{
					temp = temp.pnext;
				}
		}
	}
}

template<>
std::unique_ptr <Student>*  APQueue<std::unique_ptr <Student>>:: Dequeue()
{
	if(size!=0)
	{	auto ptr { std::move((phead->pvalue)) } ;
		Item * next = phead->pnext;
		delete phead;
		size--;
		phead = next;
		return ptr;
	}
	else
	{
		return 0;
	}
	if(size==0)
	{	
		phead=nullptr;
		ptial=nullptr;
	}
	
}
template<typename T>
APQueue<T>::~APQueue()
{
	while(size!=0)
	{
		dequeue();
	}
}
template<>
APQueue<std::unique_ptr<Student>>::~APQueue()
{
	while(size!=0)
	{
		Dequeue();
	}
}

template<typename T>
T APQueue<T>::operator[](size_t i )
{
	T item{0};
	for (size_t j = 0; j < i+1; j++)
	{
		item=dequeue();
	}
	return item;

}