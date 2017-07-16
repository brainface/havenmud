// Templar invasion of Jidoor
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include <dirs.h>
#include "../tij.h"
inherit LIB_INVADER;

int CheckSprite();

static void create() {
  ::create();
  SetKeyName("Kylin Templar");
  SetShort("a Templar of Kylin");
  SetId( ({ "templar", "templar_inv" }) );
  SetAdjectives( ({ "kylin" }) );
  SetLong(
    "This is one of the fierce warrior-priests of "
    "the Kylin faith. Virtue surrounds the Templar "
    "like a Holy Light, extinguishing the enemies "
    "of the Lord of Order in one fell swoop."
  );
  SetRace("elf");
  SetGender(random(2) ? "male" : "female");
  SetClass("cleric");
  SetSkill("blunt attack", 1, 1);
  SetSkill("evokation", 1, 1);
  SetSkill("enchantment", 1, 1);
  SetSkill("blunt defense", 1, 1);
  SetLevel(65);
  SetReligion("Kylin");
  SetInventory( ([
    TIJ_OBJ + "mace" : "wield mace",
    TIJ_OBJ + "armour" : "wear shirt",
  ]) );
  SetSpellBook( ([
    "hand of judgement" : 100,
    "holy shield"       : 100,
    "wrath"             : 100,
    "wall of force"     : 100,
    "smite"             : 100,
  ]) );
  SetAction(5, ({
    "!cast wall of force",
    "!cast holy shield",
    "!yell We have come for the mages, stay out of our way!",
    "!yell If you stay indoors, you will survive!",
    "!yell The Lord of Order has no qualms with the people of Jidoor.",
    "!yell We are your friends, please do not resist!",
    "!yell Sprites, throw off the Magildan yoke!",
  }) );
  SetCombatAction(5, ({
    "!yell Templars, stand fast!",
    "!cast wrath",
    "!cast wall of force",
    "!cast smite",
    "!cast hand of judgement",
  }) );
  SetEncounter( (: CheckSprite :) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "go north",
    "go north", "go north", "enter library", "go east",
    "go east", "go up", "go up", "go up", "go up", "go down",
    "go down", "go down", "go down", "go down", "go up",
    "go west", "go south", "go north", "go west", "go out",
    "go north", "go north", "enter hall", "go down" 
  }) );
  call_out( (: eventForce :), 1, "cast wall of force");
  call_out( (: eventForce :), 1, "cast wall of force");
  call_out( (: eventForce :), 1, "cast wall of force");
 }

int CheckSprite() {
  object who = this_player();
  if (!userp(who) && !(who->GetProperty("invader")) ) {
    eventForce("attack " + who->GetKeyName());
    eventForce("cast wrath on " + who->GetKeyName());
  return 1;
  }
return 0;
}
