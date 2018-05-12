/*
 * ArrayList.h
 *
 *  Created on: 24 квіт. 2018 р.
 *      Author: atischenko
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "List.h"
#include "iostream"

namespace ticher777 {

template<typename ArrayListIteratorType>
class ArrayListIterator: public Iterator<ArrayListIteratorType> {
public:
	ArrayListIterator(const ArrayListIterator& iterator) = default;

	ArrayListIterator(ArrayListIteratorType *array, int size) :
			array(array), size(size) {
	}

	virtual ~ArrayListIterator() {
		array = nullptr;
	}

	virtual bool hasNext() const override
	{
		return array != nullptr && size != 0;
	}
	;

	virtual ArrayListIteratorType next() override
	{
		ArrayListIteratorType result = *array;
		if (hasNext()) {
			array++;
			size--;
		}
		return result;
	}
	;
private:
	ArrayListIteratorType* array;
	unsigned int size;
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
class ArrayList: public List<ArrayListType, ArrayListIterator<ArrayListType>> {
public:
	ArrayList() : ArrayList(10) {}

	ArrayList(const unsigned int initLenght) {
		m_array = new ArrayListType[initLenght];
		m_size = 0;
		m_length = initLenght;
	}

	virtual ~ArrayList() {
		delete[] m_array;
	}

	unsigned int size() const override {
		return m_size;
	}

	virtual ArrayListIterator<ArrayListType> iterator() const override {
		ArrayListIterator<ArrayListType> result(m_array, m_size);
		return result;
	}
	;
protected:

	virtual ArrayListType doGet(unsigned int index) const {
		return m_array[index];
	}

	virtual void doAdd(unsigned int index, ArrayListType value) {
		if (m_size == m_length) {
			m_length = std::min<unsigned int>(m_length * 2 + 1, MAX_LIST_SIZE);
			ArrayListType* newArray = new ArrayListType[m_length];
			for (unsigned int i = 0; i < m_size; i ++) {
				newArray[i] = m_array[i];
			}
			delete[] m_array;
			m_array = newArray;
		}

		if (index != m_size) {
			for (unsigned int i = m_size; i > index; i--) {
				m_array[i] = m_array[i - 1];
			}
		}
		m_array[index] = value;
		m_size++;
	}

	/**
	 * Safe remove method. Index is not out of the allowed range.
	 */
	virtual ArrayListType doRemove(unsigned int index) {
		ArrayListType result = m_array[index];
		for (unsigned int i = index; i < m_size - 1; i++) {
			m_array[i] = m_array[i + 1];
		}
		m_size--;
		return result;
	}

private:
	ArrayListType *m_array;
	unsigned int m_length;
	unsigned int m_size;
};

} /* namespace ticher777 */

#endif /* ARRAYLIST_H_ */
