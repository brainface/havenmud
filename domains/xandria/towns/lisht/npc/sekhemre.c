//Selket@Haven
//2006
#include <lib.h>
#include <std.h>
#include "../lisht.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("sekhemre");
  SetId( ({ "sekhemre", "sorcerer" }) );
  SetShort("Sekhemre the Sorcerer");
  SetLong(
    "Sekhemre is an empowered gnoll that nearly glows "
    "with the energies of his magic. His blue eyes seem to "
    "stare directly into one's soul, as if he searches for "
    "a kindred spirit upon this world."
  );
  SetRace("gnoll");
  SetGender("male");
  SetClass("evoker");
  SetTown("Lisht");
  SetMorality(30);
  SetLevel(40);
  SetBaseLanguage("Rehshai");
  SetSpellBook( ([
    "fireball" : 100,
    "planar assault" : 100,
    "plane warp" : 100,
    "bolt" : 100,
    "enhanced buffer" : 100,
    "energy wall" : 100,
    "enhanced aura" : 100,
    "chain lightning" : 100,
    "disintegrate" : 100,
    "psychokinetic impulse" : 100,
    "elemental protection" : 100,
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Evoker of Lisht",
    "mortal" : "the Evoker of Lisht",
    "hm"     : "the Magnificent Evoker of Lisht",
    "legend" : "the Hand of Selket",
    "avatar" : "the Pariah of the Living",
    "cavalier" : "the Keeper of the Threshold",
  ]) );
  SetRestrictRace(1);
  SetFreeEquip( ([
    STD_POLE + "staff"      : 1,
  ]) );
  SetCurrency("deben", 5000);
  SetAction(10, ({
    "!cast energy wall",
    "!cast enhanced aura",
    "!speak There is tumult in the sky.",
    "!cast elemental protection",
  }) );
  SetCombatAction(50, ({
    "!cast enhanced buffer",
    "!cast enhanced aura",
    "!cast psychokinetic impulse",
    "!cast plane warp",
    "!cast fireball",
    "!cast chain lightning",
    "!cast bolt",
    "!cast disintegrate",
    "!cast energy wall",
    "!cast elemental protection",
  }) );
  SetFirstCommands( ({ 
    "cast energy wall",
    "cast energy wall",
    "cast energy wall",
    "cast energy wall",
    "cast energy wall",
  }) );
  SetInventory( ([
    LISHT_OBJ "shenti" : "wear shenti",
    LISHT_OBJ "snake_armlet" : "wear armlet on left arm and left hand",
  ]) );
}
