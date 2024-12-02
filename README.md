Word Break


You are given a string s and a word list w which is a list of unique strings. You have to determine if s can be broken down into a sequence of words where each word is an element in w.

Examples:
s: “workattech”
w: [“tech”, “work”, “problem”, “at”]
Result: true
s: “roundandround”
w: [“and”, “round”]
Result: true
s: “helloworld”
w: [“hi”, “world”]
Result: false
Testing
Input Format
The first line contains an integer ‘T’, denoting the number of test cases.

For each test case the input has three lines:

The string s.
An integer ‘n’ denoting the size of the word list w.
n space-separated strings denoting the elements of the word list w.
Expected Output
For each test case, a line containing 1 or 0 depending on whether the string s can be partitioned or not respectively..

Sample Input
3
workattech
4
tech work problem at
roundandround
2
and round
helloworld
2
hi world
Expected Output
1
1
0