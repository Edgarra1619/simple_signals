NAME1 = server
NAME2 = client
SRCS1 = server.c
SRCS2 = client.c
SRCS = $(SRCS1) $(SRCS2)
BONUS = 0
OPTFLAG = 0
SRCDIR = ./srcs/
OBJDIR = ./objs/
LIBFT = ./libft/
CC = clang
INCFLAGS = -I ./includes/ -I $(LIBFT)
CFLAGS = -Wall -Wextra -gdwarf-4 -O$(OPTFLAG)
OBJS1 = $(patsubst %.c, $(OBJDIR)%.o, $(SRCS1))
OBJS2 = $(patsubst %.c, $(OBJDIR)%.o, $(SRCS2))
OBJS = $(OBJS1) $(OBJS2)

ifeq ($(BONUS), 1)
CFLAGS += -D BONUS
SRCS += 
endif

all: $(NAME1) $(NAME2)

bonus:
	make BONUS=1

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME1) $(NAME2)

re: clean all

$(NAME1): $(OBJS1) $(LIBFT)libft.a
	$(CC) $(CFLAGS) $(OBJS1) $(LIBFT)libft.a $(INCFLAGS) -o $@

$(NAME2): $(OBJS2) $(LIBFT)libft.a
	$(CC) $(CFLAGS) $(OBJS2) $(LIBFT)libft.a $(INCFLAGS) -o $@

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCFLAGS) $^ -c -o $@

$(LIBFT)libft.a:
	make -C $(LIBFT)

test: $(NAME2)
	./$(NAME2) $(TESTARGS)

valgrind: $(NAME1)
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME1) $(TESTARGS)

gdb: $(NAME1)
	gdbtui --args $(NAME1) $(TESTARGS)
