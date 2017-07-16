#include <lib.h>
#include "../newbie.h"
inherit LIB_FEAR;
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("ghoul");
  SetMorality(-200);
  SetShort("a hideous ghoul");
  SetRace("human", "ghoul");
  SetUndead(1);
  SetUndeadType("ghoul");
  SetGender("male");
  SetClass("fighter");
  SetLevel(3);
  SetEncounter(100);
  SetInventory( ([
     NEWBIE_OBJ + "/club" : "wield club",
   ]) );
  SetLong("This small halfling is a mass of disgusting half-decomposed \n"
          "flesh that is made up of little more than fetid tissue \n"
          "and yellowed bone.  The stiff movement of his joints might \n"
          "suggest that he is undead.");
  SetId( ({ "ghoul", "halfling" }) );
  SetAdjectives( ({ "hideous" }) );
  SetResistLevel(3);
  SetFearType("ghoulish fear");
  SetFearLength(2);
 }

void init() {
  fear::init();
  npc::init();
  }


/* Approved by Duuktsaryth on Sun Jun  8 00:17:55 1997. */
