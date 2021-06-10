/* program to construct an Expression tree for a
given prefix expression and perform recursive and non-recursive  
traversals*/

#include <iostream>

using namespace std;

struct TreeNode{
    char data;
    struct TreeNode *left, *right;
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
};

TreeNode* ExpressionTree :: createNode(char s){
    TreeNode* tmpNode = new TreeNode;
    tmpNode = NULL;
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
    for(int i=eqn.length()-1; i>=0; i++)
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
    if(top == NULL)
        cout<<"Stack Empty"<<endl;
    else{
        TreeNode *ptr = top->treeNode;
        top = top->next;
        return ptr;
    }
}

void ExpressionTree :: inorder(TreeNode *ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        cout<<" "<<ptr->data;
        inorder(ptr->right);
    }
}

void ExpressionTree :: preorder(TreeNode *ptr){
    if(ptr!=NULL){
        cout<<" "<<ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void ExpressionTree :: postorder(TreeNode *ptr){
    if(ptr!=NULL){
        preorder(ptr->left);
        preorder(ptr->right);
        cout<<" "<<ptr->data;
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
        cout<<" "<<temp->data;
        temp = temp->right;
    }
}

void ExpressionTree :: preorder_nonR(TreeNode *temp){
    top =NULL;
    while(temp!=NULL || top!=NULL){
        while(temp!=NULL){
            cout<<" "<<temp->data;
            push(temp);
            temp = temp->left;
        }
        temp = pop();
        temp = temp->right;
    }
}

void ExpressionTree :: display(){
    cout<<endl<<"Inorder : ";
    inorder(root);
    cout<<endl<<"Inorder Nonrecursive : ";
    inorder_nonR(root);
    cout<<endl<<"Preorder : ";
    preorder(root);
    cout<<endl<<"Preorder Nonrecursive : ";
    preorder_nonR(root);
    cout<<endl<<"Postorder : ";
    postorder(root);
    cout<<endl;
}

int main(){
    string s;
    ExpressionTree et;
    cout<<endl<<"Enter equation in Prefix form: ";
    cin>>s;
    et.buildTree(s);
    cout<<"Travesals :"<<endl;
    et.display();
    return 0;
}