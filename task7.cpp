#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

template <typename T>
class String
{
private:
    T content;
    T delimiter;

public:
    String(const T &content, const T &delimiter) : content(content), delimiter(delimiter) {}

    friend std::istream &operator>>(std::istream &input, String &str)
    {
        input >> str.content;
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const String &str)
    {
        output << str.content;
        return output;
    }

    void readFromFile(const std::string &fileName)
    {
        std::ifstream inputFile(fileName);
        if (!inputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for reading.");
        }

        inputFile >> content;
        inputFile.close();
    }

    void writeToFile(const std::string &fileName) const
    {
        std::ofstream outputFile(fileName);
        if (!outputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for writing.");
        }

        outputFile << content;
        outputFile.close();
    }

    void setDelimiter(const T &newDelimiter)
    {
        delimiter = newDelimiter;
    }

    String concatenate(const String &other) const
    {
        return String(content + delimiter + other.content, delimiter);
    }

    std::size_t length() const
    {
        return content.length();
    }

    T mergeCharacters() const
    {
        if (content.length() > 0)
        {
            return content[0];
        }
        throw std::out_of_range("Cannot merge characters from an empty string.");
    }

    typename T::value_type operator[](std::size_t index) const
    {
        if (index < content.length())
        {
            return content[index];
        }
        throw std::out_of_range("Index out of range.");
    }

    void removeCharacter(std::size_t index)
    {
        if (index < content.length())
        {
            content.erase(index, 1);
        }
        else
        {
            throw std::out_of_range("Index out of range.");
        }
    }
};

template <>
class String<char>
{
private:
    std::string content;
    char delimiter;

public:
    String(const std::string &content, char delimiter) : content(content), delimiter(delimiter) {}

    friend std::istream &operator>>(std::istream &input, String &str)
    {
        input >> str.content;
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const String &str)
    {
        output << str.content;
        return output;
    }

    void readFromFile(const std::string &fileName)
    {
        std::ifstream inputFile(fileName);
        if (!inputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for reading.");
        }

        inputFile >> content;
        inputFile.close();
    }

    void writeToFile(const std::string &fileName) const
    {
        std::ofstream outputFile(fileName);
        if (!outputFile.is_open())
        {
            throw std::runtime_error("Unable to open file for writing.");
        }

        outputFile << content;
        outputFile.close();
    }

    void setDelimiter(char newDelimiter)
    {
        delimiter = newDelimiter;
    }

    String concatenate(const String &other) const
    {
        return String(content + delimiter + other.content, delimiter);
    }

    std::size_t length() const
    {
        return content.length();
    }

    char mergeCharacters() const
    {
        if (content.length() > 0)
        {
            return content[0];
        }
        throw std::out_of_range("Cannot merge characters from an empty string.");
    }

    char operator[](std::size_t index) const
    {
        if (index < content.length())
        {
            return content[index];
        }
        throw std::out_of_range("Index out of range.");
    }

    void removeCharacter(std::size_t index)
    {
        if (index < content.length())
        {
            content.erase(index, 1);
        }
        else
        {
            throw std::out_of_range("Index out of range.");
        }
    }
};

int main()
{
    String<char> str1("Hello", ' ');
    String<char> str2("world!", ' ');

    std::cout << "Initial strings:\n";
    std::cout << "String 1: " << str1 << "\n";
    std::cout << "String 2: " << str2 << "\n";

    str1.setDelimiter('-');
    str2.setDelimiter('-');

    String<char> result = str1.concatenate(str2);

    std::cout << "\nConcatenated string:\n";
    std::cout << "Result: " << result << "\n";

    result.removeCharacter(5);

    std::cout << "\nAfter removing character at index 5:\n";
    std::cout << "Result: " << result << "\n";

    return 0;
}
