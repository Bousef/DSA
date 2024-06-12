// Add two numbers

/*You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *temp = dummy;
    int carry = 0;

    // loop through the linked list while l1 or l2 or carry is not null
    while (l1 || l2 || carry)
    {
        int sum = 0;
        if (l1) // if l1 is not null
        {
            sum += l1->val; // add the value of l1 to sum
            l1 = l1->next;  // move to the next node
        }
        if (l2)
        {
            sum += l2->val; // add the value of l2 to sum
            l2 = l2->next;  // move to the next node
        }
        sum += carry;                                                                  // add the carry to the sum because we are adding two numbers and carry from the previous sum if any
        carry = sum / 10;                                                              // calculate the carry for the next sum if any
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode)); // create a new node
        newNode->val = sum % 10;                                                       // store the remainder of the sum in the new node
        newNode->next = NULL;                                                          // set the next node to null
        temp->next = newNode;                                                          // set the next node of the current node to the new node
        temp = temp->next;                                                             // move to the next node
    }
    return dummy->next;
}