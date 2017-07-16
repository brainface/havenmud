// Amelia@Haven

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;
 
static void create() {
   armour::create();
   SetDestroyOnSell(1);
   SetKeyName("jacket");
   SetId( ({ "jacket","coat" }) );
   SetAdjectives( ({ "leather" }) );
   SetShort("a leather jacket");
   SetLong("This leather jacker was carefully made.  It is "
           "soft and pliable and appears like it would offer "
           "some amount of protection.");
   SetMass(20);
   SetValue(45);
   SetDamagePoints(150);
   SetSize(SIZE_SMALL);
   SetArmourClass(ARMOUR_LEATHER);
   SetVendorType(VT_ARMOUR);
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,5);
   // SetProtection(HEAT,1);
   SetArmourType(A_VEST);
   SetMaterial( ({ "leather" }) );
   SetWarmth(35);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetRepairDifficulty(6);
   SetProperty("history","A wandering adventurer was wearing this "
               "fine leather jacket when a gnome waylaid him and "
               "stole it, along with the adventurers money pouch "
               "and a few other items.  The others drifted out of "
               "the gnome's possession before another adventurer "
               "killed the gnome and took this jacket from him.");
}
