#include"node.hpp"

class Controller{
    public:
        vector<Node> placeholder;
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
    int smol = placeholder[0].value;
    bool changed = false;
    while(true){
        for(int j = 0; j < placeholder.size(); j++){
            if(smol < placeholder[j].value){
                this->swap(j-1, j);
                changed = true;
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
        cout << "PLACEHOLDER SIZE: " << placeholder.size() << "\n";
        this->sort();
        cout << "SORT FINISHED\n";
        Node p(&placeholder[placeholder.size() - 1]);
        cout << "P BOARD: ";
        p.printBoard();
        // cout << "HELLO?\n";
        // p.printBoard();
        placeholder.pop_back();
        cout << "SHIT?\n";
        
        if(p.isSolved()){
            cout << "FOUND THE SOLUTION\n";
            this->goal = &p;
        }
        else{
            p.create(&p);
            cout << "CREATED THE CHILDREN\n";
            for(int i = 0; i < p.children.size(); i++){
                placeholder.push_back(p.children[i]);
            }
        }
        cout << "IS IT DONE?\n";
    }
}

void Controller::printSolution(){
    cout << "tried running\n";
    vector<Node> trace;
    Node *temp = this->goal;
    trace.push_back(*temp);
    while(temp->parent != NULL){
        temp = temp->parent;
        trace.push_back(*temp);
    }

    cout << "SOLUTION: \n";
    for(int i = trace.size() - 1; i >= 0; i--){
        trace[i].printBoard();
    }
}