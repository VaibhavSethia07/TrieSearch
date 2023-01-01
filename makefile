CC = g++
default: trie_search clean
trie_search: trie_search.o read_input.o storage.o trie.o word_freq.o
	$(CC) -o trie_search trie_search.o read_input.o storage.o trie.o word_freq.o
storage.o: storage.cpp Storage.h
	$(CC) -c storage.cpp
read_input.o: read_input.cpp ReadInput.h
	$(CC) -c read_input.cpp
trie_search.o: trie_search.cpp TrieSearch.h
	$(CC) -c trie_search.cpp
trie.o: trie.cpp Trie.h
	$(CC) -c trie.cpp
word_freq.o: word_freq.cpp WordFreq.h
clean:
	rm *.o