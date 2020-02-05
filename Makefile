COMPILER = clang -g
PROG_NAME = http
EXECUTABLE = http_client

SOURCE = $(wildcard ./*.c)
OBJECTS = $(SOURCE:.c=.o)

all: $(EXECUTABLE)
	@echo "\033[92m[$(EXECUTABLE) done]\033[0m"

$(EXECUTABLE): $(OBJECTS)
	@$(COMPILER) $(SOURCE) -o $@
	@echo "\033[92m[Target $(EXECUTABLE) Has been created, run ./$@]\033[0m"
	@echo "\033[92m[Starting $(EXECUTABLE) ...]\033[0m"

%.o: %.c
	@echo "Compiling $@"
	@$(COMPILER) -c $< -o $@


clean:
	@echo "Deleting all binaries and object files"
	@rm -rf $(OBJECTS) $(EXECUTABLE)

re: clean all
