#include <lib.h>
inherit LIB_VERB;

static void create() {
  verb::create();
  SetVerb("darken");
  SetSynonyms( ({ "extinguish" }) );
  SetRules("OBJ");
  SetErrorMessage("Extinguish what?");
  SetHelp("Syntax:  <extinguish OBJECT> \n"
         "         <darken OBJECT> \n"
           "Darkens an object, like a torch.");
  }

mixed can_darken_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
  return 1;
  }

mixed do_darken_obj(object ob) {
  ob->SetHeat(-1);
  ob->eventDarken();
  return 1;
  }
