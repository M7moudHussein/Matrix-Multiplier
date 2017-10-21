all:
	gcc -pthread -o multiply main.c file_manager.c model.c multiply.c

clean: 
	rm -r multiply
	rm -r c.out
