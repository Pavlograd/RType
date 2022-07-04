# B-CPP-501-LIL-5-1-rtype-victor.cuvelier
With Maurin L | Tristan M | Mattéo D | Victor C

**Installation:**

To Install Conan:
```
sudo pip install conan
conan remote add conan-center https://api.bintray.com/conan/conan-community/conan
conan remote add epitech https://api.bintray.com/conan/epitech/public-conan
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
```

You should have this following output with this command:
```
conan remote list
```
>conan-center: https://api.bintray.com/conan/conan-community/conan [Verify SSL: True]
>epitech: https://api.bintray.com/conan/epitech/public-conan [Verify SSL: True]
>bincrafters: https://api.bintray.com/conan/bincrafters/public-conan [Verify SSL: True]

At the Root of the repository:
```
rm -rf build && mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build .
```

>If an error occured don't forget to go back at the root !

At the end of the process:
```
make
```

Now you're able to launch either client or server with the commands:
```
./r-type_client
./r-type_server
```