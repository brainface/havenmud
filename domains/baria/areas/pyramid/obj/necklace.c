/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: necklace.c
// Area: the dark pyramid
//

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("necklace");
  SetId( ({ "necklace","feathered necklace" }) );
  SetShort("a feathered necklace");
  SetLong("A beautiful necklace made out of pearls linked together. "
          "From each pearl, several feathers that differ in color "
          "are hung. It's purpose its more decorative than "
          "protective." 
         );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_AMULET);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(50);
  SetValue(150);
  SetDamagePoints(200);
  SetSize(SIZE_MEDIUM);
  SetMaterials( ({ "natural" }) );
  SetWarmth(0);
  SetRepairDifficulty(5);
  SetRepairSkills( ([
                     "natural working" : 5,
                     "armour smithing" : 5,
                 ]) );
  SetProperties( ([
                   "history" : "The beautiful necklace was specially "
                               "made for decorative purposes of some "
                               "stone statues." 
                ]) );
}
