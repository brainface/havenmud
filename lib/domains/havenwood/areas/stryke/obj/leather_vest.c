/*  A leather vest for the explorers */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather vest");
  SetDamagePoints(600);
  SetValue(150);
  SetMass(120);
  SetSize(SIZE_SMALL);
  SetMaterial( ({ "leather" }) );
  SetWarmth(10);
  SetRepairSkills( ([
      "leather working" : 0,
     ]) );
  SetRepairDifficulty(10);
  SetArmourClass(ARMOUR_LEATHER);
  SetShort("a lightweight vest of leather");
  SetId( ({ "vest" }) );
  SetAdjectives( ({ "leather", "lighweight" }) );
  SetArmourType(A_VEST);
  // SetProtection(SLASH, 10);
  // SetProtection(BLUNT, 4);
  // SetProtection(PIERCE, 6);
  // SetProtection(HEAT, 10);
  SetProperty("magic", "This vest has protection against heat.");
  SetVendorType(VT_ARMOUR);
  SetLong("This vest of leather is of a fine type used by gnomish "
          "explorers in their underground searches.");
  }
