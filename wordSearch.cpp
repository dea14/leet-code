class node{
    public:
    map<char, node*> m;
    bool isEnd;
    string word;
};
class Solution {
public:
    
    void insert(node *& head, string s){
        node * curr = head;
        for(int i = 0;i<s.length();i++){
            if(!curr->m[s[i]]){
                curr->m[s[i]] = new node();
                curr->m[s[i]]->isEnd = false;
            }
            curr = curr->m[s[i]];
        }
        curr->isEnd = true;
        curr->word = s;
    }
    
    void solve(vector<vector<char>> &  board, int i, int j,vector<string>& ans, node * curr){
        if(board[i][j] == ' ' || !curr->m[board[i][j]]) return;
        
        curr = curr->m[board[i][j]];
        
        if(curr->isEnd){
            ans.push_back(curr->word);
            curr->isEnd= false;
        }
        
        
        char ch = board[i][j];
        board[i][j] = ' ';
        
        if(i > 0)
        solve(board, i - 1, j, ans, curr);
        if(i < board.size() - 1)
        solve(board, i + 1, j, ans, curr);
        if(j < board[0].size() - 1)
        solve(board, i, j + 1, ans, curr);
        if(j > 0)
        solve(board, i, j - 1, ans, curr);
        
        board[i][j] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node * head  = new node();
        head->isEnd = false;
        vector<string> ans;
        
        for(string s : words){
            insert(head, s);
        }
        
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                solve(board, i, j, ans, head);
            }
        }
        
        return ans;
    }
};