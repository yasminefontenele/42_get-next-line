# 42_get-next-line
Reading a line from a fd is way too tedious

> _This project is about programming a function that returns a line read from a file descriptor._

For detailed information: [**subject of this project**](https://github.com/yasminefontenele/42_get-next-line/blob/main/Get_next_line.pdf).

### _File descriptor_

A file descriptor is a unique identifier or integer value used by an operating system to represent an open file or input/output (I/O) stream. In simple terms, it is a reference to a file or I/O resource that a process can read from or write to.

In Unix-like systems, file descriptors are typically represented as non-negative integers. The following conventions are commonly used:

- Standard input (stdin) is represented by file descriptor 0.
- Standard output (stdout) is represented by file descriptor 1.
- Standard error (stderr) is represented by file descriptor 2.

In programming, file descriptors are commonly manipulated using functions provided by the operating system or programming language, such as open(), read(), write(), close(), and others. These functions allow the programmer to interact with files and I/O resources using the file descriptor associated with them.

### _static variable_

static variable is a variable that retains its value throughout the program's execution, unlike automatic variables that are created and destroyed each time a function is called.

- They are accessible only within the block where they are defined.
- They are initialized only once when the program starts and retain their value between function calls.
- If is not explicitly initialized, it is automatically initialized to zero (0) or a null value, depending on its data type.
- The value of a static variable persists between function calls.
- Are typically allocated in the data segment of memory. They occupy memory for the entire duration of the program, regardless of whether they are currently in use or not.
- Are not visible or accessible outside the block where they are defined. They are private to the function or block in which they are declared.


## 💡Tips
- [**understanding I**](https://medium.com/@ayogun/master-file-i-o-operations-with-42s-get-next-line-project-5fb001d1fff5).
- [**understanding II**](https://velog.io/@ljiwoo59/getnextline)
- [**Handling a File by its Descriptor in C**](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/).
- [**Static Variables in C**](https://www.codequoi.com/en/local-global-static-variables-in-c/).
- [**coder get_next_line**](https://www.youtube.com/watch?v=xgDSXNOHTIA).
- [**get_next_line**](https://www.youtube.com/watch?v=-Mt2FdJjVno).
- [**one more**](https://www.youtube.com/watch?v=5hvjwHZFwi0).
