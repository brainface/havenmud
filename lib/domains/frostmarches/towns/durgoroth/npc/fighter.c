#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../durgoroth.h"

inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Baelrot");
  SetRace("daemon");
  SetClass("fighter");
  SetLevel(250);
  SetGender("male");
  SetShort("Baelrot the Champion of the Pit");
  SetId( ({ "baelrot","fighter","champion" }) );
  SetLong("Baelrot's body is covered in wounds"
          " both new and old. His horns have been"
          " shattered and now are only inches long"
          " but their jagged edges look extremely"
          " sharp. His name is known throughout"
          " the FrostMarches as the Champion of the"
          " Pit and one could learn many things"
          " about the ways of the fighter simply"
          " by observing Baelrot in action.");
  SetUniqueSkills( ([
      "slash combat" : 0,
      "melee combat" : 1,
      ]) );
  SetAction(5, ({
    "!roar",
    "!cackle",
    "!speak Who dare challenge me!? I shall grind your bones"
            " and devour your heart!",
    "!emote licks his axe.",
    "!yell Come! I grow tired of waiting!",
    "!speak You're a pathetic wretch. I'll take pleasure in"
            " guttin' you, boy!",
    "!speak Worthless piece of trash. Watch me, I'll show you"
            " how to fight!",
    }) );
  SetCombatAction(50, ({
    "!disorient",
    "!disarm",
    "!speak Muahahah! The blood! I can feel your pulse... I"
            " will put that to an end!",
    "!disarm",
    }) );
  SetReligion("Saahagoth","Saahagoth");
  SetTown("Durgoroth");
  SetMorality(-2000);
  SetPlayerTitles( ([
      "newbie"   : "the Wretched Whelp",
      "mortal"   : "the Cursed Contender",
      "hm"       : "the Bringer of Bedlam ",
      "legend"   : "Nightmare $N the Axe of Chaos",
      "avatar"   : "the Long-Lived Destroyer of Dreams",
     ]) );
  SetFreeEquip( ([
     "/std/weapon/melee/brass_knuckles" : 1,
     "/std/weapon/hack/meat_hook" : 1,
     DURG_OBJ "newb_chain" : 1,
     ]) );
  SetInventory( ([
     "/std/weapon/melee/brass_knuckles" : "wield knuckles",
     DURG_OBJ "fighter_axe" : "wield axe",
     DURG_OBJ "fighter_plate" : "wear suit",
     DURG_OBJ "fighter_helmet" : "wear helmet",
     DURG_OBJ "horseshoe" : "wear 1st shoe on left hoof",
     DURG_OBJ "horseshoe2" : "wear 1st shoe on right hoof",
     ]) );
  SetCurrency("crystals", 5000);
  }
