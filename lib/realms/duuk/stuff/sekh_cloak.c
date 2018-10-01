//A specially made cloak for Sekh, the Soirin badass     //
//Made by Alessandra  10-2004                            //

#include <lib.h>
#include <std.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

int CheckReligion();

static void create() {
  armour::create();
  
  SetKeyName("cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "stunning", "black" }) );
  SetShort("a stunning black cloak");
  SetLong(
     "Without doubt, this black cloak is the most stunning piece of workmanship "
     "around. Almost as if black liquid, the cloak flows from the shoulders "
     "spilling gracefully to the ground. Scarlet satin lines the inside of the "
     "cloak, contrasting the midnight coloring beautifully. With the hood drawn "
     "one would become nearly invisible in the darkness. In all its glory, "
     "the clasp is the most exquisite part of the cloak. Sparkling black sapphires "
     "are arranged in the symbol of the Soirin religion, a beautiful black rose."
     );
  SetWear( (:CheckReligion:) );
        SetMaterials( ({ "textile" }) );
  SetRadiantLight(-5);
  SetMass(95);
  SetArmourClass(ARMOUR_CLOTH);
  SetValue(0);
  SetDamagePoints(1000);
  SetWarmth(20);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_CLOAK);
  SetSize(SIZE_MEDIUM);
  SetRetainOnDeath(1);
}

int CheckReligion() {
  if (this_player()->GetReligion() == "Soirin" &&
     this_player()->GetKeyName() == "sekh")  {
     send_messages("wear", 
       "$agent_name $agent_verb an exquisite looking black cloak.",
       this_player(), 0, environment(this_player()) );
     return 1;
}
  message("system", 
     "You are a heretic and not worthy of this gift!.",
     this_player() );
  return 0;
}
