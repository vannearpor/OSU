#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

/* Double link */
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
    struct Link *circleList = (struct Link *) malloc(sizeof(struct Link));
    assert(circleList != 0);
    circleList->next = 0;
    circleList->prev = 0;
    list->sentinel = circleList;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
    struct Link *newLink = (struct Link *) malloc(sizeof(struct Link));
    assert(newLink != 0);
    newLink->value = value;
    newLink->next = 0;
    newLink->prev = 0;
	return NULL;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
    struct Link *newLink = (struct Link *) malloc(sizeof(struct Link));
    assert(newLink != 0);
    newLink->value = value;
    newLink->prev = link;
    newLink->next = link->next;
    link->next->prev = newLink;
    link->next = newLink;
    list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
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
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
    while (!circularListIsEmpty(list));
    {
        circularListRemoveFront(list);
    }
    free(list->sentinel);
    free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
    struct Link *addFront = (struct Link *) malloc(sizeof(struct Link));
    assert(addFront != 0);
    addFront->value = value;
    addFront->prev = list->sentinel;
    addFront->next = list->sentinel->next;
    list->sentinel->next->prev = addFront;
    list->sentinel->next = addFront;
    list->size++;
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
    struct Link *addBack = (struct Lihnk *) malloc(sizeof(struct Link));
    assert(addBack != 0);
    addBack->value = value;
    addBack->prev = list->sentinel->prev;
    addBack->next = list->sentinel;
    list->sentinel->prev->next = addBack;
    list->sentinel->prev = addBack;
    list->size++;
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
    assert(!circularListIsEmpty(list));
    
    return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
    assert(!circularListIsEmpty(list));
    
    return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
    assert(!circularListIsEmpty(list));
    
    struct Link *remove = list->sentinel->next;
    
    list->sentinel->next->next->prev = list->sentinel;
    list->sentinel->next = list->sentinel->next->next;
    free(remove);
    list->size--;
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
    assert(!circularListIsEmpty(list));
    
    struct Link *remove = list->sentinel->prev;
    list->sentinel->prev->prev->next = list->sentinel;
    list->sentinel->prev = list->sentinel->prev->prev;
    free(remove);
    list->size--;
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	if ((list->sentinel->next == 0) && (list->sentinel->prev == 0))
    {
        return 1; /* true, is empty */
    }
    else
    {
        return 0; /* false, is not empty */
    }
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
    assert (!circularListIsEmpty(list));
    
    struct Link *printLink = list->sentinel->next;
    
    while (printLink != list->sentinel)
    {
        printf("%d\n", printLink->value);
        printLink = printLink->next;
    }
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
    assert (!circularListIsEmpty(list));
    
    struct Link *prevLink = 0;
    struct Link *currentLink = list->sentinel->next;
    struct Link *nextLink = 0;
    
    for (int i = 0; i < list->size; i++)
    {
        nextLink = currentLink->next;
        currrentLink->next = prevLink;
        prevLink = currentLink;
        currentLink = nextLink;
    }
    
    list->sentinel->next = prevLink;
    
}
