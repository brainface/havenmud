// Templar invasions of Jidoor
// By Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include "../tij.h"

inherit LIB_INVADER;
int CheckSprite();

static void create() {
  ::create();
  SetKeyName("grand inquisitor");
  SetShort("Grand Inquisitor Banewulf");
  SetId( ({ "inquisitor", "templar", "banewulf", "templar_inv" }) );
  SetAdjectives( ({ "grand", "inquisitor" }) );
  SetLong(
    "This virtuous warrior-priest is the leader "
    "of the Kylin Templar invasion forces. "
    "The devout look of peace on the face of the warrior "
    "is of sublime happiness in the cause of Kylin."
  );
  SetRace("elf");
  SetGender("male");
  SetClass("cleric");
  SetSkill("evokation", 1, 1);
  SetSkill("enchantment", 1, 1);
  SetSkill("blunt attack", 1, 1);
  SetSkill("blunt defense", 1, 1);
  SetLevel(95);
  SetReligion("Kylin");
  SetInventory( ([
    TIJ_OBJ + "mace" : "wield mace",
    TIJ + "armour" : "wear shirt",
  ]) );
  SetCurrency("imperials", 7500);
  SetAction(5, ({
    "!yell Die JidoorMages!",
    "!yell We have come for you, Sprites!",
    "!yell Citizens, fall back before us!",
    "!cast wall of force",
  }) );
  SetCombatAction(15, ({
    "!cast wall of force",
    "!cast wrath",
    "!cast hand of judgement",
    "!yell We are only here for the Mages!",
  }) );
  SetSpellBook( ([
    "wrath" : 100,
    "wall of force" : 100,
    "smite" : 100,
    "hand of judgement" : 100,
  ]) );
  SetEncounter( (: CheckSprite :) );
  SetFriends( ({ "templar_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "go north", "go north", "enter library", "go east", "go east",
    "go up", "go up", "go up", "go up", "go down", "go down", 
    "go down", "go down", "go west", "go south", "go north", 
    "go west", "go out", "go north", "go north", "enter hall",
    "go down" 
  }) );
  SetDie("The Inquisitor %^BOLD%^BLUE%^casts%^RESET%^ a quick spell of retreat.");
  SetNoCorpse(1);
  call_out( (: eventForce :), 1, "cast wall of force");
  call_out( (: eventForce :), 1, "cast wall of force");
  call_out( (: eventForce :), 1, "cast wall of force");
 }

int CheckSprite() {
  object who = this_player();
  if (!userp(who) && !(who->GetProperty("invader"))) {
    SetAttack(who);
    eventForce("say " + who->GetKeyName() + ", you should surrender!");
    eventForce("cast wrath on " + who->GetKeyName());
    return 1;
  }
return 0;
}
