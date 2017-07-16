#include <lib.h>
#include <std.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("farmer");
  SetId( ({ "farmer" }) );
  SetAdjectives( ({ "local" }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetClass("merchant");
  SetLevel(15);
  SetGender(random(2) ? "male" : "female");
  SetShort("a local farmer");
  SetLimit(6);
  
  SetCurrency("rubles", 20);
  SetMorality(50);
  SetLong(
    "This is a local farmer."
    );
  SetInventory( ([
    STD_OBJ "digging/shovel" : "wield shovel",
    ]) );
  SetAction(10, ({
      "!farm with shovel",
      "!farm with shovel",
      "!say Lovely day for farming.",
      "!say Early to bed and early to rise.",
      "!hum",
    }) );
  SetFirstCommands( ({ "farm with shovel" }) );
}