struct Node {
    static int MAX;

    int count;
    Node *left, *right;

    Node(int count, Node* left, Node* right): 
        count(count), left(left), right(right) {}

    Node* insert(int l, int r, int k) {
        if (l <= k && k < r) {
            if (l + 1 == r) {
                return new Node(this->count + 1, null, null);
            }
            int m = (l + r) >> 1;
            return new Node(this->count + 1, 
                            this->left->insert(l, m, k),
                            this->right->insert(m, r, k));
        }
        return this;
    }
};

Node* null = new Node(0, NULL, NULL);

int main() {
    null->left = null->right = null;
}
