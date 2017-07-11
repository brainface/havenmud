#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
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
   SetSize(SIZE_SMALL);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_PANTS);
   SetDamagePoints(95);
   //BLUNT,2);
   //SLASH,2);
   //PIERCE,2);
   //COLD,3);
   //HEAT,1);
   SetWear("The pants are rough.");
   SetMaterial( ({ "textile" }) );
  SetWarmth(10);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
}
