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
	int cnt = 0;
	
	//добавление элемента в конец списка
	void add(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = first;
		if (first == nullptr) {
			first = newNode;
			first->next = first;
		}
		else {
			Node* temp = first;
			while (temp->next != first) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
		cnt++;
	}
	
	//вставка в данную позицию данного значения
	void insert(int index, int val) {
		Node* temp = first;
		Node* previous = nullptr;
		for (int i = 0; i < index; i++) {
			previous = temp;
			temp = temp->next;
		}
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = temp;
		previous->next = newNode;
		cnt++;
	}

	//удаление из коллекции элемента в заданной позиции
	void removeAt(int index) {
		Node* temp = first;
		Node* previous = nullptr;
		for (int i = 0; i < index; i++) {
			previous = temp;
			temp = temp->next;
		}
		previous->next = temp->next;
		cnt--;
	}
	
	//доступ к информационной части элемента в данной позиции
	int elementAt(int index) {
		Node* temp = first;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp->data;
	}

	//количество элементов в коллекции
	int count() {
		return cnt;
	}

	//вставка единицы перед каждым отрицательным элементом
	void insertBeforeNegative() {
		Node* temp = first;
		Node* prev = nullptr;
		if (temp->data < 0) {
			Node* newNode = new Node;
			newNode->data = 1;
			newNode->next = temp->next;
			temp->next = newNode;
			cnt++;
		}
		while (temp->next != first) {
			prev = temp;
			temp = temp->next;
			if (temp->data < 0) {
				Node* newNode = new Node;
				newNode->data = 1;
				newNode->next = temp->next;
				temp->next = newNode;
				cnt++;
			}
		}
	}

	//удаление всех отрицательных элементов
	void removeNegative() {
		Node* temp = first; 
		Node* prev = nullptr;
		while (temp->data < 0) {
			if (first->next != nullptr) { 
				first = first->next; 
			}
			delete temp; 
			temp = first; 
			cnt--;
		}
		while (temp->next != first) {
			prev = temp; 
			temp = temp->next; 
			if (temp->data < 0) { 
				prev->next = temp->next; 
				delete temp; 
				temp = prev->next; 
				cnt--;
			}
		}
	}


	//подсчет количества вхождений переданного значения в коллекцию
	int count(int number) {
		int cnt_local = 0;
		Node* temp = first;
		while (temp->next != first) {
			if (temp->data == number) {
				cnt_local++;
				temp = temp->next;
			}
		}
		if (temp->data == number) {
			cnt_local++;
		}
		return cnt_local;
	}


	//удаление всех элементов коллекции
	void clear() {
		while (first != nullptr) {
			Node* temp = first;
			first = first->next;
			delete temp;
		}
		first = nullptr;
		cnt = 0;
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
			cout << "enter the index to insert";
			cin >> index;
			cout << "enter the item to be inserted";
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
			if (index2 < GeneratedList.count()) {
				cout << GeneratedList.elementAt(index2) << endl;
			}
			else {
				cout << "Index out of list count" << endl;
			}
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
			cout << "enter the item that you want to count";
			cin >> number;
			cout << GeneratedList.count(number);
			break;
		case 9:
			GeneratedList.clear();
			cout << "list is empty";
			break;
		case 10:
			return 0;
		default:
			cout << "Error! Enter the correct command number!";
			break;
		}
	}
}