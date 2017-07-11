/*    /daemon/bugs.c
 *    from the Dead Soulsr1 Object Library
 *    a management daemon for bug tracking
 *    created by Descartes of Borg 950925
 */

#include <lib.h>
#include <daemons.h>
#include <save.h>
#include "include/bugs.h"

inherit LIB_DAEMON;

private int NextID;

static void create() {
    int bug_id;
    daemon::create();
  if( file_size(SAVE_BUGS __SAVE_EXTENSION__) > 0 )
      unguarded( (: restore_object, SAVE_BUGS :));
  if( NextID < 1 ) {
	  NextID = 1;
	  } 
    unguarded( (: save_object, SAVE_BUGS :));
}

int eventReport(string who, string type, string bug, string data) {
    object ob = find_living(lower_case(who));
    int x = NextID;
    string path = "/log/bugs/";
    if (ob->GetTestChar()) {
        path += "test/";
        if (file_size(path) != -2) unguarded((: mkdir, path :));
        }
   write_file(path + NextID + ".bug",
      "Reported by: " + who + " (" + ob->GetEmail() + ")\n" +
      "Time       : " + ctime(time()) + "\n" +
      "Type       : " + type + "\n" +
      "Location   : " + data + "\n" +
      "Status     : " + "NEW\n" +
      "Bug        : " + bug  );
   SMTP_D->eventCreateOutgoingMessage( ({ "bugs@duuk.com" }),
      "Bug Report # " + NextID + "(" + type + ")",
      "Reported by: " + who + " (" + ob->GetEmail() + ")\n" +
      "Time       : " + ctime(time()) + "\n" +
      "Type       : " + type + "\n" +
      "Location   : " + data + "\n" +
      "Status     : " + "NEW\n" +
      "Bug        : \n" + bug       
     );

    NextID++;
    unguarded( (: save_object, SAVE_BUGS :) );
    return x;
    
}
