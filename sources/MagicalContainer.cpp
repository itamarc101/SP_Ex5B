#include "MagicalContainer.hpp"
using namespace ariel;

bool MagicalContainer::isPrime(int num)
{
    if(num < 2) return false;
    
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}

// compares between the numbers so the vector will be sorted during insertion of each 
// elemenet so we keep the complexity good.
bool pSort(int *numA, int *numB)
{
    return *numA < *numB;
}

MagicalContainer::~MagicalContainer()
{

    for (size_t i = 0; i < container_primes.size(); i++)
    {
        delete container_primes[i];
    }

    container_primes.clear();
    
}

void MagicalContainer::addElement(int elem)
{
    // find the position where the element should be inserted in the container
    // we use lower_bound in order to find the last element before the right place for elem
    auto itt = lower_bound(container.begin(), container.end(), elem);
    //
    
    // insert the element at the found position
    container.insert(itt, elem);

    // check if prime
    if (isPrime(elem))
    {
        // creates a new pointer
        int* prime = new int(elem);
        
        // find the position where the prime element should be inserted 
        auto primeIt = lower_bound(container_primes.begin(), container_primes.end(), prime, pSort);
        
        // insert the prime element in his ordered index
        container_primes.insert(primeIt, prime);
    }
}

void MagicalContainer::removeElement(int elem)
{
    // indicator if element we want to remove is present
    bool flag = false;

    auto itt = container.begin();
    while( itt != container.end())
    {
        if(*itt == elem)
        {
            itt = container.erase(itt);
            flag = true;
            break;
        }
        ++itt;
    }
    
    if(isPrime(elem))
    {
        auto iter = container_primes.begin();
        while(iter != container_primes.end())
        {
            if(**iter == elem)
            {
                iter = container_primes.erase(iter);
                break;
            }
            ++iter;
        }
    }
    
    // if the element wasnt found in the container we throw error
    if(!flag) throw runtime_error("Element wasn't found in container!!");
}

size_t MagicalContainer::size() const
{
    return container.size();
}
