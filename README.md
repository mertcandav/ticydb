# TicyDB

[Documentations](https://github.com/mertcandav/ticydb/tree/master/docs) |
[Examples](https://github.com/mertcandav/ticydb/tree/master/examples)

TicyDB is local key-value data-store library in single header written in C. <br>

It offers a manual save mechanism.
For this reason, you can use it both as in-memory and save every transaction end and free the memory and use it plainly.
TicyDB offers all its root functions, so you can develop a custom custom application without modifying it on your own.

## Featured Features
+ Single Header
+ Written in pure C
+ Simple and Strong
+ Lightweight
+ Efficient
+ Supports ACID
+ Performance

## Simple Data Representation
```
"Message" "Hello World"
"PI_Number" f3.14
"Admins" [["admin" "1230"] ["super" "3434"] ["root" "9090"]]
"Fibonacci" [d1 d1 d2 d3 d4 d8 d13 d21 d34 d55]
```
The data type representation is part of the representation of the data. <br>
Its data is separated by spaces, each line consists of a single key/value pair.

## License
[See License](https://github.com/mertcandav/ticydb/blob/master/LICENSE)
