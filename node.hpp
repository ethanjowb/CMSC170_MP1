#include<cmath>
#include"board.hpp"

using namespace std;

class Node{
    public:
        Node *parent;
        Board b;
        int height;
        int value;
        vector<Node> children;
        bool seen;
    
    public:
        Node();
        Node(Node*);
        Node(Board);
        Node(Node*,Board);
        ~Node();

    public:
        void manhattanValue();
        void printBoard();
        void printNode();
        void create(Node*);
        bool isSolved();
        void hasSeen();
};

Node::Node(){
    this->parent = NULL;
    this->b = Board();
    this->height = 0;
    this->seen = false;
    this->manhattanValue();
}

Node::Node(Node *other){
    this->parent = other->parent;
    this->b = Board(other->b.board);
    this->height = other->height;
    this->value = other->value;
    this->seen = false;

    for(int i = 0; i < other->children.size(); i++){
        this->children.push_back(other->children[i]);
    }
}

Node::Node(Board other){
    this->b = Board(other.board);
    this->parent = NULL;
    this->height = 0;
    this->seen = false;
    this->manhattanValue();
}

Node::Node(Node *p, Board other){
    this->parent = p;
    this->b = Board(other.board);
    this->height = p->height + 1;
    this->seen = false;
    // if(this->parent != NULL){
    //     cout << "PARENT INITIALIZES: \n";
    //     this->parent->printBoard();
    //     cout << "DONE\n";
    // }
    this->manhattanValue();
}

Node::~Node(){
    this->children.clear();
    this->parent = NULL;
}

void Node::manhattanValue(){
    // goal board
    Board other;
    // other.printBoard();
    // initializes value
    this->value = 0;
    // iterates the current board
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int flag = true;
            // iterates the goal board with the current node board position
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    if(b.board[i][j] == other.board[k][l]){
                        k = abs(k - i);
                        l = abs(l - j);
                        this->value += k;
                        // cout << "added: " << k << "\n";
                        this->value += l;
                        // cout << "added: " << l << "\n";
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
        }
    }
    this->value += this->height;
    // cout << "mahattanValue initializes\n";
}

void Node::create(Node *n){
    axis zero = this->b.findEmpty();
    // down, left, up, right
    int x_move[] = {0,-1, 0,1};
    int y_move[] = {1, 0,-1,0};
    for(int i = 0; i < 4; i++){
        axis toPosition;
        if(((x_move[i] + zero.x) >= 0) &&
           ((x_move[i] + zero.x) <= 2) &&
           ((y_move[i] + zero.y) >= 0) &&
           ((y_move[i] + zero.y) <= 2)){
            //    cout << "CHILD CREATED\n";
               toPosition.x = x_move[i] + zero.x;
               toPosition.y = y_move[i] + zero.y;
               Board child(this->b.board);
            //    cout << "GOING TO SWAP\n";
               child.toSwap(zero, toPosition);
            //    cout << "GONNA CREATE NCHILD\n";
               Node nChild(n, child);
            //    cout << "CREATED NODE CHILD\n";
               this->children.push_back(nChild);
           }
    }
    // cout << "CHILDREN FINISHED\n";
}

void Node::printBoard(){
    this->b.printBoard();
}

void Node::printNode(){
    cout << "---------------\n";
    cout << "HEIGHT: " << this->height << "\n";
    cout << "VALUE: " << this->value << "\n";
    cout << "BOARD: ";
    this->printBoard();
    if(this->parent != NULL){
        cout << "PARENT: ";
        this->parent->printBoard();
        cout << "\n";
    }
    cout << "CHILDREN: ";
    for(int i = 0; i < this->children.size(); i++){
        cout << "\nCHILD VALUE: " << this->children[i].value;
        this->children[i].printBoard();
        cout << "---";
    }
}

bool Node::isSolved(){
    return this->b.isSolved();
}

void Node::hasSeen(){
    this->seen = true;
}