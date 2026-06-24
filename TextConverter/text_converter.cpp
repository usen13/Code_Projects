#include <string>
#include <vector>
#include <iostream>
#include <cstdint>



// Convert integer to string
// std::string intToString(uint64_t value) {
//     std::string result;
//     while (value > 0) {
//         char c = static_cast<char>(value % 256);
//         result.insert(result.begin(), c); // Insert at the beginning
//         value /= 256;
//     }
//     return result;
// }

// // Function to convert string to integer (simple example using ASCII values)
// uint64_t stringToInt(const std::string& str) {
//     uint64_t result = 0;
//     for (char c : str) {
//         result = result * 256 + static_cast<int>(c);
//     }
//     return result;
// }
std::vector<uint64_t> stringToIntChunks(const std::string& str) {
    std::vector<uint64_t> chunks;
    for (size_t i = 0; i < str.size(); i += 8) {
        uint64_t chunk = 0;
        for (size_t j = 0; j < 8 && (i + j) < str.size(); ++j) {
            chunk = (chunk << 8) | static_cast<unsigned char>(str[i + j]);
        }
        chunks.push_back(chunk);
    }
    return chunks;
}

std::string intChunksToString(const std::vector<uint64_t>& chunks) {
    std::string result;
    for (uint64_t chunk : chunks) {
        for (int i = 7; i >= 0; --i) { // Extract 8 bytes per chunk
            char c = (chunk >> (i * 8)) & 0xFF;
            if (c != 0) { // Skip padding bytes
                result.push_back(c);
            }
        }
    }
    return result;
}

int main () {
    std::string str = "Hello World what can I do for you ?";
    std::cout << "Original string: " << str << std::endl;
    auto chunks = stringToIntChunks(str);
    std::cout << "Converted to chunks" << std::endl;
    for (uint64_t chunk: chunks) {
        std::cout << chunk << "";
    }
    std::cout << std::endl;
    std::string converted = intChunksToString(chunks);
    //std::cout << "Converted integer: " << converted << std::endl;
    std::cout << "Converted integer to string: " << converted << std::endl;
    return 0;
}