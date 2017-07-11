#include <lib.h>
#include "../skaven.h"
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("slave");
    SetId( ({ "slave", "skaven" }) );
    SetAdjectives( ({ "dirty", "slave", "skaven" }) );
    SetShort("a dirty skaven slave");
    SetLong("This wretched looking creature has been forced into "
             "servitude and appears to be competent at a variety "
            "of mundane tasks.");
    
    SetRace("skaven");
    SetClass("rogue");
    SetLevel(random(5) + 1);
    SetMorality(-250);
    SetGender("male");
    SetDie("The slave drops to the ground and twitches violently.");    
    SetAction(5, ({
          "!emote squeaks softly.",
          "!emote sets about cleaning something."  }) );
    SetCombatAction(5,
         ({"!say Help!",
           "!emote tries vainly to flee.",
           "!emote squeaks in fear."           
            }) );          
    SetInventory( ([
          S_OBJ + "dagger.c" : "wield dagger",
          ]) );
}
