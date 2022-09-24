CFLAGS=-g -Wall -Wextra $$(pkg-config --cflags gtk4)
LDFLAGS=$$(pkg-config --libs gtk4)
CC=gcc

hydra: hydra.c
	$(CC) $(CFLAGS) -o hydra test.c $(LDFLAGS)
