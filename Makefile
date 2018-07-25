SOURCES			=	src/error.c \
					src/free_objects.c \
					src/ft_putchar.c \
					src/ft_putnbr.c \
					src/ft_putstr.c \
					src/ft_strlen.c \
					src/grid_lines.c \
					src/read_description.c \
					src/read_map.c \
					src/read_map_line.c

OBJECTS			=	$(SOURCES:.c=.o)

CC				= 	gcc

CFLAGS			=	-g -Wall -Werror -Wextra

CPFLAGS			=	-I./include


#TEST_SRCS		=	./test/test_read_description.c
TEST_SRCS		=	./test/test_read_map.c

TEST_OBJS		=	$(TEST_SRCS:.c=.o)

TEST_BINS		=	$(TEST_SRCS:.c=)


all:			$(TEST_BINS)

$(TEST_BINS):	$(OBJECTS) $(TEST_OBJS)
				$(CC) $(CFLAGS) $(CPFLAGS) -o $@ $^

%.o:			%.c
				$(CC) $(CFLAGS) $(CPFLAGS) -o $@ -c $<
		
clean:
				rm -f *.o */*.o

fclean: 		clean
				rm -f $(TEST_BINS)

re:				fclean all
