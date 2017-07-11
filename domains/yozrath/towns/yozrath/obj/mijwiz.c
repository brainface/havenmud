#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("mijwiz");
  SetShort("a wooden mijwiz");
  SetId( ({ "mijwiz", "bard_instrument" }) );
  SetAdjectives( ({ "wooden" }) );
  SetLong(
    "A mijwiz is a woodwind instrument, similiar to a flute.  It has two pipes "
    "and several fingering positions."
    );
  SetDamagePoints(2500);
  SetValue(350);
  SetMass(40);
  SetWeaponType("blunt");
  SetClass(4);
  SetMaterials( ({ "wood", "natural" }) );
  SetRepairDifficulty(5);
}

 