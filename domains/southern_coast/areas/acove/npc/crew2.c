/*crew2
 Zara 8/8/98
*/

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../acove.h"
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("pirate");
  SetShort("a undead mangy pirate");
  SetId( ({"pirate","zombie"}) );
  SetAdjectives( ({"undead","zombie","bony"}) );
  SetLong("This pirate zombie wears an eyepatch. 'Mom' is "
         "tatooed on what is left of the flesh of his muscular "
         "bicep.");
  SetGender("male");
  SetMorality(-1000);
  SetRace("human");
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The pirate crumbles to dust.");
  SetClass("cavalier");
  SetLevel(30);
  SetAction(5,
        ({"!emote advances, growling to meet each adversary."})
        );
  SetInventory( ([
       ACOVE_OBJ + "rapier" : "wield rapier",
       ACOVE_OBJ + "dubloon" : random(3),
        ]) );
}

int eventDie(object killer) {
  object pirate_inv;
  if(!random(200)) {
     pirate_inv = new(DIR_INVASIONS + "/haven_pirate/pih_inv");
    INVASION_D->eventRegisterInvasion(pirate_inv, killer);
  }
  return ::eventDie(killer);
}
