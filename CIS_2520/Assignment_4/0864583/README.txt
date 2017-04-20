****************************************************
Erik Zorn-Wallentin	 0864583
CIS2520			     Assignment #4
Sunday, Nov. 23 / 2014
****************************************************

**********************
Compilation
**********************

To compile this program make sure you are in the correct directory in the terminal for where your file is.
Next type make in the command prompt.

***********************
Running the program(s)
***********************

To run the program type "./avltree or avltree" for the specific program, you need to first compile it properly as directed above. 

When the program is running a menu will pop up with several options, error checking was done on the first menu and will give proper feedback.
1) Reads in a file, and if the file exists it will insert all the data into AVL tree
2) Prompts user for a key to find, if the key can be found it will print the key to the screen otherwise it will say no such key.
3) Prompts the user for a key to insert, if the key can be inserted it will insert it to AVL tree and print it
4) Prompts the user for a key to be deleted, if the key can be deleted it will delete it from AVL tree, otherwise it will print no such key.
5) If an AVL tree exists it will print the height and size of the tree.
6) Prompts the user for an integer value, and will print all keys above that integer value. (No error checking on non-integer values done)
7) Quits the program

**************************
Bibliography / References
**************************
http://www.zentut.com/c-tutorial/c-avl-tree/ -- Help understanding AVL tree
http://www.thecrazyprogrammer.com/2014/03/c-program-for-avl-tree-implementation.html -- Help understanding AVL tree
http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/ -- help understand depth of tree

*****************
Known Limitations
*****************
Reading from a large file may take a few seconds to load everything.
A few menu options don't check for characters when it asks for an integer on error checking

When calculating the height I noticed the file on moodle said first height counts at 0,
so when option 5 asks for height the first one will count at 0 as the first height. So
it may be off by 1 depending on what TA is looking for.


