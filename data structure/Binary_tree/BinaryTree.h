template <class T>
class BinaryTree {
	class Node {
	public:
		Node(){}
		~Node(){}

		T data_;
		Node * left_;
		Node * rught_;
	};

	Node * root_;
};
