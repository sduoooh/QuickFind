# QuickFind

A simple command-line C program , finding files using a part of its name.
But not so quick.

## How to use？

Changing the value of ".*path"s in ```QuickFind.h``` and,
some cases will needing to change the codes' behaves.

Such as the number of your "spypath" is more than 2,
so that you need add a same sentences or converting the code style.

### What the ".*path"s meaning is?

Well, the "spypath" is which path you want to monitor.

And the "srcpath" and "desktoppath" is my file path,
it means I have two file path.

### Why it so slow?

This is a one-day program, at the begining of the first char of its cores,
I have not knowledges about C++ except basic C.

So some places where this program core function implement needing optimize.
Such as when the ```Spy``` get the feedback of some files have changed at your spypath,
```generrate``` will reindex all the files instead of performing local operations on the original index， 
based on the file pointer feedback by the change.

## Other

There is a same inner program at windows 10. 

If you are tried of my program's bugs or my English level's low,
you can find it on the ```Setting``` of the windows system and, 
to do some fine-tuning.

Although I started this project partly because I didn't find the above-mentioned built-in program, 
the main reason was that I wanted to prepare for my other programs through this program I developed.
