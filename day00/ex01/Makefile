CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = phonebook

HEADERS = phonebook.hpp
SOURCES = phonebook.cpp	\
	  addContact.cpp \
	  showPhonebook.cpp \
	  main.cpp

OBJECT = $(SOURCES:.cpp=.o)
all: $(NAME)

%.o: %.cpp %.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) -o $(NAME)

clean:
	rm -rf $(OBJECT)
fclean: clean
	rm -fr $(NAME)
re: fclean all
