#include<iostream>
using namespace std;

// ------------------- Stack Class -------------------
class Stack {
private:
    int* arr;    // مصفوفة ديناميكية لتخزين عناصر الـ Stack
    int top;     // مؤشر لقمة الـ Stack
    int capacity;// سعة الـ Stack

public:
    Stack(int size) {  // Constructor لتحديد حجم الـ Stack
        capacity = size;
        arr = new int[size];
        top = -1;      // Stack فارغ في البداية
    }

    bool isFull() { return top == capacity - 1; }   // تحقق هل الـ Stack ممتلئ
    bool isEmpty() { return top == -1; }           // تحقق هل الـ Stack فارغ

    void push(int value) {   // إضافة عنصر جديد
        if (isFull()) {
            cout << "Stack is Full!" << endl;
            return;
        }
        arr[++top] = value;   // زيادة top ثم حفظ القيمة
        cout << value << " pushed." << endl;;
    }

    void pop() {             // إزالة العنصر الأعلى
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;;
            return;
        }
        cout << arr[top] << " popped." << endl;;
        top--;               // تقليل top بعد الحذف
    }

    void display() {         // عرض عناصر الـ Stack
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--)   // نعرض من الأعلى للأسفل
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ------------------- Queue Class -------------------
class Queue {
private:
    int* arr;        // مصفوفة ديناميكية لتخزين عناصر الـ Queue
    int front;       // مؤشر العنصر الأمامي
    int rear;        // مؤشر العنصر الخلفي
    int capacity;    // سعة الـ Queue

public:
    Queue(int size) {
        capacity = size;
        arr = new int[size];
        front = -1;  // Queue فارغ في البداية
        rear = -1;
    }

    bool isFull() { return rear == capacity - 1; }  // تحقق هل الـ Queue ممتلئ
    bool isEmpty() { return front == -1; }          // تحقق هل الـ Queue فارغ

    void enqueue(int value) {  // إضافة عنصر في النهاية
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty()) front = 0;  // إذا كانت Queue فارغة، اجعل front = 0
        arr[++rear] = value;        // إضافة العنصر وزيادة rear
        cout << value << " enqueued." << endl;
    }

    void dequeue() {            // إزالة العنصر الأمامي
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        for (int i = front; i < rear; i++) // نقل العناصر لليسار بعد الحذف
            arr[i] = arr[i + 1];
        rear--;                        // تقليل rear بعد الحذف
        if (rear < 0) front = -1;      // إعادة تعيين front إذا Queue أصبحت فارغة
    }

    void display() {             // عرض عناصر الـ Queue
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ------------------- Node Struct for Linked List -------------------
struct Node {
    int data;   // قيمة العقدة
    Node* next; // مؤشر للعقدة التالية
};

// ------------------- Main Function -------------------
int main() {
    cout << "========================================"<<endl;
cout << "      MENU DRIVEN DATA STRUCTURES        "<<endl;
cout << "========================================"<<endl;
   int Select_Data_Structure;  // لتخزين اختيار المستخدم
   cout << "Select Data Structure:"<<endl;
   cout << "[1] Stack"<<endl;
   cout << "[2] Queue"<<endl;
   cout << "[3] Array"<<endl;
   cout << "[4] Linked List"<<endl;
   cout << "Enter choice: ";
   cin >> Select_Data_Structure;

    // ------------------- Stack Menu -------------------
    if (Select_Data_Structure == 1) {
        int size;
        cout << "Enter Size: ";
        cin >> size;
        Stack s(size);
        int Select_Operation, value;

        do {
        cout << "----------------------------------------"<<endl;
        cout << "              STACK MENU"<<endl;
        cout << "----------------------------------------"<<endl;
        cout << "[1] Push"<<endl;
        cout << "[2] Pop"<<endl;
        cout << "[3] Display"<<endl;
        cout << "[4] Exit"<<endl;
        cout << "Choose An Operation: ";
        cin >> Select_Operation;

            switch (Select_Operation) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);   // استدعاء دالة Push
                break;
            case 2:
                s.pop();         // استدعاء دالة Pop
                break;
            case 3:
                s.display();     // عرض عناصر الـ Stack
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid!" << endl;
            }
        } while (Select_Operation != 4);
    }

    // ------------------- Queue Menu -------------------
    else if (Select_Data_Structure == 2) {
        int size;
        cout << "Enter Size: ";
        cin >> size;
        Queue q(size);
        int Select_Operation, value;

        do {
             cout << "----------------------------------------"<<endl;
        cout << "              QUEUE MENU"<<endl;
        cout << "----------------------------------------"<<endl;
        cout << "[1] Enqueue"<<endl;
        cout << "[2] Dequeue"<<endl;
        cout << "[3] Display"<<endl;
        cout << "[4] Exit"<<endl;
        cout << "Choose An Operation: ";
            cin >> Select_Operation;

            switch (Select_Operation) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);  // استدعاء دالة Enqueue
                break;
            case 2:
                q.dequeue();       // استدعاء دالة Dequeue
                break;
            case 3:
                q.display();       // عرض عناصر الـ Queue
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid!" << endl;
            }
        } while (Select_Operation != 4);
    }

    // ------------------- Array Menu -------------------
    else if (Select_Data_Structure == 3) {
        int size;
        cout << "Enter Size: ";
        cin >> size;
        int arr[size];   // مصفوفة ديناميكية الحجم
        int count = 0;   // تتبع عدد العناصر الفعلية
        int Select_Operation, value;

        do {
            cout << "----------------------------------------"<<endl;
            cout << "              ARRAY MENU"<<endl;
            cout << "----------------------------------------"<<endl;
            cout << "[1] Insert At End"<<endl;
            cout << "[2] Delete From Begin"<<endl;
            cout << "[3] Display"<<endl;
            cout << "[4] Exit"<<endl;
            cout << "Choose an operation: ";
            cin >> Select_Operation;

            switch (Select_Operation) {
            case 1: // Insert في النهاية
                if (count == size)
                    cout << "Array is full!\n";
                else {
                    cout << "Enter value: ";
                    cin >> value;
                    arr[count] = value;
                    count++;
                }
                break;

            case 2: // Delete من البداية (shift left)
                if (count == 0)
                    cout << "Array is empty!\n";
                else {
                    for (int i = 0; i < count - 1; i++)
                        arr[i] = arr[i + 1];
                    count--;
                }
                break;

            case 3: // Display
                if (count == 0)
                    cout << "Array is empty!\n";
                else {
                    cout << "Array Elements: ";
                    for (int i = 0; i < count; i++)
                        cout << arr[i] << " ";
                    cout << endl;
                }
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid!" << endl;
            }

        } while (Select_Operation != 4);
    }

    // ------------------- Linked List Menu -------------------
    else if (Select_Data_Structure == 4) {
        Node* head = nullptr;   // رأس القائمة
        int Select_Operation, value;

        do {
            cout << "----------------------------------------"<<endl;
            cout << "            LINKED LIST MENU"<<endl;
            cout << "----------------------------------------"<<endl;
            cout << "[1] Insert At End"<<endl;
            cout << "[2] Delete From End"<<endl;
            cout << "[3] Display"<<endl;
            cout << "[4] Exit"<<endl;
            cout << "Choose an operation: ";
            cin >> Select_Operation;

            switch (Select_Operation) {
            case 1: // Insert في النهاية
            {
                cout << "Enter value: ";
                cin >> value;
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = nullptr;

                if (head == nullptr) head = newNode;       // إذا القائمة فارغة
                else {
                    Node* temp = head;
                    while (temp->next != nullptr) temp = temp->next;
                    temp->next = newNode;
                }
                break;
            }

            case 2: // Delete من النهاية
            {
                if (head == nullptr)
                    cout << "Linked List is empty!\n";
                else if (head->next == nullptr) {  // عنصر واحد فقط
                    delete head;
                    head = nullptr;
                } else {                          // أكثر من عنصر
                    Node* temp = head;
                    while (temp->next->next != nullptr) temp = temp->next;
                    delete temp->next;
                    temp->next = nullptr;
                }
                break;
            }

            case 3: // Display
            {
                if (head == nullptr) cout << "Linked List is empty!\n";
                else {
                    cout << "Linked List Elements: ";
                    Node* temp = head;
                    while (temp != nullptr) {
                        cout << temp->data << " ";
                        temp = temp->next;
                    }
                    cout << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!\n";
            }

        } while (Select_Operation != 4);

        // تحرير الذاكرة بعد الانتهاء
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}
