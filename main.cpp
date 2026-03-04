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
        cout << propertyName << " | " << propertyColor << " | $" << value << " | Rent $" << rent;
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
        }

        nodeCount++;
        return true;
    }

    // Core B
    int addMany(vector<T> values)
    {
        int addedCount = 0;
        for (const T& value : values)
        {
            if (addSpace(value))
            {
                addedCount++;
            }
            else
            {
                break;
            }
        }
        return addedCount;
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
        if (playerNode == nullptr || count <= 0)
        {
            return;
        }

        Node<T>* current = playerNode;

        for (int i = 0; i < count; i++)
        {
            current->data.print();
            cout << endl;
            current = current->nextNode;
        }
    }

    // Advanced Option A
    bool removeByName(string name) {
        // TODO: Implement removeByName
        return false;
    }

    vector<string> findByColor(string color) {
        // TODO: Implement findByColor
        return {};
    }

    void clear() {
        // TODO: Implement destructor logic
    }
};

// -------------------------------
// Main
// -------------------------------
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    CircularLinkedList<MonopolySpace> board;

    // TODO: Build the board
    cout << "Monopoly Simulator Initialized." << endl;

    // TODO: Playable loop

    return 0;
}