# rest-test-c

Bygg med

```console
gcc main.c -o main \
-L/D/Program/msys64/mingw64/lib \
-L/D/Program/msys64/usr/lib \
-I/D/Program/msys64/mingw64/include \
-I/D/Program/msys64/usr/include \
-ljson-c -lcurl
```

eller med make

```console
$ make
gcc -g -Wall -I/D/Program/msys64/mingw64/include -I/D/Program/msys64/usr/include -c main.c  -o main.o
gcc -g -Wall -I/D/Program/msys64/mingw64/include -I/D/Program/msys64/usr/include -o myFile main.o -L/D/Program/msys64/mingw64/lib -L/D/Program/msys64/usr/lib -ljson-c -lcurl
Simple compiler named myFile has been compiled
```

För att lägga till fler paket, kör msys2 i Windows.
En terminal öppnas, där pakethanteraren heter pacman
Gå till https://packages.msys2.org/package/?repo=msys
och hitta libbet du vill ha
t.ex https://packages.msys2.org/base/mingw-w64-json-c
Under Binary Packages väljer du nåt, t.ex. https://packages.msys2.org/package/mingw-w64-x86_64-json-c?repo=mingw64

```console
pacman -S mingw-w64-x86_64-json-c
```
