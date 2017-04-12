/*

130. Surrounded Regions


Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.


For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Subscribe to see which companies asked this question.




*/





class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size()<3 || board[0].size()<3)return;
    	fillBorders(board, 'O', 'Y');
        replace(board, 'O', 'X');
        replace(board, 'Y', 'O');

        }


    void fillBorders(vector<vector<char>> &board, char target, char c) {
        int MaxRow = board.size(), MaxCol = board[0].size();
        for(int i=0; i<MaxRow; i++) {
            if(board[i][0]==target) fill(board, i, 0, target, c);
            if(board[i][MaxCol-1]==target) fill(board, i, MaxCol-1, target, c);
        }

        for(int j=1; j<MaxCol-1; j++) {
            if(board[0][j]==target) fill(board, 0, j, target, c);
            if(board[MaxRow-1][j]==target) fill(board, MaxRow-1, j, target, c);
        }
    }

    void fill(vector<vector<char>> &board, int i, int j, char target, char c) {
        int m = board.size(), n = board[0].size();
        if( board[i][j]!=target) return;
        board[i][j] = c;
        queue<int> queue;
        int code =  i * n +j;
        queue.push(code);
        while (!queue.empty())
        {
        	code = queue.front();

        	int row = code/n;
        	int col = code%n;

        	if (row >=1 && board[row-1][col] == 'O'){
        		queue.push((row-1)*n + col);
        		board[row-1][col] = c;
        	}
        	if(row<=board.size()-2 && board[row+1][col]=='O'){
        	      queue.push((row+1)*n + col);
        	             board[row+1][col]= c;
        	}

        	if(col>=1 && board[row][col-1]=='O'){
        	    queue.push(row*n + col-1);
        	    board[row][col-1]= c;
        	}

        	if(col<=board[0].size()-2 && board[row][col+1]=='O'){
        	    queue.push(row*n + col+1);
        	    board[row][col+1]= c;
        	}
        	queue.pop();

        }

    }

    void replace(vector<vector<char>> &board, char target, char c) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]==target)
                    board[i][j] = c;
            }
        }
    }
};