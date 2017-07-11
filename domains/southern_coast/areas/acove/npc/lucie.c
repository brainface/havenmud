/*lucie
 Zara 8/8/98
*/
#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../acove.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Lucie");
  SetShort("Lady Lucie");
  SetId( ({"lady","lucie","beauty","pirate"}) );
  SetAdjectives( ({"undead","amazonian","beauty","blonde",
                  "beautiful","lady"}) );
  SetLong("This lady pirate is amazonian in size. She is "
          "a stunning beauty and her piercing green eyes "
          "seem to see into the soul. Long blonde tresses "
          "swirl about her shoulders. Her breeches fit snugly "
          "as do her supple leather boots. The top of her "
         "ruffled white shirt is open, displaying to advantage "
         "a gleaming black opal pendant. Few brave intruders "
         "have lived to tell the tale of their rendezvous "
         "with the beautiful Lucie.");
  SetGender("female");
  SetMorality(-2000);
  SetRace("human");
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The pirate crumbles to dust.");
  SetClass("cavalier");
  SetLevel(43);
  SetAction(5,
      ({"!emote stands, hands on hips, and tosses her head in "
       "challenge. Her enticing appearance belies her great "
        "prowess in battle."
        }) );
  SetInventory( ([
             ACOVE_OBJ + "rapier" : "wield rapier",
             ACOVE_OBJ + "pendant" : "wear pendant",
             ACOVE_OBJ + "breeches" : "wear breeches",
             ACOVE_OBJ + "shirt" : "wear shirt",
             ACOVE_OBJ + "boots" : "wear boots",
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
