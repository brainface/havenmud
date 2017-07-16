#include <lib.h>
#include "path.h"

inherit LIB_NPC;


static void create() {
    npc::create();
    SetMorality(150);
    SetKeyName("Lord Beornwulf");
    SetId( ({ "lord", "lord beornwulf", "beornwulf" }) );
    SetShort("Lord Beornwulf");
    SetLong("Because of his outstanding service to the military forces of "
            "the town of Haven, Beornwulf was given this land and the title of "
            "Lord.  Now that his keep is under attack by the orkish armies, "
            "he spends most of his time in this room, lost in thought.  "
             "He is tall and regal, wearing a perpetual frown.");
    SetClass("fighter");
    SetLevel(50);
    SetCurrency("imperials", random(500) + 100);
    SetCombatAction(20, ({
    			"!disarm",
    			"!disorient",
    			}) );
    SetRace("human");
    SetGender("male");
    SetInventory( ([
          BEORN_OBJ + "bastard.c" : "wield bastard sword" ,
          BEORN_OBJ + "torso.c" : "wear breastplate" ,
          BEORN_OBJ + "armgreaves.c" : "wear arm greaves" ,
          BEORN_OBJ + "leggreaves.c" : "wear leg greaves" ,
          BEORN_OBJ + "helmet1.c" : "wear helmet" ,
          ]) );
}
