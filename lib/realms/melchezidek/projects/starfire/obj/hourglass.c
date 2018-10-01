#include <lib.h>
#include <domains.h>
#include "../starfire.h"

inherit LIB_ITEM;

int eventTurn();

static void create() {
  ::create();
  SetKeyName("hourglass");
  SetShort("a large hourglass");
  SetLong("This is a large hourglass made of obsidian and glass. Two"
          " identical glass bulbs rest in the obsidian frame mirroring"
          " each other. The bottom bulb is filled halfway with pure"
          " white sand."
          );
  SetAdjectives( ({ "large", "obsidian", "glass" }) );
  SetId( ({ "hourglass" }) );
  SetMaterials( ({ "natural" } ) );
  SetMass(10000000);
  SetPreventGet("You are unable to pick up the hourglass for some reason."
                " Perhaps you should try turning it?");
  }




int eventTurn() {
  object who;
  string dest;
  who = this_player();
  
  dest = YOZRATH_VIRTUAL + "/desert/" + ( "-" + random(100) + "," + random(100));
  send_messages( ({ "are", "turn" }),
                 "$agent_name $agent_verb wisked away in a shower of sand as"
                 " $agent_nominative $agent_verb the hourglass.",
                 who, 0, environment(who));
   who->eventMoveLiving(dest, 
                        "$N is wisked away in a shower of sand as they turn the hourglass!",
                        "$N lands roughly in the sand.");
  return 1;
}

int direct_turn_obj() { return 1; }
