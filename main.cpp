#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

string line;
string input;
int total = 0;
map<string, int> locations;
map<int, string> decoder;


void encode()
{
    ifstream infile(input);
    ofstream outfile("Dictionary.txt");
    ofstream outfile2("Encoded.txt");

    //set up single characters in dictionary
    for (int i = 0; i <= 222; i++) 
    {
        string ch = "";
        ch += char(i+33);
        locations[ch] = i;
        if (i < 10)
            outfile << "ID: " << i << "\t\tData: " << ch << endl;
        else
            outfile << "ID: " << i << "\tData: " << ch << endl;
    }

    int ID = 223;
    string prev_letter = "";
    string letter = "";

    //set up dictionary for specific file and encode data into new file
    while (getline(infile,line))
    {   
        prev_letter = line[0];
        for (int i = 0; i < line.length(); i++) 
        {   
            if (i != line.length() - 1)
                letter += line[i + 1];
            if (locations.find(prev_letter + letter) != locations.end())
            {
                prev_letter = prev_letter + letter;
                if (i == line.length() - 1)
                    outfile2 << locations[prev_letter] << "\t";
            }
            else
            {
                outfile << "ID: " << ID << "\tData: " << prev_letter + letter << endl;
                outfile2 << locations[prev_letter] << " ";
                locations[prev_letter + letter] = ID;
                prev_letter = letter;
                ID ++;
            }
            letter = "";
        }
        outfile2 << endl;
    }
     cout << "Encoded file created. Named: \"Encoded.txt\"" << endl;
}


void decode()
{
    ofstream outfile3("Decoded.txt");

    //flip dictionary created from encoding
    for(auto it = locations.begin(); it != locations.end(); it++)
        decoder[it->second] = it->first;
    
    //read data from encoded file
    ifstream infile2("Encoded.txt");
    while (getline(infile2,line))
    {   
        if (line == "")
            break;

        vector<int> read_code;
        string temp = "";

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ' ')
                temp += line[i];
            else
            {
                read_code.push_back(stoi(temp));
                temp = "";
            }
            if (i == line.length()-1)
                read_code.push_back(stoi(temp));
        }

        temp = "";
        for (int i = 0; i < read_code.size();i++)
        {
            string output = decoder[read_code[i]];
            temp += output;
        }

        if (temp == input)
            total++;

        outfile3 << temp << endl;
    }
}


int main()
{
    
    cout << "Enter input file name: ";
    cin >> input;
    ifstream infile(input);
   
    //check if file has been opened
    if (!infile) {
        cerr << "Unable to open file";
        exit(1);   // call system to stop
    }

    auto encoding_start = std::chrono::steady_clock::now();
    encode();
    auto encoding_end = std::chrono::steady_clock::now();
    
    std::chrono::duration<double> elapsed_seconds = encoding_end - encoding_start;
    cout << "Encoding took " << elapsed_seconds.count() << " seconds " << endl;

    cout << "Type data to check from encoded file total number of occurences: ";
    cin >> input;
    
    auto decoding_start = std::chrono::steady_clock::now();
    decode();
    auto decoding_end = std::chrono::steady_clock::now();

    elapsed_seconds = decoding_end - decoding_start;
    cout << "Decoding took " << elapsed_seconds.count() << " seconds " << endl;
    
    cout << "Total number of times data item, \"" << input << "\", occurs: " << total << endl;
}