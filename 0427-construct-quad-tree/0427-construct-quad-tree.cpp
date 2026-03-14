class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return buildQuadTree(grid, 0, n-1, 0, n-1);
    }

    Node* buildQuadTree(vector<vector<int>>& grid, int left, int right, int low, int high) {
        // Base case: single cell
        if (left == right && low == high) {
            return new Node(grid[low][left], true);
        }

        // Recursive case: divide into 4 quadrants
        int midX = left + (right - left) / 2;
        int midY = low + (high - low) / 2;

        Node* topLeft = buildQuadTree(grid, left, midX, low, midY);
        Node* topRight = buildQuadTree(grid, midX+1, right, low, midY);
        Node* bottomLeft = buildQuadTree(grid, left, midX, midY+1, high);
        Node* bottomRight = buildQuadTree(grid, midX+1, right, midY+1, high);

        // ✅ Check if ALL children are leaves with same value
        if (topLeft->isLeaf && topRight->isLeaf && 
            bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && 
            topRight->val == bottomLeft->val && 
            bottomLeft->val == bottomRight->val) {
            
            // Merge into single leaf
            bool val = topLeft->val;
            
            // Clean up children
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            
            return new Node(val, true);
        }

        // Cannot merge - return internal node
        Node* node = new Node(0, false);
        node->topLeft = topLeft;
        node->topRight = topRight;
        node->bottomLeft = bottomLeft;
        node->bottomRight = bottomRight;
        
        return node;
    }
};