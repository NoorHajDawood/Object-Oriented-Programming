#include <iostream>

#include "DoublyLinkedList.h"
#include "Customer.h"

using namespace std;

Customer test[] = { Customer("CustomerName1", "CustomerId1", "CustomerAddress1"),
                    Customer("CustomerName2", "CustomerId2", "CustomerAddress2"),
                    Customer("CustomerName3", "CustomerId3", "CustomerAddress3"),
                    Customer("CustomerName4", "CustomerId4", "CustomerAddress4"),
                    Customer("CustomerName5", "CustomerId5", "CustomerAddress5"),
                    Customer("CustomerName6", "CustomerId6", "CustomerAddress6"),
                    Customer("CustomerName7", "CustomerId7", "CustomerAddress7") };

int main(void)
{
    DoublyLinkedList<Customer> customers;
    
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); ++i)
        customers.insert(test[i]);
    
    customers.print();
    customers.printReverse();
    
    Node<Customer>* p = customers.find(test[3]);
    if (p != customers.end())
    {
		cout << "Found: " << *(p->data()) << endl;
        customers.remove(p);
    }
    
    p = customers.begin();
    while (p != customers.end())
    {
		cout << *(p->data()) << endl;
        p = p->next();
    }
    
    customers.print();
    customers.printReverse();
    
    ofstream file("out.bin");
    if (!file.is_open())
        return -1;
    
    customers.saveBin(file);
    
    file.close();
    
    ifstream inFile("out.bin");
    if (!inFile.is_open())
        return -1;
    
    DoublyLinkedList<Customer> c;
    c.loadBin(inFile);
    
    inFile.close();
    
	cout << endl;
    c.print();
    c.printReverse();
    
	cin.get();
}
