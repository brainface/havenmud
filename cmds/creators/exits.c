/*    /cmds/creator/exits.c
 *    from the Dead Souls LPC Library
 *    Command to display exit and enter info for rooms
 *    by Kalinash 100195
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd()
{
    string *asExits, sDir, sExit;
    string *asEnters;
    object oEnv;

    if ( !( oEnv = environment( this_player() ) ) )
        return "You do not have a valid environment.";

    asExits = oEnv->GetExits();
    asEnters = oEnv->GetEnters();

    message( "my_action", sprintf("\t *** %s ***\n", identify( oEnv ) ),
      this_player() );

    if ( !( sizeof( asExits ) ) )
        message( "my_action", "This " + oEnv->GetClimate() + " room has no exits.", this_player() );
    else {
        message( "my_action", "This " + oEnv->GetClimate() + " room has the following exits :\n",
          this_player() );
        foreach( sExit in asExits ) {
            message( "my_action", sprintf( "\t%10s -> %s", sExit,
             short_file(oEnv->GetExit(sExit))), this_player() );
        }
    }

    if ( !( sizeof( asEnters ) ) )
        message( "my_action", "\nThis room has no enters.", this_player() );
    else {
        message( "Nmy_action", "\nThis room has the following enters :\n\n",
          this_player() );
        foreach( sExit in asEnters ) {
            message( "my_action", sprintf( "\t%10s -> %s", sExit,
             short_file(oEnv->GetEnter(sExit))), this_player());
        }
    }

    return 1;
}

string GetHelp(string blah) {
    return "Syntax: <exits>\n\n"
           "Displays the enter and exit information for your "
           "current room.";
}
