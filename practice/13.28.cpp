#include<iostream>
#include<string>

using namespace std;

class TreeNode{

public:
    TreeNode(const string& s):value(s)
    {
        left = nullptr;
        right = nullptr;
        count = 1;
    };

    TreeNode():value("")
    {
        left = nullptr;
        right = nullptr;
        count = 1;
    };


    // 拷贝构造函数
    TreeNode(const TreeNode& t): value(t.value), count(1), left(t.left), right(t.right){
        if(left) left->CopyTree();
        if(right) right->CopyTree();
    }


    // 拷贝赋值函数
    TreeNode& operator=(TreeNode& t){
        ++t.count;
        if(--this->count == 0){
            delete left;
            delete right;
        }
        value = t.value;
        left = t.left;
        right = t.right;
        return *this;
    }

    // 需要一个拷贝子节点的函数
    void CopyTree(){
        if(left) left->CopyTree();
        if(right) right->CopyTree();
        count++;
    }

    int ReleaseTree(){
        if(left){
            if(!left->ReleaseTree())
                delete left;
        }
        if(right){
            if(!right->ReleaseTree())
                delete right;
        }
        count--;
        return count;
    }


    ~TreeNode()
    {
        if(count == 0) ReleaseTree();
    }

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;

};







class BinStrTree{

public:
    BinStrTree():root(nullptr){}
    BinStrTree(TreeNode* t = nullptr):root(t){}

    BinStrTree(const BinStrTree& b):root(b.root){
        root->CopyTree();
    }

    BinStrTree& operator=(const BinStrTree& b){
        this->root = b.root;
        return *this;
    }

    ~BinStrTree(){
        delete root;
    }

private:
    TreeNode *root;

};



int main()
{
    TreeNode *t;
    BinStrTree b(t);



}