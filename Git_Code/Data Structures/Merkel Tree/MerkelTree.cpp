#include<iostreaM>
#include<vector>
#include<string>
#include<openssl/sha.h>
#include<sstream>
#include<iomanip>

using namespace std;

// Declare the MerkelTree class before main
class MerkelTree;

// Define the SHA256 function
string SHA256(const string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// Function to construct the Merkel tree and return the Merkel root
std::string buildMerkelTree (vector <std::string>& data) {
    if (data.empty())  return "";
    
    if (data.size() == 1) {
        return SHA256(data[0]);
    }

    // If the number ofdata elements is odd, duplicate the last element
    if (data.size() % 2 != 0) {
        data.push_back(data.back());
    }

    
    vector <std::string> temp;
    for (int i = 0; i < data.size(); i += 2) {
        if (i + 1 < data.size()) {
            temp.push_back(SHA256(data[i] + data[i + 1]));
        } else {
            temp.push_back(SHA256(data[i] + data[i]));
        }
    }
    return buildMerkelTree(temp);
}