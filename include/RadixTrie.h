//
// Created by Kyle Gendreau on 7/5/21.
//

#ifndef RADIXTRIE_RADIXTRIE_H
#define RADIXTRIE_RADIXTRIE_H

#include "../module/SimpleTrieTemplate/include/SimpleTrieTemplate.h"
#include "RadixIterator.h"
#include "Parameters.h"

template<typename T>
class RadixTrie {
public:

    static const uint16_t S =                       26;
    typedef std::string                             key_type;
    typedef T                                       mapped_type;
    typedef Node<key_type,mapped_type,S>            Node;
    typedef Radix_Indexer<mapped_type>              key_indexer;
    typedef Radix_Eraser<mapped_type>               key_eraser;
    typedef RadixIterator<mapped_type>              iterator;

    // def ctor
    explicit RadixTrie();

    // copy ctor
    explicit RadixTrie(const RadixTrie<T>& rhs);
    explicit RadixTrie(const RadixTrie<T>&& rhs);

    // dtor
    ~RadixTrie() = default;

    // assignment
    RadixTrie<T> &operator=(const RadixTrie<T>& rhs);
    RadixTrie<T> &operator=(const RadixTrie<T>&& rhs);

//////////////////////////////////////////////////////
//// CAPACITY

    /**
     * checks whether the container is empty
     * @return - true if empty, false otherwise
     */
    bool empty() const noexcept;

    /**
     * returns the number of articles in trie
     * @return - unsigned int for number of elements in trie
     */
    uint32_t size() const noexcept;

//////////////////////////////////////////////////////
//// MODIFIERS

    /**
     * clears the contents, ie if not already empty, deletes the contents of the trie
     */
    void clear() noexcept;

    /**
     * inserts article if not already present, and adds value at end of article's sequence
     * @param article - the key used to find value's target
     * @param value - the value being stored at element
     * @return - an iterator to the node that holds value
     */
    //region //insert();
    iterator insertOrAssign(std::pair<key_type,mapped_type>& p, Node* ancestor = nullptr);
    iterator insertOrAssign(std::pair<key_type,mapped_type>&& p, Node* ancestor = nullptr);

    iterator insertOrAssign(key_type article, mapped_type& value, Node* ancestor = nullptr);
    iterator insertOrAssign(key_type article, mapped_type&& value, Node* ancestor = nullptr);
    //endregion

    /**
     * erases article within trie
     * @param article - the key being deleted
     */
    void erase(key_type article,Node* ancestor = nullptr);

    /**
     * swaps the contents
     * @param rhs - the container to exchange the contents with
     */
    void swap(RadixTrie& rhs) noexcept;

//////////////////////////////////////////////////////
//// LOOKUPS

    /**
     * finds the node that holds the values for the article
     * @param article - the article being searched for
     * @return - an iterator at the last node in sequence for the article, else returns .end()
     */
    iterator find(key_type article);

    /**
     * finds the last viable node in sequence for the article. The returned pair contains, first, a boolean which holds
     * the same value as the contains() function returns, and second, an iterator at the last viable node in sequence.
     *
     * Example: given 'LOOKUP' was inserted in a BTrie, scout('LOOK') will return pair<false,node('K')>, and
     * scout('LOOKUP') will return pair<true,node('P')> (where node(N) represents the node at N letter in the node
     * sequence)
     *
     * @param article - the article being searched for
     * @return - returns a pair of a boolean and an iterator at the last viable node for the article's node sequence
     */
    std::pair<bool,iterator> scout(key_type article,Node* ancestor = nullptr);

    /**
     * checks if the container contains element
     * @param element - the key being searched for
     * @return - true if in container, else false
     */
    bool contains(key_type article,Node* ancestor = nullptr);

//////////////////////////////////////////////////////
//// COMPARERS

    bool operator==(const RadixTrie& rhs) const;
    bool operator!=(const RadixTrie& rhs) const;

//////////////////////////////////////////////////////
//// ITERATORS

    iterator begin();

    iterator end();

private:

    SimpleTrieTemplate<std::string,T,26> trie_;

};

#include "../src/RadixTrie.cpp"

#endif //RADIXTRIE_RADIXTRIE_H
