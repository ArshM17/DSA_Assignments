typedef struct node{
	int val;
	char bf;
	struct node *left, *right, *parent;
}node;

typedef node* tree;

void init(tree* root);
void insert(tree* root, int val);
void rem(tree* root, int val);
void inorder(tree root);
