#include <iostream>
#include <vector>
#include <iterator>
#include "header.h" // Подключаем наш заголовочный файл


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

    class VectorUPSIterator : public std::iterator<std::input_iterator_tag, UPS> {
    private:
        std::vector<UPS>& upsVector;
        size_t currentIndex;
    public:
        VectorUPSIterator(std::vector<UPS>& upsVector, size_t index) : upsVector(upsVector), currentIndex(index) {}

        VectorUPSIterator& operator++() {
            ++currentIndex;
            return *this;
        }

        VectorUPSIterator operator++(int) {
            VectorUPSIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const VectorUPSIterator& other) const {
            return currentIndex == other.currentIndex;
        }

        bool operator!=(const VectorUPSIterator& other) const {
            return !(*this == other);
        }

        const UPS& operator*() const {
            return upsVector[currentIndex];
        }
    };

    class ArrayUPSIterator : public std::iterator<std::input_iterator_tag, UPS> {
    private:
        const UPS* upsArray;
        size_t currentIndex;
    public:
        ArrayUPSIterator(const UPS* array, size_t index) : upsArray(array), currentIndex(index) {}

        ArrayUPSIterator& operator++() {
            ++currentIndex;
            return *this;
        }

        ArrayUPSIterator operator++(int) {
            ArrayUPSIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const ArrayUPSIterator& other) const {
            return currentIndex == other.currentIndex;
        }

       
        template<typename Iterator>
        class ReverseIterator {
        private:
            Iterator iterator;
        public:
            ReverseIterator(const Iterator& iter) : iterator(iter) {}

            ReverseIterator& operator++() {
                --iterator;
                return *this;
            }

            ReverseIterator operator++(int) {
                ReverseIterator tmp = *this;
                --iterator;
                return tmp;
            }

            bool operator==(const ReverseIterator& other) const {
                return iterator == other.iterator;
            }

            bool operator!=(const ReverseIterator& other) const {
                return !(*this == other);
            }

            auto& operator*() const {
                return *iterator;
            }
        };

        
        template<typename Iterator, typename Predicate>
        class FilterIterator {
        private:
            Iterator iterator;
            Predicate predicate;
        public:
            FilterIterator(const Iterator& iter, Predicate pred) : iterator(iter), predicate(pred) {
                while (iterator != Iterator() && !predicate(*iterator)) {
                    ++iterator;
                }
            }

            FilterIterator& operator++() {
                do {
                    ++iterator;
                } while (iterator != Iterator() && !predicate(*iterator));
                return *this;
            }

            FilterIterator operator++(int) {
                FilterIterator tmp = *this;
                ++(*this);
                return tmp;
            }

            bool operator==(const FilterIterator& other) const {
                return iterator == other.iterator;
            }

            bool operator!=(const FilterIterator& other) const {
                return !(*this == other);
            }

            auto& operator*() const {
                return *iterator;
            }
        };

       
        template<typename Iterator>
        class LimitedIterator {
        private:
            Iterator iterator;
            size_t count;
            size_t currentIndex;
        public:
            LimitedIterator(const Iterator& iter, size_t limit) : iterator(iter), count(limit), currentIndex(0) {}

            LimitedIterator& operator++() {
                ++iterator;
                ++currentIndex;
                return *this;
            }

            LimitedIterator operator++(int) {
                LimitedIterator tmp = *this;
                ++(*this);
                return tmp;
            }

            bool operator==(const LimitedIterator& other) const {
                return currentIndex == other.currentIndex;
            }

            bool operator!=(const LimitedIterator& other) const {
                return !(*this == other);
            }

            auto& operator*() const {
                return *iterator;
            }
        };
};
