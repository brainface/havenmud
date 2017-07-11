// Templar invasion of Parva
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include "../tip.h"
inherit LIB_INVADER;

int CheckParva();

static void create() {
  ::create();
  SetKeyName("Capet Esterian");
  SetShort("Capet Esterian Banewulf, Lord Templar of Haven Town");
  SetId( ({ "capet", "esterian", "banewulf", "templar", "templar_inv" }) );
  SetAdjectives( ({ "kylin", "lord" }) );
  SetLong(
    "This virtuous warrior-priest is the leader "
    "of the Kylin Templar invasion forces. "
    "The devout look of peace on the face of the warrior "
    "is of sublime happiness in the cause of Kylin."
  );
  SetRace("elf");
  SetGender("male");
  SetClass("cleric");
  SetLevel(80);
  SetSkill("evokation", GetLevel()*3, 1);
  SetSkill("blunt attack", GetLevel()*3, 1);
  SetSkill("blunt defense", GetLevel()*3, 1);
  SetReligion("Kylin");
  SetInventory( ([
    TIP_OBJ + "mace" : "wield mace",
    TIP_OBJ + "armour" : "wear shirt",
  ]) );
  SetCurrency("imperials", 7500);
  SetAction(5, ({
    "!yell Repent, Citizens of Parva!",
    "!yell Your city will be spared, embrace the True Faith!",
    "!yell Citizens, fall back before us!",
    "!cast wall of force",
  }) );
  SetCombatAction(15, ({
    "!cast wall of force",
    "!cast wrath",
    "!cast hand of judgement",
    "!yell We are here to convert you, heathen!",
  }) );
  SetSpellBook( ([
    "wrath" : 100,
    "wall of force" : 100,
    "smite" : 100,
    "hand of judgement" : 100,
  ]) );
  SetFriends( ({ "templar_inv" }) );
  SetEncounter( (: CheckParva :) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "enter hall", "go out", "go east", "enter shack", "go out",
    "go south",
    "enter building", "go out", "go north", "go east", "enter store",
    "go out", "enter inn", "go out", "go east", "go north",
    "go south", "go south",
  }) );
  SetDie("Capet Esterian %^BOLD%^BLUE%^casts%^RESET%^ a quick spell of retreat.");
  SetNoCorpse(1);
 }

int CheckParva() {
  object who = this_player();
  if (!userp(who) && !(who->GetProperty("invader"))) {
    SetAttack(who);
    eventForce("say " + who->GetKeyName() + ", you should surrender!");
    eventForce("cast wrath on " + who->GetKeyName());
  return 1;
  }
return 0;
}
