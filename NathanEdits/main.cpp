/*
 * file: McDonaldJohnPaul_Midterm_Problem7_CardValues
 * Author: John-Paul McDonald
 * Date: 05/22/2022
 * Purpose: Given 4 cards with 13 possible face values, calculate the
 * probability of 1 pair, 2 pair, 3 of a kind and 4 of a kind. Simulate
 * the results and compare to calculations.
 */

 //System Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

vector<string> ReadNames(const char* fileName);

int main(int, char**)
{
    srand(time(0));

    vector<string> boyarr = ReadNames("boyname.txt");
    vector<string> girlarr = ReadNames("girlname.txt");
    vector<string> lastarr = ReadNames("lastname.txt");

    ofstream outputFile("output.txt");

    int num = 0, num2 = 0, num3 = 0, num4 = 0;
    for (int i = 0; i < 512; i++)
    {
        outputFile << "\t\t\t\t#" << i;
        num = abs(rand() % 1000);
        outputFile << " num " << num;
        num2 = (num * 53) % 999;
        num3 = (num * 69) % 999;
        num4 = num % 999;
        num = num % 2;
        outputFile << " num " << num << " num2 " << num2 << " num3 " << num3 << " num4 " << num4;

        string name;
        if (num > 0)
            name = boyarr[num2] + " " + boyarr[num3] + " " + lastarr[num4];
        else if (num == 0)
            name = girlarr[num2] + " " + girlarr[num3] + " " + lastarr[num4];

        outputFile << " name: " << name << "\n";
    }

    outputFile.close();
    return 0;
}

vector<string> ReadNames(const char* fileName)
{
    ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile.good())
        return {};

    vector<string> result;
    string line;
    while (getline(inputFile, line))
        result.push_back(move(line));

    inputFile.close();
    return result;
}
