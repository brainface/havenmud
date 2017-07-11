#include <lib.h>
#include "../skaven.h"
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("captain");
    SetId( ({ "stormvermin", "captain", "skaven" }) );
    SetAdjectives( ({ "storm", "vermin", "skaven", "captain" }) );
    SetShort("a skaven stormvermin captain");
    SetLong("This member of the rat-like skaven race looks well-fed "
             "and well-trained. This particular "
            "skaven is much larger than the rest, and appears to have "
            "some authority.  With thick, wiry muscles and a threatening " 
            "posture, this warrior appears to be a very competent fighter.");
    
    SetRace("skaven");
    SetClass("fighter");
    SetLevel(random(15) + 30);
    SetMorality(-1200);
    
    SetDie("The captain slumps to the ground with a sickening squeal.");
    SetGender("male");
    SetAction(5, ({
          "!emote squints at you with evil intent.",
          "!emote readies its morning star and shield."  }) );
    SetCombatAction(5,
         ({"!say What are you doing here?",
         	 "!disarm",
         	 "!disorient",
           "!emote crouches into a defensive position.",
           "!emote growls in rage.", 
           "!emote snarls.",
           "!say Prepare to die!"
            }) );          
    SetInventory( ([
          S_OBJ + "m_star" : "wield star in left claw",
          S_OBJ + "plate.c" : "wear plate",
          S_OBJ + "armgreaves.c" : "wear arm greaves",
          S_OBJ + "leggreaves.c" : "wear leg greaves",
          S_OBJ + "skull.c" : "wear mask",
          S_OBJ + "shield.c" : "wear shield on right claw"
          ]) );
}
