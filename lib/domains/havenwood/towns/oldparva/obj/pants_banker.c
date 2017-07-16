#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of grey pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","grey","gray" }) );
   SetLong("A talented seamstress sewed these from a plain "
           "grey material.  The seams securely hold the "
           "pieces together, and the material itself is fairly "
           "durable and hardy against normal wear.");
   SetMass(20);
   SetValue(20);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_PANTS);
   SetDamagePoints(100);
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,4);
   // SetProtection(HEAT,1);
   SetWear("The pants are a little rough on the inside.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Magnum, Parva Banker.");
}
