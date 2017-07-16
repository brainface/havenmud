//
// The 'halt' command
// Stops fighting
// Created by ???
// Immortal Syntax added by Zaxan@Haven
//

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
   object me = this_player();
   object *stuff = all_inventory(environment(me));
   object who;

   if(angelp(me)) { return "Uh ok...like...all stopped and stuff...NOT!"; }
   if(immortalp(me)) {
      stuff = filter(stuff, (: noncreatorp :) );
      stuff = filter(stuff, (: sizeof($1->GetEnemies()) :) );
      stuff = filter(stuff, (: $1 :) );
      if (!sizeof(stuff)) {
      	me->eventPrint("Nothing interesting happening here!");
      	return 1;
      }
      
      foreach(object dude in stuff) {
         foreach(object enemy in dude->GetEnemies()) {
            dude->RemoveEnemy(enemy);
         }
         dude->ResetCurrentEnemy();
      }
      message("system",me->GetName()+" stops all attacks in the "
                 "room!",environment(me),me);
      return "You stop all attacks in the room.";
   } 
   if (!args) {
      return "Stop attacking who?";
   }
   if (!(who = find_living(args))) {
      return "No such being exists!";
   }
   if (!userp(who) && who->GetOwner() != "") {
    return "That person doesn't care that you want to stop.";
    }
   me->RemoveEnemy(who);
   me->ResetCurrentEnemy();
   return "You stop your attack.";
}

void help() {
   if(immortalp(this_player())) {
      message("help","Syntax: <halt>\n\n"
              "This command allows an immortal to stop all attacking "
              "in a room.",this_player());
   } else {
      message("help","Syntax: <halt LIVING>\n\n"
              "Stops an attack against a target.\n"
              "Does not stop target's attack.",this_player());
   }
}
