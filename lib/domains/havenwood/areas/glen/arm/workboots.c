#include <lib.h>oot.c
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetMaterial("leather");
  SetWarmth(7);
  SetRepairSkills( ([
                     "leather working" : 5,
                     "armour smithing" : 6
                 ]) );
  SetRepairDifficulty(30);
  SetKeyName("leather work boots");
  SetId(( { "leather boots","work boots",
            "leather work boots","boots"} ));
  SetShort("a pair of leather work boots");
  SetLong("The boots are made of thick, brown leather. "
          "While they appear to be of great age and to have "
          "seen much of the world, they would still offer "
          "decent protection.");
  SetMass(40);
  SetValue(60);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(700);
  
  // SetProtection(PIERCE,5);
  // SetProtection(SLASH,4);
  // SetProtection(COLD,6);
  // SetProtection(BLUNT,2);
  // SetProtection(HEAT,2);
  // SetProtection(ACID,2);
  SetSize(SIZE_SMALL);
  SetArmourType(A_BOOT);
  SetVendorType(VT_ARMOUR);
  
  SetWear("The boots feel heavy but comfortable.");
  SetProperty("multiples",1);
}
