//Samah@Haven
//20040911
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>

#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("tattered shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ 
      "tattered",
      "soaked"
   }) );
   SetShort("a tattered shirt");
   SetLong(
      "This plain looking shirt was at one point "
      "a relatively nice article of clothing.  "
      "However, the shirt is barely worthy of the "
      "title as it dangles in strips of cloth.  "
      "The shirt is soaked through, and appears to provide "
      "less then nothing in the sense of warmth."
   );
   SetArmourType(A_SHIRT);
   SetVendorType(VT_CLOTHING);
   SetMass(10);
   SetArmourClass(ARMOUR_CLOTH);
   SetMaterials("textile");
   SetDamagePoints(10);
   SetWarmth(-5);
   SetValue(0);
   SetSize(SIZE_SMALL);
   SetRepairDifficulty(5);
}

/** Approved by Laoise at Sat Sep 11 20:28:17 2004. **/
