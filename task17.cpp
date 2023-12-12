#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

std::string replaceFirstLetter(const std::string &sentence)
{
    std::istringstream iss(sentence);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word)
    {
        words.push_back(word);
    }

    std::vector<std::string> articles = {"a", "an", "the"};

    for (size_t i = 1; i < words.size(); ++i)
    {
        for (const std::string &article : articles)
        {
            if (words[i - 1] == article)
            {
                if (!words[i].empty())
                {
                    words[i][0] = std::tolower(words[i][0]);
                }
            }
        }
    }

    std::ostringstream oss;
    for (const std::string &w : words)
    {
        oss << w << ' ';
    }

    return oss.str();
}

int main()
{
    std::string inputSentence = "A quick brown Fox jumps over the lazy Dog";
    std::string result = replaceFirstLetter(inputSentence);

    std::cout << result << std::endl;

    return 0;
}
