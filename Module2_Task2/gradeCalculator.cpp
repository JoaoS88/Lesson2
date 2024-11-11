#include <iostream>
#include <sstream>
#include <string>

// function to get grade from input score
std::string getGrade(int score)
{
    // if statements to determine grade from score
    if (score >= 80) { return "A*"; }
    else if (score >= 70) { return "A"; }
    else if (score >= 60) { return "B"; }
    else if (score >= 50) { return "C"; }
    else if (score >= 40) { return "D"; }
    else if (score >= 1) { return "F"; }
    else { return "U"; }
}
// method to output the from the given input using getGrade(score)
void outputGrade()
{
    // ask user for input of their grade out of 100
    std::cout << "Input Grade Scored in Programming Class: (?/100)" << std::endl;
    int score;
    // input "grade/100" igore "/" and "100" and only store and use grade
    char ignore;
    std::cin >> score >> ignore >> ignore;
    // output their score alongside their grade
    std::cout << "You got: " << score << "/100 => " << getGrade(score) << std::endl;
}

int main()
{
    outputGrade();
    return 0;
}