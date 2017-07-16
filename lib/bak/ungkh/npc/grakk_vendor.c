#include <lib.h>
#include <std.h>
#include "../ungkh.h"
#include <vendor_types.h>

inherit LIB_VENDOR;

static void create() {
  vendor::create();

  SetKeyName("Grakk");
  SetAdjectives( ({
    }) );
  SetId( ({
    "Grakk","merchant",
    }) );

  SetShort("Grakk the merchant");
  SetLong(
    "Grakk is small for an orc, just under six feet tall,"
    " and possesses an uncommonly large nose, with a large"
    " wart prominently positioned. His small black eyes are"
    " close set, and he has an intelligence"
    " extraordinary for an orc. He collects junk as a hobby"
    " and occasionally parts with it for a modest fee.");
  SetRace("orc");
  SetClass("merchant");

  SetSkill("blunt attack" , 1, 52);

  SetLevel(45);
  SetGender("male");

  SetInventory( ([
    STD_WEAPON + "blunt/copper_club" : "wield club",
    U_OBJ + "gob_loincloth" : "wear loincloth",
    ]) );

  SetLocalCurrency("skins");
  SetStorageRoom(U_ROOM + "grakk_store");
  SetMaxItems(65);
  SetVendorType(VT_ALL);

  SetAction(1, ({
    "!say you going to buy something or not?"
    "!emote scratches himself.",
    "!emote grunts meaningfully.",
                 }) );

  SetMorality(-500);
  SetCurrency("skins",123 + random(75) );

  SetDie("The orc slowly topples to the ground.");

}
