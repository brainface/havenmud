//Samah@Haven
//20040911
#include "../clearing.h"
#include <lib.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("male muezzin");
    SetId( ({ "child","muezzin" }) );
    SetAdjectives( ({
       "muezzin",
       "male",
       "frail"
    }) );
    SetShort("a frail child");
    SetLong(
       "Covered in sopping fur, this muezzin is completely "
       "disheveled.  His clothes hang in torn dripping tatters that "
       "dangle pathetically from his frail form.  Blood streams "
       "down his small spindly arms from numerous cuts along his body."
    );
    SetRace("muezzin");
    SetClass("fighter");
    SetLevel(4);
    SetGender("male");
    SetMorality(200);
    SetAction(5, ({ 
       "!emote swings his sword weakly at the brambles", 
       "!say it's okay, my father will find us!",
       "!say I'll protect us, daddy showed me how!" 
    }) );
    SetDie(
       "The muezzin child clutches his sword " 
       "as his last breath escapes his body."
    );
    SetInventory( ([        
       CLEAR_OBJ "w_sword": "wield sword",
       CLEAR_OBJ "t_shirt": "wear all" 
    ]) );
}
/** Approved by Laoise at Sat Sep 11 20:25:58 2004. **/