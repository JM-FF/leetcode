#include<iostream>
#include<utility>
using namespace std;

enum COLOR
{
	BLACK,
	RED
};

template<class K, class V>
struct RBNode
{
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;
	RBNode<K, V>* _parent;
	pair<K, V> _value;
	COLOR _color;

	RBNode(const pair<K, V>& value = pair<K,V>())
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(value)
		, _color(RED)
	{}
};

template<class K, class V>
class RBTree
{
public:
	typedef RBNode<K, V> Node;
	typedef  RBNode<K, V>* pNode;

	RBTree()
	{
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}
	bool insert(const pair<K, V>& value)
	{
		if (_header->_parent == nullptr)
		{
			pNode root = new Node(value);
			root->_parent = _header;
			root->_color = BLACK;
			_header->_parent = root;

			_header->_left = root;
			_header->_right = root;
			return true;
		} 

		pNode cur = _header->_parent;
		pNode parent = nullptr;

		//进行插入
		while (cur)     //while寻找插入的位置
		{
			parent = cur;
			//key值不能相等
			if (cur->_value.first == value.first)
				return false;
			else if (cur->_value.first > value.first)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		//创建节点进行插入
		cur = new Node(value);

		if (parent->_value.first > cur->_value.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//调整和更新颜色
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			pNode gfather = parent->_parent;
			if (gfather->_left == parent)
			{
				pNode uncle = gfather->_right;
				//uncle存在并且为红色
				if (uncle && uncle->_color == RED)
				{
					//修改颜色
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//继续向上更新
					cur = gfather;
				}
				else  //uncle不存在或者存在为黑色  执行相同的操作
				{
					//如果存在双旋的场景，既cur在parent的右边，可以先进行一次单旋变成下面的场景
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//右旋
					RotateR(gfather);

					//修改颜色
					parent->_color = BLACK;
					gfather->_color = RED;
					//停止调整
					break;
				}
			}
			else
			{
				pNode uncle = gfather->_left;
				//uncle存在并且为红色
				if (uncle && uncle->_color == RED)
				{
					//进行颜色的更新
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//继续向上更新
					cur = gfather;
				}
				else
				{
					if (cur == parent->_left)
					{
						//右旋
						RotateR(parent);
						//交换
						swap(cur, parent);
					}
					//左旋
					RotateL(gfather);

					//修改颜色
					parent->_color = BLACK;
					gfather->_color = RED;
					//停止调整
					break;
				}
			}
		}
		
		//跟的颜色始终为黑色
		_header->_parent->_color = BLACK;

		//更新_header->left 和_header->right
		_header->_left = leftMost();
		_header->_right = rightMost();

		return true;
	}

	void inorder()
	{
		_inorder(_header->_parent);
		cout << endl;
	}
	void _inorder(pNode root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_value.first << endl;
			_inorder(root->_right);
		}
	}

	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;
		//1,2
		subL->_right = parent;
		parent->_left = subLR;
		//3
		if (subLR)
			subLR->_parent = parent;
		//4,5

		if (parent != _header->_parent)
		{
			pNode gParent = parent->_parent;
			if (gParent->_left == parent)
				gParent->_left = subL;
			else
				gParent->_right = subL;
			subL->_parent = gParent;
		}
		else
		{
			//更新根节点
			_header->_parent = subL;
			subL->_parent = nullptr;
		}
		parent->_parent = subL;

	}

	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent != _header->_parent)
		{
			pNode gparent = parent->_parent;
			if (gparent->_left == parent)
				gparent->_left = subR;
			else
				gparent->_right = subR;
			subR->_parent = gparent;
		}
		else
		{
			_header->_parent = subR;
			subR->_parent = nullptr;
		}
		parent->_parent = subR;
	}

	pNode leftMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_left != nullptr)
		{
			cur = cur->_left;
		}
		return cur;
	}
	pNode rightMost()
	{
		pNode cur = _header->_right;
		while (cur && cur->_right != nullptr)
		{
			cur = cur->_right;
		}
		return cur;
	}

private:
	pNode _header;
};

void testRBtree()
{
	RBTree<int, int> rbt;
	rbt.insert(make_pair(1, 1));
	rbt.insert(make_pair(10, 1));
	rbt.insert(make_pair(-1, 1));
	rbt.insert(make_pair(-2, 1));
	rbt.insert(make_pair(100, 1));
	rbt.insert(make_pair(19, 1));
	rbt.insert(make_pair(20, 1));
	rbt.inorder();
}

int main()
{	
	testRBtree();
	return 0;
}