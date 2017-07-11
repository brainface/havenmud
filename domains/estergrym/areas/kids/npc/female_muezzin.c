//Samah@Haven
//20040911
#include "../clearing.h"
#include <lib.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("female muezzin");
    SetId( ({ "child","muezzin" }) );
    SetAdjectives( ({ 
       "muezzin",
       "female",
       "pathetic"
    }) );
    SetShort("a pathetic child");
    SetLong(
       "Her shambled fur lies matted and soaked against her skin.  "
       "Her dress hangs tattered and ruined against her body, adding to her "
       "disheveled appearance.  Blood drips down the front of her body "
       "from countless cuts on her face and arms."
    );
    
    SetRace("muezzin");
    SetClass("bard");
    SetLevel(1);
    SetGender("female");
    SetMorality(200);
    SetAction(5, ({ 
       "!emote clutches a teddy bear close, mumbling to herself", 
       "!cry",
       "!emote crys pathetically as she desperatly pulls at her bur "
       "filled fur.",
       "!say I want to go home!",
       "!say I want my mommy!",
       "!say mommy please find us!",
       "!say Someone please help us get home!",
       "!emote hugs her teddy bear close to her, whispering soothing words "
       "to it",
       "!say mister snuggles is afraid!",
       "!say mister snuggles wants to go home!", 
    }) );
    SetDie(
       "A muezzin child screams painfully as the final blow is struck and she "
       "falls to the ground dead."
    );
    SetInventory( ([        
       CLEAR_OBJ "t_bear": 1,
       CLEAR_OBJ "t_dress" : "wear all" 
    ]) );
}

/** Approved by Laoise at Sat Sep 11 20:24:58 2004. **/