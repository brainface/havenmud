/*  The spirit warrior */

#include <lib.h>
#include "../ruins.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Spirit Knight");
  SetId( ({ "spirit", "knight", "commander" })  );
  SetAdjectives( ({ "spirit", "knight", }) );
  SetShort("the spirit of a Knight Commander of Arcanith");
  SetLong("The transparent image of an armoured warrior is all that is left "
          "of this forgotten soldier.  His face looks pale and haggard, as "
          "if he's been without sleep for a long time.  His armour looks "
          "antiquated and damaged, as if he had been in a large battle. "
          "He appears to serve still as guardian of Arcanith and would like "
          "nothing more than to teach a new round of recruits how to fight.");

  
  SetRace("human");
  SetBaseLanguage("Koblich");
  SetTown("Arcanith");
  SetClass("cavalier");
  SetLevel(5);
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
    "newbie" : "the Young Knight of Arcanith",
    "mortal" : "Sir $N the Knight of Arcanith",
    "hm"     : "Sir $N the Defender of Arcanith",
    "legend" : "Knight-Commander $N of Arcanith",
    ]) );
  SetFreeEquipment( ([
    OBJ "/shortsword_old" : 1,
    OBJ "/rapier_old"     : 1,
    ]) );
}
