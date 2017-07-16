#include <lib.h>
#include "../skaven.h"
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("ogre");
    SetId( ({ "rat", "rat ogre", "ogre" }) );
    SetAdjectives( ({ "massive", "muscular", "rat", }) );
    SetShort("a brutally massive rat ogre");
    SetLong("This strange skaven creation is not really a true skaven. "
            "The rat ogre stands over three meters tall and is nearly "
            "hairless.  Its massive frame is covered with muscles, "
            "painted runes, and scar tissue.  It appears to have been "
            "sedated in some way, yet it still looks incredibly dangerous." );
    
    SetRace("ogre");
    SetClass("fighter");
    SetSkill("melee combat",2,1);
    SetLevel(random(5) + 50);
    SetMorality(-750);
    SetGender("male");
    SetDie("The rat ogre slowly slides to the ground with a loud gurgling noise.");    
    SetCombatAction(5,
         ({"!emote foams at the mouth",
           "!emote lunges at you wildly.",
           "!emote growls in rage.", 
           "!emote snarls.",
           "!emote pulverizes a section of cavern wall just above your head."
            }) );
    SetAction(5, ({
          "!emote growls and tugs at its chains.",
          "!emote swings wildly, tearing a chunk of stone from the wall."  
            }) );
}
