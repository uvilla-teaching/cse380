# Assert

Assert is very useful to turn on/off condition checking

By default, condition checking is on when using assert
```
gcc -o macro macro.c
./macro
```

However, it is easy to turn it off when you are in _production_ mode:

```
gcc -DNDEBUG -o macro macro.c 
./macro
```
