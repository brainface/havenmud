/* crew6
 Zara 8/16/98
*/

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../acove.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("pirate");
  SetShort("an undead skeleton pirate");
  SetId( ({"skeleton","pirate","zombie"}) );
  SetAdjectives( ({"undead","zombie","bony","tall","agile","skeleton"}) );
  SetLong("Any trace of flesh is long gone from this zombie. "
         "His bony skull seems to smile in anticipation of fights "
         "to come. He is tall and agile.");
  SetGender("male");
  SetMorality(-1000);
  SetRace("human");
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The pirate crumbles to dust.");
  SetClass("cavalier");
  SetLevel(28);
  SetAction(5,
      ({"!emote stands ready to meet his next challenge with a "
      "smile on his ghastly face."
      }) );
  SetInventory( ([
     ACOVE_OBJ + "longsword" : "wield longsword",
     ACOVE_OBJ + "comb" : 1,
     ACOVE_OBJ + "bottle" : 1,
      ]) );
}

int eventDie(object killer) {
  object pirate_inv;
  if(!random(200)) {
     pirate_inv = new(DIR_INVASIONS + "/parva_pirate/pip_inv");
    INVASION_D->eventRegisterInvasion(pirate_inv, killer);
  }
  return ::eventDie(killer);
}
