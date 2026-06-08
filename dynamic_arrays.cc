#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> std_vector_numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::size_t std_vector_numbers_size = std_vector_numbers.size();
    std::size_t std_vector_numbers_capacity = std_vector_numbers.capacity();
    
    std::cout << "Size: " << std_vector_numbers_size << std::endl;
    std::cout << "Capacity: " << std_vector_numbers_capacity << std::endl;


    return 0;
}