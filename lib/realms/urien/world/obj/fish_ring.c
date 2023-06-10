// A ring for the "small" merchant classers
// Urien@Haven 06JUN2023

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  ::create();
  SetKeyName("teal ring");
  SetId(( { "ring","teal ring"} ));
  SetShort("a teal ring");
  SetLong("Two bands of bright teal pigment have been painted on top "
          "of the main body openings of the wooden ring. The entire body "
          "has a very thin layer of gloss which reflects a dim portion "
          "of natural lighting. Dark black char marks in the wood grain "
          "illustrate a superior quality in the craft itself.");
  SetMass(1);
  SetValue(random(20)+35);
  SetDamagePoints(80);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_SMALL);
  SetArmourType(A_RING);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetMaterial( ({ "wood" }) );
//  SetProtectionBonus(BARGAINING, 1);
//  SetProtectionBonus(STEALTH, -2);  
  SetWear("As the teal ring slips on your finger a soft whisper is heard.");

  SetProperty("history",
  "It has been passed within numerous muezzin generations to the "
  "clansfolk who travel the unknown paths of Kailie in search "
  "of wealth and treasure. The complete total history is faint "
  "and echoes of only modern existence and exposure."
   );
  SetProperty("magic", 
  "The magic properties endowed in this ring is to pull a tiny "
  "appeal to charm. It will enhance the bargaining power "
  "of those in sales and if worn, the wearer will be less likely "
  "to move stealthily as its design is eye catching and the "
  "bright teal color is very easy to identify. Even in large "
  "crowds."); 
}
