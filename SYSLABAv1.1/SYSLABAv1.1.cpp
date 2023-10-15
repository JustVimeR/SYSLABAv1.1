#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

bool hasDoubleConsonants(const std::string& word) {
    // Список англійських приголосних літер
    const std::string consonants = "bcdfghjklmnpqrstvwxyzабвгдеєжзиіїйклмнопрстуфхцчшщьюя";

    for (int i = 0; i < word.length() - 1; ++i) {
        if (consonants.find(word[i]) != std::string::npos && word[i] == word[i + 1]) {
            return true; // Знайдено здвоєну приголосну літеру
        }
    }

    return false;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::unordered_set<std::string> uniqueWords;

    if (!inputFile) {
        std::cerr << "Не вдалося відкрити файл." << std::endl;
        return 1;
    }

    std::string word;
    while (inputFile >> word) {
        // Перевірка довжини слова та наявності здвоєних приголосних літер
        if (word.length() <= 30 && hasDoubleConsonants(word)) {
            uniqueWords.insert(word);
        }
    }

    inputFile.close();

    // Вивід унікальних слів, які задовольняють умову
    for (const std::string& uniqueWord : uniqueWords) {
        std::cout << uniqueWord << std::endl;
    }

    return 0;
}
