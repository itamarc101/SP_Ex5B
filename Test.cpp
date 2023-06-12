#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("Add and Remove elements from Magical")
{
    MagicalContainer container;
    
    CHECK_EQ(container.size(), 0);
    container.addElement(7);
    container.addElement(2);
    container.addElement(5);
    CHECK_EQ(container.size(), 3);

    container.removeElement(7);
    CHECK_EQ(container.size(), 2);
    container.removeElement(2);
    container.removeElement(5);
    CHECK_EQ(container.size(), 0);

    CHECK_THROWS(container.removeElement(12));
}

TEST_CASE("Ascending")
{
    MagicalContainer container;
    container.addElement(7);
    container.addElement(2);
    container.addElement(5);
    container.addElement(4);
    container.addElement(1);
    MagicalContainer::AscendingIterator ascIt(container);

    CHECK_EQ(*ascIt, 1);
    ++ascIt;
    CHECK_EQ(*ascIt, 2);
    ++ascIt;
    CHECK_EQ(*ascIt, 4);
    ++ascIt;
    // skip 5
    ++ascIt;
    CHECK_EQ(*ascIt, 7);
}

TEST_CASE("SideCross")
{
    MagicalContainer container;
    container.addElement(7);
    container.addElement(2);
    container.addElement(5);   
    MagicalContainer::SideCrossIterator sCrossIt(container);
    CHECK_EQ(*sCrossIt, 2);
    ++sCrossIt;
    CHECK_EQ(*sCrossIt, 7);
    ++sCrossIt;
    CHECK_EQ(*sCrossIt, 5);
}

TEST_CASE("Prime")
{
    MagicalContainer container;
    container.addElement(7);
    container.addElement(6);
    container.addElement(2);
    container.addElement(13);   
    MagicalContainer::PrimeIterator pIt(container);
    CHECK_EQ(*pIt, 2);
    ++pIt;
    CHECK_EQ(*pIt, 7);
    ++pIt;
    CHECK_EQ(*pIt, 13);
}

TEST_CASE("Comparison")
{
    MagicalContainer container;
    container.addElement(7);
    container.addElement(2);
    container.addElement(1);
    container.addElement(27);
    MagicalContainer::AscendingIterator con1(container);
    MagicalContainer::AscendingIterator con2(container);

    CHECK(con1 == con2);
    ++con1;
    CHECK(con1 != con2);
    ++con2;
    CHECK(con1 == con2);
    ++con1;
    CHECK(*con1 > *con2);
    CHECK(*con2 < *con1);
}

TEST_CASE("Empty container")
{
    MagicalContainer container;
    MagicalContainer::SideCrossIterator cross(container);
    auto begin = cross.begin();
    auto end = cross.end();
    CHECK(begin == end);
}