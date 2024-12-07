#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function declarations
void Take_Order_Customer(int Numberoforders, vector<string> &Customer_Order);
void Print_Certain(vector<string> &Customer_Order);
void Add_Order(vector<string> &Customer_Order);
void Modify_Order(vector<string> &Customer_Order);
void Add_PrePared_Order(vector<string> &todays_orders, vector<string> Pre_prepared);
void Vector_Size(vector<string> &todays_orders);
void Remove_Order(vector<string> &Customer_Order);
void Order_Iterators(vector<string> &todays_orders);
void Clear_Order(vector<string> &todays_orders);

int main()
{
    int Numberoforders = 0; // Variable to store the number of orders
    vector<string> todays_orders; // Vector to store today's orders
    vector<string> Pre_prepared(4, "Bread"); // A predefined list of prepared items (4 "Bread" items)
    vector<string> Customer_Order{"cookies", "brownbread", "chocolate", "biscuits"}; // Initial customer orders
    string Decision;

    // Prompt the user to input the number of orders
    cout << "please Enter the Number of your Orders";
    cin >> Numberoforders; // Read the number of orders

    // Call function to take customer orders
    Take_Order_Customer(Numberoforders, Customer_Order);

    // Call function to modify orders
    Modify_Order(Customer_Order);

    // Call function to print certain customer orders
    Print_Certain(Customer_Order);

    // Copy customer orders to today's orders
    todays_orders = Customer_Order;

    // Call function to add pre-prepared orders to today's orders
    Add_PrePared_Order(todays_orders, Pre_prepared);

    // Shrink the vector capacity to fit the current size (removes extra allocated memory)
    todays_orders.shrink_to_fit();

    // Call function to display vector size, capacity, and max size
    Vector_Size(todays_orders);

    // Call function to print orders using different types of iterators
    Order_Iterators(todays_orders);

    // Call function to clear all orders from today's orders
    Clear_Order(todays_orders);

    return 0;
}

// Function to take customer orders based on the number of orders
void Take_Order_Customer(int Numberoforders, vector<string> &Customer_Order)
{
    string OrderName = "No Order"; // Temporary variable to store each order

    // Loop to take each order from the customer
    for (int i = 0; i < Numberoforders; i++)
    {
        cout << "Your Order : "; // Prompt user to enter an order
        cin >> OrderName; // Read the order name
        Customer_Order.push_back(OrderName); // Add the order to the vector
    }
}

// Function to print specific orders (first, last, and third orders)
void Print_Certain(vector<string> &Customer_Order)
{
    cout << "The First customer order is " << Customer_Order.front() << endl; // Print the first order
    cout << "The Last customer order is " << Customer_Order.back() << endl; // Print the last order
    cout << "The Third customer order is " << Customer_Order.at(2) << endl; // Print the third order (using at() for bounds checking)
}

// Function to add an additional order to the customer's order list
void Add_Order(vector<string> &Customer_Order)
{
    cout << "What is your add order"; // Prompt user for the order they want to add
    fflush(stdout);

    string order_added;
    cin >> order_added; // Read the order to be added
    Customer_Order.push_back(order_added); // Add the new order to the vector
}

// Function to modify an existing order (either add or remove)
void Modify_Order(vector<string> &Customer_Order)
{
    char main_decision; // Variable to store user's decision to modify or not
    string second_decision; // Variable to store the type of modification (add/remove)

    // Ask if the user wants to modify the order
    cout << "Would you like to modify the order (Y/N)";
    fflush(stdout);
    cin >> main_decision;

    // If the user chooses not to modify, exit the function
    if (main_decision == 'N')
    {
        cout << "OK";
        return;
    }
    else
    {
        cout << "What do you want to modify (add/remove)"; // Prompt user to choose "add" or "remove"
        fflush(stdout);
        cin >> second_decision;

        // If the decision is "add", call Add_Order function
        if (second_decision == "add")
        {
            Add_Order(Customer_Order);
        }
        // If the decision is "remove", call Remove_Order function
        else if (second_decision == "remove")
        {
            Remove_Order(Customer_Order);
        }
    }

    // Recursively call Modify_Order to allow continuous modifications
    Modify_Order(Customer_Order);
}

// Function to remove an order from the customer's order list
void Remove_Order(vector<string> &Customer_Order)
{
    fflush(stdout);
    cout << "What is your removed order"; // Prompt user for the order they want to remove
    fflush(stdout);

    string order_removed;
    cin >> order_removed; // Read the order to be removed

    // Find the order in the vector
    auto it = find(Customer_Order.begin(), Customer_Order.end(), order_removed);

    // If the order exists, erase it
    if (it != Customer_Order.end())
    {
        cout << "Item is removed" << endl;
        Customer_Order.erase(it); // Erase the found order
    }
    else
    {
        cout << "No Order With Such Name"; // If order is not found, print an error message
    }
}

// Function to add a list of pre-prepared orders to the beginning of today's orders
void Add_PrePared_Order(vector<string> &todays_orders, vector<string> Pre_prepared)
{
    // Insert pre-prepared orders at the beginning of today's orders
    todays_orders.insert(todays_orders.begin(), Pre_prepared.begin(), Pre_prepared.end());
}

// Function to display the size, capacity, and max size of the orders vector
void Vector_Size(vector<string> &todays_orders)
{
    cout << "Todays Order size : " << todays_orders.size() << endl; // Print the current size
    cout << "Todays Order Capacity : " << todays_orders.capacity() << endl; // Print the allocated capacity
    cout << "Todays Order maxsize : " << todays_orders.max_size() << endl; // Print the maximum possible size of the vector
}

// Function to demonstrate different types of iterators for traversing the orders
void Order_Iterators(vector<string> &todays_orders)
{
    // Normal Iterator: Iterates from the beginning to the end
    cout << "Normal Iterators : ";
    for (vector<string>::iterator it = todays_orders.begin(); it != todays_orders.end(); it++)
    {
        cout << *it << "  "; // Dereference the iterator to get the element
    }
    cout << endl;

    // Reverse Iterator: Iterates from the end to the beginning
    cout << "Reverse Iterators : ";
    for (vector<string>::reverse_iterator it = todays_orders.rbegin(); it != todays_orders.rend(); it++)
    {
        cout << *it << "  "; // Dereference the reverse iterator to get the element
    }
    cout << endl;

    // Constant Iterator: Same as normal iterators but read-only
    cout << "const Iterators : ";
    for (vector<string>::const_iterator it = todays_orders.cbegin(); it != todays_orders.cend(); it++)
    {
        cout << *it << "  "; // Dereference the constant iterator to get the element
    }
    cout << endl;

    // Auto Iterator: Uses the auto keyword for automatic type deduction
    cout << "auto Iterators : ";
    for (auto it = todays_orders.begin(); it != todays_orders.end(); it++)
    {
        cout << *it << "  "; // Dereference the auto iterator to get the element
    }
    cout << endl;
}

// Function to clear all orders in the vector
void Clear_Order(vector<string> &todays_orders)
{
    cout << "Clearing The Order List \n"; // Inform user that the list is being cleared
    todays_orders.clear(); // Clear all elements from the vector

    // Check if the vector is empty after clearing
    if (todays_orders.empty())
    {
        cout << "The Order List is now empty"; // If empty, print a confirmation message
    }
}
