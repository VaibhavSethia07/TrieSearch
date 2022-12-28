CC = g++
default: trie_search clean
trie_search: trie_search.o
	$(CC) -o trie_search trie_search.o
trie_search.o: trie_search.cpp trie_search.h
	$(CC) -c trie_search.cpp
clean:
	rm *.o