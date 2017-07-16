/*    /secure/cmds/creator/ed.c
 *    from the Nightmare IV LPC Library
 *    creator command to enter the editor
 *    created by Descartes of Borg 950406
 *    
 *    edited to log edits 5/16/97 by
 *    Balishae of Haven
 *    edited to remember last file edited
 *    5/17/97 by Balishae of Haven
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    int x;

    if( args == "" || !args )
      if(!this_player()->GetProperty("last_edit"))
      {
        args = user_path((string)this_player()->GetKeyName()) + "tmp.edit";
      }
      else
      {
      args = this_player()->GetProperty("last_edit");
      }
      
    if( (int)this_player()->GetForced() ) {
        message("system", "Someone tried to force you to edit "+ args +"\n" +
                identify(previous_object(-1)), this_player());
        return 0;
    }
    args = absolute_path( (string)this_player()->query_cwd(), args );
    if( (x = file_size(args)) == -2 )
      return "You cannot edit a directory!";
    else if( x == -1 )
      message("editor", args + ", new file, starting in input mode.\n",
        this_player());
    else message("editor", args + ", " + x + " bytes\n", this_player());
    
      write_file("/log/edits/" + lower_case(this_player()->GetKeyName()),
        "(" + ctime(time()) + ") - " + args + "\n");
      write_file("/log/edits/ed_log", "(" + ctime(time()) + ") " +
      this_player()->GetKeyName() + " <" + args + ">\n");
    
    this_player()->SetProperty("last_edit",args);
    
    this_player()->eventEdit(args, 1);
    return 1;
}

void help() {
    message("help", "Syntax: <ed ([filename])>\n\n"
            "Enters the editor editing the file you name.\n\n"
            "See also: led", this_player());
}

