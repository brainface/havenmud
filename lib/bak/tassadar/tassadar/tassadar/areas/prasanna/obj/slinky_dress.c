#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

int CheckGender();

static void create() {
  armour::create();
  SetKeyName("dress");
  SetId(( { "dress" } ));
  SetAdjectives( ({"beautiful","black","silk" }) );
  SetShort("a black silk dress");
  SetLong("This long black silk dress is astoundingly beautiful "
          "and in the light, appears almost liquid. It was "
          "obviously made to be quite attractive and comfortable.");
  SetMass(50);
  SetWarmth(15);
  SetValue(70);
  SetDamagePoints(150);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_ARMOUR);
  SetWear( (:CheckGender:));
}

int CheckGender()
{
  if(this_player()->GetGender() == "female")
  {
          message("environment",
            "The dress slides on and feels really really sexy... ",
            this_player());
          message("environment",
            this_player()->GetName() + " slides into a black silk dress and "
            "looks sexy.",
            environment(this_player()),this_player());
                  }
        else
        {
          message("environment",
            "You slide into the black silk dress.",
            this_player());
          message("environment",
            this_player()->GetName() + " pulls the transvestite thing and slips "
            "into a black silk dress.",
            environment(this_player()),this_player());
                  }
}
