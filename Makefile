#			LIBOX
#
NAME		:=	bin/libox.a
MAKEFLAGS	+=	-s
#
#			DIRECTORIES
#
BDIR		:=	bin/
SDIR		:=	src/
ODIR		:=	.obj/
TDIR		:=	test/
IDIR		:=	include/
#
#			LIBFT
#
FTDIR		:=	libft/
FTFSRC		:=	$(shell find $(SDIR)$(FTDIR)*.c)
FTSRC		:=	$(call FTFSRC)
FTOBJ		:=	${FTSRC:.c=.o}
FTOBJP		:=	$(subst $(SDIR),$(ODIR),$(FTOBJ))
#
#			LIBUI
#
UIDIR		:=	libui/
UIFSRC		:=	$(shell find $(SDIR)$(UIDIR)*.c)
UISRC		:=	$(call UIFSRC)
UIOBJ		:=	${UISRC:.c=.o}
UIOBJP		:=	$(subst $(SDIR),$(ODIR),$(UIOBJ))
#
#			COMPILATION
#
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
#
$(ODIR)%.o	: $(SDIR)%.c
			mkdir -p $(BDIR) $(subst $(SDIR),$(ODIR),$(shell dirname $<)/)
			$(CC) $(CFLAGS) -c $< -o ${addprefix $(ODIR),${<:$(SDIR)%.c=%.o}}
			ar rc $(NAME) ${addprefix $(ODIR),${<:$(SDIR)%.c=%.o}}
			ranlib $(NAME)
#
#			RULES
#
$(NAME)		: $(FTOBJP) $(UIOBJP)
#
all			: $(NAME)
libft		: $(FTOBJP)
libui		: $(UIOBJP)
#
clean		:
			rm -rf $(ODIR)
fclean		: clean
			rm -rf $(NAME)
re			: clean all
#
ft_test		: libft
			mkdir -p $(BDIR)
			$(CC) $(TDIR)$@.c $(NAME) -o $(BDIR)$@
ui_test		: libui
			mkdir -p $(BDIR)
			$(CC) $(TDIR)$@.c $(NAME) -o $(BDIR)$@
#
.DEFAULT	:
			echo $@ ignored
.PHONY		: all libft libui all clean fclean re ft_test ui_test
