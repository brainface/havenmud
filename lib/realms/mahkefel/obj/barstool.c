// Mahkefel 2010
// guess what this does.
#include <lib.h>

inherit LIB_ITEM;
inherit LIB_SIT;

static void create() {
  ::create();
  SetShort("a wobbly wooden barstool");
  SetKeyName("barstool");
  SetId( ({"stool","barstool" }) );
  SetAdjectives( ({ "wobbly","wooden" }) );
  SetLong(
    "Beerstains and bootscuffs mar this truly ancient "
    "barstool. The seat is worn to a smooth polish from "
    "years of use, and the wobbling legs look like they've been "
    "loose for years."
  );
  SetMass(100);
  SetDamagePoints(250);

  SetWeaponClass(20); // BARSTOOL MEAT FACE.
}

