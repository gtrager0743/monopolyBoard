#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

static const int MAX_SPACES = 40;

// -------------------------------
// Data class
// -------------------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace() {
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }

    MonopolySpace(string name, string color, int val, int r) {
        propertyName = name;
        propertyColor = color;
        value = val;
        rent = r;
    }
    bool isEqual(MonopolySpace other)
    {
        return (propertyName == other.propertyName);
    }

    void print()
    {
        cout << propertyName << ", " << propertyColor << ", $" << value << ": Rent $" << rent << endl;
    }
};

// -------------------------------
// Node class
// -------------------------------
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// -------------------------------
// Circular Linked List class
// -------------------------------
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;
    Node<T>* playerNode;
    int nodeCount;
    int passGoCount;

public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;
        nodeCount = 0;
        passGoCount = 0;
    }

    // Core A
    bool addSpace(T value)
    {
        if (nodeCount >= MAX_SPACES)
        {
            return false;
        }


        Node<T>* newNode = new Node<T>(value);

        if (headNode == nullptr)
        {
            headNode = newNode;
            tailNode = newNode;
            playerNode = newNode;
            newNode->nextNode = headNode;
        }
        else
        {
            tailNode->nextNode = newNode;
            tailNode = newNode;
            tailNode->nextNode = headNode;
            // this closes the circular linked list back up
        }

        nodeCount++;

        return true;
    }

    // Core B
    int addMany(vector<T> values)
    {

        int added = 0;
        for (int i = 0; i < values.size(); i++)
        {
            if (addSpace(values[i]))
            {
                added++;
            }
            else
            {
                break;
                // addspace returns false once our 40 space limit is hit, this ends our loop for addMany if that happens
            }
        }


        return added;
    }

    // Core C
    void movePlayer(int steps)
    {
        if (playerNode == nullptr)
        {
            return;
        }
        for (int i = 0; i < steps; i++)
        {
            if (playerNode == tailNode)
            {
                passGoCount++;
                // if we hit the tail node and still have more spaces to move, that means were about to pass GO
            }
            playerNode = playerNode->nextNode;
        }
    }

    int getPassGoCount() {
        return passGoCount;
    }

    // Core D
    void printFromPlayer(int count)
    {
        if (playerNode == nullptr)
        {
            return;
        }
        if (count <= 0)
        {
            return;
        }
        // right here a temporary pointer is created and used to iterate through spaces for printing
        // this is so the actual player pointer can remain in its current position
        Node<T>* current = playerNode;

        for (int i = 0; i < count; i++)
        {
            current->data.print();
            cout << endl;
            current = current->nextNode;
        }
    }

    // Advanced Option A
    bool removeByName(string name)
    {
        // to check circular linked list integrity
        if (headNode == nullptr)
        {
            return false;
        }

        Node<T>* curr = headNode;
        Node<T>* prev = tailNode;
        bool found = false;

        for (int i = 0; i < nodeCount; i++)
        {
            if (curr->data.propertyName == name)
            {
                found = true;
                break;
            }
            // if we always move both pointers forward together then we can ensure that prev always stays exactly one step behind curr
            prev = curr;
            curr = curr->nextNode;
        }

        if (!found)
        {
            return false;
        }

        if (playerNode == curr)
        {
            if (nodeCount == 1)
            {
                playerNode = nullptr;
            }
            else
            {
                playerNode = curr->nextNode;
                // this will move the player off of the current node if the current node is the one being deleted
            }
        }

        if (nodeCount == 1)
        {
            headNode = nullptr;
            tailNode = nullptr;
        }
        else
        {
            // routing node pointers around the gap created by deleting a node
            prev->nextNode = curr->nextNode;
            if (curr == headNode)
            {
                headNode = curr->nextNode;
            }
            if (curr == tailNode)
            {
                tailNode = prev;
            }
        }

        delete curr;
        nodeCount--;
        return true;
    }

    vector<string> findByColor(string color)
    {
        vector<string> matches;

        if (headNode == nullptr)
        {
            return matches;
        }

        Node<T>* curr = headNode;
        // this loop checks every node exactly once without geting stuck in an infinite loop
        for (int i = 0; i < nodeCount; i++)
        {
            if (curr->data.propertyColor == color)
            {
                cout << curr->data.propertyName << endl;
            }
            curr = curr->nextNode;
        }

        return matches;
    }

    void clear()
    {
        if (headNode == nullptr)
        {
            return;
        }
        // by setting the tailNodes pointer to null, we break the circular nature of the linked list so we can delete spaces safely one by one
        tailNode->nextNode = nullptr;
        Node<T>* next = nullptr;
        Node<T>* curr = headNode;


        while (curr != nullptr)
        {
            next = curr->nextNode;
            delete curr;
            curr = next;
        }

        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;
        nodeCount = 0;
        passGoCount = 0;
    }
};

// -------------------------------
// Main
// -------------------------------
int rolls()
{
    return (rand() % 6 + 1) +
        (rand() % 6 + 1);
}

int main()
{
srand(static_cast<unsigned>(time(nullptr)));



    CircularLinkedList<MonopolySpace> board;

    board.addSpace(MonopolySpace("GO", "None", 0, 0));


    vector<MonopolySpace> spaces(39);
    string colors[8] = {"Brown", "Light Blue", "Pink", "Orange", "Red", "Yellow", "Green", "Dark Blue"};

    for (int i = 0; i < 39; i++)
    {
        string name = "Property " + to_string(i + 1);


    int rent = i * 2; int value = i * 10;
        // by dividing the assignment of colors like this, specific batches of adjacent spaces will have the same color just like real monopoly
        int colorIndex = i / 5;
        if (colorIndex > 7)
        {
            colorIndex = 7;
        }

        spaces[i] = MonopolySpace(name, colors[colorIndex], value, rent);
    }

    board.addMany(spaces);

    int roll = 0;
    cout << "Monopoly Simulator Initialized." << endl;
    for (int turn = 1; turn <= 10; turn++)
    {
    roll = rolls();

        cout << "turn " << turn << ": Rolled: " << roll << endl;

        board.movePlayer(roll);

        cout << "current position + preview of next 2 spaces" << endl;
        board.printFromPlayer(3);

        cout << "times passed GO so far is " << board.getPassGoCount() << endl;
        cout << "-----------------------------------" << endl;
    }

    board.clear();

    return 0;
}