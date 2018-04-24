/*
 * List.h
 *
 *  Created on: Apr 18, 2018
 *      Author: atischenko
 */

#ifndef LIST_H_
#define LIST_H_

#include <string>

namespace ticher777
{

  // TODO[t7]: I suppose it must be already calculated in std
#define MAX_LIST_SIZE 32767

  template<typename IteratorType>
  class Iterator {
  public:
    /**
     * Return true if one more value is available
     */
    virtual bool hasNext() const = 0;

    /**
     * Select and return next value in iterator
     *
     * Undefined behaviour if iterator is empty
     */
    virtual IteratorType next() = 0;
  };

  /**
   * Interface of list class.
   *
   * Simple class to store list of int values
   */
  template<typename ListType, typename ListIterator>
  class List
  {
  public:
    /**
     * return current size of the list
     */
    virtual unsigned int
    size () const = 0;

    // TODO: list shouldn't be int-typed. it should be rewritten with template using
    /**
     * Return value at index position.
     *
     * Index must be greater or equal zero and lower or equal the list's size, in other cases will be thrown exception.
     */
    virtual ListType
    get (unsigned int index) const
    {
      checkIndex (size () - 1, index, "get");
      return doGet (index);
    }

    /**
     * Add new value at index position.
     *
     * Index must be greater or equal zero and lower or equal the list's size, in other cases will be thrown exception.
     * Also exception will be thrown if the list is already full filled.
     */
    virtual void
    add (unsigned int index, ListType value)
    {
      checkAddIndex (index);
      doAdd (index, value);
    }

    /**
     * Add new value at the end of the list
     *
     * Exception will be thrown if the list is already full filled.
     */
    virtual void
    add (ListType value)
    {
      checkAddIndex (size ());
      doAdd (size (), value);
    }
    /**
     * Remove value at index.
     *
     * Index must be greater or equal zero and lower or equal the list's size, in other cases will be thrown exception.
     */
    virtual ListType
    remove (unsigned int index)
    {
      checkIndex (size () - 1, index, "remove");
      return doRemove (index);
    }

    virtual ListIterator iterator() const = 0;
  protected:

    /**
     * Safe get value. Index is not out of the allowed range
     */
    virtual ListType
    doGet (unsigned int index) const = 0;

    /**
     * Safe add method. Index is not out of the allowed range.
     */
    virtual void
    doAdd (unsigned int index, ListType value) = 0;

    /**
     * Safe remove method. Index is not out of the allowed range.
     */
    virtual ListType
    doRemove (unsigned int index) = 0;

    /**
     * Safe remove value at index. Index is not out of the allowed range.
     */

    void
    checkAddIndex (unsigned int index) const
    {
      checkIndex (size (), index, "add");
      if (index == MAX_LIST_SIZE)
	{
	  throw "List is full-filled.";
	}
    }

    void
    checkIndex (unsigned int upperBound, unsigned int index,
		const std::string& method) const
    {
      if (index > upperBound)
	{
	  throw getIndexErrorMessage (upperBound, index, method);
	}
    }

    const std::string
    getIndexErrorMessage (int upperBound, unsigned int index,
			  const std::string& method) const
    {
      std::string error;
      error.assign ("Index ").append (std::to_string (index)).append (
	  " is out of range for '").append (method).append ("' operation.").append (
	  " Valid range: [0, ").append (std::to_string (upperBound)).append ("]");
      return error;
    }
  };

}
/* namespace ticher777 */

#endif /* LIST_H_ */
