/*
 * LinkedList.h
 *
 *  Created on: Apr 18, 2018
 *      Author: atischenko
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "List.h"

namespace ticher777
{

  template<typename LinkedListType>
    class LinkedList : public List<LinkedListType>
    {
    public:
      LinkedList ()
      {
	head = tail = nullptr;
	listSize = 0;
      }

      virtual
      ~LinkedList ()
      {
	int currentSize;
	while ((currentSize = size ()) != 0)
	  {
	    doRemove (currentSize - 1);
	  }
      }
      ;

      virtual int
      size () const override
      {
	return listSize;
      }
    protected:
      struct LinkedNode
      {
	LinkedListType value;
	LinkedNode *next;
	LinkedNode *prev;
      };

      LinkedListType
      doGet (int index) const override
      {
	return doGetNode (index)->value;
      }

      void
      doAdd (int index, LinkedListType value) override
      {
	LinkedNode *newNode = new LinkedNode;
	newNode->value = value;

	if (index == 0)
	  {
	    newNode->prev = nullptr;
	    if (head == nullptr)
	      {
		head = tail = newNode;
		linkNodes (newNode, nullptr);
	      }
	    else
	      {
		linkNodes (newNode, head);
		head = newNode;
	      }
	  }
	else if (index == size ())
	  {
	    linkNodes (newNode, nullptr);
	    if (tail == nullptr)
	      {
		head = tail = newNode;
		linkNodes (nullptr, newNode);
	      }
	    else
	      {
		linkNodes (tail, newNode);
		tail = newNode;
	      }
	  }
	else
	  {
	    LinkedNode *currentNode = doGetNode (index);
	    linkNodes (currentNode->prev, newNode);
	    linkNodes (newNode, currentNode);
	  }

	listSize++;
      }

      LinkedListType
      doRemove (int index) override
      {
	LinkedListType result;
	if (index == 0)
	  {
	    result = head->value;
	    if (head == tail)
	      {
		delete head;
		head = tail = nullptr;
	      }
	    else
	      {
		LinkedNode *newHead = head->next;
		linkNodes (head->prev, head->next);
		delete head;
		head = newHead;
	      }
	  }
	else if (index == size () - 1)
	  {
	    result = tail->value;

	    LinkedNode *newTail = tail->prev;
	    linkNodes (tail->prev, tail->next);

	    delete tail;

	    tail = newTail;
	  }
	else
	  {
	    LinkedNode *currentNode = doGetNode (index);
	    result = currentNode->value;
	    linkNodes (currentNode->prev, currentNode->next);

	    delete currentNode;
	  }

	listSize--;

	return result;
      }

      LinkedNode*
      doGetNode (int index) const
      {
	int currentIndex = 0;
	LinkedNode *currentNode = head;
	while (currentIndex != index)
	  {
	    currentIndex++;
	    currentNode = currentNode->next;
	  }
	return currentNode;
      }

      void
      linkNodes (LinkedNode* prev, LinkedNode* next) const
      {
	if (prev != nullptr)
	  {
	    prev->next = next;
	  }
	if (next != nullptr)
	  {
	    next->prev = prev;
	  }
      }
      ;
    private:

      LinkedNode *head;
      LinkedNode *tail;
      int listSize;
    };

} /* namespace ticher777 */

#endif /* LINKEDLIST_H_ */
