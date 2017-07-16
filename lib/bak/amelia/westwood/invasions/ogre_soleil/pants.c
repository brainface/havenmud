#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of dirty leather pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","dirty","leather" }) );
   SetLong("The leather pants are grimy and dirty.  "
           "No self-respecting member of high society "
           "would be caught dead near them, nor near "
           "anyone wearing them, but ogres would find "
           "the pants fine.");
   SetMass(25);
   SetArmourType(A_PANTS);
   SetValue(1);
   SetVendorType(VT_CLOTHING);
   SetDamagePoints(45);
   SetProtection(HEAT,1);
   SetProtection(COLD,1);
   SetProtection(SLASH,1);
   SetProtection(PIERCE,1);
   SetProtection(BLUNT,1);
   SetMaterial( ({ "leather" }) );
  SetWarmth(20);
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "leather working" : 0,
                  ]) );
   call_out( (: eventDeteriorate, 1 :),1);
   call_out( (: eventDeteriorate, 1 :),1);
   SetProperty("history","These ragged pants were worn by a "
               "filthy ogre during a battle against Soleil.");
}
