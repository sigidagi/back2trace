
```
pipx install conan
conan install . --build=missing --settings=build_type=Debug

cmake --preset conan-debug
cmake --build build/Debug -j8
```
