// Amelia
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("pants");
   SetShort("a pair of leather pants");
   SetId( ({ "pants","pair" }) );
   SetAdjectives( ({ "pair of","leather","brown" }) );
   SetLong("Made of a softened leather, these tough pants are a decent "
           "form of protection from physical attacks.");
   SetArmourType(A_PANTS);
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(4);
   SetValue(300);
   SetDamagePoints(450);
   SetProperty("multiples",1);
   SetSize(SIZE_MEDIUM);
}
