#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
	int val;
	Node *left,*right;	
};

vector<int> in;
vector<int> pre;
Node* build(Node *root, int v){
	if(root == NULL){
		root = new Node();
		root->val = v;
		root->left = root->right = NULL;
	} else if(abs(v) <= abs(root->val)) {
		root->left = build(root->left, v);
	} else {
		root->right = build(root->right, v);
	}
	return root;
}

void preordert(Node* root){
	pre.push_back(root->val);
	if(root->left != NULL){
		preordert(root->left);
	}
	if(root->right != NULL){
		preordert(root->right);
	}
}

bool judge1(Node* root){
	if(root == NULL) return true;
	if(root->val < 0){
		if(root->left != NULL && root->left->val < 0) return false;
		if(root->right != NULL && root->right->val < 0) return false;
	}
	return judge1(root->left) && judge1(root->right);
}

int getBlackNum(Node* root){
	if(root == NULL) return true;
	int l = getBlackNum(root->left);
	int r = getBlackNum(root->right);
	return root->val > 0 ? max(l, r) + 1 : max(l, r);
}

bool judge2(Node* root){
	if(root == NULL) return true;
	int l = getBlackNum(root->left);
	int r = getBlackNum(root->right);
	if(l != r) return false;
	return judge2(root->left) && judge2(root -> right);
}


int main(){
	int n,m;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> m;
		in.clear();
		pre.clear();
		in.resize(m);
		Node* root = NULL;
		for(int j = 0; j < m; j ++){
			cin >> in[j];
			root = build(root, in[j]);
		}
		preordert(root);
		bool flag = in[0] > 0;
		for(int j = 0; j < m; j ++){
			if(in[j] != pre[j]){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout << "No" << endl;
		} else if(!judge1(root) || !judge2(root)) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
}