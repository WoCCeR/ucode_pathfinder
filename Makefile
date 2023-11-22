NAME	=	pathfinder

CC 	= 	clang
CFLAGS	=	-std=c11 -Wall -Wextra -Werror -Wpedantic

SRCDIR	=	src
INCDIR	=	inc
OBJDIR	=	obj

LMXDIR	=	libmx
LMXA:=	$(LMXDIR)/libmx.a
LMXINC:=	$(LMXDIR)/inc

INC		=	pathfinder.h
INCS	=	$(addprefix $(INCDIR)/, $(INC))

SRCS	=	$(wildcard $(SRCDIR)/*.c)
OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))


all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LMXDIR) -lmx -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR) -I$(LMXINC)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXDIR)

clean:
	@make -sC $(LMXDIR) $@
	@rm -rf $(OBJDIR)

uninstall: clean
	@make -sC $(LMXDIR) $@
	@rm -rf $(NAME)

reinstall: uninstall install

start: install
	./$(NAME) test/test