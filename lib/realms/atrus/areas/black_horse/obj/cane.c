/* A weapon sheath in a cane that can also be used as a blunt weapon. */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../bhi.h"
inherit LIB_ITEM;
inherit LIB_STORAGE;


static void create() 
  {
  ::create();
  SetKeyName("steel cane");
  SetId( ({ "cane" }) );
  SetAdjectives( ({ "steel", "holding" }) );
  SetShort("a steel cane");
  SetLong("This long steel cane has been polished to a bright sheen with inlaid "
          "ivy vines scrolled along the entire length of the shaft. The foot has "
          "a weighted pointy end which looks like it will do significant damage.");
  SetProperty("magic", "This reinforced steel cane has been masterfully crafted "
              "to the highest of standards. The cane has been enchanted to hold "
              "any size weapon in its shaft like a sheath.");
  SetProperty("history", "The history of this weapon and its hidden containment "
              "compartment were the design of a great metalweaver named Fizzle "
              "Mandrake. He has a love for trinkets and weapons and looked for "
              "impressive ways to incorporate each into the other.");
  SetMass(25);
  SetValue(3000);
  SetVendorType(VT_WEAPON);
  SetClass(35);
  SetDamagePoints(2000);
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  SetRepairSkills( ([ "metal working" : 105,]) );
  SetRepairDifficulty(60);
  SetCanClose(0);
  SetClosed(0);
  SetMaxCarry(500);
  SetInventory( ([ BHI_OBJ + "epee" : 1, ]) );
  }


int CanReceive(object ob) 
   { 
     return ::CanReceive(ob) 
     && ( sizeof(all_inventory(this_object())) < 1 ) 
     && inherits(LIB_WEAPON, ob);
   }
