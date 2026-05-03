# Basic CMake project in C++

This project is for learning how C++ applications are compiled and linked in a
layout similar to what is used in larger software projects.

## Project Structure

- `app/main.cpp` is the application entry point.
- `app/src/application.cpp` contains application logic used by `main.cpp`.
- `statlib/src/logger.cpp` is built as a static library.
- `mylib/src/math_utils.cpp` is built as a dynamic/shared library.

## Version 1 (clang build)

In version 1, the project is built manually using normal `clang++` commands.
This helps show each compilation and linking step clearly before moving to a
build system such as CMake.

### Build the dynamic library

`math_utils.cpp` is compiled into a macOS dynamic library:

```sh
clang++ -dynamiclib -fPIC mylib/src/math_utils.cpp -o build/shared/libmylib.dylib
```

Notes:

- `-dynamiclib` tells `clang++` to create a dynamic library.
- `-fPIC` generates position-independent code, which is required for shared
  libraries.
- The output library is `build/shared/libmylib.dylib`.

### Build the static library

First compile `logger.cpp` into an object file:

```sh
clang++ -I./statlib/include -c statlib/src/logger.cpp -o logger.o
```

Then archive the object file into a static library:

```sh
ar rcs build/static/libstatlib.a logger.o
```

Notes:

- `-I./statlib/include` adds the static library header path.
- `-c` compiles the source file into an object file without linking.
- `ar rcs` creates the static library archive.
- The output library is `build/static/libstatlib.a`.

### Compile the application source files

Compile `application.cpp`:

```sh
clang++ -I./app/include -I./statlib/include -I./mylib/include -c app/src/application.cpp -o application.o
```

Compile `main.cpp`:

```sh
clang++ -I./app/include -I./mylib/include -I./statlib/include -c app/main.cpp -o main.o
```

Notes:

- Both commands use `-c`, so they only create object files.
- Include paths are passed with `-I` so the compiler can find headers from the
  app, static library, and dynamic library.
- The output object files are `application.o` and `main.o`.

### Link the final executable

Link the application object files with the static and dynamic libraries:

```sh
clang++ main.o application.o ./build/static/libstatlib.a -L./build/shared -lmylib -o myapp
```

Notes:

- `main.o` and `application.o` are the application object files.
- `./build/static/libstatlib.a` links the static logger library directly into
  the executable.
- `-L./build/shared` tells the linker where to search for dynamic libraries.
- `-lmylib` links against `libmylib.dylib`.
- `-o myapp` creates the final executable named `myapp`.

### Full command sequence

```sh
clang++ -dynamiclib -fPIC mylib/src/math_utils.cpp -o build/shared/libmylib.dylib

clang++ -I./statlib/include -c statlib/src/logger.cpp -o logger.o

ar rcs build/static/libstatlib.a logger.o

clang++ -I./app/include -I./statlib/include -I./mylib/include -c app/src/application.cpp -o application.o

clang++ -I./app/include -I./mylib/include -I./statlib/include -c app/main.cpp -o main.o

clang++ main.o application.o ./build/static/libstatlib.a -L./build/shared -lmylib -o myapp
```
