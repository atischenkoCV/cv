#include "catch.hpp"
#include "ArrayList.h"

TEST_CASE( "ArrayList#iterator" , "[ArrayList]") {

	SECTION("Common iterator test"){
	ticher777::ArrayList<int> list(3);

	list.add(10);
	list.add(20);
	list.add(30);

	ticher777::ArrayListIterator<int> iterator = list.iterator();

	REQUIRE(iterator.hasNext());
	REQUIRE(iterator.next() == 10);

	REQUIRE(iterator.hasNext());
	REQUIRE(iterator.next() == 20);

	REQUIRE(iterator.hasNext());
	REQUIRE(iterator.next() == 30);

	REQUIRE(!iterator.hasNext());

	double *l = nullptr;
	ticher777::ArrayListIterator<double> iterator2(l, 0);
	REQUIRE(!iterator.hasNext());
}

}

TEST_CASE( "ArrayList#add" , "[ArrayList]") {
	ticher777::ArrayList<int> list(0);

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

		REQUIRE_THROWS_WITH(list.add(-1, 20), "Index 4294967295 is out of range for 'add' operation. Valid range: [0, 1]");
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

TEST_CASE( "ArrayList#get" , "[ArrayList]") {
	ticher777::ArrayList<double> list;
	REQUIRE(list.size() == 0);

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
	REQUIRE_THROWS_WITH(list.get(-1), "Index 4294967295 is out of range for 'get' operation. Valid range: [0, 199]");
}
}

TEST_CASE( "ArrayList#remove" , "[ArrayList]" ) {
	ticher777::ArrayList<int> list;
	REQUIRE(list.size() == 0);

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

	REQUIRE_THROWS_WITH(list.remove(-1), "Index 4294967295 is out of range for 'remove' operation. Valid range: [0, 197]");
	REQUIRE_THROWS_WITH(list.remove(list.size()), "Index 198 is out of range for 'remove' operation. Valid range: [0, 197]");
	REQUIRE_THROWS_WITH(list.remove(1000), "Index 1000 is out of range for 'remove' operation. Valid range: [0, 197]");
}

	SECTION( "Check return value of 'remove' method" ){
	int listValue = 222888;
	list.add(listValue);
	REQUIRE(list.remove(0) == listValue);
}
}
