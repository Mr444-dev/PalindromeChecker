#include <iostream>
#include <string>
#include <cctype>
#include <algorithm> r

int main() {
    std::string text;
    std::string cleanedText = "";
    bool isPalindrome = true;

    std::cout << "--- C++ Palindrome Checker ---" << std::endl;
    std::cout << "Enter a word or phrase to check: ";
    std::getline(std::cin, text);


    for (char character : text) {
        if (std::isalnum(static_cast<unsigned char>(character))) {
            cleanedText += std::tolower(static_cast<unsigned char>(character));
        }
    }

    int length = cleanedText.length();

    // Check if the cleaned string is a palindrome
    if (length > 1) {
        for (int i = 0; i < length / 2; ++i) {
            if (cleanedText[i] != cleanedText[length - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }
    } else if (length == 0) {
        // Consider an empty string or a string with only non-alphanumeric chars not a palindrome
        // Or decide based on requirements, here setting it to false for clarity.
        // If single alphanumeric char is considered a palindrome, this logic is fine.
        // If empty/non-alphanumeric only should be treated differently, add specific checks.
        isPalindrome = false; // Or handle as per specific requirements
    }
    // Single character strings are palindromes by default (isPalindrome remains true)


    std::cout << "-------------------------" << std::endl;
    std::cout << "Original text: '" << text << "'" << std::endl;
    if (isPalindrome) {
        std::cout << "Verdict: It IS a palindrome." << std::endl;
    } else {
        std::cout << "Verdict: It is NOT a palindrome." << std::endl;
    }

    return 0;
}