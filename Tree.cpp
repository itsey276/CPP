#include <iostream>
#include <vector>
using namespace std;

template <typename Type>
class Node {
public:
	Type data;
	std::vector<Node*> children;  // pointers to Node 

	Node(Type input) {
		data = input;
	}
};

int main()
{
	Node<int> myrootNode(5);
	cout << "I created a new root node with value = " << myrootNode.data << endl;
	cout << "This node has " << myrootNode.children.size() << " children." << endl;
	return 0;

}

