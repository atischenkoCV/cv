/*
 * LinkedListTest.cpp
 *
 *  Created on: 19 квіт. 2018 р.
 *      Author: atischenko
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedList.h"

#include <string>
#include <stdlib.h>
#include <time.h>

TEST_CASE( "LinkedList#add" , "[LinkedList]")
{
  ticher777::LinkedList<int> list;
  REQUIRE(list.size () == 0);

  // TODO[ECLIPSE-bug]: WRONG FORMATTING
  SECTION("Check adding in empty list"){
  list.add(0);

  REQUIRE( list.size() == 1);
}

  SECTION( "Check adding in full-filled list"){
  for (int i = 0; i < MAX_LIST_SIZE; i++)
    {
      list.add(i);
    }
  REQUIRE( list.size() == MAX_LIST_SIZE);

  REQUIRE_THROWS_WITH(list.add(-1), "List is full-filled.");
}
  SECTION( "Check bound indexes for 'add' method" ){
  REQUIRE_THROWS_WITH(list.add(10, -1), "Index 10 is out of range for 'add' operation. Valid range: [0, 0]");
  list.add(11);
  REQUIRE_THROWS_WITH(list.add(-1, 20), "Index -1 is out of range for 'add' operation. Valid range: [0, 1]");
}

  SECTION( "Check adding random values to list"){
  srand (time(nullptr));

  for (int i = 0; i < 200; i++)
    {
      list.add(rand());
    }
  REQUIRE(list.size() == 200);
}
}

TEST_CASE( "LinkedList#get" , "[LinkedList]")
{
  ticher777::LinkedList<double> list;
  REQUIRE(list.size () == 0);

  SECTION( "Check getting for a random index"){
  srand (time(nullptr));
  int listSize = 200;

  for (int i = 0; i < listSize; i++)
    {
      list.add(i);
    }
  for (int i = 0; i < listSize; i++)
    {
      list.get(rand() % listSize);
    }

}
  SECTION( "Check bound indexes for 'get' method"){
  int listSize = 200;
  for (int i = 0; i < listSize; i++)
    {
      list.add(i);
    }
  list.get(0);
  list.get(listSize - 1);
  REQUIRE_THROWS_WITH(list.get(-1), "Index -1 is out of range for 'get' operation. Valid range: [0, 199]");
}
}

TEST_CASE( "LinkedList#remove" , "[LinkedList]" )
{
  ticher777::LinkedList<int> list;
  REQUIRE(list.size () == 0);

  SECTION( "Check removing the last element in the list" ){
  int listSize = 200;

  for (int i = 0; i < listSize; i++)
    {
      list.add(i);
    }
  for (int i = 0; i < listSize; i++)
    {
      list.remove(list.size() - 1);
    }

  REQUIRE(list.size() == 0);

}
  SECTION( "Check removing the first element in the list" ){
  int listSize = 200;

  for (int i = 0; i < listSize; i++)
    {
      list.add(i);
    }
  for (int i = 0; i < listSize; i++)
    {
      list.remove(0);
    }

  REQUIRE(list.size() == 0);
}

  SECTION( "Check bound indexes for remove method" ){
  int listSize = 200;
  for (int i = 0; i < listSize; i++)
    {
      list.add(i);
    }
  list.remove(0);
  REQUIRE(list.size() == listSize - 1);

  list.remove(list.size() - 1);
  REQUIRE(list.size() == listSize - 2);

  REQUIRE_THROWS_WITH(list.remove(-1), "Index -1 is out of range for 'remove' operation. Valid range: [0, 197]");
  REQUIRE_THROWS_WITH(list.remove(list.size()), "Index 198 is out of range for 'remove' operation. Valid range: [0, 197]");
  REQUIRE_THROWS_WITH(list.remove(1000), "Index 1000 is out of range for 'remove' operation. Valid range: [0, 197]");
}

  SECTION( "Check return value of 'remove' method" ){
  int listValue = 222888;
  list.add(listValue);
  REQUIRE(list.remove(0) == listValue);
}
}

TEST_CASE( "LinkedList templates" , "[LinkedList]" )
{

  SECTION( "Check using pointers as template" ){
  ticher777::LinkedList<int *> list;

  int i[20];
  list.add(i);
  REQUIRE(list.size() == 1);

  i[4] = 30;
  REQUIRE(list.get(0)[4] == 30);
}

}

TEST_CASE( "LinkedList Iterator" , "[LinkedList]" )
{
  ticher777::LinkedList<int> list;

  SECTION( "Check iterator" ){

  list.add(1);
  list.add(4);
  list.add(-200);

  ticher777::LinkedListIterator<int> iterator = list.iterator();

  REQUIRE(iterator.hasNext());
  REQUIRE(iterator.next() == 1);

  REQUIRE(iterator.hasNext());
  REQUIRE(iterator.next() == 4);

  REQUIRE(iterator.hasNext());
  REQUIRE(iterator.next() == -200);

  REQUIRE(!iterator.hasNext());
}

  SECTION( " Check empty iterator " ) {
    ticher777::LinkedListIterator<int> iterator = list.iterator();
    REQUIRE(!iterator.hasNext());
    REQUIRE(!iterator.next());

  }

}
