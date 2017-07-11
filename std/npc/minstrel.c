#include <lib.h>

inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("wandering minstrel");
    SetId( ({ "wandering minstrel", "minstrel" }) );
    SetShort("a wandering minstrel");
    SetLong("This cheerful fellow seems to be quite happy to merely "
       "travel along, singing his songs of heroics and bravery.  "
       "However, he looks hardened enough to be able to defend "
       "himself if the need arose.");
    SetSkill("hack attack", 1 ,1);
    SetLevel(8+random(5));
    SetRace("human");
    SetClass("bard");
    SetGender("male");
    SetMorality(100);
  SetSongBook( ([
      "shielding song" : 100,
   ]) );
  SetCombatAction(9, ({
    "!sing shielding song",
    "!whimper",
    "!speak I am but a simple storyteller!",
    "!yell HELP!  Someone is killing an artist!",
    "!sing shielding song",
    }) );
    SetAction(5, ({ "!hum happily", "!dance" }));
    SetCurrency("imperials", random(30)+30);
    SetDie("The minstrel looks up at you mournfully as he dies.");
  SetInventory( ([
        "/std/clothing/body/brown_robe" : "wear robe",
        "/std/instruments/lyre" : "wield lyre",
  ]) );
    SetWander(3);
}
