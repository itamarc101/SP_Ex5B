#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace ariel
{
/*###########################################################################################
##########################      MAGICAL CONTAINER      ######################################
#############################################################################################*/

    class MagicalContainer
    {
    private:
        // container of the elements
        vector<int> container;

        // container of pointers of prime
        vector<int*> container_primes;

        
    public:
        //ctor for new magical object, deault so empty
        MagicalContainer() = default;

        // destructor
        ~MagicalContainer(); 
 
        // add element to the container, 
        //if element exists there will be no duplicates
        void addElement(int elem); 
        
        // remove element from the container,
        // if we try to remove non existing element there will be an error
        void removeElement(int elem); 

        // return the size of container
        size_t size() const;
        
        // check if num is prime
        bool isPrime(int num);

/*###########################################################################################
##########################      Ascending Iterator      #####################################
#############################################################################################*/
        class AscendingIterator
        {
            private:
                // container of the numbers we go through
                MagicalContainer *container;

                // index of the container iterator
                size_t index;

            public:
                // ctor to initialize element in given index in the container
                AscendingIterator(MagicalContainer &, size_t);
                
                // ctor to initialize first element in container
                AscendingIterator(MagicalContainer &); 

                // copy ctor
                AscendingIterator(const AscendingIterator& ); 
                
                // default dtor, destroy object
                ~AscendingIterator(){};

                // for tidy
                // move ctor and move asgnmnt operator
                AscendingIterator(AscendingIterator&&) noexcept;            
                AscendingIterator& operator=(AscendingIterator&&) noexcept;
                
                // first element
                AscendingIterator begin();

                // last element
                AscendingIterator end();

                // copy assignment operator
                AscendingIterator& operator=(const AscendingIterator&);
                
                // bool operators between 2 iterators
                bool operator==(const AscendingIterator &) const;
                bool operator!=(const AscendingIterator &) const;
                bool operator>(const AscendingIterator &) const;
                bool operator<(const AscendingIterator &) const;
                
                // iterates over the container elements
                AscendingIterator &operator++();

                // dereference - return element at cur index
                int operator*() const; 
        };

/*###########################################################################################
##########################      SIDECROSS ITERATOR      #####################################
#############################################################################################*/
        class SideCrossIterator
        {
        private:
            MagicalContainer *container;
            size_t index;

        public:
            SideCrossIterator(MagicalContainer& , size_t);
            SideCrossIterator(MagicalContainer&);
            SideCrossIterator(const SideCrossIterator& ); 
            ~SideCrossIterator(){};

            SideCrossIterator(SideCrossIterator&&) noexcept;
            SideCrossIterator& operator=(SideCrossIterator&&) noexcept;

            SideCrossIterator begin();
            SideCrossIterator end();

            SideCrossIterator& operator=(const SideCrossIterator&);
            bool operator==(const SideCrossIterator &) const;
            bool operator!=(const SideCrossIterator &) const;
            bool operator>(const SideCrossIterator &) const;
            bool operator<(const SideCrossIterator &) const;
            SideCrossIterator& operator++();

            int operator*();
        };

/*###########################################################################################
##########################      PRIME ITERATOR      #########################################
#############################################################################################*/
        class PrimeIterator
        {
        private:
            MagicalContainer *container;
            size_t primeIndex;

        public:
            PrimeIterator(MagicalContainer&, size_t);
            PrimeIterator(MagicalContainer&);
            PrimeIterator(const PrimeIterator& ); 
            ~PrimeIterator(){};

            PrimeIterator(PrimeIterator&& ) noexcept; 
            PrimeIterator& operator=(PrimeIterator&&) noexcept;

            PrimeIterator begin();
            PrimeIterator end();

            PrimeIterator &operator=(const PrimeIterator &);
            bool operator==(const PrimeIterator &) const;
            bool operator!=(const PrimeIterator &) const;
            bool operator>(const PrimeIterator &) const;
            bool operator<(const PrimeIterator &) const;
            PrimeIterator& operator++();            
            
            int operator*() const;
        };
    };

}
