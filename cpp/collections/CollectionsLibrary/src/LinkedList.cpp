/*
 * LinkedList.cpp
 *
 *  Created on: Apr 18, 2018
 *      Author: atischenko
 */

#include "LinkedList.h"

using ticher777::LinkedList;

//TODO[T7]: how to separate implementation from declaration ???

//template<typename LinkedListType> LinkedList<LinkedListType>::LinkedList ()
//{
//  head = tail = nullptr;
//  listSize = 0;
//}
//;
//
//template<typename LinkedListType> LinkedList<LinkedListType>::~LinkedList ()
//{
//  int currentSize;
//  while ((currentSize = size ()) != 0)
//    {
//      doRemove (currentSize - 1);
//    }
//}
//;

//template<typename LinkedListType>
//void LinkedList<LinkedListType>::doAdd (int index, LinkedListType value)
//{
//  LinkedNode *newNode = new LinkedNode;
//  newNode->value = value;
//
//  if (index == 0)
//    {
//      newNode->prev = nullptr;
//      if (head == nullptr)
//	{
//	  head = tail = newNode;
//	  linkNodes (newNode, nullptr);
//	}
//      else
//	{
//	  linkNodes (newNode, head);
//	  head = newNode;
//	}
//    }
//  else if (index == size ())
//    {
//      linkNodes (newNode, nullptr);
//      if (tail == nullptr)
//	{
//	  head = tail = newNode;
//	  linkNodes (nullptr, newNode);
//	}
//      else
//	{
//	  linkNodes (tail, newNode);
//	  tail = newNode;
//	}
//    }
//  else
//    {
//      LinkedNode *currentNode = doGetNode (index);
//      linkNodes (currentNode->prev, newNode);
//      linkNodes (newNode, currentNode);
//    }
//
//  listSize++;
//}
;
//template<typename LinkedListType>
//LinkedListType
//LinkedList<LinkedListType>::doRemove (int index)
//{
//  LinkedListType result;
//  if (index == 0)
//    {
//      result = head->value;
//      if (head == tail)
//	{
//	  delete head;
//	  head = tail = nullptr;
//	}
//      else
//	{
//	  LinkedNode *newHead = head->next;
//	  linkNodes (head->prev, head->next);
//	  delete head;
//	  head = newHead;
//	}
//    }
//  else if (index == size () - 1)
//    {
//      result = tail->value;
//
//      LinkedNode *newTail = tail->prev;
//      linkNodes (tail->prev, tail->next);
//
//      delete tail;
//
//      tail = newTail;
//    }
//  else
//    {
//      LinkedNode *currentNode = doGetNode (index);
//      result = currentNode->value;
//      linkNodes (currentNode->prev, currentNode->next);
//
//      delete currentNode;
//    }
//
//  listSize--;
//
//  return result;
//}
//;

