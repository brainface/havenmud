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
   SetShort("a pair of ragged leather pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","ragged","leather" }) );
   SetLong("The leather pants are slowly falling "
           "apart at the seams, but are of high "
           "quality as far as ogre steamstress work "
           "goes.  They can't protect much, but are "
           "basic coverings.");
   SetMass(25);
   SetSize(SIZE_LARGE);
   SetArmourClass(ARMOUR_LEATHER);
   SetArmourType(A_PANTS);
   SetValue(3);
   SetVendorType(VT_CLOTHING);
   SetDamagePoints(45);
   SetMaterial( ({ "leather" }) );
   SetWarmth(20);
   SetRepairDifficulty(1);
   SetRepairSkills( ([
      "leather working" : 0,
      ]) );
  if (environment()) {
   call_out( (: eventDeteriorate, 1 :),1);
   call_out( (: eventDeteriorate, 1 :),1);
  }
   SetProperty("history","An Urgesh shaman ogre wore these "
               "while directing a battle against Soleil.");
}
