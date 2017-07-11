#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("toy");
   SetShort("a wooden block");
   SetId( ({ "block","toy" }) );
   SetAdjectives( ({ "wooden" }) );
   SetLong("Brightly painted and carefully smoothed, this wooden block "
           "has pictures on each of its six sides.  A sparrow, a "
           "squirrel, an oak tree, a sun, a muezzin and an elf are the "
           "different pictures.  None are highly detailed, but great "
           "care went into this creation..");
   SetValue(15);
   SetVendorType(VT_TREASURE);
   SetDamageType(BLUNT);
   SetMass(5);
   SetWeaponType("blunt");
   SetDamagePoints(150);
   SetClass(3);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "wood working" : 0,
                       "natural working" : 0,
                  ]) );
   SetProperty("history","A competent craftsman in the WestWood was commissioned "
               "to make a gross of small wooden toys for the children in the "
               "Eclatish hospitals.  This is one of them, and was used by the "
               "poor kids for many years.");
}
