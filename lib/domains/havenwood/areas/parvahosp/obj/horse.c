#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("toy");
   SetShort("a wooden horse");
   SetId( ({ "horse","toy" }) );
   SetAdjectives( ({ "wooden" }) );
   SetLong("About the size of a grown human's hand, the wooden horse is carefully "
           "detailed and painted.  Its legs move back and forth, and the tail and "
           "mane are made from real horse hairs.");
   SetValue(35);
   SetVendorType(VT_TREASURE);
   SetDamageType(BLUNT);
   SetMass(5);
   SetWeaponType("blunt");
   SetDamagePoints(50);
   SetClass(2);
   SetMaterial( ({ "wood","natural" }) );
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "wood working" : 0,
                       "natural working" : 0,
                  ]) );
   SetProperty("history","A competent craftsman in the WestWood was commissioned "
               "to make a gross of small wooden toys for the children in the "
               "Eclatish hospitals.  This is one of them, and was used by the "
               "poor kids for many years.");
}
