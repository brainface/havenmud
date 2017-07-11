// averath ferry captain
// mahk '10
// '11 Aless made wearable again by noting out storage
#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;
//inherit LIB_STORAGE;

static void create() {
  ::create();
  SetKeyName("black waistcoat");
  SetShort("a black waistcoat");
  SetId( ({ "waistcoat" }) );
  SetAdjectives( ({ "black",  }) );
  SetLong(
    "This black waistcoat is made of fine silk. Three dark "
    "buttons of obsidian clasp it together in the front. The thin "
    "pockets would hold a few small objects. "
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetMass(20);
  SetValue(500);
  SetDamagePoints(500);
  SetSize(SIZE_MEDIUM);
//  SetMaxCarry(20);
//  SetCanClose(0);
  }
