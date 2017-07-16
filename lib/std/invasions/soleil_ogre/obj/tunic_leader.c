#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("tunic");
   SetShort("a ragged leather tunic");
   SetId( ({ "tunic" }) );
   SetAdjectives( ({ "ragged","leather" }) );
   SetLong("The ragged leather tunic is slowly falling apart.  "
           "The leather itself, when the tunic was created, "
           "was probably in merely marginal condition, and "
           "the tunic is falling apart due to that and the "
           "lack of skill in the steamstress.  It looks like "
           "it would be of high quality to an ogre.");
   SetMass(25);
   SetSize(SIZE_LARGE);
   SetArmourType(A_SHIRT);
   SetArmourClass(ARMOUR_LEATHER);
   SetValue(3);
   SetVendorType(VT_CLOTHING);
   SetDamagePoints(55);
   SetMaterial( ({ "leather" }) );
   SetWarmth(15);
   SetRepairDifficulty(2);
   SetRepairSkills( ([
      "leather working" : 0,
      ]) );
   call_out( (: eventDeteriorate, 1 :),1);
   SetProperty("history","This tunic was worn by an Urghesh "
               "shaman during a battle against Soleil.  The "
               "ogre led the battle.");
}
