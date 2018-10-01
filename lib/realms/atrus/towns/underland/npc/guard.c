#include <lib.h>
#include "../underland.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("guard");
  SetRace("gnome");
  SetGender(random(2) ? "female" : "male");
  SetShort("a " + GetGender() + " underland guard");
  SetId( ({ "gnome", "guard", "wanderer" }) );
  SetAdjectives( ({ GetGender(), "underland" }) );
  SetLong(
    "This Town Guard for Underland is a stoic creature of "
    "even demeanor. Messing with the citizens of Underland "
    "in the presence of an Underland Guard is a bad idea."
    );
  SetClass("fighter");
  SetSkill("pole combat", 1, 1);
  SetLevel(15);
  SetInventory( ([
    UNDER_OBJ "chainboots" : "wear boots",
    UNDER_OBJ "chainmail"  : "wear suit of dwarven chainmail",
    UNDER_OBJ "chainhelm"  : "wear helm",
    UNDER_OBJ "halberd"    : "wield halberd",
    ]) );
  SetTown("Underland");
  SetCurrency("rupies", 1000);
  SetWander(8);
}
