#include <string>
#include <cctype>
#include <algorithm>

class Solution {
public:
    string licenseKeyFormatting(string s, int k)
    {
        string result;

        int counter = 0;

        // Traverse the input string from the end
        for (int i = (int)s.size() - 1; i >= 0; --i)
        {
            if (s[i] == '-') continue; // Skip existing dashes

            // Add character in uppercase
            result.push_back(toupper(s[i]));

            counter++;

            // Insert dash after k characters
            if (counter == k)
            {
                result.push_back('-');
                counter = 0;
            }
        }

        // Remove trailing dash if present
        if (!result.empty() && result.back() == '-') result.pop_back();

        // Reverse the result to get correct order
        reverse(result.begin(), result.end());

        return result;
    }
};