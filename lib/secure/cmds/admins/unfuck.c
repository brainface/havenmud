/*
 * Unfuck cmd
 * Changes all files in the given dir to have
 * lowercase filenames. (damn pirates!)
 * 
 * Written by Zaxan@Haven
 */

#include <lib.h>

inherit LIB_DAEMON;

int unfuck(string dir);

int cmd(string str) {
    object tp = this_player();

    if (!archp(this_player()))
    {
	this_player()->eventPrint("No.");
	return 1;
    }
    
    if (file_size(str) != -2)
    {
	str = tp->query_cwd() + "/" + str;
    }

    if (str[<1..] != "/")
    {
	str += "/";
    }

    if (file_size(str) != -2)
    {
	tp->eventPrint("The directory " + str + " does not exist.");
	return 1;
    }

    if(!unfuck(str) || ((str != lower_case(str)) && rename(str, lower_case(str))))
    {
	tp->eventPrint("For some reason, directory "+str+" is remaining fucked.");
	return 1;
    }

    tp->eventPrint("Directory " + str + " has been un-fucked.");
	
    return 1;
}

string GetHelp() {
    return ("Syntax: unfuck <directory>\n\n"
            "Changes all files in the given dir (recursively) to have lowercase "
	    "filenames. (damn pirates!)");
}

int unfuck(string dir)
{
    string *entries;

    if (dir[<1..] != "/")
    {
	dir += "/";
    }

    if (file_size(dir) != -2)
    {
	return 0;
    }

    entries = get_dir(dir);

    foreach (string entry in entries)
    {
	string fullpath = dir + entry;

	if (file_size(fullpath) == -1)
	{
	    continue;
	}
	else if (file_size(fullpath) == -2)
	{

	    if (!unfuck(fullpath) || ((entry != lower_case(entry)) && rename(fullpath, dir + lower_case(entry))))
	    {
		return 0;
	    }
	}
	else
	{
	    if (((entry != lower_case(entry)) && rename(fullpath, dir + lower_case(entry))))
	    {
		return 0;
	    }
	}
    }

    return 1;
}
