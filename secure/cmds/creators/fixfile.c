/*++

  fixfile by Zaxan@Haven

  Gets rid of those pesky ^M's in files.

--*/

#include <lib.h>

inherit LIB_DAEMON;

int cmd(string qualifier)
{
    object tp = this_player();
    string *file_list = ({ });

    if (!qualifier)
    {
        tp->eventPrint("What file(s) do you want to fix?");
        return 1;
    }

    file_list = tp->wild_card(qualifier);

    if (!sizeof(file_list))
    {
        tp->eventPrint("Couldn't find any files to fix.");
        return 1;
    }

    foreach (string file in file_list)
    {
        int fsize = file_size(file);
        int pos = 0;
        string input = "";

        if (fsize <= 0)
        {
            tp->eventPrint("file: "+file+" is not really a file or contains nothing.");
            continue;
        }

        if (file[<2..] != ".c")
        {
            tp->eventPrint("file: "+file+" does not end in .c.");
            continue;
        }
        
        while(pos < fsize)
        {
            string read = read_bytes(file, pos++, 1);
            int c = read[0];

            if (c != 0x0D)
            {
                input += read;
            }
        }

        if (!rm(file))
        {
            tp->eventPrint("file: original "+file+" could not be deleted.");
            continue;
        }
        if (!write_file(file, input, 1))
        {
            tp->eventPrint("file: new "+file+" could not be written. Shit. You made a backup, right?");
            continue;
        }
        tp->eventPrint("file: "+file+" has been fixed and saved.");
    }

    return 1;
}

string GetHelp()
{
    return ("Syntax: fixfile <file.c>\n\n"
            "OVERWRITES the original given .c file with a file that "
            "contains no ^M (aka CR, \\r, etc) characters. Handy for those "
            "who use FTP to upload files after using an editor which only "
            "saves in MS-DOS format. WARNING: This initial version of this "
            "command can lag the MUD if used on several very large files "
            "at once.");
}
