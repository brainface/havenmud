#include <lib.h>
#define NPCS "/domains/havenwood/virtual/npcs"
inherit LIB_SENTIENT;

static void create() {
   sentient::create();
   SetKeyName("Parvan");
   SetWander(20);
   SetShort("a Parvan citizen");
   SetId( ({ "parvan","citizen" }) );
   SetAdjectives( ({ "parvan" }) );
   SetLong("This Parvan citizen has wandered "
           "away from his hown city, searching "
           "glory and adventure and maybe a "
           "few quick oros from hapless "
           "adventurers.");
   SetGender("male");
   SetTown("Parva");
   SetRace("human");
   SetClass("rogue");
   SetLevel(10+random(7));
   SetInventory( ([
     NPCS + "/shirt" : "wear shirt",
     NPCS + "/pants" : "wear pants",
     NPCS + "/knife" : "wield knife in left hand",
     ]) );
   SetCurrency("oros",20);
   SetAction(5,({ 
     "!whistle",
     "!emote idly examines some leaves.",
     "!emote flips a coin idly.",
     }) );
   SetCombatAction(5, ({ 
     "!say Fiend!",
     "!say Get away from me!",
     "!shout Someone get this jerk off of me!",
     "!shout I'm bein' oppressed!",
     "!emote spits at you.",
   }) );
}

