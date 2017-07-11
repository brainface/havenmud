#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("desert nomad");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Padashi", 100, 1);
  SetGender("male");
  SetClass("fighter");
  SetLevel(25);
  SetMorality(-20);
  SetShort("a desert nomad");
  SetId( ({ "nomad" }) );
  SetAdjectives( ({ "desert" }) );
  SetInventory( ([
    YOZRATH_VIRTUAL "obj/kopesh" : "wield large kopesh sword",
    YOZRATH_VIRTUAL "obj/short"  : "wield small kopesh sword",
    YOZRATH_VIRTUAL "obj/waterskin" : 1,
    ]) );
}
  