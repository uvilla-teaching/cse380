Compile but not link:

```
icc -c foo.c
icc -c bar.c
```

Try to link the file separately
```
icc -o foo foo.o
icc -o bar bar.o
```

Inspect the symbols
```
nm foo.o bar.o
```

You need both to link!
```
icc -o main foo.o bar.o
```
