/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:39:56 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/02 14:09:55 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}	t_node;

typedef struct s_list_gnl
{
	t_node	*current;
	t_node	*appender;
}	t_list_gnl;

char			*get_next_line(int fd);
void			ft_new_node_gnl(t_list_gnl *list, char *buffer, int bytes_read);
int				ft_read_to_list(int fd, t_list_gnl *list);
void			ft_free_list(t_list_gnl *list);
char			*ft_make_line(t_list_gnl *list);
void			ft_clean_list(t_list_gnl *list);
char			*ft_copy_line(t_list_gnl *list, char *line);
char			*ft_strdup_from(char *src);
unsigned long	ft_strlen(const char *s);
int				ft_printf(const char *s, ...);
int				ft_putnbr_base(uintptr_t nb, char *base);
int				ft_putnbr(int x);
int				ft_putstr(char *s);
void			ft_lstiter(t_list *lst, void ( *f)(void *));
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
//void ft_lstiter(t_list *lst, void (*f)(void *));
//t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void			ft_putchar_fd(char c, int fd);
int				ft_putchar(int c);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/**
 * @brief Applies function 'f' to each character of string 's' IN-PLACE.
 * @param s The string to iterate over.
 * @param f The function to apply (receives index and address of char).
 * @note  Use this to MUTATE the original string without extra memory allocation.
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Creates a NEW string by applying 'f' to each character of 's'.
 * @param s The string to iterate over.
 * @param f The function to apply (receives index and character value).
 * @return A fresh, MALLOC'D string with the results. NULL if allocation fails.
 * @note  The original string 's' remains untouched (Safe/Immutable).
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Converts an integer to a null-terminated string (ASCII).
 * @param n The integer to convert (handles negative numbers and INT_MIN).
 * @return A MALLOC'D string representing the integer.
 * @note  The 'Surgical' way to turn sensor data into printable text.
 */
char			*ft_itoa(int n);

/**
 * @brief Splits string 's' into an array of strings using 'c' as a delimiter.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return A NULL-TERMINATED array of MALLOC'D strings.
 * @note  Think of this as an 'Array of Words' from a raw data packet.
 */
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Concatenates 's1' and 's2' into a brand new string.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return A NEW MALLOC'D string containing (s1 + s2).
 * @note  Combines two data fragments into one logical frame.
 */
char			*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Extracts a substring from string 's'.
 * @param s The source string.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return A NEW MALLOC'D string containing the specified range.
 * @note  Like a 'Surgical' slice of a data stream.
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief converts the initial portion of the string pointed to by nptr to int
	 @param nptr string containing a digit
	 @return int value (handles INT_MAX INT_MIN)     
 */
int				ft_atoi(const char *nptr);

/**
 * @brief returns a pointer to a new string which is a duplicate of the string s
 * @param s string to copy to heap
 * @return pointer to the string created.NULL on fail.
 */
char			*ft_strdup(const char *s);
void			*ft_calloc( size_t num, size_t size );
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Copies characters from the object pointed to by src into dst
 * @param dst	pointer to the memory location to copy to
 * @param src 	pointer to the memory location to copy from
 * @param size number of bytes to copy ( + 1 for null )
 * @return returns size of characters (attempted) to copy
*/
size_t			ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Copies count characters from the object pointed to by src to dest
 * @param dest	pointer to the memory location to copy to
 * @param src 	pointer to the memory location to copy from
 * @param count number of bytes to copy
*/
void			*ft_memmove( void *dest, const void *src, size_t count );
int				ft_memcmp( const void *lhs, const void *rhs, size_t count );
void			*ft_memcpy( void *dest, const void *src, size_t count );
void			*ft_memchr( const void *ptr, int ch, size_t count );

/**
 * @brief check n number of characters in two strings for equality
 * @param lhs pointer to first string
 * @param rhs pointer to second string
 * @param count number of characters to check
 */
int				ft_strncmp( const char *lhs, const char *rhs, size_t count );
char			*ft_strrchr( const char *str, int ch );
/**
 * @brief find the first occurrence of a character in a null-terminated string.
 * @param str a null-terminated string.
 * @param ch character to search for.
 * @return memory address of the character in the string, or NULL if not found.
 */
char			*ft_strchr( const char *str, int ch );
/**
 * @brief checks if a given character is within ascii printable range or not.
 * @param c The character (as an ascii int) to check.
 * @return Not 0 if printable.
 */
int				ft_isprint(int c);

/**
 * @brief (Deprecated) Fills a given n pointer locations with zero bytes '\0'. 
 * @param s The pointer to the memory area to be zeroed.
 * @param n The number of bytes to set to zero.
 * @return Nothing.
 */
void			ft_bzero(void *s, size_t n);

/**
 * @brief Checks if a character is a digit (0 through 9).
 * @param c The character (as an ascii int) to check.
 * @return Non-zero if c is a digit, 0 otherwise.
 */
int				ft_isdigit(int c);

/**
 * @brief Checks if a character is an alphabet letter (a:z or A:Z).
 * @param c The character (as an ascii int) to check.
 * @return Non-zero if c is an alphabet, 0 otherwise.
 */
int				ft_isalpha(int c);

/**
 * @brief Checks if a character is alphanumeric (letter or digit).
 * @param c The character (as an ascii int) to check.
 * @return Non-zero if true, 0 if false.
 */
int				ft_isalnum(int c);

/**
 * @brief Converts a lowercase letter to uppercase.
 * @param c The character (as an ascii int) to convert.
 * @return The converted uppercase character, or c if it wasn't lowercase.
 */
int				ft_toupper(int c);

/**
 * @brief Converts a uppercase letter to lowercase.
 * @param c The character (as an ascii int) to convert.
 * @return The converted lowercase character, or c if it wasn't uppercase.
 */
int				ft_tolower(int c);

/**
 * @brief Checks if a character is a member of the standard ASCII set.
 * @param c The character (as an ascii int) to check.
 * @return 1 if c is between 0 and 127, 0 otherwise.
 */
int				ft_isascii(int c);
void			*ft_memset(void *dest, int c, size_t count);

/**
 * @brief Calculates the length of a string.
 * @param ptr Pointer to a null-terminated string.
 * @return string length (Excluding '\0' ).
 */
size_t			ft_strlen(const char *ptr);
#endif
