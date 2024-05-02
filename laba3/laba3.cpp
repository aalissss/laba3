#include <iostream>
using namespace std;

//узел односвязного списка
struct Node {
    int data;
    Node* next = nullptr;
};

//структура циклического списка
struct List {
    Node* first = nullptr;
    Node* last = nullptr;
    Node* prev = nullptr;
    Node* temp = nullptr;
    int cnt = 0;
    int position = 0;

    //к первому элементу
    void toFirst() {
        if (cnt == 0) {
            return;
        }
        temp = first;
        prev = last;
        position = 0;
    }

    //к следующему элементу
    void toNext() {
        if (cnt == 0) {
            return;
        }
        prev = temp;
        temp = temp->next;
        position++;
        position = position % cnt;
    }

    //удаление текущего
    void removeTemp() {
        if (cnt == 0) {
            return;
        }
        if (temp == first) {
            first = temp->next;
        }
        if (temp == last) {
            last = prev;
        }
        prev->next = temp->next;
        delete temp;
        cnt--;
        if (cnt == 0) {
            return;
        }
        temp = prev->next;
        position = position % cnt;
    }

    //вставка перед текущим
    void insertBeforeTemp(int val) {
        if (cnt == 0) {
            return;
        }
        Node* newNode = new Node;
        cnt++;
        position++;
        newNode->data = val;
        newNode->next = temp;
        prev->next = newNode;
        prev = newNode;
        if (temp == first) {
            first = newNode;
        }
    }

    //добавление элемента в конец списка
    void add(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        if (cnt == 0) {
            first = newNode;
            prev = newNode;
            temp = newNode;
            cnt = 1;
            position = 0;
        }
        else {
            prev = last;
            temp = newNode;
            cnt++;
            position = count() - 1;
            last->next = newNode;
        }
        newNode->next = first;
        last = newNode;
    }

    //вставка в данную позицию данного значения
    void insert(int index, int val) {
        index = index % (cnt + 1);
        if (cnt == 0 || index == cnt) {
            add(val);
        }
        else {
            elementAt(index);
            insertBeforeTemp(val);
        }
    }

    //удаление из коллекции элемента в заданной позиции
    void removeAt(int index) {
        elementAt(index);
        removeTemp();
    }

    //доступ к информационной части элемента в данной позиции
    int elementAt(int index) {
        if (cnt == 0) {
            return 0;
        }
        index = index % cnt;
        if (position > index) {
            toFirst();
        }
        while (index != position) {
            toNext();
        }
        return temp->data;
    }

    //количество элементов в коллекции
    int count() {
        return cnt;
    }

    //вставка единицы перед каждым отрицательным элементом
    void insertBeforeNegative() {
        if (cnt == 0) {
            return;
       }
        toFirst();
        for (int i = cnt; i > 0; i--) {
            if (temp->data < 0) {
                insertBeforeTemp(1);
            }
            toNext();
        }
    }

    //удаление всех отрицательных элементов
    void removeNegative() {
        toFirst();
        for (int i = cnt; i > 0; i--) {
            if (cnt == 0) {
                return;
            }
            if (temp->data < 0) {
                removeTemp();
            }
            else {
                toNext();
            }
        }
    }


    //подсчет количества вхождений переданного значения в коллекцию
    int count(int number) {
        if (cnt == 0) {
            return 0;
        }
        toFirst();
        int cntElement = 0;
        for (int i = cnt; i > 0; i--) {
            if (temp->data == number) {
                cntElement++;
            }
            toNext();
        }
        return cntElement;
    }


    //удаление всех элементов коллекции
    void clear() {
        if (cnt == 0) {
            return;
        }
        toFirst();
        for (int i = cnt; i > 0; i--) {
            removeTemp();
        }
    }
};

int main()
{
    List GeneratedList{};


    cout << "Enter number for:" << endl;
    cout << "1. adding an item to the end of the list" << endl << "2. inserting the giving value into the given position" << endl;
    cout << "3. to remove an item from a given position" << endl << "4. to access the information part of the element at a given position" << endl;
    cout << "5. item count output " << endl << "6. to insert a one before each negative number" << endl;
    cout << "7. to remove all negative elements" << endl << "8. set point calculation" << endl;
    cout << "9. deleting all items from the list" << endl << "10. program termination" << endl;

    while (true) {
        int data, numb, cnt = 0;
        cin >> numb;
        switch (numb) {
        case 1:
            cout << "Enter numbers. Enter 0 to end the input" << endl;
            while (true) {
                cin >> data;
                if (data == 0) {
                    break;
                }
                GeneratedList.add(data);
            }
            break;
        case 2:
            int index, val;
            cout << "enter the index to insert" << endl;
            cin >> index;
            cout << "enter the item to be inserted" << endl;
            cin >> val;
            GeneratedList.insert(index, val);
            break;
        case 3:
            int index1;
            cout << "enter the index of the item to be deleted" << endl;
            cin >> index1;
            if (index1 < GeneratedList.count()) {
                GeneratedList.removeAt(index1);
            }
            else {
                cout << "Index out of list count" << endl;
            }
            break;
        case 4:
            int index2;
            cout << "enter the item index to access the item" << endl;
            cin >> index2;
                cout << GeneratedList.elementAt(index2) << endl;
                break;
        case 5:
            cout << "Number of items in the list: " << endl;
            cout << GeneratedList.count() << endl;
            break;
        case 6:
            GeneratedList.insertBeforeNegative();
            break;
        case 7:
            GeneratedList.removeNegative();
            break;
        case 8:
            int number;
            cout << "enter the item that you want to count" << endl;
            cin >> number;
            cout << GeneratedList.count(number);
            break;
        case 9:
            GeneratedList.clear();
            cout << "list is empty" << endl;
            break;
        case 10:
            return 0;
        default:
            cout << "Error! Enter the correct command number!" << endl;
            break;
        }
    }
}