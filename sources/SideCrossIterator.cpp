#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t index)
    : container(&container), index(index) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    : container(&container), index(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
    : container(other.container), index(other.index) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
{
    if(container != other.container) throw runtime_error("containers are different!!");

    if(this != &other)
    {
        container = other.container;
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
{
    return index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
{
    return index != other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
{
    return index < other.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
{
    return index > other.index;
}

int MagicalContainer::SideCrossIterator::operator*() 
{
    return (*(this->container)).container[index];
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    size_t containerSize = (*container).container.size();
    size_t midIndex = containerSize / 2;

    // check if the iterator pointer at the last element - we cant go forward
    if (index == containerSize) throw runtime_error("last element");

    // if pointer at the mid element
    if( index == midIndex)
    {
        // set the index to the last element
        index = containerSize;
        return *this;
    }

    // if the pointer at the element before the middle element
    if( index < midIndex)
    {
        // move the iterator to the corresponding element at the other side
        index = containerSize - index - 1;
        return *this;
    }

    // if the pointer at the element after the middle element
    if( index > midIndex)
    {
        // move the iterator to the corresponding element at the other side
        index = containerSize - index;
        return *this;
    }
    
    // shouldnt be reached since we covered all the cases but in any case, we add this
    // to return the iterator
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() 
{
	return SideCrossIterator(*this);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{

    return SideCrossIterator(*container, (*container).size());
}