//
// Created by Kyle Gendreau on 7/5/21.
//

#ifndef RADIXTRIE_RADIXTRIE_CPP
#define RADIXTRIE_RADIXTRIE_CPP

#include "../include/RadixTrie.h"

template<typename T>
RadixTrie<T>::RadixTrie() : trie_() {}

template<typename T>
RadixTrie<T>::RadixTrie(const RadixTrie<T> &rhs) : trie_(rhs.trie_) {}

template<typename T>
RadixTrie<T>::RadixTrie(const RadixTrie<T> &&rhs) : trie_(rhs.trie_) {}

template<typename T>
RadixTrie<T> &RadixTrie<T>::operator=(const RadixTrie<T> &rhs) {
    if (this != &rhs) {
        RadixTrie<T> ph(rhs);
        this->swap(ph);
    }
    return *this;
}

template<typename T>
RadixTrie<T> &RadixTrie<T>::operator=(const RadixTrie<T> &&rhs) {
    return *this = rhs;
}

template<typename T>
bool RadixTrie<T>::empty() const noexcept {
    return trie_.empty();
}

template<typename T>
uint32_t RadixTrie<T>::size() const noexcept {
    return trie_.size();
}

template<typename T>
void RadixTrie<T>::clear() noexcept {
    trie_.clear();
}

template<typename T>
typename RadixTrie<T>::iterator RadixTrie<T>::insertOrAssign(std::pair<key_type, mapped_type> &p, Node *ancestor) {
    return insertOrAssign(p.first,p.second,ancestor);
}

template<typename T>
typename RadixTrie<T>::iterator RadixTrie<T>::insertOrAssign(std::pair<key_type, mapped_type> &&p, Node *ancestor) {
    return insertOrAssign(p.first,p.second,ancestor);
}

template<typename T>
typename RadixTrie<T>::iterator RadixTrie<T>::insertOrAssign(key_type article, mapped_type &value, Node *ancestor) {
    return iterator(trie_.insertOrAssign(article,value,ancestor));
}

template<typename T>
typename RadixTrie<T>::iterator RadixTrie<T>::insertOrAssign(key_type article, mapped_type &&value, Node *ancestor) {
    return insertOrAssign(article,value,ancestor);
}

template<typename T>
void RadixTrie<T>::erase(key_type article, Node *ancestor) {
    trie_.erase(article,ancestor);
}

template<typename T>
void RadixTrie<T>::swap(RadixTrie &rhs) noexcept {
    trie_.swap(rhs.trie_);
}

template<typename T>
typename RadixTrie<T>::iterator RadixTrie<T>::find(key_type article) {
    return iterator(trie_.find(article));
}

template<typename T>
std::pair<bool, typename RadixTrie<T>::iterator> RadixTrie<T>::scout(RadixTrie::key_type article, Node *ancestor) {
    return trie_.scout(article,ancestor);
}

template<typename T>
bool RadixTrie<T>::contains(RadixTrie::key_type article, Node *ancestor) {
    return trie_.contains(article,ancestor);
}

template<typename T>
bool RadixTrie<T>::operator==(const RadixTrie &rhs) const {
    return trie_ == rhs.trie_;
}

template<typename T>
bool RadixTrie<T>::operator!=(const RadixTrie &rhs) const {
    return !(*this == rhs);
}

template<typename T>
typename RadixTrie<T>::iterator RadixTrie<T>::begin() {
    return iterator(trie_.begin());
}

template<typename T>
typename RadixTrie<T>::iterator RadixTrie<T>::end() {
    return iterator(trie_.end());
}

#endif //RADIXTRIE_RADIXTRIE_CPP