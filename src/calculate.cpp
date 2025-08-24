
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip> // For formatting output

// Function to calculate the total combinations given the character set size and password length
unsigned long long calculate_combinations(int charset_size, int length) {
    return static_cast<unsigned long long>(std::pow(charset_size, length));
}

// Function to calculate the time needed to brute force given the total combinations and hash rate
void calculate_crack_time(unsigned long long combinations, unsigned long long hashes_per_second) {
    if (hashes_per_second == 0) {
        std::cerr << "Hash rate cannot be zero. Exiting.\n";
        return;
    }

    unsigned long long total_seconds = combinations / hashes_per_second;

    // Breakdown the total time into days, hours, minutes, and seconds
    unsigned long long hours = total_seconds / 3600;
    if (hours == 0){
        // Output the result
        std::cout << "Time required to brute force: " << std::endl;
        std::cout  << "Less than hour" << "\n";
    }else{
        // Output the result
        std::cout << "Time required to brute force: " << std::endl;
        std::cout  << "Hours : " << hours << "\n";
    }

}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <password_length> <hashes_per_second>\n";
        return 1;
    }

    // Parse command line arguments
    int password_length = std::atoi(argv[1]);
    unsigned long long hashes_per_second = std::strtoull(argv[2], nullptr, 10);

    if (password_length <= 0) {
        std::cerr << "Password length must be greater than zero.\n";
        return 1;
    }

    // Character set size (A-Z, a-z, 0-9)
    const int CHARSET_SIZE = 96;

    // Calculate total combinations
    unsigned long long combinations = calculate_combinations(CHARSET_SIZE, password_length);

    std::cout << "Total combinations to try: " << combinations << std::endl;

    // Calculate and display crack time
    calculate_crack_time(combinations, hashes_per_second);

    return 0;
}
