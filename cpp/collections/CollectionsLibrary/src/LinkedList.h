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

  /**
   * Simple class to describe LinkedList node. It has two pointers for previous and next nodes. And it contains values stored value
   */
  template<typename LinkedNodeType>
    class LinkedNode
    {
    public:
      LinkedNodeType value;
      LinkedNode *next;
      LinkedNode *prev;
    };

  /**
   * LinkedList iterator walk through head LinkedNode to chain's tail.
   */
  template<typename LinkedListIteratorType>
    class LinkedListIterator : public ticher777::Iterator<LinkedListIteratorType>
    {
    public:
      LinkedListIterator (LinkedNode<LinkedListIteratorType>* head)
      {
	iteratorHead = new LinkedNode<LinkedListIteratorType>();
	iteratorHead->next = head;
	currentPosition = iteratorHead;
      }
      ;
      ~LinkedListIterator ()
      {
	currentPosition = nullptr;
      }
      virtual bool
      hasNext () const override
      {
	return currentPosition != nullptr && currentPosition->next != nullptr;
      }
      ;
      virtual LinkedListIteratorType
      next () override
      {
	if (hasNext ())
	  {
	    currentPosition = currentPosition->next;
	  }
	return currentPosition->value;
      }
      ;
    private:
      LinkedNode<LinkedListIteratorType>* currentPosition;
      LinkedNode<LinkedListIteratorType>* iteratorHead;
    };

  template<typename LinkedListType>
    class LinkedList : public List<LinkedListType, LinkedListIterator<LinkedListType>>
    {
      friend class LinkedListIterator<LinkedListType> ;
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

      virtual unsigned
      size () const override
      {
	return listSize;
      }
      ;

      virtual LinkedListIterator<LinkedListType>
      iterator () const override
      {
	LinkedListIterator<LinkedListType> iterator (head);
	return iterator;
      }
      ;
    protected:

      LinkedListType
      doGet (unsigned int index) const override
      {
	return doGetNode (index)->value;
      }

      void
      doAdd (unsigned int index, LinkedListType value) override
      {
	LinkedNode<LinkedListType> *newNode = new LinkedNode<LinkedListType>;
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
	    LinkedNode<LinkedListType> *currentNode = doGetNode (index);
	    linkNodes (currentNode->prev, newNode);
	    linkNodes (newNode, currentNode);
	  }

	listSize++;
      }

      LinkedListType
      doRemove (unsigned int index) override
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
		LinkedNode<LinkedListType> *newHead = head->next;
		linkNodes (head->prev, head->next);
		delete head;
		head = newHead;
	      }
	  }
	else if (index == size () - 1)
	  {
	    result = tail->value;

	    LinkedNode<LinkedListType> *newTail = tail->prev;
	    linkNodes (tail->prev, tail->next);

	    delete tail;

	    tail = newTail;
	  }
	else
	  {
	    LinkedNode<LinkedListType> *currentNode = doGetNode (index);
	    result = currentNode->value;
	    linkNodes (currentNode->prev, currentNode->next);

	    delete currentNode;
	  }

	listSize--;

	return result;
      }

      LinkedNode<LinkedListType>*
      doGetNode (int index) const
      {
	int currentIndex = 0;
	LinkedNode<LinkedListType> *currentNode = head;
	while (currentIndex != index)
	  {
	    currentIndex++;
	    currentNode = currentNode->next;
	  }
	return currentNode;
      }

      void
      linkNodes (LinkedNode<LinkedListType>* prev, LinkedNode<LinkedListType>* next) const
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

      LinkedNode<LinkedListType> *head;
      LinkedNode<LinkedListType> *tail;
      unsigned listSize;
    };

} /* namespace ticher777 */

#endif /* LINKEDLIST_H_ */
