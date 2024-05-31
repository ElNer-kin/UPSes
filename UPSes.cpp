#include <iostream>
#include <vector>
#include "header.h" // Подключаем ваш заголовочный файл


using namespace std;


class UPSContainer {
public:
    virtual void addUPS(const UPS& ups) = 0;
    virtual void removeUPS(const UPS& ups) = 0;
    virtual bool containsUPS(const UPS& ups) const = 0;
    virtual void clear() = 0;
    virtual int size() const = 0;
    virtual const UPS& getUPS(int index) const = 0;
    virtual ~UPSContainer() {}
};

class VectorUPSContainer : public UPSContainer {
private:
    std::vector<UPS> upsVector;
public:
    void addUPS(const UPS& ups) override {
        upsVector.push_back(ups);
    }
    void removeUPS(const UPS& ups) override {  // Реализация удаления элемента
      
    }
    bool containsUPS(const UPS& ups) const override { // Реализация проверки наличия элемента
       
        return false;
    }
    void clear() override {
        upsVector.clear();
    }
    int size() const override {
        return upsVector.size();
    }
    const UPS& getUPS(int index) const override {
        return upsVector[index];
    }
};

class ArrayUPSContainer : public UPSContainer {
private:
    static const int MAX_SIZE = 100; 
    UPS upsArray[MAX_SIZE];
    int currentSize;
public:
    ArrayUPSContainer() : currentSize(0) {}
    void addUPS(const UPS& ups) override {
        if (currentSize < MAX_SIZE) {
            upsArray[currentSize++] = ups;
        }
        else {
           
        }
    }
    void removeUPS(const UPS& ups) override {  // Реализация удаления элемента
        
    }
    bool containsUPS(const UPS& ups) const override {  // Реализация проверки наличия элемента
       
        return false;
    }
    void clear() override {
        currentSize = 0;
    }
    int size() const override {
        return currentSize;
    }
    const UPS& getUPS(int index) const override {
        return upsArray[index];
    }
};