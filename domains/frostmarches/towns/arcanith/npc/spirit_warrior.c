/*  The spirit warrior */

#include <lib.h>
#include <std.h>
#include "/domains/frostmarches/towns/arcanith/ruins.h"

inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Spirit Commander");
  SetId( ({ "spirit", "commander" })  );
  SetAdjectives( ({ "spirit", "commander", }) );
  SetShort("the spirit of a Commander of Arcanith");
  SetLong("The transparent image of an armoured warrior is all that is left "
          "of this forgotten soldier.  His face looks pale and haggard, as "
          "if he's been without sleep for a long time.  His armour looks "
          "antiquated and damaged, as if he had been in a large battle. "
          "He appears to serve still as guardian of Arcanith and would like "
          "nothing more than to teach a new round of recruits how to fight.");

  
  SetRace("human");
  SetBaseLanguage("Koblich");
  SetTown("Arcanith");
  SetClass("fighter");
  SetLevel(25);
  SetGender("male");
  SetUndead(1);
  SetMorality(0);

  SetAction(10,
     ({ "The warrior swings his weapon in preparation of battle.",
        "!moan sadly" }) );
  SetInventory( ([ OBJ "/longsword_glowing" : "wield longsword" ]) );
  SetDie("The warrior gives a final moan as his form dissipates.");
  SetNoCorpse(1);
  SetLimit(1);
  SetPlayerTitles( ([
    "newbie" : "the Young Pup",
    "mortal" : "the Guardsman of Arcanith",
    "hm"     : "the Defender of Arcanith",
    "legend" : "the Guardian of Ruins",
    "avatar" : "the Sentinel of Light",
]) );
  SetFreeEquipment( ([
    OBJ "/shortsword_old" : 1,
    STD_WEAPON "hatchet" : 1,
    ]) );
}
