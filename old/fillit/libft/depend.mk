O_FILES :=	o/srcs/endianness.o o/srcs/ft_abs.o o/srcs/ft_arg.o \
			o/srcs/ft_containers_conversions.o o/srcs/ft_ctype/case_change.o \
			o/srcs/ft_ctype/ft_isalnum.o o/srcs/ft_ctype/ft_isalpha.o \
			o/srcs/ft_ctype/ft_isascii.o o/srcs/ft_ctype/ft_isblank.o \
			o/srcs/ft_ctype/ft_iscntrl.o o/srcs/ft_ctype/ft_isdigit.o \
			o/srcs/ft_ctype/ft_isdigit_base.o o/srcs/ft_ctype/ft_isescape.o \
			o/srcs/ft_ctype/ft_isgraph.o o/srcs/ft_ctype/ft_islower.o \
			o/srcs/ft_ctype/ft_isprint.o o/srcs/ft_ctype/ft_ispunct.o \
			o/srcs/ft_ctype/ft_isspace.o o/srcs/ft_ctype/ft_isunixspace.o \
			o/srcs/ft_ctype/ft_isupper.o o/srcs/ft_ctype/ft_isxdigit.o \
			o/srcs/ft_debug/ft_leaks.o o/srcs/ft_debug/ft_printt.o \
			o/srcs/ft_debug/ft_printt_utility.o o/srcs/ft_debug/ft_printvar.o \
			o/srcs/ft_debug/lprintf.o o/srcs/ft_debug/qprintf.o \
			o/srcs/ft_list/ftl_conversions.o o/srcs/ft_list/ftl_destruction.o \
			o/srcs/ft_list/ftl_foreach.o o/srcs/ft_list/ftl_init.o \
			o/srcs/ft_list/ftl_insertions.o o/srcs/ft_list/ftl_splice.o \
			o/srcs/ft_max.o o/srcs/ft_min.o o/srcs/ft_parseuinteger.o \
			o/srcs/ft_printf/add_color_flags.o \
			o/srcs/ft_printf/add_color_tags.o o/srcs/ft_printf/build_bonuses.o \
			o/srcs/ft_printf/build_chars_and_strings.o \
			o/srcs/ft_printf/build_dec_float.o \
			o/srcs/ft_printf/build_dec_float_nbr.o \
			o/srcs/ft_printf/build_dependencies.o \
			o/srcs/ft_printf/build_integers.o \
			o/srcs/ft_printf/build_nonprintable_string.o \
			o/srcs/ft_printf/build_nonprintable_string_deps.o \
			o/srcs/ft_printf/build_uppercases.o \
			o/srcs/ft_printf/build_uppercases2.o \
			o/srcs/ft_printf/build_wchars_and_wstrings.o \
			o/srcs/ft_printf/calc_return_value.o o/srcs/ft_printf/freemem.o \
			o/srcs/ft_printf/ft_ceil.o o/srcs/ft_printf/ft_dbltype.o \
			o/srcs/ft_printf/ft_floor.o o/srcs/ft_printf/ft_getprintf.o \
			o/srcs/ft_printf/ft_log10.o o/srcs/ft_printf/ft_pad_string.o \
			o/srcs/ft_printf/ft_printf.o o/srcs/ft_printf/ft_roundup_b10.o \
			o/srcs/ft_printf/ft_vprintf.o o/srcs/ft_printf/get_varg.o \
			o/srcs/ft_printf/parse_format.o o/srcs/ft_printf/store_opt_1to5.o \
			o/srcs/ft_printf/store_opt_6to8.o o/srcs/ft_randf.o \
			o/srcs/ft_set/fts_balance.o o/srcs/ft_set/fts_balance_tools.o \
			o/srcs/ft_set/fts_citerations.o o/srcs/ft_set/fts_destruction.o \
			o/srcs/ft_set/fts_foreach.o o/srcs/ft_set/fts_init.o \
			o/srcs/ft_set/fts_insert.o o/srcs/ft_set/fts_insert_tools.o \
			o/srcs/ft_set/fts_iterations.o o/srcs/ft_skipntype.o \
			o/srcs/ft_skiptype.o o/srcs/ft_stdio/ft_putchar.o \
			o/srcs/ft_stdio/ft_putendl.o o/srcs/ft_stdio/ft_putnbr.o \
			o/srcs/ft_stdio/ft_putnbr_base.o o/srcs/ft_stdio/ft_putnchar.o \
			o/srcs/ft_stdio/ft_putstr.o o/srcs/ft_stdlib/ft_atoi.o \
			o/srcs/ft_stdlib/ft_atoi_base.o o/srcs/ft_stdlib/ft_crealloc.o \
			o/srcs/ft_stdlib/ft_itoa.o o/srcs/ft_stdlib/ft_itoa_a.o \
			o/srcs/ft_stdlib/ft_itoa_c.o o/srcs/ft_stdlib/ft_lutoa.o \
			o/srcs/ft_stdlib/ft_lutoa_a.o o/srcs/ft_stdlib/ft_maxintlen.o \
			o/srcs/ft_stdlib/ft_realloc.o o/srcs/ft_stdlib/ft_revstr.o \
			o/srcs/ft_stdlib/ft_utoa.o o/srcs/ft_string/ft_bzero.o \
			o/srcs/ft_string/ft_memalloc.o o/srcs/ft_string/ft_memccpy.o \
			o/srcs/ft_string/ft_memchr.o o/srcs/ft_string/ft_memcmp.o \
			o/srcs/ft_string/ft_memcpy.o o/srcs/ft_string/ft_memdel.o \
			o/srcs/ft_string/ft_memdup.o o/srcs/ft_string/ft_memmove.o \
			o/srcs/ft_string/ft_memset.o o/srcs/ft_string/ft_strcat.o \
			o/srcs/ft_string/ft_strccpy.o o/srcs/ft_string/ft_strcharlen.o \
			o/srcs/ft_string/ft_strchr.o o/srcs/ft_string/ft_strclr.o \
			o/srcs/ft_string/ft_strcmp.o o/srcs/ft_string/ft_strcpy.o \
			o/srcs/ft_string/ft_strcspn.o o/srcs/ft_string/ft_strdel.o \
			o/srcs/ft_string/ft_strdup.o o/srcs/ft_string/ft_strequ.o \
			o/srcs/ft_string/ft_strjoin.o o/srcs/ft_string/ft_strjoinfree.o \
			o/srcs/ft_string/ft_strlcat.o o/srcs/ft_string/ft_strlcpy.o \
			o/srcs/ft_string/ft_strlen.o o/srcs/ft_string/ft_strncat.o \
			o/srcs/ft_string/ft_strncmp.o o/srcs/ft_string/ft_strncpy.o \
			o/srcs/ft_string/ft_strnequ.o o/srcs/ft_string/ft_strnew.o \
			o/srcs/ft_string/ft_strnstr.o o/srcs/ft_string/ft_strrchr.o \
			o/srcs/ft_string/ft_strspn.o o/srcs/ft_string/ft_strstr.o \
			o/srcs/ft_strlentype.o o/srcs/ft_timeval.o \
			o/srcs/ft_vector/ftv_add.o o/srcs/ft_vector/ftv_capacity.o \
			o/srcs/ft_vector/ftv_data.o o/srcs/ft_vector/ftv_debug.o \
			o/srcs/ft_vector/ftv_debug_print.o \
			o/srcs/ft_vector/ftv_destruction.o o/srcs/ft_vector/ftv_find.o \
			o/srcs/ft_vector/ftv_foreach.o o/srcs/ft_vector/ftv_init.o \
			o/srcs/ft_vector/ftv_iteration.o o/srcs/fterror.o \
			o/srcs/ftstrerror.o o/srcs/get_next_line.o

LIBS_DEPEND := 

libs:
.PHONY: libs



MAX_SOURCE_LEN := 47
o/srcs/endianness.o: srcs/endianness.c | o/srcs/
o/srcs/ft_abs.o: srcs/ft_abs.c | o/srcs/
o/srcs/ft_arg.o: srcs/ft_arg.c include/ft_arg.h include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/
o/srcs/ft_containers_conversions.o: srcs/ft_containers_conversions.c \
	include/ft_containers.h include/ft_ctype.h include/ft_list.h \
	include/ft_macroes.h include/ft_set.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/ft_vector.h include/libft.h | o/srcs/
o/srcs/ft_ctype/case_change.o: srcs/ft_ctype/case_change.c | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isalnum.o: srcs/ft_ctype/ft_isalnum.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isalpha.o: srcs/ft_ctype/ft_isalpha.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isascii.o: srcs/ft_ctype/ft_isascii.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isblank.o: srcs/ft_ctype/ft_isblank.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_iscntrl.o: srcs/ft_ctype/ft_iscntrl.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isdigit.o: srcs/ft_ctype/ft_isdigit.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isdigit_base.o: srcs/ft_ctype/ft_isdigit_base.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isescape.o: srcs/ft_ctype/ft_isescape.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isgraph.o: srcs/ft_ctype/ft_isgraph.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_islower.o: srcs/ft_ctype/ft_islower.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isprint.o: srcs/ft_ctype/ft_isprint.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_ispunct.o: srcs/ft_ctype/ft_ispunct.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isspace.o: srcs/ft_ctype/ft_isspace.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isunixspace.o: srcs/ft_ctype/ft_isunixspace.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isupper.o: srcs/ft_ctype/ft_isupper.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_ctype/ft_isxdigit.o: srcs/ft_ctype/ft_isxdigit.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_ctype/
o/srcs/ft_debug/ft_leaks.o: srcs/ft_debug/ft_leaks.c include/ft_ctype.h \
	include/ft_debug.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/ft_vector.h include/libft.h | o/srcs/ft_debug/
o/srcs/ft_debug/ft_printt.o: srcs/ft_debug/ft_printt.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	include/ft_debug.h include/ft_vector.h | o/srcs/ft_debug/
o/srcs/ft_debug/ft_printt_utility.o: srcs/ft_debug/ft_printt_utility.c \
	include/ft_ctype.h include/ft_debug.h include/ft_macroes.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/ft_vector.h include/libft.h | o/srcs/ft_debug/
o/srcs/ft_debug/ft_printvar.o: srcs/ft_debug/ft_printvar.c include/ft_ctype.h \
	include/ft_debug.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/ft_vector.h include/libft.h | o/srcs/ft_debug/
o/srcs/ft_debug/lprintf.o: srcs/ft_debug/lprintf.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_debug/
o/srcs/ft_debug/qprintf.o: srcs/ft_debug/qprintf.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_debug/
o/srcs/ft_list/ftl_conversions.o: srcs/ft_list/ftl_conversions.c \
	include/ft_ctype.h include/ft_list.h include/ft_macroes.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_list/
o/srcs/ft_list/ftl_destruction.o: srcs/ft_list/ftl_destruction.c \
	include/ft_ctype.h include/ft_list.h include/ft_macroes.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_list/
o/srcs/ft_list/ftl_foreach.o: srcs/ft_list/ftl_foreach.c include/ft_ctype.h \
	include/ft_list.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_list/
o/srcs/ft_list/ftl_init.o: srcs/ft_list/ftl_init.c include/ft_ctype.h \
	include/ft_list.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_list/
o/srcs/ft_list/ftl_insertions.o: srcs/ft_list/ftl_insertions.c \
	include/ft_ctype.h include/ft_list.h include/ft_macroes.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_list/
o/srcs/ft_list/ftl_splice.o: srcs/ft_list/ftl_splice.c include/ft_ctype.h \
	include/ft_list.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h include/fterror.h | o/srcs/ft_list/
o/srcs/ft_max.o: srcs/ft_max.c | o/srcs/
o/srcs/ft_min.o: srcs/ft_min.c | o/srcs/
o/srcs/ft_parseuinteger.o: srcs/ft_parseuinteger.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/
o/srcs/ft_printf/add_color_flags.o: srcs/ft_printf/add_color_flags.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/add_color_tags.o: srcs/ft_printf/add_color_tags.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/build_bonuses.o: srcs/ft_printf/build_bonuses.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/build_chars_and_strings.o: \
	srcs/ft_printf/build_chars_and_strings.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_printf.h include/ft_printfdefs.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_printf/
o/srcs/ft_printf/build_dec_float.o: srcs/ft_printf/build_dec_float.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/build_dec_float_nbr.o: srcs/ft_printf/build_dec_float_nbr.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/build_dependencies.o: srcs/ft_printf/build_dependencies.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/build_integers.o: srcs/ft_printf/build_integers.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/build_nonprintable_string.o: \
	srcs/ft_printf/build_nonprintable_string.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_printf.h include/ft_printfdefs.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_printf/
o/srcs/ft_printf/build_nonprintable_string_deps.o: \
	srcs/ft_printf/build_nonprintable_string_deps.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_printf.h include/ft_printfdefs.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_printf/
o/srcs/ft_printf/build_uppercases.o: srcs/ft_printf/build_uppercases.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/build_uppercases2.o: srcs/ft_printf/build_uppercases2.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/build_wchars_and_wstrings.o: \
	srcs/ft_printf/build_wchars_and_wstrings.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_printf.h include/ft_printfdefs.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_printf/
o/srcs/ft_printf/calc_return_value.o: srcs/ft_printf/calc_return_value.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/freemem.o: srcs/ft_printf/freemem.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_printf.h include/ft_printfdefs.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_printf/
o/srcs/ft_printf/ft_ceil.o: srcs/ft_printf/ft_ceil.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	include/ft_printf.h include/ft_printfdefs.h | o/srcs/ft_printf/
o/srcs/ft_printf/ft_dbltype.o: srcs/ft_printf/ft_dbltype.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	include/ft_dbltype.h | o/srcs/ft_printf/
o/srcs/ft_printf/ft_floor.o: srcs/ft_printf/ft_floor.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	include/ft_printf.h include/ft_printfdefs.h | o/srcs/ft_printf/
o/srcs/ft_printf/ft_getprintf.o: srcs/ft_printf/ft_getprintf.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/ft_log10.o: srcs/ft_printf/ft_log10.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	include/ft_printf.h include/ft_printfdefs.h include/ft_dbltype.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/ft_pad_string.o: srcs/ft_printf/ft_pad_string.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_printf/
o/srcs/ft_printf/ft_printf.o: srcs/ft_printf/ft_printf.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_printf.h include/ft_printfdefs.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_printf/
o/srcs/ft_printf/ft_roundup_b10.o: srcs/ft_printf/ft_roundup_b10.c \
	| o/srcs/ft_printf/
o/srcs/ft_printf/ft_vprintf.o: srcs/ft_printf/ft_vprintf.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_printf.h include/ft_printfdefs.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_printf/
o/srcs/ft_printf/get_varg.o: srcs/ft_printf/get_varg.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_printf.h include/ft_printfdefs.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_printf/
o/srcs/ft_printf/parse_format.o: srcs/ft_printf/parse_format.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/store_opt_1to5.o: srcs/ft_printf/store_opt_1to5.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_printf/store_opt_6to8.o: srcs/ft_printf/store_opt_6to8.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_printf.h \
	include/ft_printfdefs.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_printf/
o/srcs/ft_randf.o: srcs/ft_randf.c | o/srcs/
o/srcs/ft_set/fts_balance.o: srcs/ft_set/fts_balance.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_set.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_set/
o/srcs/ft_set/fts_balance_tools.o: srcs/ft_set/fts_balance_tools.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_set.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_set/
o/srcs/ft_set/fts_citerations.o: srcs/ft_set/fts_citerations.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_set.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_set/
o/srcs/ft_set/fts_destruction.o: srcs/ft_set/fts_destruction.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_set.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_set/
o/srcs/ft_set/fts_foreach.o: srcs/ft_set/fts_foreach.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_set.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_set/
o/srcs/ft_set/fts_init.o: srcs/ft_set/fts_init.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_set.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_set/
o/srcs/ft_set/fts_insert.o: srcs/ft_set/fts_insert.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_set.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_set/
o/srcs/ft_set/fts_insert_tools.o: srcs/ft_set/fts_insert_tools.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_set.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_set/
o/srcs/ft_set/fts_iterations.o: srcs/ft_set/fts_iterations.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_set.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/ft_set/
o/srcs/ft_skipntype.o: srcs/ft_skipntype.c | o/srcs/
o/srcs/ft_skiptype.o: srcs/ft_skiptype.c | o/srcs/
o/srcs/ft_stdio/ft_putchar.o: srcs/ft_stdio/ft_putchar.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_stdio/
o/srcs/ft_stdio/ft_putendl.o: srcs/ft_stdio/ft_putendl.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_stdio/
o/srcs/ft_stdio/ft_putnbr.o: srcs/ft_stdio/ft_putnbr.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_stdio/
o/srcs/ft_stdio/ft_putnbr_base.o: srcs/ft_stdio/ft_putnbr_base.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_stdio/
o/srcs/ft_stdio/ft_putnchar.o: srcs/ft_stdio/ft_putnchar.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_stdio/
o/srcs/ft_stdio/ft_putstr.o: srcs/ft_stdio/ft_putstr.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h | o/srcs/ft_stdio/
o/srcs/ft_stdlib/ft_atoi.o: srcs/ft_stdlib/ft_atoi.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_atoi_base.o: srcs/ft_stdlib/ft_atoi_base.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_crealloc.o: srcs/ft_stdlib/ft_crealloc.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_itoa.o: srcs/ft_stdlib/ft_itoa.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_itoa_a.o: srcs/ft_stdlib/ft_itoa_a.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_itoa_c.o: srcs/ft_stdlib/ft_itoa_c.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_lutoa.o: srcs/ft_stdlib/ft_lutoa.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_lutoa_a.o: srcs/ft_stdlib/ft_lutoa_a.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_maxintlen.o: srcs/ft_stdlib/ft_maxintlen.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_realloc.o: srcs/ft_stdlib/ft_realloc.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_revstr.o: srcs/ft_stdlib/ft_revstr.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_stdlib/
o/srcs/ft_stdlib/ft_utoa.o: srcs/ft_stdlib/ft_utoa.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_stdlib/
o/srcs/ft_string/ft_bzero.o: srcs/ft_string/ft_bzero.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_memalloc.o: srcs/ft_string/ft_memalloc.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_string/
o/srcs/ft_string/ft_memccpy.o: srcs/ft_string/ft_memccpy.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_memchr.o: srcs/ft_string/ft_memchr.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_memcmp.o: srcs/ft_string/ft_memcmp.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_memcpy.o: srcs/ft_string/ft_memcpy.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_memdel.o: srcs/ft_string/ft_memdel.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_memdup.o: srcs/ft_string/ft_memdup.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_memmove.o: srcs/ft_string/ft_memmove.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_memset.o: srcs/ft_string/ft_memset.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strcat.o: srcs/ft_string/ft_strcat.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strccpy.o: srcs/ft_string/ft_strccpy.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strcharlen.o: srcs/ft_string/ft_strcharlen.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_string/
o/srcs/ft_string/ft_strchr.o: srcs/ft_string/ft_strchr.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strclr.o: srcs/ft_string/ft_strclr.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strcmp.o: srcs/ft_string/ft_strcmp.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strcpy.o: srcs/ft_string/ft_strcpy.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strcspn.o: srcs/ft_string/ft_strcspn.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strdel.o: srcs/ft_string/ft_strdel.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strdup.o: srcs/ft_string/ft_strdup.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strequ.o: srcs/ft_string/ft_strequ.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strjoin.o: srcs/ft_string/ft_strjoin.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strjoinfree.o: srcs/ft_string/ft_strjoinfree.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/ft_string/
o/srcs/ft_string/ft_strlcat.o: srcs/ft_string/ft_strlcat.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strlcpy.o: srcs/ft_string/ft_strlcpy.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strlen.o: srcs/ft_string/ft_strlen.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strncat.o: srcs/ft_string/ft_strncat.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strncmp.o: srcs/ft_string/ft_strncmp.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strncpy.o: srcs/ft_string/ft_strncpy.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strnequ.o: srcs/ft_string/ft_strnequ.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strnew.o: srcs/ft_string/ft_strnew.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strnstr.o: srcs/ft_string/ft_strnstr.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strrchr.o: srcs/ft_string/ft_strrchr.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strspn.o: srcs/ft_string/ft_strspn.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_string/ft_strstr.o: srcs/ft_string/ft_strstr.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/libft.h \
	| o/srcs/ft_string/
o/srcs/ft_strlentype.o: srcs/ft_strlentype.c | o/srcs/
o/srcs/ft_timeval.o: srcs/ft_timeval.c include/ft_timeval.h | o/srcs/
o/srcs/ft_vector/ftv_add.o: srcs/ft_vector/ftv_add.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/ft_vector.h \
	include/libft.h | o/srcs/ft_vector/
o/srcs/ft_vector/ftv_capacity.o: srcs/ft_vector/ftv_capacity.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/ft_vector.h include/libft.h | o/srcs/ft_vector/
o/srcs/ft_vector/ftv_data.o: srcs/ft_vector/ftv_data.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/ft_vector.h \
	include/libft.h | o/srcs/ft_vector/
o/srcs/ft_vector/ftv_debug.o: srcs/ft_vector/ftv_debug.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/ft_vector.h \
	include/libft.h include/ft_debug.h | o/srcs/ft_vector/
o/srcs/ft_vector/ftv_debug_print.o: srcs/ft_vector/ftv_debug_print.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/ft_vector.h include/libft.h include/ft_debug.h | o/srcs/ft_vector/
o/srcs/ft_vector/ftv_destruction.o: srcs/ft_vector/ftv_destruction.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/ft_vector.h include/libft.h | o/srcs/ft_vector/
o/srcs/ft_vector/ftv_find.o: srcs/ft_vector/ftv_find.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/ft_vector.h \
	include/libft.h | o/srcs/ft_vector/
o/srcs/ft_vector/ftv_foreach.o: srcs/ft_vector/ftv_foreach.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/ft_vector.h include/libft.h | o/srcs/ft_vector/
o/srcs/ft_vector/ftv_init.o: srcs/ft_vector/ftv_init.c include/ft_ctype.h \
	include/ft_macroes.h include/ft_stdio.h include/ft_stdlib.h \
	include/ft_string.h include/ft_typedefs.h include/ft_vector.h \
	include/libft.h | o/srcs/ft_vector/
o/srcs/ft_vector/ftv_iteration.o: srcs/ft_vector/ftv_iteration.c \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/ft_vector.h include/libft.h | o/srcs/ft_vector/
o/srcs/fterror.o: srcs/fterror.c include/ft_ctype.h include/ft_macroes.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h include/fterror.h | o/srcs/
o/srcs/ftstrerror.o: srcs/ftstrerror.c include/ft_ctype.h include/ft_macroes.h \
	include/ft_stdio.h include/ft_stdlib.h include/ft_string.h \
	include/ft_typedefs.h include/libft.h | o/srcs/
o/srcs/get_next_line.o: srcs/get_next_line.c include/get_next_line.h \
	include/ft_ctype.h include/ft_macroes.h include/ft_stdio.h \
	include/ft_stdlib.h include/ft_string.h include/ft_typedefs.h \
	include/libft.h | o/srcs/
