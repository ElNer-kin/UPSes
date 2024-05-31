#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib> // для использования rand()
#include <ctime> // для инициализации генератора случайных чисел
#include <SQLiteCpp/SQLiteCpp.h> // для работы с SQL
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
     vector<UPS> upsVector;
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
}
class VectorUPSIterator : public  iterator< input_iterator_tag, UPS> {
    private:
         vector<UPS>& upsVector;
        size_t currentIndex;
    public:
        VectorUPSIterator( vector<UPS>& upsVector, size_t index) : upsVector(upsVector), currentIndex(index) {}

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

class ArrayUPSIterator : public  iterator< input_iterator_tag, UPS> {
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

class UPSFactory {
public:
    static UPS* createUPS(const  string& type, ColorUPS color) {
        if (type == "Line_interactive") {
            Line_interactive* ups = new Line_interactive();
            ups->Color = color;
            return ups;
        }
        else if (type == "Standby") {
            Standby* ups = new Standby();
            ups->Color = color;
            return ups;
        }
        else if (type == "Online") {
            Online* ups = new Online();
            ups->Color = color;
            return ups;
        }
        else {
            return nullptr;
        }
    }
};

template<typename Container>
void fillContainerRandomly(Container& container, size_t maxSize) {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));
    size_t numObjects = rand() % maxSize; // генерируем случайное количество объектов

    for (size_t i = 0; i < numObjects; ++i) {
        string types[] = { "Line_interactive", "Standby", "Online" };
        int index = rand() % 3;
        string type = types[index];
        ColorUPS colors[] = { ColorUPS::Black, ColorUPS::Grey, ColorUPS::White };
        index = rand() % 3;
        ColorUPS color = colors[index];
        UPS* ups = UPSFactory::createUPS(type, color);
        if (ups) {
            container.addUPS(*ups);
            delete ups;
        }
        else {
             cerr << "Error: Unknown UPS type.\n";
        }
    }
}

class SQLiteUPSContainer {
private:
    SQLite::Database database;
public:
    SQLiteUPSContainer(const  string& dbFileName) : database(dbFileName) {}

    void addUPS(const UPS& ups) {
        SQLite::Statement query(database, "INSERT INTO UPS (name, model, color, output_power, number_of_batteries, is_working) VALUES (?, ?, ?, ?, ?, ?)");
        query.bind(1, ups.name);
        query.bind(2, ups.model);
        query.bind(3, static_cast<int>(ups.look_at()));
        query.bind(4, ups.output_power);
        query.bind(5, ups.number_of_batteries);
        query.bind(6, static_cast<int>(ups.is_working));
        query.exec();
    }

     vector<UPS> getUPSs() {
         vector<UPS> upsList;
        SQLite::Statement query(database, "SELECT * FROM UPS");
        while (query.executeStep()) {
            UPS ups;
            ups.name = query.getColumn(0).getString();
            ups.model = query.getColumn(1).getString();
            ups.Color = static_cast<ColorUPS>(query.getColumn(2).getInt());
            ups.output_power = query.getColumn(3).getInt();
            ups.number_of_batteries = query.getColumn(4).getInt();
            ups.is_working = static_cast<Working>(query.getColumn(5).getInt());
            upsList.push_back(ups);
        }
        return upsList;
    }
}
int main() {
    // Создание контейнера
    VectorUPSContainer upsContainer;

    // Наполнение контейнера случайными объектами
    fillContainerRandomly(upsContainer, 10);

    // Использование декоратора фильтра итератора для выбора объектов UPS черного цвета
    auto isBlack = [](const UPS& ups) { return ups.look_at() == ColorUPS::Black; };
    using FilteredUPSIterator = FilterIterator<VectorUPSIterator, decltype(isBlack)>;
    FilteredUPSIterator fitEnd = FilteredUPSIterator(upsContainer.end(), isBlack);
     cout << "UPS with black color:\n";
    for (FilteredUPSIterator fit = FilteredUPSIterator(upsContainer.begin(), isBlack); fit != fitEnd; ++fit) {
        const UPS& ups = *fit;
         cout << "Model: " << ups.model << ", Color: ";
        switch (ups.look_at()) {
        case ColorUPS::Black:
             cout << "Black";
            break;
        case ColorUPS::Grey:
             cout << "Grey";
            break;
        case ColorUPS::White:
             cout << "White";
            break;
        }
        cout <<  endl;
    }

    return 0;
}
