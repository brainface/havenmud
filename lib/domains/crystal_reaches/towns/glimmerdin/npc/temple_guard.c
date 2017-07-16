#include <lib.h>
#include "../path.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("Knight Templar");
  SetId( ({ "knight", "templar", "paladin", "dwarf", "glim_wander" }) );
  SetAdjectives( ({ "knight", "kylin", "dwarven", "templar", }) );
  SetShort("a dwarven knight-templar of Kylin");
  SetLong(
    "The dwarven knight-templar is a dwarf of high personal conviction. "
    "A dwarven knight-templar is a foe to be respected and admired. "
    "Their dedicatation has led them to the peak of their field."
    );
  
  SetRace("dwarf");
  
  SetClass("cavalier");
  SetSkill("blunt combat", 1);
  SetSkill("faith", 1);
  SetSkill("melee combat", 2);
  SetSkill("enchantment", 1);
  
  SetTown("Glimmerdin");
  SetReligion("Kylin", "Kylin");
  SetGender("male");
  SetInventory( ([ 
    G_OBJ "chainmail.c" : "wear chainmail",
    G_OBJ "hammer.c"    : "wield hammer",
    G_OBJ "breeches.c"  : "wear breeches",
    G_OBJ "boots.c"     : "wear boots",
    G_OBJ "church_tabard.c" : "wear tabard",
    ]) );
  
  SetMorality(2500);
  SetLevel(60);
  SetCurrency("nuggets", random(25)+10);
  SetSpellBook( ([
    "wall of force"     : 100,
    "kylin touch"       : 100,
    "wrath"             : 100,
    "desert banishment" : 100,
    ]) );
  SetAction(8, ({
  	"!cast wall of force",
  	"!cast wall of force on kuthan",
  	"!emote quietly prays.",
  	"!speak We go forth to smite the wicked!",
  	}) );
  SetCombatAction(15, ({
  	"!cast wall of force",
  	"!cast wrath",
  	"!cast kylin touch",
  	"!cast bless on hammer",
  	"!cast desert banishment",
  	}) );
  SetFriends( ({"glim_wander", "dwarf" }) );
  SetFirstCommands( ({
  	"cast wall of force",
  	"cast wall of force",
  	"cast wall of force",
  	"cast wall of force on kuthan",
  	"cast wall of force on kuthan",
  	}) );
  
  
}
