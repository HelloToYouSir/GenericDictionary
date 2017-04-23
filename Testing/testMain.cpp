
#include <iostream>
#include "../Dictionary.h"


int main() {

    std::cout << "Execute Test Cases" << std::endl;

    std::cout << "Test Dictionary<std::string, std::string>" << std::endl;

    Dictionary<std::string, std::string> d;
    //Basic functionality, No exceptions
    {
        std::cout << "Create Dictionary<std::string, std::string> by default constructor." << std::endl;
        if (d.getCount() != 0)
            std::cout << "  --Failure, dictionary was created with some element." << std::endl;

        std::cout << "Add valid key to dictionary." << std::endl;
        d.add("Test Key 1", "Test Value 1");
        if (d.getCount() != 1)
            std::cout << "  --Failure, add action did not increase dictionary entry count." << std::endl;
        if (d.getByIndex(0).getValue() != "Test Value 1")
            std::cout << "  --Failure, incorrect value found when get by index." << std::endl;
        if (d.getByKey("Test Key 1").getValue() != "Test Value 1")
            std::cout << "  --Failure, incorrect value found when get by key." << std::endl;

        std::cout << "Add 99 more elements to dictionary, force grow." << std::endl;
        for (int i = 1; i < 100; i++) {
            std::string k = "bunch-" + std::to_string(i);
            std::string v = "buch-value-" + std::to_string(i);
            d.add(k, v);
        }
        if (d.getCount() != 100)
            std::cout << "  --Failure, incorrect count of elements found." << std::endl;

        std::cout << "Remove an element from dictionary by index." << std::endl;;
        std::string oldValue = d.getByIndex(5).getValue();
        d.removeByIndex(5);
        if (d.getByIndex(5).getValue() == oldValue)
            std::cout << "  --Failure, value which was removed still found in Dictionary." << std::endl;
    }

    //Test Exception functionality
    {
        std::cout << "Get negative index." << std::endl;
        try{
            d.removeByIndex(-1);
            std::cout << "  --Failure, exception not thrown with negative index." << std::endl;
        } catch (std::exception& e) {
        }

        std::cout << "Get too large of index." << std::endl;
        try{
            d.removeByIndex(99999);
            std::cout << "  --Failure, exception not thrown with too large of index." << std::endl;
        } catch (std::exception& e) {
        }

        std::cout << "Get too large of index." << std::endl;
        try{
            d.removeByIndex(99999);
            std::cout << "  --Failure, exception not thrown with too large of index." << std::endl;
        } catch (std::exception& e) {
        }

        std::cout << "Remove invalid key." << std::endl;
        std::string oldKey = d.getByIndex(5).getKey();
        d.removeByKey(oldKey);
        try{
            d.removeByKey(oldKey);
            std::cout << "  --Failure, exception not thrown when removing a missing key." << std::endl;
        } catch (std::exception& e) {
        }

        std::cout << "Add key twice." << std::endl;
        std::string key = "New Key";
        d.add(key, "some value");
        try{
            d.add(key, "some other value");
            std::cout << "  --Failure, exception not thrown when adding key twice." << std::endl;
        } catch (std::exception& e) {
        }

    }


    std::cout << "Test Dictionary<std::string, int>" << std::endl;
    //Test int typed get value
    {

        std::cout << "Add int values." << std::endl;
        Dictionary<std::string, int> i;
        i.add("five",5);
        i.add("twenty",20);
        i.add("eleven",11);
        i.add("one",1);
        i.add("ten",10);
        if(i.getCount()!= 5)
            std::cout << "  --Failure, wrong count of entries." << std::endl;

        std::cout << "Check int values." << std::endl;
        if (i.getByKey("five").getValue() != 5)
            std::cout << "  --Failure, wrong value for key 'five'." << std::endl;
        if (i.getByKey("twenty").getValue() != 20)
            std::cout << "  --Failure, wrong value for key 'twenty'." << std::endl;
        if (i.getByKey("eleven").getValue() != 11)
            std::cout << "  --Failure, wrong value for key 'eleven'." << std::endl;
        if (i.getByKey("one").getValue() != 1)
            std::cout << "  --Failure, wrong value for key 'one'." << std::endl;
        if (i.getByKey("ten").getValue() != 10)
            std::cout << "  --Failure, wrong value for key 'ten'." << std::endl;
    }

    std::cout << "Testing complete, I have shown many valid test cases, including exceptions." << std::endl;
    std::cout << "I have also shown different typings of dictionaries." << std::endl;

    return 0;
}