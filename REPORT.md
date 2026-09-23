# Project Report

## Part 2: Multi-file Build and Git

### 1. Explain the linking rule in this part's Makefile: $(TARGET): $(OBJECTS). How does it differ from a Makefile rule that links against a library?

The rule `$(TARGET): $(OBJECTS)` means that the final executable depends directly on the object files. The object files are passed to the compiler/linker to create the executable. In this case, the functions are linked directly from the project's object files.

A Makefile rule that links against a library is different because the executable is linked using a library, such as `libmyutils.a` or `libmyutils.so`. Instead of directly listing all library object files in the executable rule, the linker is given the library location and library name. This allows the library to provide the required functions during the linking process.

### 2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?

A Git tag is a name attached to a specific commit. It is useful for marking important versions or milestones of a project, such as a completed feature or release.

A simple tag is a lightweight reference to a commit and mainly acts as a name for that commit. An annotated tag is a separate Git object that contains additional information such as the tag message, tagger, and date. Annotated tags are useful for official project releases because they provide more information about the version.

### 3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?

A GitHub Release provides a clear and organized way to publish a specific version of a project. It is connected to a Git tag and can include information about what was completed in that version.

Attaching binaries such as the client executable allows users to obtain and use the already-built program without having to compile the source code themselves. It also provides a specific, preserved version of the executable associated with that release.

---

## Part 3: Static Library

### 4. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?

The Part 2 Makefile directly compiled the source files into object files and linked those object files to create the executable.

In Part 3, additional variables were introduced for the static library, such as `AR`, `ARFLAGS`, `LIB_SRC`, `LIB_OBJ`, and `LIBRARY_STATIC`. A rule was also added to create `libmyutils.a` from the library object files.

The `ar` command was used to combine the object files into a static library. The final client was then linked against this library using the `-L` option to specify the library directory and `-lmyutils` to specify the library.

### 5. What is the purpose of the ar command? Why is ranlib often used immediately after it?

The `ar` command is used to create and modify archive files. In this project, it combines object files into the static library `libmyutils.a`.

`ranlib` creates or updates the symbol index of an archive. This index helps the linker quickly find the required functions inside the static library. Modern versions of `ar` can create the symbol index automatically when using options such as `rcs`, so a separate `ranlib` command may not always be necessary.

### 6. When you run nm on your client_static executable, are the symbols for functions like mystrlen present? What does this tell you about how static linking works?

Yes, functions such as `mystrlen` are present in the static executable when they are used by the program.

This shows that during static linking, the required code from the static library is copied into the executable. Therefore, the resulting executable contains the required library code and does not need to load that code from a shared library at runtime.

---

## Part 4: Dynamic Library

### 7. What is Position-Independent Code (-fPIC) and why is it a fundamental requirement for creating shared libraries?

Position-Independent Code, or PIC, is code that can execute correctly regardless of where it is loaded into memory. The `-fPIC` compiler option tells the compiler to generate this type of code.

It is important for shared libraries because the operating system's dynamic loader can load a shared library at different memory addresses for different processes. Position-independent code allows the same shared library to be loaded and used without requiring its machine code to be rewritten for a particular memory location.

### 8. Explain the difference in file size between your static and dynamic clients. Why does this difference exist?

The static client is generally larger than the dynamic client because the required library code is included inside the static executable.

The dynamic client is generally smaller because the shared library code remains in a separate `.so` file. The dynamic executable contains references to the shared library instead of containing all of its library code. The operating system's dynamic loader loads the shared library when the program runs.

The exact file sizes can depend on compiler options, symbols, and which functions are used.

### 9. What is the LD_LIBRARY_PATH environment variable? Why was it necessary to set it for your program to run, and what does this tell you about the responsibilities of the operating system's dynamic loader?

`LD_LIBRARY_PATH` is an environment variable that tells the dynamic loader additional directories where it should search for shared libraries.

It was necessary in this project because `libmyutils.so` was stored in the project's `lib` directory, which was not one of the standard directories searched by the dynamic loader.

For example, setting `LD_LIBRARY_PATH` to the project's library directory allowed the loader to find `libmyutils.so` when `client_dynamic` was executed.

This shows that the dynamic loader is responsible for finding and loading the required shared libraries when a dynamically linked program starts. If a required library cannot be found in the loader's search paths, the program may fail to start.

