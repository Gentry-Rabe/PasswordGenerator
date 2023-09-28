#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

//done
string toLength(string in){
    string out = "";
    int i = 0;
    while(out.length() < 6){
        out += in[i];
        out += in[in.length() - (i + 1)];
        i++;
        if(i == in.length()){
            i = 0;
        }
    }
    return out;
}

//done
string addCap(string in, int key){
    string out = "";
    if(key % 2 == 0){
        for(int i = 0; i < in.length(); i++){
            if(i % 2 == 0){
                out += toupper(in[i]);
            }else{
                out += in[i];
            }
        }
    }else{
        for(int i = 0; i < in.length(); i++){
            if(i % 2 == 1){
                out += toupper(in[i]);
            }else{
                out += in[i];
            }
        }
    }
    return out;
}

//done
string addNum(string in, int key){
    string out = "";
    //extract 6 individual numbers from key
    int nums[6];
    string skey = to_string(key);
    for(int i = 0; i < 6; i++){
        char snum = skey[i];
        int num = snum - '0';
        nums[i] = num;
    }

    //int nums[] = {((int)key / 10000), (((int)key % 10000) / 100), fmod(key, 100)};

    //insert numbers into main string
    for(int i = 0; i < in.length(); i++){
        out += in[i];
        out += to_string(nums[i]);
    }

    return out;
}

//done
string getSP(string skey, int i){
    //get special character from key
    char snum = skey[i];
    int num = snum - '0';

    switch(num){
    case 0:
        return ")";
        break;
    case 1:
        return "!";
        break;
    case 2:
        return "@";
        break;
    case 3:
        return "#";
        break;
    case 4:
        return "$";
        break;
    case 5:
        return "%";
        break;
    case 6:
        return "^";
        break;
    case 7:
        return "&";
        break;
    case 8:
        return "*";
        break;
    case 9:
        return "(";
        break;
    default:
        return "!";
        break;
    }
}

//done
string addSP(string in, int key){
    string out = "";
    int i = 0;
    do{
        out += in[i];
        i++;
        if(i % 2 == 0){
            out += getSP(to_string(key), i/2);
        }
    }while(i < in.length());
    return out;
}

int main(){
    //string and key input
    string input;
    int key;
    cout << "Input starter string (one word): ";
    cin >> input;
    cout << endl << "Input key (int only, 6 digits): ";
    cin >> key;
    //convert string to all lowercase (for universal application)
    for(int i = 0; i < input.length(); i++){
        input[i] = tolower(input[i]);
    }

    //basic encryption
    //getting input to length. Fill forwards and backwards with "checkerboard" design
    string s1 = toLength(input);

    //adding capitalization
    string s2 = addCap(s1, key);

    //adding numbers
    string s3 = addNum(s2, key);

    //adding special chars
    string s4 = addSP(s3, key);

    //output
    cout << endl << "Encrypting phrase: '" << input << "' with key: " << key << endl << endl;
    cout << "Generated phrase: '" << s4 << "'." << endl;
    return 0;
}


