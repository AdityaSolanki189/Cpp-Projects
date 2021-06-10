#include <iostream>

using namespace std;

struct TreeNode{
    char data;
    TreeNode *left, *right;
}*root;

class StackNode{
    public:
    TreeNode *treeNode;
    StackNode *next;
    StackNode(TreeNode *treeNode){
        this->treeNode = treeNode;
        next = NULL;
    }
};

class ExpressionTree{
    private:
        StackNode *top;
    public:
        ExpressionTree(){
            top = NULL;
        }
    TreeNode *createNode(char);
    void buildTree(string);
    void insert(char);

    void push(TreeNode *);
    TreeNode *pop();

    void display();
    void inorder(TreeNode *);
    void inorder_nonR(TreeNode *);
    void preorder(TreeNode *);
    void preorder_nonR(TreeNode *);
    void postorder(TreeNode *);
    void postorder_nonR(TreeNode *);
};

TreeNode* ExpressionTree :: createNode(char s){
    TreeNode* tmpNode = new TreeNode;
    tmpNode->left = tmpNode->right = NULL;
    tmpNode->data = s;

    return tmpNode;
}

void ExpressionTree :: insert(char ch){
    TreeNode *temp = new TreeNode;
    temp = createNode(ch);

    if(ch>='0' && ch<='9')
        push(temp);
    else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        temp->left = pop();
        temp->right = pop();
        push(temp);
    }
    else{
        cout<<"Invalid Expression!!"<<endl;
        return;
    }
}

void ExpressionTree :: buildTree(string eqn){
    for(int i=eqn.length()-1; i>=0; i--)
        insert(eqn[i]);
    root = top->treeNode;
}

void ExpressionTree :: push(TreeNode *ptr){
    if(top == NULL)
        top = new StackNode(ptr);
    else{
        StackNode *nxtptr = new StackNode(ptr);
        nxtptr->next = top;
        top = nxtptr;
    }
}

TreeNode* ExpressionTree :: pop(){
    if(top == NULL){
        cout << "Stack Empty" << endl;
        return NULL;
    }
    else{
        TreeNode *ptr = top->treeNode;
        top = top->next;
        return ptr;
    }
}

void ExpressionTree :: inorder(TreeNode *ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        cout << " " << ptr->data;
        inorder(ptr->right);
    }
}

void ExpressionTree :: preorder(TreeNode *ptr){
    if(ptr!=NULL){
        cout << " " << ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void ExpressionTree :: postorder(TreeNode *ptr){
    if(ptr!=NULL){
        preorder(ptr->left);
        preorder(ptr->right);
        cout << " " << ptr->data;
    }
}

void ExpressionTree :: inorder_nonR(TreeNode *temp){
    top =NULL;
    while(temp!=NULL || top!=NULL){
        while(temp!=NULL){
            push(temp);
            temp = temp->left;
        }
        temp = pop();
        cout << " " << temp->data;
        temp = temp->right;
    }
}

void ExpressionTree :: preorder_nonR(TreeNode *temp){
    if(temp == NULL){
        return;
    }
    
    top =NULL;
    push(temp);

    while(top != NULL){
        TreeNode* curr = pop();
        cout << curr->data << " ";

        if(curr->right){
            push(curr->right);
        }

        if(curr->left){
            push(curr->left);
        }
    }
}

void ExpressionTree :: postorder_nonR(TreeNode* root) 
{
    top = NULL; 
    push(root);
 
    char postorder[50];

    int i=0; 
    while (top != NULL) {
        TreeNode* curr = pop();
        postorder[i]=curr->data;
        i++;
 
        if (curr->left) {
            push(curr->left);
        }
 
        if (curr->right) {
            push(curr->right);
        }
    }

    for (int j=i-1; j>=0; j--){
        cout << postorder[j] << " ";
    }
}

void ExpressionTree :: display(){
    cout << "\nInorder : ";
    inorder(root);

    cout << "\nInorder Non-Recursive : ";
    inorder_nonR(root);

    cout << "\n\nPreorder : ";
    preorder(root);

    cout << "\nPreorder Non-Recursive : ";
   preorder_nonR(root);

    cout << "\n\nPostorder : ";
    postorder(root);

    cout << "\nPostorder Non-Recursive : ";
    postorder_nonR(root);
    cout << "\n\n";
}

int main(){
    string str;
    ExpressionTree Obj;

    cout << "\nExpression Tree : \n";
    cout << "Enter Prefix Expression : ";
    cin >> str;

    Obj.buildTree(str);

    cout << "\nTravesals :-";

    Obj.display();

    return 0;
}