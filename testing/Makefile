# Makefile

CC = gcc
CFLAGS = -lncurses
COMMON_SOURCES = common/game_manager.c common/maze_game.c common/obstacle_game.c common/puzzle_game.c common/pattern_game.c
SERVER_SOURCES = game_server/server.c $(COMMON_SOURCES)
CLIENT_SOURCES = game_client/client.c $(COMMON_SOURCES)
SERVER_EXECUTABLE = server
CLIENT_EXECUTABLE = client

# 기본 타겟
all: $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE)

# 서버 실행 파일 생성
$(SERVER_EXECUTABLE): $(SERVER_SOURCES)
	$(CC) -o $@ $^

# 클라이언트 실행 파일 생성
$(CLIENT_EXECUTABLE): $(CLIENT_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS)

# 클린 타겟
clean:
	rm -f $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE)

.PHONY: all clean
