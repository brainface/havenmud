#include <lib.h>
#include <std.h>
#include "../underland.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("azonia");
  SetRace("gnome");
  SetGender("female");
  SetShort("Azonia the Fierce Fighter");
  SetId( ({ "gnome", "azonia", "fighter", }) );
  SetAdjectives( ({ "fierce" }) );
  SetLong(
    "Azonia the Fierce Fighter trains young gnomes seeking to become fighters. "
    "Those interested in her teachings should <greet> her."
    );
  SetClass("fighter");
  SetLevel(25);
  SetTown("Underland");
  SetFreeEquipment( ([
    STD_SLASH "shortsword" : 1,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Fighter",
    "mortal" : "the Warrior",
    "hm"     : "the Fierce Fighter",
    "legend" : "the Legendary Warrior",
    ]) );
}
