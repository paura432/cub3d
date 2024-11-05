# Libft

**Libft** is a personal C library designed to provide custom implementations of various standard C functions and additional utilities. This library helps with learning and practicing C programming, especially focusing on string manipulation, memory management, and linked list operations.

## Components

The library includes implementations for:

### String Manipulation
- `ft_atoi.c`: Converts a string to an integer.
- `ft_strdup.c`: Duplicates a string.
- `ft_strchr.c`: Locates the first occurrence of a character in a string.
- `ft_strjoin.c`: Joins two strings into a new string.
- `ft_strlcat.c`: Concatenates strings with a size limit.
- `ft_strlcpy.c`: Copies strings with a size limit.
- `ft_strlen.c`: Calculates the length of a string.
- `ft_strnstr.c`: Finds a substring in a string.
- `ft_strtrim.c`: Trims characters from the start and end of a string.
- `ft_substr.c`: Extracts a substring from a string.

### Memory Management
- `ft_bzero.c`: Sets a block of memory to zero.
- `ft_calloc.c`: Allocates memory and initializes it to zero.
- `ft_memchr.c`: Searches for a character in a block of memory.
- `ft_memcmp.c`: Compares two blocks of memory.
- `ft_memcpy.c`: Copies a block of memory.
- `ft_memmove.c`: Moves a block of memory.
- `ft_memset.c`: Fills a block of memory with a specific value.

### Linked Lists
- `ft_lstadd_back_bonus.c`: Adds a node to the end of a list.
- `ft_lstadd_front_bonus.c`: Adds a node to the front of a list.
- `ft_lstclear_bonus.c`: Clears all nodes from the list.
- `ft_lstdelone_bonus.c`: Deletes a specific node.
- `ft_lstiter_bonus.c`: Iterates over a list and applies a function.
- `ft_lstlast_bonus.c`: Gets the last node of the list.
- `ft_lstmap_bonus.c`: Maps a function to each node in the list.
- `ft_lstnew_bonus.c`: Creates a new list node.
- `ft_lstsize_bonus.c`: Returns the number of nodes in the list.

### File Descriptors
- `ft_putchar_fd.c`: Writes a character to a file descriptor.
- `ft_putendl_fd.c`: Writes a string followed by a newline to a file descriptor.
- `ft_putnbr_fd.c`: Writes an integer to a file descriptor.
- `ft_putstr_fd.c`: Writes a string to a file descriptor.

### Other
- `ft_isalnum.c`: Checks if a character is alphanumeric.
- `ft_isalpha.c`: Checks if a character is alphabetic.
- `ft_isascii.c`: Checks if a character is ASCII.
- `ft_isdigit.c`: Checks if a character is a digit.
- `ft_isprint.c`: Checks if a character is printable.
- `ft_itoa.c`: Converts an integer to a string.
- `ft_split.c`: Splits a string into an array of substrings.
- `ft_striteri.c`: Applies a function to each character in a string with its index.
- `ft_strmapi.c`: Applies a function to each character in a string and creates a new string.

## Installation

To integrate **Libft** into your project:

### Clone the Repository

```bash
git@github.com:paura432/libft.git
