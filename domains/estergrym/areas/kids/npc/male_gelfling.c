//Samah@Haven
//20040911
#include "../clearing.h"
#include <lib.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("male gelfling");
    SetId( ({ "child","gelfling" }) );
    SetAdjectives( ({
       "male",
       "gelfling",
       "wimpering"
    }) );
    SetShort("a wimpering child");
    SetLong(
       "The small gelfling's eyes are wide with fear as he "
       "clutches his wooden sword with both hands.  His clothing " 
       "is soaked, and lies in tatters that hang loosely from his arms.  " 
       "His face is scratched and bleeding."
    );
    SetRace("gelfling");
    SetClass("fighter");
    SetLevel(2);
    SetGender("male");
    SetMorality(200);
    SetAction(10, ({ 
       "!emote clutches his wooden sword tightly",
       "!say D-d-don't worry mommy will find us!",
       "!say My daddy showed me how to fight, we'll be okay",
       "!emote 's eyes water up", 
    }) );
    SetDie(
       "The gelfling child cries one last time before "
       "falling to the ground dead."
    );
    SetInventory( ([        
        CLEAR_OBJ "w_sword": "wield sword",
        CLEAR_OBJ "t_shirt": "wear all"
    ]) );
}

/** Approved by Laoise at Sat Sep 11 20:25:44 2004. **/