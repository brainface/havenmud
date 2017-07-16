#include <lib.h>
#include "../ungkh.h"
#include <vendor_types.h>

inherit LIB_VENDOR;

static void create() {
  vendor::create();

  SetKeyName("Krak");
  SetAdjectives( ({
    }) );
  SetId( ({
    "Krak","weaponsmith",
    }) );

  SetShort("Krak the weaponsmith");
  SetLong(
    "Krak the weaponsmith is huge for an orc, standing at"
    " just under nine feet tall. His eyes smoulder as if"
    " they contain the heat of his forge, and his thick-"
    "set eyebrows are lowered in a permanent glower.");
  SetRace("orc");
  SetClass("merchant");

  SetSkill("blunt attack" , 1, 52);

  SetLevel(50);
  SetGender("male");

  SetInventory( ([
    U_OBJ + "forge_hammer" : "wield hammer",
    U_OBJ + "krak_loincloth" : "wear loincloth",
    ]) );

  SetLocalCurrency("skins");
  SetStorageRoom(U_ROOM + "krak_store");
  SetMaxItems(65);
  SetVendorType(VT_WEAPON);

  SetAction(1, ({
    "!say you going to buy something or what?",
    "!emote scratches himself.",
    "!emote grunts meaningfully.",
    "!emote hammers a sword into shape.",
    "!emote heats a sword in the forge.",
    }) );

  SetMorality(-500);
  SetCurrency("skins",123 + random(75) );

  SetDie("The orc slowly topples to the ground.");

}
