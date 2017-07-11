#include <lib.h>
#include "../caves.h"

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("ogre");
    SetId("ogre");
    SetAdjectives("male");
    SetShort("an ogre");
    SetLong("This is a very large, smelly ogre.  This monstrocity has many "
            "scars from previous battles and bashing the occasional "
            "noncompliant goblin");
    SetRace("ogre");
    SetClass("fighter");
    
    SetLevel(15);
    
    SetGender("male");
    SetMorality(-250);
    SetInventory( ([CAVES_OBJ + "spikeclub" : "wield club",
                    CAVES_OBJ + "bonearmour" : "wear armour"]) );
    SetCurrency( ([
      "senones"   : 130,
               ]) );
   
}
