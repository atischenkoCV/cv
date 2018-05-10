#include "catch.hpp"
#include "ArrayList.h"

TEST_CASE( "ArrayList#iterator" , "[ArrayList]") {

	SECTION("Common iterator test"){
	int i[]
	{	10, 20, 30};
	ticher777::ArrayListIterator<int> iterator(i, 3);

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
