// torak 10/27/12
#include <lib.h>
#include <domains.h>
#include <dirs.h>
#include <daemons.h>
#include <std.h>
#include "../gwonish.h"
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("Ssorvor");
  SetShort("Ssorvor");
  SetId( ({ "ssorvor" }) );
  SetClass("fighter");
  SetLevel(100);
  SetRace("lizardman");
  SetGender("male");
  SetBaseLanguage("Slith");
  SetTown("Gwonish");
  SetLong(
    "SSorvor is a spear maker for the lizardman of Gwonish. "
    "His green, scaly body shows many scars from glorious "
    "battle. ");
  SetInventory( ([
    STD_CRAFTING "wood/bamboo_spike" : "wield spike",
    STD_CLOTHING "body/loin" : "wear loincloth",
    ]) );
  }

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}
