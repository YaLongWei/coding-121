//
// Created by mac on 2019-06-24.
//

#ifndef UNTITLED1_CHASHTABLE_H
#define UNTITLED1_CHASHTABLE_H
#include <map>
#include <vector>

template <class K, class V>
class CHashTable {
public:
    CHashTable();

    ~CHashTable();

    int getSize();
    void add(K key, V value);
    V remove(K key);
    void set(K key, V value);
    bool contains(K key);
    V get(K key);
private:
    int hash(K key);
    void resize(int newM);
private:
    static const int upperTol;
    static const int lowerTol;
    int capacityIndex;
    const std::vector<int> cacpcityTable;
private:

    std::vector<std::map<K, V>> *m_hashTable;
    int M;
    int size;
};

template <class K, class V>
const int CHashTable<K, V>::upperTol = 10;

template <class K, class V>
const int CHashTable<K, V>::lowerTol = 2;


#endif //UNTITLED1_CHASHTABLE_H
