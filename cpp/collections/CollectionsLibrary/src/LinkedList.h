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

  class LinkedList : public List
  {
  public:
    LinkedList ();

    virtual
    ~LinkedList ();

    virtual int
    size () const override
    {
      return listSize;
    }
  protected:
    struct LinkedNode
    {
      int value;
      LinkedNode *next;
      LinkedNode *prev;
    };

    int
    doGet (int index) const override
    {
      return doGetNode (index)->value;
    }

    void
    doAdd (int index, int value) override;

    int
    doRemove (int index) override;

    LinkedNode*
    doGetNode (int index) const;

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
