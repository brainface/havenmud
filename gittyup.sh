#!/bin/sh

# haha it's a pun

# cron job script to commit whatever code changes have
# been made to haven from the mud/ftp whatever

# change to mud dir
cd /home/haven/haven

# make a variable for current date (human readable)
sDATE=date

# add eerthing
git add .

# commit changes
git commit -m "$sDATE snapshot"

# push to github
git push origin master
