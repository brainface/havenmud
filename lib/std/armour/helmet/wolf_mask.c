#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("mask");
  SetShort("a black wolf mask");
  SetId( ({ "mask" }) );
  SetAdjectives( ({ "black", "wolf" }) );
  SetLong("This mask has been carved from ebony and treated"
          " with lacquer which gives it a very slight sheen, but"
          " adds significantly to its durability. The snout of the"
          " mask is very short, with overly emphasized fangs."
          " The eye slots are wide enough to see through, but narrow"
          " enough so that ones eye movement would remain undetected"
          " while wearing it.");
  SetValue(500);
  SetMass(30);
  SetSize(SIZE_MEDIUM);
  SetWarmth(5);
  SetMaterial( ({ "natural" }) );
  SetArmourClass(ARMOUR_NATURAL);
  SetArmourType(A_HELMET);
  SetDamagePoints(450);
  SetVendorType(VT_ARMOUR);
  SetRepairSkills( ([
          "armour smithing" : 20,
          "natural working" : 20,
         ]) );   
  SetRepairDifficulty(35);
}
