/*
 * ArrayList.h
 *
 *  Created on: 24 квіт. 2018 р.
 *      Author: atischenko
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "List.h"

namespace ticher777
{

  template<typename ArrayListIteratorType>
    class ArrayListIterator : public Iterator<ArrayListIteratorType>
    {
    public:

      virtual bool
      hasNext () const override
      {
	//TODO[T7]: will be implement later
	return false;
      }
      ;

      virtual ArrayListIteratorType
      next () override
      {
	//TODO[T7]: will be implement later
	return 0;
      }
      ;
    };

  /**
   * ArrayList implementation of List. It's based on array to store values.
   *
   * The best practice to use this list is:
   * 1) you need random access to elements of array
   * 2) you want to add elements to the end of list
   *
   *
   * example:
   * ticher777::ArrayList<int> list;
   * list.add(11);
   * list.add(16);
   *
   * ticher777::ArrayListIterator<int> iterator = list.iterator();
   *
   * while(iterator.hasNext()) {
   * 	std::cout << iterator.next() << " ";
   * }
   */
  template<typename ArrayListType>
    class ArrayList : public List<ArrayListType,
	ArrayListIterator<ArrayListType>>
    {
    public:
      ArrayList (const unsigned int initLenght)
      {
	array = new ArrayListType[initLenght];
	size = 0;
	length = 0;
      }
      ;
      unsigned int
      getLength ()
      {
	return 0;
      }
      ;
      virtual ArrayListIterator<ArrayListType>
      iterator () const = 0;
    protected:

      virtual ArrayListType
      doGet (unsigned int index) const
      {
	return 0;
      }
      ;

      virtual void
      doAdd (unsigned int index, ArrayListType value)
      {
	//TODO[T7]: will be implement later
      }
      ;

      /**
       * Safe remove method. Index is not out of the allowed range.
       */
      virtual ArrayListType
      doRemove (unsigned int index)
      {
	//TODO[T7]: will be implement later
	return 0;
      }
      ;

    private:
      ArrayListType *array;
      unsigned int length;
      unsigned int size;
    };

} /* namespace ticher777 */

#endif /* ARRAYLIST_H_ */
