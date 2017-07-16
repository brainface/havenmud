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
   SetLong("The ragged leather tunic is slowly falling apart. "
           "The fur still clings to most of the leather, and "
           "its making just barely allows it to fit an ogre "
           "and stay on without being too big, too small, or "
           "falling off.");
   SetMass(25);
   SetSize(SIZE_LARGE);
   SetArmourClass(ARMOUR_LEATHER);
   SetArmourType(A_SHIRT);
   SetValue(1);
   SetVendorType(VT_CLOTHING);
   SetDamagePoints(45);
   SetMaterial( ({ "leather" }) );
   SetWarmth(15);
   SetRepairDifficulty(1);
   SetRepairSkills( ([
      "leather working" : 0,
      ]) );
   call_out( (: eventDeteriorate, 1 :),1);
   call_out( (: eventDeteriorate, 1 :),1);
   SetProperty("history","The tunic was worn by an ogre during "
               "a battle against Soleil.");
}
