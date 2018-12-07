// Mahkefel@haven
// I just want this to read "scabbard"
// needs "only weapon" limitation
#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_WORN_STORAGE;

static void create()
{
  ::create();
  SetKeyName("scabbard");
  SetId( ({ "scabbard" }) );
  SetAdjectives( ({ "belt"}) );
  SetShort("a belt scabbard");
  SetLong(
    "A leather belt and sturdy buckle with sheathes and hooks for several "
    "weapons, tools, or miscellaneous instruments of violence."
  );
  SetMass(20);
  SetMaterials( ({ "leather" }) );
  SetValue(100);
  SetMaxCarry(1000);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BELT);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(700);
}

int CanReceive(object ob) {
  if(!ob->GetWeaponType()) {
    this_player()->eventPrint("You can't fit that in the scabbard, it's not "
      "remotely weaponlike.");
    return 0;
  }
  return worn_storage::CanReceive(ob);
}


