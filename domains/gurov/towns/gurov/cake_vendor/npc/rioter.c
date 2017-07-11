#include <lib.h>
#include <std.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("Gurov Rioter");
  SetShort("an angry Gurov Rioter");
  SetId( ({ "rioter" }) );
  SetAdjectives( ({ "angry", "gurov" }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetClass("fighter");
  SetLevel(25);
  SetInventory( ([
    STD_HACK "battle_axe" : "wield axe",
    STD_ARMOUR "pants/studded_leather_pants" : "wear pants",
    STD_ARMOUR "shirt/vest_leather"          : "wear vest",
    ]) );
  SetGender("male");
  SetCurrency("rubles", 50);
  SetLong(
    "This Gurovian seems upset about something.  His violence appears to be focused "
    "on a specific issue."
    );
}