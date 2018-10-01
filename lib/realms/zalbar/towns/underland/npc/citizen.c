#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("gnome citizen");
  SetRace("gnome");
  SetGender(random(2) ? "male" : "female");
  SetShort("a friendly " + GetGender() + " gnomish citizen");
  SetId( ({ "gnome", "citizen", GetGender() }) );
  SetAdjectives( ({ "friendly", "gnomish", GetGender() }) );
  SetLong(
    "This citizen of the Underland is a content creature full of joy."
    );
  SetClass("merchant");
  SetLevel(random(4) + 1);
  SetAction(5, ({
    "!hum",
    "!whistle",
    "!smile",
    }) );
  SetWander(5);
  SetLimit(4);
}
