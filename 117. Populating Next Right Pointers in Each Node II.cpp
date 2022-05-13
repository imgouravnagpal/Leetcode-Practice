class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
        {
            return NULL;
        }
        queue<Node*> pe;
        pe.push(root);
        pe.push(NULL);
        
        while(!pe.empty())
        {
            Node* top = pe.front();
            pe.pop();
            if(top == NULL)
            {
                if(pe.empty())
                {
                    break;
                }
                pe.push(NULL);
                continue;
            }
            
            top->next = pe.front();
            if(top->left)
            {
                pe.push(top->left);
            }
            if(top->right)
            {
                pe.push(top->right);
            }
        }
        return root;
    }
};