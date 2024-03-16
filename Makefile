LIBFT	= libft/libft.a
CLIENT	= client
SERVER	= server
CLIENTB = client_bonus
SERVERB = server_bonus
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
AR		= ar rcs

SRC_S	= server.c
SRC_C	= client.c

SRCB_S	= server_bonus.c
SRCB_C	= client_bonus.c

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C ./libft

$(SERVER):
	$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) -o server

$(CLIENT):
	$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) -o client

bonus:
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRCB_S) $(LIBFT) -o server_bonus
	$(CC) $(CFLAGS) $(SRCB_C) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./libft
	$(RM) client server client_bonus server_bonus

fclean: clean
	$(MAKE) fclean -C ./libft

re: fclean all
