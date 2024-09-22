// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// In-Class Exercise - Part 2
// Notes or Remarks: ......
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Node structure for a singly linked list
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 1. Add Two Numbers
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *p = l1, *q = l2, *current = dummy;
    int carry = 0;

    while (p != nullptr || q != nullptr)
    {
        int x = (p != nullptr) ? p->val : 0;
        int y = (q != nullptr) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;

        if (p != nullptr)
            p = p->next;
        if (q != nullptr)
            q = q->next;
    }

    if (carry > 0)
    {
        current->next = new ListNode(carry);
    }

    return dummy->next;
}

// 2. Copy List with Random Pointers
class RandomListNode
{
public:
    int val;
    RandomListNode *next;
    RandomListNode *random;
    RandomListNode(int x) : val(x), next(nullptr), random(nullptr) {}
};

RandomListNode *copyRandomList(RandomListNode *head)
{
    if (!head)
        return nullptr;

    unordered_map<RandomListNode *, RandomListNode *> map;
    RandomListNode *curr = head;

    // Create all nodes with next pointers only
    while (curr)
    {
        map[curr] = new RandomListNode(curr->val);
        curr = curr->next;
    }

    // Set the next and random pointers
    curr = head;
    while (curr)
    {
        map[curr]->next = map[curr->next];
        map[curr]->random = map[curr->random];
        curr = curr->next;
    }

    return map[head];
}

// 3. Swap Nodes in a Linked List
ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *first = head, *second = head, *kthNode = nullptr;

    for (int i = 1; i < k; ++i)
    {
        first = first->next;
    }
    kthNode = first;

    while (first->next != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    swap(kthNode->val, second->val);

    return head;
}

// 4. Remove the N-th Node from the End of a List
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *fast = dummy;
    ListNode *slow = dummy;

    for (int i = 0; i <= n; ++i)
    {
        fast = fast->next;
    }

    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy->next;
}

// 5. Separate Odd and Even Nodes in a Linked List
ListNode *separateOddEvenNodes(ListNode *head)
{
    if (!head)
        return nullptr;

    ListNode *odd = head, *even = head->next, *evenHead = even;

    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

// 6. Divide a Linked List into Parts
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> result(k, nullptr);
    ListNode *curr = head;
    int length = 0;

    while (curr)
    {
        length++;
        curr = curr->next;
    }

    int partSize = length / k;
    int extra = length % k;
    curr = head;

    for (int i = 0; i < k && curr != nullptr; ++i)
    {
        result[i] = curr;
        int currPartSize = partSize + (extra-- > 0 ? 1 : 0);
        for (int j = 1; j < currPartSize; ++j)
        {
            curr = curr->next;
        }
        ListNode *next = curr->next;
        curr->next = nullptr;
        curr = next;
    }

    return result;
}

// 7. Remove Zero-Sum Consecutive Nodes from a Linked List
ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    unordered_map<int, ListNode *> prefixMap;
    int prefixSum = 0;

    for (ListNode *node = dummy; node != nullptr; node = node->next)
    {
        prefixSum += node->val;
        prefixMap[prefixSum] = node;
    }

    prefixSum = 0;
    for (ListNode *node = dummy; node != nullptr; node = node->next)
    {
        prefixSum += node->val;
        node->next = prefixMap[prefixSum]->next;
    }

    return dummy->next;
}

// 8. Automatic Input List
ListNode *automaticInputList()
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int size = rand() % 21 + 39; // Random size between 39 and 59

    for (int i = 0; i < size; ++i)
    {
        int val = rand() % 199 - 99; // Random value between -99 and 99
        ListNode *newNode = new ListNode(val);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void printRandomList(RandomListNode *head)
{
    while (head)
    {
        cout << "Value: " << head->val;
        if (head->random)
        {
            cout << ", Random points to: " << head->random->val;
        }
        else
        {
            cout << ", Random points to: nullptr";
        }
        cout << endl;
        head = head->next;
    }
}
// Menu function
int main()
{
    int choice;
    cout << "STT: 22520165\n";
    cout << "Full Name : Nguyen Chu Nguyen Chuong\n";
    cout << "In-Class Exercise - Part 2\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    do
    {
        cout << "\nSelect a problem to test:\n";
        cout << "1. Add Two Numbers\n";
        cout << "2. Copy List with Random Pointers\n";
        cout << "3. Swap Nodes in a Linked List\n";
        cout << "4. Remove the N-th Node from the End of a List\n";
        cout << "5. Separate Odd and Even Nodes in a Linked List\n";
        cout << "6. Divide a Linked List into Parts\n";
        cout << "7. Remove Zero-Sum Consecutive Nodes from a Linked List\n";
        cout << "8. Automatic Input List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ListNode *l1 = new ListNode(2);
            l1->next = new ListNode(4);
            l1->next->next = new ListNode(3);
            ListNode *l2 = new ListNode(5);
            l2->next = new ListNode(6);
            l2->next->next = new ListNode(4);
            ListNode *result = addTwoNumbers(l1, l2);
            cout << "Result of adding two numbers: ";
            while (result)
            {
                cout << result->val << " ";
                result = result->next;
            }
            cout << endl;
            break;
        }
        case 2:
        {
            // Create a sample RandomListNode linked list
            RandomListNode *head = new RandomListNode(1);
            head->next = new RandomListNode(2);
            head->next->next = new RandomListNode(3);
            head->random = head->next;             // 1's random points to 2
            head->next->random = head;             // 2's random points to 1
            head->next->next->random = head->next; // 3's random points to 2

            cout << "Original list with random pointers:\n";
            printRandomList(head);

            // Copy the list
            RandomListNode *copiedList = copyRandomList(head);

            cout << "Copied list with random pointers:\n";
            printRandomList(copiedList);

            break;
        }
        case 3:
        {
            ListNode *head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(4);
            head->next->next->next->next = new ListNode(5);
            cout << "Original list: ";
            printList(head);
            ListNode *swappedList = swapNodes(head, 2);
            cout << "List after swapping nodes: ";
            printList(swappedList);
            break;
        }
        case 4:
        {
            ListNode *head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(4);
            head->next->next->next->next = new ListNode(5);
            int n = 2;
            cout << "Original list: ";
            printList(head);
            ListNode *modifiedList = removeNthFromEnd(head, n);
            cout << "List after removing the " << n << "-th node from the end: ";
            printList(modifiedList);
            break;
        }
        case 5:
        {
            ListNode *head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(4);
            head->next->next->next->next = new ListNode(5);
            cout << "Original list: ";
            printList(head);
            ListNode *modifiedList = separateOddEvenNodes(head);
            cout << "List after separating odd and even nodes: ";
            printList(modifiedList);
            break;
        }
        case 6:
        {
            ListNode *head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(4);
            head->next->next->next->next = new ListNode(5);
            int k = 3;
            vector<ListNode *> parts = splitListToParts(head, k);
            cout << "Divided list into parts:\n";
            for (int i = 0; i < k; ++i)
            {
                cout << "Part " << i + 1 << ": ";
                printList(parts[i]);
            }
            break;
        }
        case 7:
        {
            ListNode *head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(-3);
            head->next->next->next->next = new ListNode(4);
            head->next->next->next->next->next = new ListNode(-2);
            cout << "Original list: ";
            printList(head);
            ListNode *modifiedList = removeZeroSumSublists(head);
            cout << "List after removing zero-sum sublists: ";
            printList(modifiedList);
            break;
        }
        case 8:
        {
            ListNode *list = automaticInputList();
            cout << "Generated list: ";
            while (list)
            {
                cout << list->val << " ";
                list = list->next;
            }
            cout << endl;
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
