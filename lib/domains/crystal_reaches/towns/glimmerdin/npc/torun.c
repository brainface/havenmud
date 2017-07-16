#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Torun Stonebone");
  SetRace("dwarf");
  SetClass("priest");
  SetGender("male");
  SetShort("Torun Stonebone, Supreme War Priest of Kylin");
  SetId( ({ "torun", "stonebone", "priest", "dwarf", "glim_wander" }) );
  SetAdjectives( ({ "torun", "stonebone", "war", "supreme", "kylin", "of" }) );
  SetLong(
    "Torun Stonebone is a large dwarf with a flowing grey beard.  His "
    "girth is matched by an intense gaze on his face that seems to spell "
    "disaster for those opposed to his philosophy. He has large, thick "
    "hands which seem prepared for both war and religion."
    );
  SetTown("Glimmerdin");
  SetReligion("Kylin", "Kylin");
  SetUniqueSkills( ([
    "blunt combat" : 0,
    "hack combat" : 1,
    ]) );
  SetLevel(75);
  SetMorality(1250);
  SetSpellBook( ([
    "divine magic fully" : 100,
    "mend" : 100,
    "revive" : 100,
    "sanctify" : 100,
    "bless" : 100,
    "wall of force" : 100,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Acolyte of Kylin",
    "mortal" : "the War Priest of Kylin",
    "hm"     : "the Bishop of Glimmerdin",
    "avatar" : "the Cardinal of the Undermountain",
    "fighter": "the Glimmerdin Monk",
    "cavalier" : "the War-Paladin of Kylin",
    ]) );
  SetFriends( ({"glim_wander", "dwarf"}) );
  SetFreeEquip( ([
     G_OBJ "axe" : 1,
    ]) );
  SetAction(5, ({
  	"!cast wall of force",
  	"!cast wall of force",
  	"!speak For the glory of Kylin, we preach!",
  	"!speak Convert and be saved!",
  	"!speak Join the religion, become a cleric!",
  	}) );
  SetCombatAction(20, ({
    "!cast sanctify",
    "!cast bless on hammer",
    "!cast wall of force",
    }) );
  SetInventory( ([ 
    G_OBJ "crobes" : "wear robes",
    G_OBJ "mithril_hammer" : "wield hammer"
   ]) );
  SetFirstCommands( ({
  	"cast wall of force",
  	"cast wall of force",
  	"cast wall of force",
  	}) );
}
