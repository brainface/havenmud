/*first mate
 Zara 8/8/98
*/

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../acove.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("pirate");
  SetShort("first mate");
  SetId( ({"mate","pirate"}) );
  SetAdjectives( ({"undead","formidable","brawny","first"}) );
  SetLong("Next to the captain, this pirate is one of the ship's most "
         "formidable adversaries. His firey eyes burn from sunken "
         "sockets. His brawny arms hold a double-edged longsword "
          "as if it were a toy. His sole purpose is to guard his "
         "captain and he will do so to the death.");
  SetGender("male");
  SetMorality(-1500);
  SetRace("human");
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The pirate crumbles to dust.");
  SetClass("cavalier");
  SetLevel(40);
  SetAction(5,
       ({"!emote stands, feet apart, ready to meet any intruder."
      }) );
  SetInventory( ([
      ACOVE_OBJ + "dlongsword" : "wield longsword",
      ACOVE_OBJ + "dubloon" : random(10),
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
