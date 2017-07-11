 /*captain
 Zara 8/11/98
*/

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../acove.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("pirate captain");
  SetShort("pirate captain");
  SetId( ({"captain","foe","pirate"}) );
  SetAdjectives( ({"formidable","undead","pirate"}) );
  SetLong("Standing a full seven feet tall, this pirate captain "
         "is an awe-inspiring sight! Long black hair, pulled "
         "back at the nape, glittering black eyes, and a "
         "permanent five o'clock shadow suit his role. A "
         "flamboyant scarlet sash is tied about his waist "
         "and a gold earring flashes in the light. Bulging "
         "muscles, a whipcord grace and acute balance attained "
         "from the roll and pitch of the ship at sea, make him "
         "a formidable foe.");
  SetGender("male");
  SetRace("human");
  SetMorality(-2000);
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The pirate crumbles to dust.");
  SetClass("cavalier");
  SetLevel(45);
  SetLanguage("Eltherian",100,);
  SetAction(3,
    ({"!say in eltherian come any closer and I will cut you from stem to stern, matey.",
      "!say in eltherian shiver me timbers!",
      "!emote fingers his cutlass lovingly.",
    }) );
  SetInventory( ([
      ACOVE_OBJ + "cutlass" : "wield cutlass",
     ACOVE_OBJ + "/emerald" : 4,
    ACOVE_OBJ + "/chalice" : 1,
    ACOVE_OBJ + "/dubloon" : 40,
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
