#include"node.hpp"

class Controller{
    public:
        vector<Node> placeholder;
        vector<Board> uniqueBoards;
        Node *goal;

    public:
        Controller();
        ~Controller(){}

    public:
        void sort();
        void swap(int,int);
        void solve(Node);
        void printSolution();
};

Controller::Controller(){
    this->goal = NULL;
}

void Controller::sort(){
    bool changed = false;
    while(true){
        int smol = placeholder[0].value;
        for(int j = 0; j < placeholder.size(); j++){
            if(smol < placeholder[j].value){
                this->swap(j-1, j);
                changed = true;
            }
            else{
                smol = placeholder[j].value;
            }
        }
        if(changed){
            changed = false;
            smol = placeholder[0].value;
        }
        else{
            break;
        }
    }
}

void Controller::swap(int from, int to){
    Node fromNode(&placeholder[from]);
    Node toNode(&placeholder[to]);
    placeholder.erase(placeholder.begin() + from);
    placeholder.insert(placeholder.begin() + from, toNode);
    placeholder.erase(placeholder.begin() + to);
    placeholder.insert(placeholder.begin() + to, fromNode);
}

void Controller::solve(Node prob){
    placeholder.push_back(prob);
    while(true && placeholder.size() > 0){
        bool isUnique = true;
        this->sort();

        // cout << "\nAFTER SORT: \n";
        // for(int i = 0; i < placeholder.size(); i++){
        //     cout << placeholder[i].value << " ";
        // }

        Node p(&placeholder[placeholder.size() - 1]);
        placeholder.pop_back();

        for(int j = 0; j < uniqueBoards.size(); j++){
            if(p.b.compare(uniqueBoards[j])){
                isUnique = false;
            }
        }

        // p.printBoard();
        // cout << "CURRENT HEIGHT: " << p.height << "\n";
        // cout << "CURRENT VALUE: " << p.value << "\n";

        if(p.isSolved()){
            Node *g = new Node(&p);
            this->goal = g;
            break;
        }

        if((p.children.size() == 0) && isUnique){
            p.hasSeen();
            uniqueBoards.push_back(p.b);
            p.create(&p);
            for(int i = 0; i < p.children.size(); i++){
                placeholder.push_back(p.children[i]);
            }
        }

        p.printNode();
    }
}

void Controller::printSolution(){
    cout << "running\n";
    vector<Node> trace;
    Node *temp = this->goal;
    cout << "CURRENT TEMP: ";
    temp->printBoard();
    trace.push_back(*temp);

    while(temp->parent != NULL){
        cout << "HAS TEMP PARENT\n";
        temp->parent->printBoard();
        temp = temp->parent;
        temp->printBoard();
        trace.push_back(*temp);
    }

    cout << "SOLUTION: \n";
    for(int i = trace.size() - 1; i >= 0; i--){
        trace[i].printBoard();
    }
}