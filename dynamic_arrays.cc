#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>

class DynamicArray
{
    private:
        T* memory;
        std::size_t size;
        std::size_t capacity;

    public:
        DynamicArray(std::size_t initial_capacity = 2) {
            this->capacity = initial_capacity;
            this->size = 0;
            this->memory = new T[this->capacity];
        };
        
        ~DynamicArray() {
            delete[] this->memory;
        };

    private:
        void resize() {
            this->capacity = (this->capacity == 0) ? 1 : this->capacity * 2;
            
            T* new_memory = new T[this->capacity];

            for (int i = 0; i < this->size; i++) {
                new_memory[i] = this->memory[i];
            }

            delete[] this->memory;

            this->memory = new_memory;
        }

    public:
        T get(int index) {
            if (index < 0 || index >= this->size) {
                throw std::out_of_range("Índice fora dos limites do array");
            }
            return this->memory[index];
        }

        void push(T value) {
            if (this->size == this->capacity) {
                this->resize();
            }

            this->memory[this->size] = value;
            this->size++;
        }

        T pop() {
            if (this->size == 0) {
                throw std::out_of_range("Não é possível remover de um array vazio");
            }
            
            this->size--;
            T value = this->memory[this->size];

            return value;
        }

        int get_size() {
            return this->size;
        }

        int get_capacity() {
            return this->capacity;
        }


};

int main()
{
    std::cout << "\n*** Instantianting the DynamicArray... ***\n" << std::endl;

    DynamicArray<int>* numbers = new DynamicArray<int>();

    std::cout << "> Inital Capacity: " << numbers->get_capacity() << std::endl;
    std::cout << "> Inital Size: " << numbers->get_size() << std::endl;

    numbers->push(25);

    std::cout << "\n*** Adding value... ***\n" << std::endl;
    std::cout << "> Capacity: " << numbers->get_capacity() << std::endl;
    std::cout << "> Size: " << numbers->get_size() << std::endl;

    numbers->push(25);
    std::cout << "\n*** Adding value... ***\n" << std::endl;
    std::cout << "> Capacity: " << numbers->get_capacity() << std::endl;
    std::cout << "> Size: " << numbers->get_size() << std::endl;

    numbers->push(25);
    std::cout << "\n*** Adding value... ***\n" << std::endl;

    std::cout << "> Capacity: " << numbers->get_capacity() << std::endl;
    std::cout << "> Size: " << numbers->get_size() << std::endl;


    delete numbers;

    return 0;
}