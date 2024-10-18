#include "rle.h"
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include "stdlib.h"
using namespace std;
// Constructor
rle::rle(int gamma): gamma(gamma){}

int highest_power_of_two (int k) {
    int i = 0;
    while (k > 0) {
        k/= 2;
        i++;
    }
    return i;
}


// Convert integer to gamma-bit binary string
string rle::f(int i)
{ 
    string return_string = "";

    string string_ones = "";
    for (int k = 0; k < gamma; k++) {
        string_ones += "1";
    }
    string string_zeroes = "";
    for (int k = 0; k < gamma; k++) {
        string_zeroes += "1";
    }
    if (i > pow(2, gamma) - 1) {
        //cout<<"GOINGWRONG";
        return_string += string_ones + "" + string_zeroes + "";
        i -= pow(2, gamma);
        i++;
    }
    while (i > pow(2, gamma) - 1) {
        return_string += string_ones + "" + string_zeroes + "";
        i -= pow(2, gamma);
        i++;
    }    
    if (i > 0) {
        int num_zeroes_extra = gamma - highest_power_of_two(i);
        // cout<<num_zeroes_extra;
            for (int i = 0; i < num_zeroes_extra; i++) {
                return_string += "0";
            }
            string trial = "";
        while (i>0) {
            
            // cout<<i<<" check "<<highest_power_of_two(i)<<endl;
            
            trial += to_string(i%2);
            i /= 2;
        }
        reverse(trial.begin(), trial.end());
        return_string+=trial;
        //cout<<"LET'S SEE: "<<return_string<<endl;
    }
    // cout<<return_string;
    return return_string; 
}

// Convert gamma-bit binary string to integer
int rle::g(string i)
{ 
    int return_integer = 0;
    while (!i.empty()) {
        //cout<<int(i[0] - '0')<<"GEN"<<endl;
        return_integer = return_integer*2 + int(i[0] - '0');
        i.erase(i.begin());
        // cout<<return_integer<<"NCIEDF"<<endl;
    }
    return return_integer; 
}

// Compress the input file
string rle::compress(string input_string)
{   
    string return_string = "";
    if (input_string == "\n") return return_string;
    // cout<<input_string;
    // while (input_string.back() == '\n') {
    //     //cout<<"HHH";
    //     input_string.erase(input_string.end());
    // }
    //cout<<input_string;
    input_string.pop_back();   
    input_string.pop_back(); 
    
    if (input_string[0] == '1') {
        return_string += '1';
    }
    else {
        return_string += "0";
    }
    
    while (!input_string.empty()) {
        //if (input_string.empty()) return return_string;
        //cout<<input_string<<endl;
        int function_call_integer = 1;
        int j = 1;
        while (input_string[j]!= '\0') {
            if (input_string[j] == input_string[0]) j++; 
            else break;}
        // cout<<j<<endl;
        //cout<<gamma<<endl;
        return_string += f(j);
        //cout<<f(j)<<endl;
        //cout<<"J VALUE"<<j<<endl;
        for (int k = 0; k <j; k++) {
            //cout<<"BEFORE "<<input_string<<endl;
            input_string.erase(input_string.begin());
            //cout<<"after "<<input_string<<endl;
        }
        // cout<<input_string<<"FINAL";
    }
    //return_string.erase(return_string.begin());
    return return_string;
}

// Decompress the input file
string rle::decompress(string input_string)
{   
    // cout<<input_string<<endl;
    char current_bit = input_string[0];
    string final_return_string = "";
    input_string.erase(input_string.begin());
    // cout<<input_string<<endl;
    while (!input_string.empty()) {
        string current_string_function_call = "";
        for (int i = 0; i < gamma; i++) {
            current_string_function_call += input_string[0];
            input_string.erase(input_string.begin());
        }
        // cout<<current_string_function_call<<endl;
        int function_call_return_integer = g(current_string_function_call) ;
        // cout<<function_call_return_integer<< "CHCH"<<endl;
        for (int i = 0 ; i < function_call_return_integer; i++) {
            // cout<<char(current_bit)<<" HELLO "<<endl;
            final_return_string.push_back(current_bit);
            // cout<<current_bit<<" CSBCJBSJA"<<endl;
            // cout<<"CHECK_current_bit "<<final_return_string<<endl;
        }
        if (current_bit == '0') current_bit = '1';
        else current_bit = '0';
        // cout<<current_bit<<"SAKSHAM"<<endl;
    }
    cout<<final_return_string<<endl;
    return final_return_string;
} 