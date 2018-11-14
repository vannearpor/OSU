#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* Double link */
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

/* Double linked list with front and back sentinels */
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list)
{
    struct Link *linkedlist = (struct Link *) malloc(sizeof(struct Link));
    assert(linkedlist != 0);
    linkedlist->next = 0;
    linkedlist->prev = 0;
    list->frontSentinel = list->backSentinel = linkedlist;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
    struct Link *newLink = (struct Link *) malloc(sizeof(struct Link));
    assert(newLink != 0);
    newLink->value = value;
    link->prev->next = newLink;
    newLink->prev = link->prev;
    link->prev = newLink;
    newLink->next = link;
    list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
    assert(!linkedListIsEmpty(list));
    struct Link *remove = link;
    link->prev->next = link->next;
    link->next->prev = link->prev;
    link->next = 0;
    link->prev = 0;
    free(remove);
    list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = (struct LinkedList *) malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
    assert (list != 0);
    
    addLinkBefore (list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
    assert (list != 0);
    
    addLinkBefore (list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
    assert(!linkedListIsEmpty(list));
    return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
    assert(!linkedListIsEmpty(list));
    return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
    assert(!linkedListIsEmpty(list));
    struct Link *remove = list->frontSentinel->next;
    list->frontSentinel->next->next->prev = list->frontSentinel;
    list->frontSentinel->next = list->frontSentinel->next->next;
    free(remove);
    list->size--;
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
    assert(!linkedListIsEmpty(list));
    struct Link *remove = list->backSentinel->prev;
    list->backSentinel->prev->prev->next = list->backSentinel;
    list->backSentinel->prev = list->backSentinel->prev->prev;
    free(remove);
    list->size--;
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	if ((list->frontSentinel->next == 0) && (list->backSentinel->prev == 0))
    {
        return 1; /* true, is empty*/
    }
    else
    {
        return 0; /* false, is not empty */
    }
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
    assert(!linkedListIsEmpty(list));
    
    struct Link *printLink = list->frontSentinel->next;
    
    while (printLink != list->backSentinel)
    {
        printf("%d\n", printLink->value);
        printLink = printLink->next;
    }
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
    struct Link *newLink = (struct Link *) malloc(sizeof(struct Link));
    assert(newLink != 0);
    newLink->value = value;
    newLink->next = list->frontSentinel->next;
    newLink->prev = list->frontSentinel;
    list->frontSentinel->next->prev = newLink;
    list->frontSentinel->next = newLink;
    list->size++;
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
    assert(!linkedListIsEmpty(list));
    
    struct Link *contains = list->frontSentinel->next;
    
    while (contains != list->backSentinel)
    {
        if (contains->value == value)
        {
            return 1;
        }
        else
        {
            contains = contains->next; /* move to next link */
        }
    }
    
    return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
    assert(!linkedListIsEmpty(list));
    
    struct Link *remove = list->frontSentinel->next;
    
    while (remove != list->backSentinel)
    {
        if (remove->value == value)
        {
            removeLink(list, remove);
            break;
        }
        
        remove = remove->next; /* move to next link */
    }
}
