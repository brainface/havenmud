#include <lib.h>
#include <std.h>
#include "../yozrath.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("abdullah");
  SetShort("Abdullah the Butcher, Trainer of Janissaries");
  SetId( ({ "abdullah", "butcher", "trainer", "janissary" }) );
  SetAdjectives( ({ "trainer", "janissary", "butcher" }) );
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetTown("Yozrath");
  SetClass("janissary");
  SetLevel(100);
  SetMorality(1000);
  SetAction(3, ({
    "!speak I could train you in Janissary ways.",
    "!speak Ask me about Janissaries.",
  }) );
  SetInventory( ([
    YOZRATH_OBJ "kopesh" : "wield sword",
    YOZRATH_OBJ "thobe" : "wear thobe",
    ]) );
  SetPlayerTitles( ([
    "newbie" : "$N the Ajemi of the Desert",
    "mortal" : "$N the Devshirmeh Warrior of the Desert",
    "hm"     : "$N the Elite Janissary of Yozrath",
    "legend" : "$N Jemaat of the Desert",
    "avatar" : "$N the Imperial Beuluk of Yozrath",
    ]) );
  SetFreeEquipment( ([
    YOZRATH_OBJ "newbie_kopesh" : 1,
    YOZRATH_OBJ "waterskin"     : 3,
    ]) );
  SetLimit(1);
  SetGender("male");
  SetLong(
    "Abdullah the Butcher is the trainer of the Janissary Corps for the "
    "army of the desert. His proud overbearing stance is one of confidence "
    "in his skills."
    );
}
