#include <lib.h>
#include "path.h"

inherit LIB_NPC;


static void create () {
    npc::create();
    SetKeyName("sklaag the Mauler");
    SetId( ({ "sklaag", "orc", "sklaag the mauler" }) );
    SetMorality(-500);
    SetShort("Sklaag the Mauler");
    SetLong("Sklaag is a huge, muscular orc, bearing the scars from many "
         "a battle, but it is clear that he came out of each one victorious.");
    SetAdjectives( ({ "field" }) );
    SetRace("orc");
    SetClass("fighter");
  	SetLevel(50);
    SetGender("male");
    SetCombatAction(20, ({
    			"!disarm",
    			"!disorient",
    			}) );
    SetInventory( ([
          BEORN_OBJ + "poleaxe.c" : "wield poleaxe" ,
          BEORN_OBJ + "brigandine.c" : "wear brigandine armour" ,
       		BEORN_OBJ + "orcshield.c" : "wear shield on left arm" ,
               ]) );
}
