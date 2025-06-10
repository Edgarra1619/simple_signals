NAME = libft.a
SOURCES = ft_bsdstr.c ft_istests.c ft_iter.c ft_mem.c ft_memcheck.c ft_newstr.c \
		 ft_putfd.c ft_splitrim.c ft_stdlib.c ft_string.c ft_to.c
SOURCES += ft_lstadd_bonus.c ft_lstdel_bonus.c ft_lstutils_bonus.c
SRCSDIR = ./
INCLUDEDIR = ./
OBJDIR = ./
ARFLAGS = rc

CC = clang
CFLAGS = -Wall -Wextra -Werror -gdwarf-4 -I $(INCLUDEDIR)

OBJECTS = $(patsubst %.c, $(OBJDIR)%.o, $(SOURCES))
BONUSOBJS = $(patsubst %.c, $(OBJDIR)%.o, $(BONUSSRCS))
.PHONY: all clean fclean re

all: $(NAME)

clean:
	@echo "Clean"
	@$(RM) $(OBJECTS)

fclean:
	@echo "Full Clean"
	@$(RM) $(OBJECTS) -f
	@$(RM) $(BONUSOBJS) -f
	@$(RM) $(NAME)

re: fclean all

$(filter-out %.a, $(NAME)): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

$(filter %.a, $(NAME)): $(OBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

$(BONUSOBJS) $(OBJECTS): $(OBJDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $^ -c -o $@

bonus: $(BONUSOBJS)
	$(AR) $(ARFLAGS) $(NAME) $(BONUSOBJS)

