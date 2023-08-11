rh = 1 + root->right->ht;
if (lh > rh)
return (lh);
return (rh);
}
// inserts a new node in the AVL tree
struct node* insert(struct node* root, int data)
{
if (root == NULL)
{
struct node* new_node = create(data);
if (new_node == NULL)
{
return NULL;
}
root = new_node;
}
else if (data > root->data)
{
// insert the new node to the right
root->right = insert(root->right, data);
// tree is unbalanced, then rotate it
if (balance_factor(root) == -2)
{
if (data > root->right->data)
{
root = rotate_left(root);
}
else
{
root->right = rotate_right(root->right);
root = rotate_left(root);
}
}
}
else
{
// insert the new node to the left
root->left = insert(root->left, data);
// tree is unbalanced, then rotate it
if (balance_factor(root) == 2)
{
if (data < root->left->data)
{
root = rotate_right(root);
}
else
{
root->left = rotate_left(root->left);
root = rotate_right(root);
}
}
}
// update the heights of the nodes
root->ht = height(root);
return root;
}
// deletes a node from the AVL tree
struct node * delete(struct node *root, int x)
{
struct node * temp = NULL;
if (root == NULL)
{
return NULL;
}
if (x > root->data)
{
root->right = delete(root->right, x);
if (balance_factor(root) == 2)
{
if (balance_factor(root->left) >= 0)
{
root = rotate_right(root);
}
else
{
root->left = rotate_left(root->left);
root = rotate_right(root);
}
}
}
else if (x < root->data)
{
root->left = delete(root->left, x);
if (balance_factor(root) == -2)
{
if (balance_factor(root->right) <= 0)
{
root = rotate_left(root);
}
else
{
root->right = rotate_right(root->right);
root = rotate_left(root);
}
}
}
else
{
if (root->right != NULL)
{
temp = root->right;
while (temp->left != NULL)
temp = temp->left;
root->data = temp->data;
root->right = delete(root->right, temp->data);
if (balance_factor(root) == 2)
{
if (balance_factor(root->left) >= 0)
{
root = rotate_right(root);
}
else
{
root->left = rotate_left(root->left);
root = rotate_right(root);
}
}
}
else
{
return (root->left);
}
}
root->ht = height(root);
return (root);
}
// search a node in the AVL tree
struct node* search(struct node* root, int key)
{
if (root == NULL)
{
return NULL;
}
if(root->data == key)
{
return root;
}
if(key > root->data)
{
search(root->right, key);
}
else
{
search(root->left, key); }}
