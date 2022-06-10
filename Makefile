SRC = main.cpp
$(eval SRC = $(addprefix src/, $(SRC)))

CLASS = object.cpp \
		game.cpp
$(eval CLASS = $(addprefix class/, $(CLASS)))

OBJ	=	$(SRC:.cpp=.o) \
		$(CLASS:.cpp=.o)

%.o: %.cpp
	g++ -c -o $@ $< $(LDFLAGS) $(CPPFLAGS)

NAME = minesweeper

CPPFLAGS = -I./class

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

$(NAME): $(OBJ)
	g++ -o $@ $^ $(LDFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

debug: CPPFLAGS += -g3
debug: re
