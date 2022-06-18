CFLAGS = -Wall -Werror -Wextra

CLIENT = client
SERVER = server

COMMON_FILES = ft_atoi.c ft_putnbr_fd.c
SRC_CLIENT = $(COMMON_FILES) client.c
SRC_SERVER = $(COMMON_FILES) server.c
COBJ = $(SRC_CLIENT:%.c=%.o)
SOBJ = $(SRC_SERVER:%.c=%.o)

all : $(SERVER) $(CLIENT)

$(SERVER): $(SOBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Compiling server"

$(CLIENT) : $(COBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Compiling client"

%.o : %.c minitalk.h
	@$(CC) $(CFLAGS) $^ -c
	@echo "Compiling $^"

clean:
	@rm -rf *.o *.gch
	@echo "Cleaning..."

fclean : clean
	@rm -rf $(SERVER) $(CLIENT)
	@echo "Full cleaning..."

re : fclean all
	@echo "Remaking"
