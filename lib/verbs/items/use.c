#pragma save_binary

#include <lib.h>
#include "include/use.h"

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("use");
    SetRules("OBJ to STR", "OBJ");
    SetErrorMessage("Use what to do what?");
    SetHelp("Syntax: <use OBJ to CMD>\n"
            "        <use OBJ>\n"
	    "Certain objects, like scrolls, allow you to perform acts beyond "
	    "your naturaly abilities.  Of course, the only way to know if an "
	    "object can so empower you is either to try it or to somehow "
	    "detect its magic.\n\n"
	    "See also: detect, discern");
}

mixed can_use_obj() {
  if (this_player()->GetSleeping()) return "You're asleep.";
  return 1;
}  

mixed can_use_obj_to_str(string str) {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
   return 1;
}

mixed do_use_obj_to_str(object ob, string str) {
    if( !ob ) return 0;
    else return (mixed)ob->eventUse(this_player(), str);
}

mixed do_use_obj(object ob) {
   if (!ob) return 0;
   return ob->eventUse(this_player());
}