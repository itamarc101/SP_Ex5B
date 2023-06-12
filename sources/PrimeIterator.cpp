#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, size_t primeIndex)
    : container(&container), primeIndex(primeIndex) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
    : container(&container), primeIndex(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
    : container(other.container), primeIndex(other.primeIndex) {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
{
    if(container != other.container) throw runtime_error("containers are different!!");

    if(this != &other)
    {
        container = other.container;
        primeIndex = other.primeIndex;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const
{
    return primeIndex == other.primeIndex;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
{
    return primeIndex != other.primeIndex;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
{
    return primeIndex < other.primeIndex;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
{
    return primeIndex > other.primeIndex;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    return *(*container).container_primes[primeIndex];
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    if( primeIndex >= (*container).container_primes.size()) throw runtime_error("out of bound index...");
    ++primeIndex;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(*this);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return PrimeIterator(*container, (*container).container_primes.size());
}