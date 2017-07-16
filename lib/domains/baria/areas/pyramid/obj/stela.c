/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: stela.c
// Area: the dark pyramid
//
#include <lib.h>
#include <vendor_types.h>
#include "../pyramid.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ethereal stela");
  SetDamagePoints(100);
  SetShort("an ethereal stela");
  SetLong("This large stela looks like if it was only an illusion. "
          "If it was solid, it would appear to be made out of a "
          "greyish stone with several figures and signs carved on "
          "it. Perhaps reading the stela would be wise."
         );
  SetId( ({ "stela" }) );
  SetMaterial( ({ "natural" }) );
  SetAdjectives( ({"ethereal","large","greyish"}) );
  SetValue(1);
  SetMass(20);
  SetVendorType(VT_TREASURE);
  SetPreventGet("You cannot get that!");
  SetRead("Aldor mook tarn dul dos tuth gith rej teth murg");
}
