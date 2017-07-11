/*bosun's mate
  Zara 8/8/98
*/


#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../acove.h"

inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("bosun's mate");
  SetShort("bosun's mate");
  SetId( ({"mate","pirate"}) );
  SetAdjectives( ({"bosun", "bosun's",}) );
  SetLong("This undead pirate appears to be slightly drunk "
         "and unsteady. He is small and agile in spite of his "
         "tipsy condition.");
  SetGender("male");
  SetMorality(-500);
  SetRace("human");
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The pirate crumbles to dust.");
  SetClass("merchant");
  SetClass("rogue");
  SetLevel(5);
  SetAction(5,({
          "!emote sways unsteadily on his feet, but his eyes are "
          "sharp and coherant."})
        );
  SetInventory( ([
       ACOVE_OBJ + "knife" : "wield knife",
        ]) );
}

int eventDie(object killer) {
  object pirate_inv;
  if(!random(5)) {
    pirate_inv = new(DIR_INVASIONS + "/haven_pirate/pih_inv");
     INVASION_D->eventRegisterInvasion(pirate_inv, killer);
  }
  return ::eventDie(killer);
}
