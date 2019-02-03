#!/usr/bin/env python

# i've not run this yet! somebody is actually trying to PLAY THE GAME

# hey it's mike i'm trying to solve a problem
# of "the vagrant does not work because it's
# missing a bunch of git ignore stuff I don't want git to track

# so this script should throw most everything in the gitignore
# file into an archive, and then we're going to make git track
# that archive, which is a binary and that way we won't have a
# bunch of "for every day somebody logged in, the chat save
# was updated!" nonsense git entries.

# oh look that's a lib
import tarfile

# open our gitignore file
gitignore = open(".gitignore")

# start up an archive for all our character saves,
# chat logs, etc
ignored_saves = tarfile.open("ignored_saves.tgz", "w:gz")

# for each line in gitignore add whatever that line
# says to the tarball. if it stars with a / it should be a
# file or directory
for line in gitignore.readlines():
    if line.startswith("/"):
        # directory may not exist, it crashes if it does not
        try:
            ignored_saves.add("."+line.rstrip("\n"))
        except:
            pass

# close the file
ignored_saves.close()
            
# pray? this probably works        
        
        
    
