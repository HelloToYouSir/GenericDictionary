//
// Created by David on 4/2/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include "KeyValue.h"
#include <iostream>

template <class KeyType, class ValueType> class Dictionary : std::exception {

private:
    KeyValue<KeyType, ValueType> **entries;
    int containerSize;
    int nextEntryIndex = 0;

public:

    Dictionary() {
        initEntries(10);
    }

    Dictionary(const Dictionary &obj) {
        initEntries(obj.containerSize);
        for (int i = 0; i < containerSize; i++) {
            if (obj.entries[i] != nullptr)
                entries[i] = new KeyValue<KeyType, ValueType>(obj.entries[i]->getKey(), obj.entries[i]->getValue());
            else
                entries[i] = nullptr;
        }
        nextEntryIndex = obj.nextEntryIndex;
    }

    Dictionary(int initialSize) {
        initEntries(initialSize);
    }

    void initEntries(int size) {
        entries = new KeyValue<KeyType, ValueType> *[size];
        containerSize = size;
        for (int i = 0; i < size; i++) {
            entries[i] = nullptr;
        }
    }

    void destroyEntries() {
        for (int i = 0; i < containerSize; i++) {
            delete (entries[i]);
        }
    }

    ~Dictionary() {
        destroyEntries();
        delete entries;
    }

    void add(KeyType key, ValueType value) {
        bool keyExists = false;
        for (int i = 0; i < nextEntryIndex; i++) {
            if (entries[i] == nullptr)
                break;
            if (entries[i]->getKey() == key) {
                keyExists = true;
                break;
            }
        }
        if (keyExists)
            throw exception();

        if (nextEntryIndex > containerSize-1)
            growContainer();

        entries[nextEntryIndex++] = new KeyValue<KeyType, ValueType>(key, value);
    }

    void growContainer() {
        KeyValue<KeyType, ValueType>** newEntries;
        newEntries = new KeyValue<KeyType, ValueType>*[containerSize*2];

        for (int i = 0 ; i < containerSize*2; i++){
            if (i < containerSize)
                newEntries[i] = entries[i];
            else
                newEntries[i] = nullptr;
        }
        delete[] entries;
        entries = newEntries;
        containerSize = containerSize*2;
    }

    int getCount() {
        return nextEntryIndex;
    }

    KeyValue<KeyType,ValueType> getByKey(KeyType key){

            for (int i = 0; i < nextEntryIndex; i++) {
                if (entries[i] != nullptr && entries[i]->getKey() == key)
                    return *entries[i];
            }

        throw exception();
    };

    KeyValue<KeyType,ValueType> getByIndex(int index){
        if (index < 0 || index > nextEntryIndex-1){
            throw exception();
        }
        return *entries[index];
    };

    KeyValue<KeyType, ValueType> operator[] (int x){
        return getByIndex(x);
    }

    void removeByKey(KeyType key){

        for (int i = 0; i < nextEntryIndex; i++) {
            if (entries[i] == nullptr)
                break;
            if (entries[i]->getKey() == key) {
                removeByIndex(i);
                return;
            }
        }
        throw exception();
    }

    void removeByIndex(int index) {
        if (index < 0 || index > nextEntryIndex -1)
            throw exception();
        delete entries[index];
        entries[index] = entries[nextEntryIndex-1];
        nextEntryIndex--;
        entries[nextEntryIndex] = nullptr;
    }
};

#endif //GENERICDICTIONARY_DICTIONARY_H
