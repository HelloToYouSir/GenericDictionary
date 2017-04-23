#include <iostream>
#include "Dictionary.h"

int main() {
    std::cout << std::endl << "BASIC CONSTRUCTOR DEMONSTRATION <std::string, std::string> " << std::endl;

    Dictionary<std::string, std::string> b;

    for (int i = 0 ; i < 13 ; i++){
        b.add("<KEY" + std::to_string(i) + ">","<VALUE" + std::to_string(i) +">");
    }

    std::cout << "looking up entry by valid key: <KEY3> " << b.getByKey("<KEY3>").getValue() << std::endl << std::endl;

    try {
        std::string invalidKey = "<ff>";
        std::cout << "looking up entry by invalid key: " << invalidKey << std::endl;
        b.getByKey(invalidKey);
    } catch (std::exception& e) {
        std::cout << "Exception thrown! That means I correctly did not find the invalid key." << std::endl<< std::endl;
    }

    try {
    std::string validKey = "<KEY9>";
    std::cout << "Adding same key again. Key is " << validKey << " which currently has a value of " << b.getByKey(validKey).getValue() << std::endl;
    b.add(validKey, "<NEW_VALUE9>");
    std::cout << "The new value for " << validKey << " is:" << b.getByKey(validKey).getValue() << std::endl<< std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception thrown! That means I correctly threw exception on repeat key.." << std::endl<< std::endl;
    }

    std::cout << "I will now get by index 8: " << b.getByIndex(8).getValue() << std::endl;
    std::cout << "Notice that index 9 returns the value for what was once the last entry in the list: " << b.getByIndex(9).getValue() << std::endl;
    std::cout << "  That's because some speed optimization during add duplicate." << std::endl << std::endl;

    std::cout << "I will now remove the object at index 0 by using remove by index." << std::endl;
    std::cout << "The item at index 0 is currently- key:" << b.getByIndex(0).getKey() << " value: " << b.getByIndex(0).getValue() << std::endl;
    std::cout << "And there are currently " << b.getCount() << " entries." << std::endl;
    b.removeByIndex(0);
    std::cout << "Removal complete. There are now only " << b.getCount() << " entries and" << std::endl;
    std::cout << "the entry at index 0 is now - key:" << b.getByIndex(0).getKey() << " value: " << b.getByIndex(0).getValue() << std::endl<< std::endl;

    std::cout << "Now I need to show you a removal by key, let's remove the one we just showed at index 0 by using its key." << std::endl;
    b.removeByKey(b.getByIndex(0).getKey());
    std::cout << "Done. There are now " << b.getCount() << " entries and index zero now has a value of: " << b.getByIndex(0).getValue() << std::endl << std::endl;

    std::cout << "And last with this dictionary, I will show you my [] overload making this dictionary usable like an array." << std::endl;
    std::cout << "Since we like index 0 so much, let's use it. The key is:" << b[0].getKey() << " and value:" << b[0].getValue() << std::endl<< std::endl;

    std::cout << std::endl << "INITIAL SIZE CONSTRUCTOR DEMONSTRATION <std::string, int> " << std::endl;
    std::cout << "And now to create a new dictionary with an initial container size." << std::endl;
    Dictionary<std::string, int> n(100);
    std::cout << "Done. This one was easy." << std::endl << std::endl;

    std::cout << "Let's show you how I now associate a string key with an int value..." << std::endl;
    n.add("One", 1);
    n.add("Three", 3);
    std::cout << "The sum of the values for keys \"One\" and \"Two\" is:" << (n.getByKey("One").getValue() + n.getByKey("Three").getValue() ) << std::endl << std::endl;

    std::cout << std::endl << "COPY CONSTRUCTOR DEMONSTRATION <std::string, std::string> " << std::endl;
    std::cout << "Last I will copy the first dictionary into another" << std::endl;
    Dictionary<std::string, std::string> copy(b);
    std::cout << "Done." << std::endl << "To prove I did it right I will show the values of the <KEY11> entries..." << std::endl;
    std::cout << "  original dictionary[5] value: " << b.getByKey("<KEY11>").getValue() << std::endl;
    std::cout << "  copy dictionary[5] value: " << copy.getByKey("<KEY11>").getValue() << std::endl;


    std::cout << "Removing entry of valid key to show removal on only the copied Dictionary." << std::endl;
    copy.removeByKey("<KEY11>");
    std::cout << "Done. Now a reprint to show you that only the copy's KeyValue was removed..." << std::endl;

    try{
        std::cout << "  original dictionary[5] value: " << b.getByKey("<KEY11>").getValue() << std::endl;
    } catch (std::exception& e) {

    }

    try{
        std::cout << "  copy dictionary[5] value: " << copy.getByKey("<KEY11>").getValue() << std::endl << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception thrown! That means this copied Dictionary had the KeyValue removed." << std::endl<< std::endl;
    }

    std::cout << "Now to show you I can get a KeyValue and assign it to a const.." << std::endl;
    const KeyValue<std::string, std::string>& kv = b[3];
    std::cout << "Done. The key is " << kv.getKey() << " and the value " << kv.getValue() << std::endl<< std::endl;

    std::cout << "And that's the end of my demonstration. Have a wonderful day! Ps, the cake is a lie. ;-)" << std::endl;

    return 0;
}