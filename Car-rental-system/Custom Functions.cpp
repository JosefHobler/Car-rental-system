#include "Custom functions.h"

string CenteredText(string word, const int& size_to_center)
{
    bool space = true;
    for (int i = word.size(); i < size_to_center; i++)
    {
        if (space)
        {
            word += ' ';
        }
        else
        {
            word = ' ' + word;
        }
        space = !space;
    }
    return word;
}