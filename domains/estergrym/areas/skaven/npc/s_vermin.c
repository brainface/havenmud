#include <lib.h>
#include "../skaven.h"
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("stormvermin");
    SetId( ({ "stormvermin", "skaven" }) );
    SetAdjectives( ({ "storm", "vermin", "skaven" }) );
    SetShort("a skaven stormvermin");
    SetLong("This member of the rat-like skaven race looks well-fed "
             "and well-trained.  The stormvermin are an elite cadre "
            "of warriors selected for important tasks.");
    
    SetFriends( ({ "stormvermin" }) );
    SetRace("skaven");
    SetClass("fighter");
    SetSkill("pole combat",2,1);
    SetLevel(random(5) + 15);
    SetGender("male");
    SetMorality(-600);
    SetDie("The stormvermin clutches at its wounds before dropping like a stone.");
    SetCombatAction(5,
         ({"!say Intruder alert!",
           "!emote growls angrily.", "!emote snarls viciously.",
           "!emote tries to keep you at bay with its halberd."
            }) );        
    SetAction(5, ({
          "!emote growls menacingly.",
          "!emote holds its halberd threateningly."  }) );
    SetInventory( ([
          S_OBJ + "halberd.c"    : "wield halberd",
          S_OBJ + "plate.c"      : "wear plate",
          S_OBJ + "armgreaves.c" : "wear arm greaves",
          S_OBJ + "leggreaves.c" : "wear leg greaves",
          S_OBJ + "helmet.c"     : "wear helmet"
          ]) );
}
