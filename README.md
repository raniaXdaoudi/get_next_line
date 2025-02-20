# get_next_line

A custom implementation of a function that reads a line from a file descriptor. This project is part of the 42 school curriculum.

## Description

This project involves developing a function that returns a line read from a file descriptor. It's a way to learn a very interesting concept in C: static variables, while handling file descriptors.

## Features

The function supports:
- Reading line by line from a file descriptor
- Handling multiple file descriptors simultaneously (bonus version)
- Managing a variable-sized buffer (defined at compilation)
- Returning the line without the '\n' character
- Proper memory management

## Getting Started

### Prerequisites
- GCC compiler
- Make (optional)

### Installation
```bash
git clone https://github.com/yourusername/get_next_line.git
cd get_next_line
```

### Usage
```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Compilation
To compile with a specific buffer size:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

For the bonus version:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Return Value
- The read line if successful
- NULL if there is nothing else to read or if an error occurred

## Author
- Rania (radaoudi)

## License
This project is part of the 42 school curriculum. Please refer to 42's policies regarding code usage and distribution.

## Acknowledgments
- 42 school for providing the project requirements and framework
- The system functions documentation for file manipulation
