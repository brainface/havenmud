#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of dark brown pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","dark","brown" }) );
   SetLong("The brown pants were carefully sewn out of a "
           "rough textile.  It looks like it would be "
           "uncomfortable to wear on all but the tough "
           "skinned races.");
   SetMass(15);
   SetValue(40);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_PANTS);
   SetDamagePoints(95);
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,3);
   // SetProtection(HEAT,1);
   SetWear("The pants are rough.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetSize(SIZE_SMALL);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Inimicii, "
               "the Parva Hunter.");
}
