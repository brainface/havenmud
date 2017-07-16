#include <lib.h>
#include "../skaven.h"
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("runner");
    SetId( ({ "gutter runner", "runner", "skaven" }) );
    SetAdjectives( ({ "gutter", "runner", "skaven", "shadowy" }) );
    SetShort("a shadowy skaven gutter runner");
    SetLong("This member of the rat-like skaven race looks well-fed "
             "and well-trained.  The gutter runners are an elite caste "
            "of spies and thieves, trained to carry out a variety of "
            "underhanded tasks.  This particular skaven appears to be "
            "of a high rank, and consequently very dangerous." );
    
    SetRace("skaven");
    SetClass("rogue");
    SetLevel(random(5) + 40);
    SetGender("male");
    SetMorality(-1000);
    SetDie("The gutter runner hisses loudly with its final breath.");
    SetCombatAction(5,
         ({"!say What are you doing here?",
           "!emote strikes with lightning speed.",
           "!emote growls in contempt.", "!emote snarls nastily.",
           "!emote seems to be everywhere at once."
            }) );      
    SetAction(5, ({
          "!emote squints at you with evil intent.",
          "!emote seems to fade into the shadows."  }) );
    SetInventory( ([
          S_OBJ + "magic_dagger" : "wield dagger in left claw",
          S_OBJ + "cloak" : "wear cloak",
          S_OBJ + "stars" : "wield stars in right claw"
          ]) );
}
