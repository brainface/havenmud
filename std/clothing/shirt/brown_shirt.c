#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
   SetKeyName("shirt");
   SetShort("a dark brown shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "dark","brown" }) );
   SetLong("The brown shirt is made of a rough, scratchy textile.  "
           "It couldn't be too comfortable for anyone with soft, "
           "sensitive skin, to wear, but it would offer some "
           "minimal protection from attacks.");
   SetMass(5);
   SetValue(35);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetDamagePoints(75);
   //BLUNT,2);
   //SLASH,2);
   //PIERCE,2);
   //COLD,4);
   //HEAT,1);
   SetWear("The shirt is rough.");
   SetMaterial( ({ "textile" }) );
  SetWarmth(10);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
}
