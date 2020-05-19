struct Obj{
	int val_;
	Obj(int val): val_(val){}
};

struct Node{
	Obj data_;
	Node * next_;
	Node(const Obj & data = 0, Node * next = 0)
		:data_(data), next_(next)
	{}
}

class List
{
	Node * head_;
	Node * curr_;

public:
	typedef Node * Iterator;
	List(): head_(new Node()), curr_(0){}
	
	void insert(Iterator dest, const Obj & data){
		if (dest == curr_)
		{
			curr_->next_ = new Node(data, curr_->next_);
		}
		else if (next_)
		{
			curr_ = curr_->next_;
		}
	}

	Iterator start(){return head_;}
	Iterator GetNext(){return next_;}
	Obj & GetData(){return data_;}
};

int main()
{
	List * list = new List(Obj(1));
	List::Iterator itt = list->start();

	for(; itt; itt = itt->GetNext())
	{}
}