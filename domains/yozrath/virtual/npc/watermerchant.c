#include <lib.h>
#include <domains.h>
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("water merchant");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Padashi", 100, 1);
  SetGender("male");
  SetClass("fighter");
  SetLevel(18);
  SetMorality(-20);
  SetShort("a dusty water merchant");
  SetId( ({ "merchant" }) );
  SetAdjectives( ({ "dusty", "water" }) );
  SetInventory( ([
    YOZRATH_VIRTUAL "obj/kopesh" : "wield sword",
    YOZRATH_VIRTUAL "obj/waterskin" : 2,
    ]) );
  SetAction(2, ({
    "!yell Fresh water, right here!",
    "!yell Come and buy from me, water here!",
    "!yell Finest water in all the land!",
  }) );
  SetMenuItems( ([
    "water" : YOZRATH_VIRTUAL "obj/waterskin",
    ]) );
}
  