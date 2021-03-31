## Running the code
The code is compiled using the command: 
```g++ main.cpp –o main```

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
The program was ran on two devices, Device 1 (Intel Core i5 4690 @ 3.50GHz) and Device 2 (i7-8700k overclocked to 4.45Ghz). 
|File Size     |Device 1: Encoding Speed|Device 2: Encoding Speed|Device 1: Decoding Speed|Device 2: Decoding Speed|
|--------------|------------------------|------------------------|------------------------|------------------------|
|932 KB        | 1.089 sec              | 0.895 sec              |0.518 sec               |0.511 sec               |
|9,382 KB      | 12.85 sec              | 10.18 sec              |5.82 sec                |5.53 sec                |
|184,132 KB    | 336.05 sec             | 254.03 sec             |185.38 sec              |122.7 sec               |

![image](https://user-images.githubusercontent.com/71051737/113090505-ea3f6d00-91b7-11eb-9b9f-f7fdce1dd221.png)
![image](https://user-images.githubusercontent.com/71051737/113090509-ec093080-91b7-11eb-80fc-b1ad333f0c38.png)

As it can be seen, the run time increases as file size increases.  The decoder is almost half the time of the encoding. This can be due to the face that the decoding only requires dictionary look up which is in O(1) time as we know that the ID value is in the dictionary. At a smaller file size, processor did not make a signifant different. However, as file size increases, the runtime difference between the two devices increased. 

## Conclusions
