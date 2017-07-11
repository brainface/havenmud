/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: darkred_robe.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 21th, 1998
// Abstract: This is the magical robe worn by P'alirith.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;
static void create() 
  {
  ::create();
  SetProperty("history", "This item once belonged to the great mage of the "
                         "Jidoor Forest.",);
  SetProperty("magic", "This robe appears to be excellent armour by means "
                       "of protective magic casted on it.  As a result, it "
                       "does feel heavier then an average garment of it's "
                       "type.  It also has a warm feeling when the material "
                       "is touched." );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("dark red robe");
  SetArmourClass(ARMOUR_CLOTH);
  SetShort("a dark red robe");
  SetAdjectives( ({ "dark", "red" }) );
  SetId( ({ "robe" }) );
  SetLong("This fine silk garment has embroidery all through it.  It "
          "appears quite valueable.");
  SetRepairSkills( ([ "textile working" : 15,]) );
  SetMaterial( ({ "textile" }) );
  SetWarmth(25);
  SetRepairDifficulty(20);
  SetMass(110);
  SetSize(SIZE_VERY_SMALL);
  SetValue(1200);
  SetDamagePoints(600);
  // SetProtection(ACID, 35);
  // SetProtection(PIERCE, 10);
  // SetProtection(BLUNT, 10);
  // SetProtection(SLASH, 10);
  // SetProtection(MAGIC, 20);
  // SetProtection(COLD, 15);
  // SetProtection(HEAT, 15);
  // SetProtection(SHOCK, 20);
  }
