
Cheaters!
EE312

This program finds similarities amongst groups of files to check for plagiarism. This is done using a hash table and hash function
to store sequences of words in each file. Then using the concept of collisions within hashtables, the program finds matching word sequences 
and outputs them depending on the threshold provided by the user.

Instructions: 

1. Make sure to have the files m1.cpp, Hashmap.cpp, Hashmap.H, makefile, and a folder containing the files you want to compare
   in the same directory

2. From the command line navigate to the directory containing these files, type "make"

3. Then type the following:

	./plagiarismCatcher folderName num1 num2


	folderName: replace with the name of the folder containing the files you want to compare, this could also be replaced by a path if the folder is in another location

	num1: replace with the size of the "chunks" to compare. That is, the size of the sequence of words. Cannot be greater than the max number of words in any file.
	
	num2: replace with the threshold for which the program will output a match between two files. That is, if two files have more
	      than num2 amount of similarities of size num1 words, it will output.

	
Example:

./plagiarismCatcher sm_doc_set 6 200

This input in the command line will print out all pairs of files that share more than 200 matches of 6 word sequences. Note that
they will output in descending order, with the most similar files listed at the top

    

