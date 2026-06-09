#include <cstddef>
#include <iostream>
#include <stdexcept>

/**
 * @brief A dynamic array implementation that automatically resizes itself.
 * 
 * @tparam T The type of elements stored in the array.
 */
template <typename T>
class DynamicArray
{
    private:
        T* memory;              ///< Pointer to the dynamically allocated contiguous memory block.
        std::size_t size;       ///< Current number of elements in the array.
        std::size_t capacity;   ///< Total allocated capacity in the memory block.

        /**
         * @brief Doubles the current capacity of the array.
         * 
         * Allocates a new memory block with double the capacity,
         * copies existing elements, and safely deallocates the old block
         * to prevent memory leaks.
         */
        void resize() {
            this->capacity = (this->capacity == 0) ? 1 : this->capacity * 2;
            
            T* new_memory = new T[this->capacity];

            for (std::size_t i = 0; i < this->size; i++) {
                new_memory[i] = this->memory[i];
            }

            delete[] this->memory;
            this->memory = new_memory;
        }

    public:
        /**
         * @brief Constructs a new Dynamic Array object.
         * 
         * @param initial_capacity The starting capacity of the array. Defaults to 2.
         */
        DynamicArray(std::size_t initial_capacity = 2) {
            this->capacity = initial_capacity;
            this->size = 0;
            this->memory = new T[this->capacity];
        }
        
        /**
         * @brief Destroys the Dynamic Array object and deallocates memory.
         */
        ~DynamicArray() {
            delete[] this->memory;
        }

        /**
         * @brief Retrieves the element at the specified index.
         * 
         * @param index The zero-based index of the element to retrieve.
         * @return T The element at the specified index.
         * @throws std::out_of_range If the index is less than 0 or greater than/equal to size.
         */
        T get(int index) {
            if (index < 0 || static_cast<std::size_t>(index) >= this->size) {
                throw std::out_of_range("Index out of bounds");
            }
            return this->memory[index];
        }

        /**
         * @brief Appends a new element to the end of the array.
         * 
         * If the array has reached its maximum capacity, it will automatically
         * trigger a resize operation before inserting the element.
         * 
         * @param value The value to append.
         */
        void push(T value) {
            if (this->size == this->capacity) {
                this->resize();
            }

            this->memory[this->size] = value;
            this->size++;
        }

        /**
         * @brief Removes and returns the last element of the array.
         * 
         * @return T The removed element.
         * @throws std::out_of_range If the array is empty.
         */
        T pop() {
            if (this->size == 0) {
                throw std::out_of_range("Cannot pop from an empty array");
            }
            
            this->size--;
            T value = this->memory[this->size];

            return value;
        }

        /**
         * @brief Gets the current number of elements in the array.
         * 
         * @return int The current size.
         */
        int get_size() {
            return static_cast<int>(this->size);
        }

        /**
         * @brief Gets the total allocated capacity of the array.
         * 
         * @return int The current capacity.
         */
        int get_capacity() {
            return static_cast<int>(this->capacity);
        }
};

int main()
{
    std::cout << "\n*** Instantiating the DynamicArray... ***\n" << std::endl;

    // Allocate dynamic array on the heap.
    DynamicArray<int>* numbers = new DynamicArray<int>();

    std::cout << "> Initial Capacity: " << numbers->get_capacity() << std::endl;
    std::cout << "> Initial Size: " << numbers->get_size() << std::endl;

    // Insert first element; no reallocation required.
    numbers->push(10);
    std::cout << "\n*** Adding the 1st value (10)... ***\n" << std::endl;
    std::cout << "> Capacity: " << numbers->get_capacity() << std::endl;
    std::cout << "> Size: " << numbers->get_size() << std::endl;

    // Insert second element; array reaches its initial capacity.
    numbers->push(20);
    std::cout << "\n*** Adding the 2nd value (20)... ***\n" << std::endl;
    std::cout << "> Capacity: " << numbers->get_capacity() << std::endl;
    std::cout << "> Size: " << numbers->get_size() << std::endl;

    // Insert third element; triggers resize() to accommodate new data.
    numbers->push(30);
    std::cout << "\n*** Adding the 3rd value (30) - Will trigger Resize! ***\n" << std::endl;
    std::cout << "> New Capacity: " << numbers->get_capacity() << std::endl;
    std::cout << "> New Size: " << numbers->get_size() << std::endl;
    std::cout << std::endl;

    // Retrieve and output element safely.
    int item_0 = numbers->get(0);
    std::cout << "Item at Index 0: " << item_0 << std::endl;

    // Pop elements (LIFO sequence).
    std::cout << "\n*** Removing items with pop()... ***\n" << std::endl;
    std::cout << "Removed: " << numbers->pop() << std::endl;
    std::cout << "Removed: " << numbers->pop() << std::endl;
    std::cout << "Removed: " << numbers->pop() << std::endl;

    // Free allocated memory to prevent leaks.
    delete numbers;

    return 0;
}