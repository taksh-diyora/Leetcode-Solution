class BrowserHistory {
private:
    struct node{
        string url;
        node* prev;
        node* next;
        node(string u) : url(u), prev(nullptr), next(nullptr){}
    };
    node* current;
public:
    BrowserHistory(string homepage) {
        current = new node(homepage);
    }
    
    void visit(string url) {
        node* newNode = new node(url);
        current->next = nullptr;
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }
    
    string back(int steps) {
        while(steps-- > 0 && current->prev){
            current = current -> prev;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while(steps-- >0 && current->next){
            current = current->next;
        }
        return current->url;
    }
};