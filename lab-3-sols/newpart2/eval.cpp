#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

// Encryption key
const char EncryptionKey = 0x01;

// Encrypt a string using a simple substitution cipher
std::string encrypt(const std::string& plaintext) {
    std::string encrypted;
    
    for (char c : plaintext) {
        if (int(c)!=32)
        encrypted += c - EncryptionKey;
        else
        encrypted += c;
    }
    
    return encrypted;
}

// Decrypt an encrypted string
std::string decrypt(const std::string& encrypted) {
    std::string decrypted;
    
    for (char c : encrypted) {
        if (int(c)!=32)
        decrypted += c + EncryptionKey;
        else
        decrypted += c;
    }
    
    return decrypted;
}

size_t insecureHashOne(const std::string& input) {
    size_t hash = 0;
    for (char c : input) {
        hash = (hash * 256) + c;
    }
    return hash;
}

size_t insecureHashTwo(const std::string& input) {
    size_t hash = 0;
    for (char c : input) {
        hash += c;
    }
    return hash;
}

size_t insecureHashThree(const std::string& input) {
    unsigned long hash = 5381; // Initial value

    for (char c : input) {
        hash = ((hash << 5) + hash) + c; // DJB2 algorithm
    }

    return hash;
}

size_t insecureHashFour(const std::string& input) {
    unsigned long hash = 5381; // Initial value

    for (char c : input) {
        hash = ((hash << 4) + hash) + c; // DJB2 algorithm
    }

    return hash % 10000;
}

size_t insecureHashFive(const std::string& input) {
    unsigned long hash = 5381; // Initial value

    for (char c : input) {
        hash = (hash * c) + c;
    }
    return hash;
}

size_t insecureHashSix(const std::string& input) {
    unsigned long long int hash = 0; // Initial value
    int i = 0;
    std::string count = "";

    for (char c : input) {
        i += 1;
        count = count + to_string(int(c));
        if (i>2)
        break;
    }
    try{
        hash = stoi(count);
    }
    catch(std::exception& e)
    {
        return 0;
    }
    return hash;
}

int main(int argc, char* argv[]) {
  if( argc < 3 ||
      ( argv[1][0] != '6' && argv[1][0] != '1' && argv[1][0] != '2' &&
        argv[1][0] != '3' && argv[1][0] != '4' && argv[1][0] != '5' ) ) {
    cout<<"Choose insecure hash and the text to hash \n"
      " $exec [1-6] [password]" << endl;
    return 1;
  }
  int choice = std::atoi(argv[1]);
    std::string message;
    // std::cout<<"Enter password"<<endl;
    // std::getline(std::cin, pass);
    std::string pass(argv[2]);
    
    switch (choice)
    {
    case 1:
        /* code */
        message = "Mdudq fnmm` fhud xnt to";
        if (insecureHashOne(pass) == PASSWORD_HASH_ONE)
        {
            std::cout<<"Correct Password!\nSecret Message: "<<decrypt(message)<<std::endl;
        }
        else
        {
            std::cout<<"Entered Password hash value: "<<insecureHashOne(pass)<<std::endl;
            std::cout<<"Correct Password hash value: 7286957716698854768"<<std::endl;
            std::cout<<"Incorrect Password. Try again."<<std::endl;
        }
        break;

    case 2:
        /* code */
        message = "Vhmsdq hr Bnlhmf";
        if (insecureHashTwo(pass) == PASSWORD_HASH_TWO)
        {
            std::cout<<"Correct Password!\nSecret Message: "<<decrypt(message)<<std::endl;
        }
        else
        {
            std::cout<<"Entered Password hash value: "<<insecureHashTwo(pass)<<std::endl;
            std::cout<<"Correct Password hash value: 1522"<<std::endl;
            std::cout<<"Incorrect Password. Try again"<<std::endl;
        }
        break;

    case 3:
        /* code */
        message = "Sgdqd hr nmd v`x nts";
        if (insecureHashThree(pass) == PASSWORD_HASH_THREE)
        {
            std::cout<<"Correct Password!\nSecret Message: "<<decrypt(message)<<std::endl;
        }
        else
        {
            std::cout<<"Entered Password hash value: "<<insecureHashThree(pass)<<std::endl;
            std::cout<<"Correct Password hash value: 4203767532912581189"<<std::endl;
            std::cout<<"Incorrect Password. Try again"<<std::endl;
        }
        break;

    case 4:
        /* code */
        message = "L`x sgd Enqbd ad vhsg xnt";
        if (insecureHashFour(pass) == PASSWORD_HASH_FOUR)
        {
            std::cout<<"Correct Password!\nSecret Message: "<<decrypt(message)<<std::endl;
        }
        else
        {
            std::cout<<"Entered Password hash value: "<<insecureHashFour(pass)<<std::endl;
            std::cout<<"Correct Password hash value: 2956"<<std::endl;
            std::cout<<"Incorrect Password. Try again"<<std::endl;
        }
        break;

    case 5:
        /* code */
        message = "Lx rnkchdqr+ s`s`j`d";
        if (insecureHashFive(pass) == PASSWORD_HASH_FIVE)
        {
            std::cout<<"Correct Password!\nSecret Message: "<<decrypt(message)<<std::endl;
        }
        else
        {
            std::cout<<"Entered Password hash value: "<<insecureHashFive(pass)<<std::endl;
            std::cout<<"Correct Password hash value: 714300129759786736"<<std::endl;
            std::cout<<"Incorrect Password. Try again"<<std::endl;
        }
        break;

    case 6:
        message = "Sqd`rtqd sgd Dwodqhdmbd- Cqd`lr e`cd `v`x nmbd xnt v`jd to-";
        if (insecureHashSix(pass) == PASSWORD_HASH_SIX)
        {
            std::cout<<"Correct Password!\nSecret Message: "<<decrypt(message)<<std::endl;
        }
        else
        {
            std::cout<<"Entered Password hash value: "<<insecureHashSix(pass)<<std::endl;
            std::cout<<"Correct Password hash value: 84114101"<<std::endl;
            std::cout<<"Incorrect Password. Try again"<<std::endl;
        }
        break;
    
    default:
        cout<<"Incorrect choice. Try again"<<endl;
        break;
    }

    // cout<<insecureHashOne("Never gonna give you up")<<endl;
    // cout<<insecureHashTwo("Winter is Coming")<<endl;
    // cout<<insecureHashThree("There is one way out!")<<endl;
    // cout<<insecureHashFour("May the Force be with you")<<endl;
    // cout<<insecureHashFive("My soldiers, tatakae!")<<endl;
    // cout<<insecureHashSix("Treasure the Experience")<<endl;
}
