// Templar invasion of Parva
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include "../tip.h"
inherit LIB_INVADER;

int CheckParva();

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
    "of the Lord of Balance in one fell swoop."
  );
  SetRace("elf");
  SetGender(random(2) ? "male" : "female");
  SetClass("cleric");
  SetSkill("blunt attack", 1, 1);
  SetSkill("evokation", 1, 1);
  SetSkill("blunt defense", 1, 1);
  SetLevel(45);
  SetReligion("Kylin");
  SetInventory( ([
    TIP_OBJ + "mace" : "wield mace",
    TIP_OBJ + "armour" : "wear shirt",
  ]) );
  SetAction(5, ({
    "!cast wall of force",
    "!cast holy shield",
    "!yell Flee before us, ye unfaithful swine!",
    "!yell If you stay indoors, you will survive!",
    "!yell The Lord of Order has no qualms with the people of Parva.",
    "!yell We are your friends, please do not resist!",
    "!yell Friends, repent and accept the True Faith!",
  }) );
  SetCombatAction(5, ({
    "!yell Templars, stand fast!",
    "!cast wrath",
    "!cast wall of force",
    "!cast smite",
    "!cast hand of judgement",
  }) );
  SetSpellBook( ([
    "hand of judgement" : 100,
    "holy shield"       : 100,
    "wrath"             : 100,
    "wall of force"     : 100,
    "smite"             : 100,
  ]) );
  SetFriends( ({ "templar_inv" }) );
  SetEncounter( (: CheckParva :) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "enter hall", "go out", "go east", "enter shack",
    "go out", "go south", "enter building", "go out",
    "go north", "go east", "enter store", "go out",
    "enter inn", "go out", "go east", "go north",
    "go south", "go south",
  }) );
}

int CheckParva() {
  object who = this_player();
  if (!userp(who) && !(who->GetProperty("invader")) ) {
    eventForce("attack " + who->GetKeyName());
    eventForce("cast wrath on " + who->GetKeyName());
  return 1;
  }
return 0;
}
