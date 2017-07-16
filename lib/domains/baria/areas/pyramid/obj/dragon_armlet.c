/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: dragon_armlet.c
// Area: the dark pyramid
//

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dragon armlet");
  SetId( ({ "armlet" }) );
  SetAdjectives( ({"dragon"}) );  
  SetShort("a dragon armlet");
  SetLong("This armlet is made out of bone, an ancient one. "
          "It is yellowish and looks old, but it hasn't lost "
          "it's strength. It might have other properties too.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_LONG_GLOVE);
  SetArmourClass(ARMOUR_NATURAL);
  SetProperty("multiples", 1);
  SetMass(100);
  SetValue(600);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(230);
  SetDestroyOnSell(1);
  SetMaterial( ({"natural"}) );
  SetWarmth(0);
  SetProperties( ([
                   "magic" : "The armlet has magical properties "
                             "due to the nature of its creation.",
                   "history" : "This armlet was once part of a bone "
                               "of a mighty dragon who died in the "
                               "GodsWar. It was recently discovered "
                               "by Gihan, the ruins examiner."
                ]) );
}
