/* ----------------------------------------------------------------------- */

// Area Title: Jidoor Forest
// Filename: soft_boots.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is a just a pair of soft boots.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() 
  {
  armour::create();
  SetKeyName("a pair of soft leather boots");
  SetId( ({ "boots","soft" }) );
  SetAdjectives( ({ "soft","leather" }) );
  SetShort("a pair of soft leather boots");
  SetLong("Made from a softened leather, these boots look very "
          "comfortable and warm.  They do not appear very "
          "durable, but they do look light.");
  SetVendorType(VT_CLOTHING);
  SetMass(40);
  SetValue(200);
  SetArmourClass(ARMOUR_CLOTH);
  SetProperty("multiples", 1);
  SetDamagePoints(350);
  SetArmourType(A_BOOT);
  // SetProtection(ACID, 5);
  // SetProtection(PIERCE, 5);
  // SetProtection(BLUNT, 5);
  // SetProtection(SLASH, 5);
  // SetProtection(COLD, 5);
  // SetProtection(HEAT, 5);
  SetMaterial( ({"leather"}) );
  SetWarmth(5);
  SetRepairSkills( (["leather working" : 3,]) );
  SetRepairDifficulty(11);
  }

