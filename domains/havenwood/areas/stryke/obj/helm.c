/*  A hard hat */
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helmet");
  SetShort("a steel helmet");
  SetId( ({ "helmet" }) );
  SetAdjectives( ({ "steel" }) );
  // SetProtection(SLASH, 6);
  // SetProtection(BLUNT, 10);
  // SetProtection(PIERCE, 8);
  SetVendorType(VT_ARMOUR);
  SetMass(60);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetLong("This is a steel helmet ideally designed to protect the head "
          "while caving.");
  SetValue(80);
  SetArmourClass(ARMOUR_PLATE);
  SetArmourType(A_HELMET);
  }
