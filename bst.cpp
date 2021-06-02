#include <cstdio>

using namespace std;

struct node {
	int info;
	node *left, *right;
};

typedef node* NODE;
class BST {
	public:
		NODE root;

		BST() {
			root = NULL;
		}

		void insert();
		void delet();
		void search(int);
		void display(NODE, int);
		void inorder(NODE);
		void preorder(NODE);
		void postorder(NODE);
};

void BST::insert() {
	NODE temp, cur, prev;

	int item;

	printf("Enter element to insert: ");
	scanf("%d", &item);

	temp = new node;

	temp->info = item;
	temp->left = NULL;
	temp->right = NULL;

	if (root == NULL) {
		root = temp;
		return ;
	}

	prev = NULL;
	cur = root;

	while (cur != NULL) {
		prev = cur;
		if (item == cur->info) {
			printf("Duplicate items are not allowed\n");
			delete(temp);
			return ;
		}
		if (item < cur->info)
			cur = cur->left;
		else
			cur = cur->right;
	}
	if (item < prev->info)
		prev->left = temp;
	else
		prev->right = temp;
}

void BST::delet() {
	NODE cur, parent, suc, q;

	int item;

	printf("Enter item to be deleted: ");
	scanf("%d", &item);

	if (root == NULL) {
		printf("Tree is empty\n");
		return ;
	}

	parent = NULL;

	cur = root;

	while (cur != NULL) {
		if (item == cur->info)
			break;
		parent = cur;

		if (item < cur->info)
			cur = cur->left;
		else
			cur = cur->right;
	}
	if (cur == NULL) {
		printf("Item not found in the tree\n");
		return ;
	}

	if (cur->left == NULL)
		q = cur->left;
	else if (cur->right == NULL)
		q = cur->right;
	else {
		NODE suc = cur->right;
		while (suc->left != NULL)
			suc = suc->left;
		suc->left = cur->left;
		q = cur->right;
	}

	if (parent == NULL)
		root = q;
	else if (parent->left == cur)
		parent->left = q;
	else
		parent->right = q;

	delete cur;
}

void BST::display(NODE root, int level) {
	if (root == NULL)
		return ;

	display(root->right, level+1);
	for (int i = 0; i < level; i++)
		printf(" ");

	printf("%d\n", root->info);
	display(root->left, level+1);
}

void BST::inorder(NODE root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->info);
		inorder(root->right);
	}
}

void BST::preorder(NODE root) {
	if (root != NULL) {
		preorder(root->left);
		preorder(root->right);
		printf("%d ", root->info);
	}
}

void BST::postorder(NODE root) {
	if (root != NULL) {
		printf("%d ", root->info);
		postorder(root->left);
		postorder(root->right);
	}
}

void BST::search(int key) {
	if (root == NULL) {
		printf("Key item not found\n");
		return ;
	}
	NODE cur = root;
	while (cur != NULL && cur->info != key)
		cur = (key < cur->info) ? cur->left : cur->right;

	if (cur == NULL) {
		printf("Key item not found\n");
		return ;
	}

	printf("Key item found in the tree\n");
}

int main() {
	BST a;
	int ch;
	while (1) {
		printf("\nBST Operations\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Preorder\n");
		printf("5. Inorder\n");
		printf("6. Postorder\n");
		printf("7. Exit\n");
		printf("Enter option: ");
		scanf("%d", &ch);

		if (ch == 1)
			a.insert();
		else if (ch == 2)
			a.delet();
		else if (ch == 3) {
			int key;

			printf("Enter key: ");
			scanf("%d", &key);

			a.search(key);
		}

		else if (ch == 4) {
			a.display(a.root, 1);
			a.preorder(a.root);
		}
		else if (ch == 5) {
			a.display(a.root, 1);
			a.inorder(a.root);
		}
		else if (ch == 6) {
			a.display(a.root, 1);
			a.postorder(a.root);
		}
		else if (ch == 7)
			break;
		else
			printf("Invalid choice\n");
	}

	return 0;
}
