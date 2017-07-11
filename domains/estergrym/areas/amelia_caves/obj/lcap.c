// Amelia@Haven

#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetDestroyOnSell(1);
   SetKeyName("cap");
   SetId( ({ "cap" }) );
   SetAdjectives( ({ "leather" }) );
   SetShort("a leather cap");
   SetLong("This leather cap might protect one's head a little.");
   SetMass(10);
   SetValue(15);
   SetArmourClass(ARMOUR_LEATHER);
   SetVendorType(VT_ARMOUR);
   SetSize(SIZE_SMALL);
   SetDamagePoints(50);
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,2);
   SetArmourType(A_HELMET);
   SetMaterial( ({ "leather" }) );
   SetWarmth(5);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetRepairDifficulty(6);
   SetProperty("history","An old gnome in the Estergrym Mountains "
               "recieved this hat from a kind adventurer that "
               "took pity on him in his dishelved state.  "
               "The hat travelled to the mountains "
               "from the Southern Coast, venturing into Grymxoria "
               "during its stay with the gnome.");
}
