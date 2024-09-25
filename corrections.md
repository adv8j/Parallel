1. no `i++` is being given, change it to i+=1
2. remove the range thing, we are giving .. operators
3. remove `main` from existence
4. Adding some points:
There cannot be nested comments.
There cannot be any comments in between a keyword.
“ This is /*  Not a comment */ “
5. Remove range() from everywhere in the whitepaper
6. include taskgroup statement inside compound statement?
7. Structure is being defined as identifier in parser right now...not a data type
8. Using arrays as function parameter confusion:
int arr[][][][][]		not allowed

int arr[][number][number][number]

int arr[number][number]

int arr[num][number, number]	//not allowed
int arr [][num,num]	// not allowed