/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string s;
    string serialize(TreeNode* root) {
      if (!root) return "#";
  
      queue<TreeNode*> q;
      q.push(root);
      string s;
  
      while (!q.empty()) {
          TreeNode* curr = q.front();
          q.pop();
  
          if (curr) {
              s += to_string(curr->val) + ",";
              q.push(curr->left);
              q.push(curr->right);
          } else {
              s += "#,";
          }
      }
  
      if (!s.empty() && s.back() == ',') {
          s.pop_back();
      }
  
      return s;
  }
  TreeNode* deserialize(string data) {
      if (data.empty() || data == "#") return nullptr;
  
      stringstream ss(data);
      string item;
      vector<string> values;
  
      while (getline(ss, item, ',')) {
          values.push_back(item);
      }
  
      TreeNode* root = new TreeNode(stoi(values[0]));
      queue<TreeNode*> q;
      q.push(root);
  
      int i = 1; 
      while (!q.empty() && i < values.size()) {
          TreeNode* curr = q.front();
          q.pop();
  
          if (values[i] != "#") {
              curr->left = new TreeNode(stoi(values[i]));
              q.push(curr->left);
          }
          i++;
  
          if (i < values.size() && values[i] != "#") {
              curr->right = new TreeNode(stoi(values[i]));
              q.push(curr->right);
          }
          i++;
      }
  
      return root;
  }


};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
