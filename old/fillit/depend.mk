O_FILES :=	obj/srcs/main.o obj/srcs/parse.o obj/srcs/solve.o \
			obj/srcs/solve128.o obj/srcs/solve128_plus.o obj/srcs/solve64.o \
			obj/srcs/solveptr.o

LIBS_DEPEND := libft/libft.a

libs:
	make -C libft
.PHONY: libs



MAX_SOURCE_LEN := 20
obj/srcs/main.o: srcs/main.c include/fillit.h libft/include/ft_ctype.h \
	libft/include/ft_macroes.h libft/include/ft_stdio.h \
	libft/include/ft_stdlib.h libft/include/ft_string.h \
	libft/include/ft_typedefs.h libft/include/libft.h | obj/srcs/
obj/srcs/parse.o: srcs/parse.c include/fillit.h libft/include/ft_ctype.h \
	libft/include/ft_macroes.h libft/include/ft_stdio.h \
	libft/include/ft_stdlib.h libft/include/ft_string.h \
	libft/include/ft_typedefs.h libft/include/libft.h | obj/srcs/
obj/srcs/solve.o: srcs/solve.c include/fillit.h libft/include/ft_ctype.h \
	libft/include/ft_macroes.h libft/include/ft_stdio.h \
	libft/include/ft_stdlib.h libft/include/ft_string.h \
	libft/include/ft_typedefs.h libft/include/libft.h | obj/srcs/
obj/srcs/solve128.o: srcs/solve128.c include/fillit.h libft/include/ft_ctype.h \
	libft/include/ft_macroes.h libft/include/ft_stdio.h \
	libft/include/ft_stdlib.h libft/include/ft_string.h \
	libft/include/ft_typedefs.h libft/include/libft.h | obj/srcs/
obj/srcs/solve128_plus.o: srcs/solve128_plus.c include/fillit.h \
	libft/include/ft_ctype.h libft/include/ft_macroes.h \
	libft/include/ft_stdio.h libft/include/ft_stdlib.h \
	libft/include/ft_string.h libft/include/ft_typedefs.h \
	libft/include/libft.h | obj/srcs/
obj/srcs/solve64.o: srcs/solve64.c include/fillit.h libft/include/ft_ctype.h \
	libft/include/ft_macroes.h libft/include/ft_stdio.h \
	libft/include/ft_stdlib.h libft/include/ft_string.h \
	libft/include/ft_typedefs.h libft/include/libft.h | obj/srcs/
obj/srcs/solveptr.o: srcs/solveptr.c include/fillit.h libft/include/ft_ctype.h \
	libft/include/ft_macroes.h libft/include/ft_stdio.h \
	libft/include/ft_stdlib.h libft/include/ft_string.h \
	libft/include/ft_typedefs.h libft/include/libft.h | obj/srcs/
