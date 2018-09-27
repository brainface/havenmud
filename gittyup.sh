#!/bin/sh

# haha it's a pun

# cron job script to commit whatever code changes have
# been made to haven from the mud/ftp whatever
cd /home/haven/haven
sDATE = date

git add .
git commit -m "$sDATE snapshot"
