 /*   /secure/cmds/sages/addlanguage.c
  *   adds languages to the language daeamon
  *   balishae@haven
  *   7/99
  */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;


mixed cmd(string args){
    string file;
    
    if(!args || args == "") return "Syntax: <addlanguage LANGUAGE>";
    if(!file_exists(file = DIR_CFG "/languages/" + args) )
        return "File not found: " + file;
    LANGUAGE_D->AddLanguage(file);
    previous_object()->eventPrint("Language added.");
    return 1;
}


string GetHelp(string str)
{
    return ("Syntax:  <addlanguage LANGUAGE>\N"
            "Allows you to add custom phonetic sounds for different "
            "languages.  Specifically, you create a language "
            "configuration file and then issue this command with the "
            "language name as the argument to load the new language "
            "into the language daemon.  Languages without configuration "
            "files will default to a group of generic sounds.\n\n"
            "The format of the file being read is:\n"
            "language_name\n"
            "phonetic_sound\n"
            ".\n"
            ".\n"
            ".\n"
            "\nWith a new sound on each line following the language name. "
            "\n\nSee also: removelanguage");
}
