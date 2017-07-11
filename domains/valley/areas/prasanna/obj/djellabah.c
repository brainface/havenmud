/* A robe of silk */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {

  armour::create();
  SetKeyName("djellabah");
  SetShort("a black silk robe");
  SetId( ({ 
    "djellabah", 
    "robe" 
    }) );
  SetAdjectives( ({ 
    "thin", 
    "cloth", 
    "black",
    "silk", 
    "beautiful", 
    "belted",
    "fashionable" 
    }) );
  SetLong("This fine, sandwashed black silk robe is beautiful beyond "
          "words. Belted at the waist, it looks capable of taking a "
          "small amount of damage, but is clearly more fashionable "
          "than functional.");
  SetMass(45);
  SetArmourClass(ARMOUR_CLOTH);
  SetValue(100);
  SetMaterial( ({ "textile" }) );
  SetWarmth(20);
  SetRepairDifficulty(10);
  SetRepairSkills( ([
    "textile working" : 2,
    "armour smithing" : 2,
    ]) );
  SetDamagePoints(190);
  // SetProtection(HEAT, 5);
  SetArmourType(A_BODY_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetVendorType(VT_CLOTHING);
  }
