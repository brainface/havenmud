//
// The 'where' command
// Gives player locations
// Created by Duuk@Haven
// Re-written by Zaxan@Haven for alpha sort
// Modified by Zaxan@Haven to group together multiple locations
//

#include <lib.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

static void create() {
   help::create();
   SetHelp("Syntax: where [user] \n\n"
           "If arg is specified, shows the location "
           "of that user. If no arg is specified, "
           "shows a list of all users logged on "
           "and their location. \n\n"
           "See also: who, people, summ");
}

mixed cmd(string args) {
   mapping locations = ([ ]);
   object *who;
   string bar, *msg = ({ });
   int Screen;

   if(angelp(this_player())) {
      return "You are here.";
   }
   if(!creatorp(this_player())) return 0;
   Screen = this_player()->GetScreen()[0];
   bar = repeat_string("-", Screen);
   msg = ({ "\n"+bar });
   msg += ({ "%^BOLD%^BLUE%^NAME               LOCATION%^RESET%^" });
   msg += ({ bar });
   if (!args) {
      who = filter(users(), (: playerp :) );
      who = filter(who, (: !($1->GetTestChar()) :) );
      who = filter(who, (: living :));
     if (!sizeof(who)) return "No players currently.";
   } else {
      args = convert_name(args);
      who = ({ find_living(args) });
   }
   if( (!who[0]) || (who[0]->GetTestChar()) ||
   (who[0]->GetInvis() && !(archp(this_player()))) ) {
      return "Where is who?";
   }
   foreach(object person in who) {
      if(locations[short_file(file_name(environment(person)))]) {
         locations[short_file(file_name(environment(person)))] += 
            ({ capitalize(person->GetKeyName()) });
      } else {
         locations[short_file(file_name(environment(person)))] = 
            ({ capitalize(person->GetKeyName()) });
      }
   }
   foreach(string env, string *ppl in locations) {
      msg += ({ item_list(ppl)+":" });
      msg += ({ "     ("+env+")" });
   }
   msg += ({ bar });
   this_player()->eventPage(msg, "info");
   return 1;
}
