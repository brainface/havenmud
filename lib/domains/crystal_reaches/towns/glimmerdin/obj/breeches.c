#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("breeches");
  SetId( ({ "breeches", "pants" }) );
  SetAdjectives( ({ "small", "pair", "leather", }) );
  SetShort("a small pair of leather breeches");
  SetLong(
    "Signs of wear mark the knees and cuffs of the leather breeches."
    );
  SetVendorType(VT_ARMOUR);
  SetMass(50);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_SMALL);
  SetValue(80);
  SetDamagePoints(2000);
  // SetProtection(BLUNT,  8);
  // SetProtection(PIERCE, 8);
  // SetProtection(SLASH, 12);
  // SetProtection(COLD,   3);
  SetArmourType(A_PANTS);
  SetMaterial( ({ "leather" }) );
  SetWarmth(15);
  SetRepairSkills( ([
    "leather working" : 3,
    ]) );
  SetRepairDifficulty(10);
}
