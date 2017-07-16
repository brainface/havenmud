#include <lib.h>
#include <damage_types.h>
#include <domains.h>

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("dark figure");
  SetShort("a dark figure");
  SetId( ({ "human", "figure", }) );
  SetAdjectives( ({ "dark" }) );
  SetLong("The dark cloaked figure stalks the sewers, looking slyly "
          "from side to side. His hand hovers near his waist, just "
          "inside his cloak.");
  SetRace("human");
  SetClass("rogue");
  SetGender("male");
  SetLevel(5);
  SetStat("strength", 30, 4);
  SetStat("speed", 45, 3);
  SetStat("agility", 45, 3);
  SetStat("durability", 35, 3);
  AddCurrency("ducats", random(20));
  SetCombatAction(3, ({
    "!emote deftly spins to the side, and lunges in.",
    "!emote grins sadisticly as he continues to fight.",
    }) );
  SetAction(3, ({
    "!emote leans against the sewer tunnel, his eyes carefully scanning the area.",
    }) );
  SetInventory( ([ 
     AVERATH_OBJ "wbknife.c" : "wield knife",
     AVERATH_OBJ "bcloak.c" : "wear cloak", 
     AVERATH_OBJ "bpants.c" : "wear pants",
     ]) );
  SetEncounter(0);
  SetMorality(-100);
}
