CC = g++
default: trie_search clean
trie_search: trie_search.o
	$(CC) -o trie_search trie_search.o
read_input.o: read_input.cpp ReadInput.h
	$(CC) -c read_input.cpp
trie_search.o: trie_search.cpp TrieSearch.h
	$(CC) -c trie_search.cpp
clean:
	rm *.o