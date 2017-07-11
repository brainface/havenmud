//Samah@Haven
//20040911
#include "../clearing.h"
#include <lib.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("female gelfling");
    SetId( ({ "child","gelfling" }) );
    SetAdjectives( ({
       "gelfling",
       "female",
       "crying"
    }) );
    SetShort("a crying child");
    SetLong(
       "Her clothes are in shambles and her face is tattered and "
       "bleeding.  This young gelfling appears to have been through "
       "quite an ordeal and her eyes are swollen and red from crying."
    );
    
    SetRace("gelfling");
    SetClass("bard");
    SetGender("female");
    SetLevel(1);
    SetMorality(200);
    SetAction(5, ({ 
       "!emote hugs herself, crying softly", 
       "!cry",
       "!say I want my mommy!",
       "!say I'm scared!",
       "!say I hope daddy comes soon",
       "!emote sniffles pathetically",
    }) );
    SetDie(
       "The gelfling child screams as she falls to the ground dead."
    );
    SetInventory( ([        
       CLEAR_OBJ "ball" : 1,
       CLEAR_OBJ "t_dress" : "wear all" 
    ]) );
}

/** Approved by Laoise at Sat Sep 11 20:24:48 2004. **/