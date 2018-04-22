/*
 * List.h
 *
 *  Created on: Apr 18, 2018
 *      Author: atischenko
 */

#ifndef LIST_H_
#define LIST_H_

#include <string>

namespace ticher777 {

	// TODO[t7]: I suppose it must be already calculated in std
#define MAX_LIST_SIZE 32767

	// TODO[T7]: list shouldn't be int-typed. it should be rewritten with template using
	/**
	 * Interface of list class.
	 *
	 * Simple class to store list of int values
	 */
	class List {
		public:
			/**
			 * return current size of the list
			 */
			virtual int size() const = 0;

			// TODO: list shouldn't be int-typed. it should be rewritten with template using
			/**
			 * Return value at index position.
			 *
			 * Index must be greater or equal zero and lower or equal the list's size, in other cases will be thrown exception.
			 */
			virtual int get(int index) const {
				checkIndex(0, size() - 1, index, "get");
				return doGet(index);
			}

			/**
			 * Add new value at index position.
			 *
			 * Index must be greater or equal zero and lower or equal the list's size, in other cases will be thrown exception.
			 * Also exception will be thrown if the list is already full filled.
			 */
			virtual void add(int index, int value) {
				checkAddIndex(index);
				doAdd(index, value);
			}

			/**
			 * Add new value at the end of the list
			 *
			 * Exception will be thrown if the list is already full filled.
			 */
			virtual void add(int value) {
				checkAddIndex(size());
				doAdd(size(), value);
			}
			/**
			 * Remove value at index.
			 *
			 * Index must be greater or equal zero and lower or equal the list's size, in other cases will be thrown exception.
			 */
			virtual int remove(int index) {
				checkIndex(0, size() - 1, index, "remove");
				return doRemove(index);
			}
		protected:

			/**
			 * Safe get value. Index is not out of the allowed range
			 */
			virtual int doGet(int index) const = 0;

			/**
			 * Safe add method. Index is not out of the allowed range.
			 */
			virtual void doAdd(int index, int value) = 0;

			/**
			 * Safe remove method. Index is not out of the allowed range.
			 */
			virtual int doRemove(int index) = 0;

			/**
			 * Safe remove value at index. Index is not out of the allowed range.
			 */

			void checkAddIndex(int index) const {
				checkIndex(0, size(), index, "add");
				if (index == MAX_LIST_SIZE) {
					throw "List is full-filled.";
				}
			}

			void checkIndex(int lowerBound, int upperBound, int index, const std::string& method) const {
				if (index < lowerBound || index > upperBound) {
					throw getIndexErrorMessage(lowerBound, upperBound, index, method);
				}
			}

			const std::string getIndexErrorMessage(int lowerBound, int upperBound, int index, const std::string& method) const {
				std::string error;
				error.assign("Index ").append(std::to_string(index))
						.append(" is out of range for '").append(method).append("' operation.")
						.append(" Valid range: [").append(std::to_string(lowerBound)).append(", ").append(std::to_string(upperBound)).append("]");
				return error;
			}
	};

}
/* namespace ticher777 */

#endif /* LIST_H_ */
