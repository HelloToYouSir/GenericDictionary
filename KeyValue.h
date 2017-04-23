//
// Created by David on 4/2/2017.
//

#ifndef GENERICDICTIONARY_KEYVALUE_H
#define GENERICDICTIONARY_KEYVALUE_H

template <class KeyType, class ValueType> class KeyValue {

private:
    KeyType key;
    ValueType value;

public:
    KeyValue<KeyType, ValueType>(KeyType key, ValueType value) : key(key), value(value){
    }

    KeyType getKey()const {
        return key;
    }

    ValueType getValue() const {
        return value;
    }
};

#endif //GENERICDICTIONARY_KEYVALUE_H
