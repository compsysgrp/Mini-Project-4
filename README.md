## Running the code
The code is compiled using the command: 
```-g main.cpp –o main```

The program will ask for the name of the file that will be used compressed and encoded. The dictionary will be outputed to a file called, "dictionary.txt," and the encoded file will be a filed called, "encoded.txt." 

The program will then ask for the data that the user would like to check whether it exist in the column and the number of occurences. 

## Data Structure

The dictionary is made from the map data struction through C++. The data is set as the key and the new ID as the value when encoding. When decoding, the dictionary is flipped, where the key is the ID and the data is set as the value. 

## Functions
### Main:
The main function calls the functions mentioned below and asks the user for inputs. 
### Encode:
The encoding function is based off of Lempel–Ziv–Welch compression technique. The function indentifies repeated sequences in the data and adds it to the dictionary. Each line is read and converted before being output to the "encoded.txt" file. The dictionary is also output to a file called, "dictionary.txt."
### Decode:
The decoding function simply uses the existing dictionary that was made. The original dictionary is flipped, where the keys become the values and the values become the keys. This allows the program is read the encoded data and get the decoded value by directing calling the key from the dictionary.

## Test Results


## Conclusions
