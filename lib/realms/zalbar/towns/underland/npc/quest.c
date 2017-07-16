#include <lib.h>
#include "../underland.h"
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("Adumant");
  SetRace("gnome");
  SetGender("male");
  SetShort("Adumant the Rumor Monger");
  SetId( ({ "adumant", "monger" }) );
  SetAdjectives( ({ "rumor" }) );
  SetLong(
    "Adumant is the local rumor monger.  <ask> him <for quests> to find "
    "out what the locals are talking about!"
    );
  SetClass("fighter");
  SetLevel(2);
  SetTown("Underland");
}
