#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class LinkedList
{
public:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
    };
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        node_count = 0;
    };
    LinkedList(const LinkedList<T>& list) {
        if (list.head == nullptr){
            head = nullptr;
            tail = nullptr;
            node_count = 0;
        }
        Node* iterator =  list.head;
        Node* copy = nullptr;
        while(iterator != nullptr){
            copy = new Node();
            copy->data = iterator->data;
            copy->next = iterator->next;
            copy->prev = iterator->prev;
            if (head == nullptr){
                head = copy;
                tail = copy;
            }
            else{
                tail->next = copy;
                copy->prev = tail;
                tail = copy;
            }
            node_count++;
            iterator = iterator->next;
        }
    };
    ~LinkedList(){
        Node* iterator = head;
        while (head != nullptr){
            iterator = head;
            head = head->next;
            delete iterator;
        }
    };
    const T& operator[](unsigned int index) const{
        Node* iterator = head;
        int i = 0;
        while (i < index){
            if (index > node_count) {
                throw out_of_range("The index is out of range!");
            }
            else{
                iterator = iterator->next;
                i++;
            }
        }
        return iterator->data;
    };
    T& operator[](unsigned int index){
        Node* iterator = head;
        int i = 0;
        while (i < index){
            if (iterator->next == nullptr) {
                throw out_of_range("The index is out of range!");
            }
            else{
                iterator = iterator->next;
                i++;
            }
        }
        return iterator->data;
    };
    LinkedList<T>& operator=(const LinkedList<T>& rhs){
        Node* iterator = head;
        while (head != nullptr){
            iterator = head;
            head = head->next;
            delete iterator;
        }
        if (rhs.head == nullptr){
            head = nullptr;
            tail = nullptr;
        }
        iterator =  rhs.head;
        Node* copy = nullptr;
        while(iterator != nullptr){
            copy = new Node();
            copy->data = iterator->data;
            copy->next = nullptr;
            if (head == nullptr){
                head = copy;
                tail = copy;
            }
            else{
                tail->next = copy;
                tail = copy;
            }
            iterator = iterator->next;
        }
    };
    bool operator==(const LinkedList<T>& rhs) const{
        Node* iterator1 = head;
        Node* iterator2 = rhs.head;
        while(iterator1 != nullptr && iterator2 != nullptr){
            if (iterator1->data != iterator2->data){
                return false;
            }
            iterator1 = iterator1->next;
            iterator2 = iterator2->next;
        }
        return true;
    };
    void AddHead(const T& data){
        if (head == nullptr){
            Node* temp = new Node();
            temp->data = data;
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
            node_count++;
        }
        else{
            Node* temp = new Node();
            temp->data = data;
            temp->next = head;
            temp->prev = nullptr;
            head->prev = temp;
            head = temp;
            node_count++;
        }
    };
    void AddTail(const T& data){
        if (head == nullptr){
            Node* temp = new Node();
            temp->data = data;
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
            node_count++;
        }
        else {
            Node *temp = new Node();
            temp->data = data;
            temp->next = nullptr;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            node_count++;
        }
    };
    void AddNodesHead(const T* data, unsigned int count){
        int i = 0;
        while (i < count){
            if (head == nullptr){
                Node* temp = new Node();
                temp->data = data[i];
                temp->next = nullptr;
                temp->prev = nullptr;
                head = temp;
                tail = temp;
                node_count++;
            }
            else{
                Node* temp = new Node();
                temp->data = data[i];
                temp->next = head;
                temp->prev = nullptr;
                head->prev = temp;
                head = temp;
                node_count++;
            }
            i++;
        }
    };
    void AddNodesTail(const T* data, unsigned int count){
        int i = 0;
        while (i < count){
            if (head == nullptr){
                Node* temp = new Node();
                temp->data = data[i];
                temp->next = nullptr;
                temp->prev = nullptr;
                head = temp;
                tail = temp;
                node_count++;
            }
            else{
                Node *temp = new Node();
                temp->data = data[i];
                temp->next = nullptr;
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
                node_count++;
            }
            i++;
        }
    };
    unsigned int NodeCount() const{
        return node_count;
    };
    void PrintForward() const{
        Node* iterator = head;
        while (iterator != nullptr){
            cout<<iterator->data<<endl;
            iterator = iterator->next;
        }
    };
    void PrintReverse() const{
        Node* iterator = tail;
        while (iterator != nullptr){
            cout<<iterator->data<<endl;
            iterator = iterator->prev;
        }
    };
    Node* Head(){
        return head;
    };
    const Node* Head() const{
        return head;
    };
    Node* Tail(){
        return tail;
    };
    const Node* Tail() const{
        return tail;
    };
    const Node* GetNode(unsigned int index) const{
        Node* iterator = head;
        int i = 0;
        while (i <= index){
            if (iterator->next == nullptr) {
                throw out_of_range("The index is out of range!");
            }
            else{
                iterator = iterator->next;
                i++;
            }
        }
        return iterator;
    };
    Node* GetNode(unsigned int index){
        Node* iterator = head;
        int i = 0;
        while (i <= index){
            if (iterator == nullptr) {
                throw out_of_range("The index is out of range!");
            }
            else{
                iterator = iterator->next;
                i++;
            }
        }
        return iterator;
    };
    Node* Find(const T& data){
        Node* iterator = head;
        while (iterator != nullptr){
            if (iterator->data == data){
                return iterator;
            }
            else{
                iterator = iterator->next;
            }
        }
        return nullptr;
    };
    const Node* Find(const T& data) const{
        Node* iterator = head;
        while (iterator != nullptr){
            if (iterator->data == data){
                return iterator;
            }
            else{
                iterator = iterator->next;
            }
        }
        return nullptr;
    };
    void FindAll(vector<Node*>& outData, const T& value) const{
        Node* iterator = head;
        while (iterator != nullptr){
            if (iterator->data == value){
                outData.push_back(iterator);
                iterator = iterator->next;
            }
            else{
                iterator = iterator->next;
            }
        }
    };
    void InsertAfter(Node* node, const T& data){
        Node* insert = new Node();
        insert->data = data;
        insert->next = node->next;
        node->next = insert;
        insert->prev = node;
        if (insert->next != nullptr){
            insert->next->prev = insert;
        }
        node_count++;
    };
    void InsertBefore(Node* node, const T& data){
        Node* insert = new Node();
        insert->data = data;
        insert->prev = node->prev;
        node->prev = insert;
        insert->next = node;
        if (insert->prev != nullptr){
            insert->prev->next = insert;
        }
        node_count++;
    };
    void InsertAt(const T& data, unsigned int index){
        Node* iterator = head;
        int i = 0;
        while (i <= index){
            if (index > node_count) {
                throw out_of_range("The index is out of range!");
            }
            else if (i == index){
                if (i == node_count){
                    AddTail(data);
                }
                else if (index == 0){
                    AddHead(data);
                }
                else {
                    InsertBefore(iterator, data);
                }
                break;
            }
            iterator = iterator->next;
            i++;
        }
    };
    bool RemoveHead(){
        if (node_count == 0){
            head = nullptr;
            tail = nullptr;
            return false;
        }
        else if(node_count == 1){
            delete head;
            node_count--;
            return true;
        }
        else{
            cout << head->data <<endl;
            Node* node = head->next;
            delete head;
            head = node;
            head->prev = nullptr;
            node_count--;
            return true;
        }

    };
    bool RemoveTail(){
        if (node_count == 0){
            head = nullptr;
            tail = nullptr;
            return false;
        }
        else if(node_count == 1){
            delete tail;
            node_count--;
            return true;
        }
        else {
            Node *node = tail->prev;
            delete tail;
            tail = node;
            tail->next = nullptr;
            node_count--;
            return true;
        }
    };
    bool RemoveAt(unsigned int index){
        Node* iterator = head;
        Node* node;
        int i = 0;
        while (i <= index){
            if (index > node_count) {
                return false;
            }
            else if (i == index){
                if (i == node_count){
                    RemoveTail();
                    return true;
                }
                else if (index == 0){
                    RemoveHead();
                    return true;
                }
                else {
                    node = iterator->prev;
                    node->next = iterator->next;
                    delete iterator;
                    node_count--;
                    return true;
                }
            }
            else{
                iterator = iterator->next;
                i++;
            }
        }

    };
    unsigned int Remove(const T&data){
        unsigned int amt_deleted = 0;
        Node* node = nullptr;
        Node* iterator = head;

        while(iterator != nullptr){
            if (iterator->data == data){
                if (node == nullptr){
                    RemoveHead();
                    iterator = head;
                }
                else{
                    node->next = iterator->next;
                    delete iterator;
                    iterator = node->next;
                }
                amt_deleted++;
                node_count--;
            }
            else{
                node = iterator;
                iterator = iterator->next;
            }
        }
        if (head == nullptr){
            tail = nullptr;
        }
        return amt_deleted;
        /*Node* iterator = head;
        unsigned int amt_deleted = 0;
        while (iterator != nullptr){
            if (iterator->data == data){
                Node* node = iterator->next;
                delete iterator;
                iterator = node;
                cout << "Current:" << iterator->data <<endl;
                amt_deleted++;
                node_count--;
            }
            else{
                iterator = iterator->next;
            }
        }
        return amt_deleted;*/
    };
    void Clear(){
        Node* iterator = head;
        while (head != nullptr){
            iterator = head;
            head = head->next;
            delete iterator;
            node_count--;
            if (node_count == 0){
                head = nullptr;
                tail = nullptr;
            }
        }
    };
    void PrintForwardRecursive(const Node* node) const{
        cout << node->data <<endl;
        if (node->next != nullptr) {
            PrintForwardRecursive(node->next);
        }
    };
    void PrintReverseRecursive(const Node* node) const{
        cout << node->data <<endl;
        if (node->prev != nullptr) {
            PrintReverseRecursive(node->prev);
        }
    };
private:
    Node* head;
    Node* tail;
    unsigned int node_count;
};

