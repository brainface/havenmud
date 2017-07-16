#include <lib.h>
#include "../starfire.h"

inherit LIB_BURN;

static void create() {
  ::create();
  SetKeyName("pillar");
  SetShort("a large obsidian pillar in the shape of a flame");
  SetLong("This large pillar has been carved from solid obsidian."
          " It has been crafted to resemble a burning flame. At"
          " the top of the pillar a basin with oil has been"
          " attached, but the flame has long since burnt out."
          );
  SetAdjectives( ({ "large", "obsidian", "flame" }) );
  SetId( ({ "pillar" }) );
  SetMaxFuel(-1);
  SetMaterials( ({ "natural" } ) );
  SetRadiantLight(40);
  SetHeat(20);
  SetMass(10000000);
  SetPreventGet("You do not have nearly enough strength to get the pillar.");
  }

varargs mixed eventLight(object who, object tool) {
    SetLit(1);
    SF_ROOM "room06"->SetProperty("eastlamplit", 1);
    send_messages("mymessage", "A low rumble can be heard to the west.", who, 0, environment(who));
    SetLong("This large pillar has been carved from solid obsidian."
            " It has been crafted to resemble a burning flame. At"
            " the top of the pillar sits a basin with oil and shows"
            " signs of recent use."
           );
    return 1;
}

mixed eventDarken() {
    object env;
    object who;
    who = this_player();
    
  if( env = environment() ) {
          env->eventPrint("The " + GetKeyName() + " goes dark.");
          if( living(env) ) {
            environment(env)->eventPrint(possessive_noun(env) + " " + GetKeyName() + " goes dark.", env);
            }
   }
   SetLong("This large pillar has been carved from solid obsidian."
          " It has been crafted to resemble a burning flame. At"
          " the top of the pillar a basin with oil has been"
          " attached, but the flame has recently been extinguished."
          );
   if (who = present(who)) {
     SF_ROOM "room06"->RemoveProperty("eastlamplit");
     send_messages("mymessage2", "A loud scream erupts from the west.", who, 0, environment(who));
    }
   SetLit(0);
   return 1;
}
