#ifndef MACROS_H
# define MACROS_H

# define ISNEWLINE(c) (c == '\n')
# define ISNUMBER(c) (c >= '0' && c <= '9')
# define IS_2_DIFF(a,b) (a != b)
# define IS_3_DIFF(a,b,c) (IS_2_DIFF(a,b) && IS_2_DIFF(b,c) && IS_2_DIFF(a,c))
# define MIN_2(a,b) ((a > b) ? b : a)
# define MIN_3(a,b,c) (MIN_2(MIN_2(a,b), c)

#endif
