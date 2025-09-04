ASM=nasm

NAME=libasm.a
OBJ_DIR=obj/
SRC_DIR=src/

SRCS= $(addprefix $(SRC_DIR), ft_strlen.s ft_write.s ft_strcpy.s ft_strcmp.s ft_read.s)
OBJS= $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(SRCS))

ASMFLAGS=-f elf64

$(OBJ_DIR)%.o: $(SRC_DIR)%.s
	@mkdir -p $(dir $@)
	$(ASM) $(ASMFLAGS) $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re