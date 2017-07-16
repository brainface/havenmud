#include <lib.h>
#include <damage_types.h>
#include <domains.h>

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("dark troll");
  SetShort("a dark troll");
  SetId( ({ "troll" }) );
  SetAdjectives( ({ "dark" }) );
  SetLong("This massive creature is covered in short black hairs, "
          "filth, and bits of its last couple of meals. The troll "
          "stands at nine feet tall, and is as wide as 3 men "
          "standing abreast. It also seems to be very aggresive.");
  SetRace("troll");
  SetClass("fighter");
  SetGender("male");
  SetSkill("blunt attack", 1, 1);
  SetLevel(10);
  AddCurrency("ducats", random(50));
  SetCombatAction(3, ({
    "!emote lets out a loud roar as it charges in at you.",
    "!emote swings its massive bone club from side to side.",
    }) );
  SetAction(3, ({
    "!emote roars loudly as a warning to any in its territory.",
    }) );
  SetInventory( ([ 
     AVERATH_OBJ "bclub.c" : "wield club",
     AVERATH_OBJ "barmour.c" : "wear bone armour", 
     ]) );
  SetEncounter(101);
  SetMorality(-500);
}
