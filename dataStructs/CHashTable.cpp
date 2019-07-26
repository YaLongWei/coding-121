//
// Created by mac on 2019-06-24.
//

#include "CHashTable.h"
#include <map>
#include <vector>

using namespace std;

template <class T>
int hashCode(T key)
{
    return key;
}


template <class K, class V>
CHashTable<K, V>::CHashTable():cacpcityTable({53,97,193,389,769,1543,3079,
                                              6151,12289,24593,49157,98317,
                                              196613,393241,786433,1572869,
                                              3145739,6291469,12582917,
                                              25165843,50331653,100663319,
                                              201326611,402653189,805306457,
                                              1610612741}),capacityIndex(0)
{
    this->M = cacpcityTable[capacityIndex];
    this->size = 0;
    m_hashTable = new std::vector<std::map<K, V>>;
    for(int i = 0; i < M; i++)
    {
        m_hashTable->push_back(std::map<K, V>());
    }
}

template <class K, class V>
CHashTable<K, V>::~CHashTable()
{
    if(nullptr != m_hashTable)
    {
        delete m_hashTable;
        m_hashTable = nullptr;
    }
}

template <class K, class V>
int CHashTable<K, V>::hash(K key)
{
    return (hashCode(key) & 0x7FFFFFFF)%M;
}

template <class K, class V>
int CHashTable<K, V>::getSize()
{
    return this->size;
}
#include <map>
using namespace std;
template <class K, class V>
void CHashTable<K, V>::add(K key, V value)
{
    auto m = m_hashTable[0][hash(key)];

    m[key] = value;
    if(m.find(key) == m.end()) {
        size++;

        if (size >= upperTol * M) {
            capacityIndex++;
            resize(cacpcityTable[capacityIndex]);
        }
    }
}

template <class K, class V>
V CHashTable<K, V>::remove(K key)
{
    auto m = m_hashTable[0][hash(key)];
    auto vit = m.find(key);
    if(vit == m.end())
        throw "not find";
    V ret = m.erase(key);
    size--;

    if(size < lowerTol * M &&  capacityIndex - 1 >= 0)
    {
        capacityIndex--;
        resize(cacpcityTable[capacityIndex]);
    }

    return ret;
}

template <class K, class V>
void CHashTable<K, V>::set(K key, V value)
{
    auto m = m_hashTable[0][hash(key)];
    if(m.find(key) != m.end())
        throw "doesn't exist!";
    m.insert();
}

template <class K, class V>
bool CHashTable<K, V>::contains(K key)
{
    return m_hashTable[0][hash(key)].find(key) != m_hashTable[0][hash(key)].end();
}

template <class K, class V>
V CHashTable<K, V>::get(K key)
{

    if(m_hashTable[0][hash(key)].find(key) == m_hashTable[0][hash(key)].end())
    {
        throw "not find";
    }
    return *(m_hashTable[0][hash(key)].find(key));
}

template <class K, class V>
void CHashTable<K, V>::resize(int newM)
{
    vector<map<K, V>> *newHashTable = new vector<map<K, V>>;
    for(int i = 0; i < newM; i++)
    {
        newHashTable->push_back(std::map<K, V>());
    }
    int oldM = M;
    this->M = newM;

    for(int i = 0; i < oldM; i++)
    {
        auto m = m_hashTable[0][i];
        for(auto &key: m)
        {
            newHashTable[0][hash(key.first)][key.first] = key.second;
        }

    }
    if(nullptr != this->m_hashTable)
    {
        delete this->m_hashTable;
    }

    this->m_hashTable = newHashTable;
}
