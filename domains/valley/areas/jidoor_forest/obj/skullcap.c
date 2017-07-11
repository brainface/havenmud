/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: skullcap.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is a mithril skullcap.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
//                   August 28th, 1998 - History and Magic Properties added
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create()
  {
  armour::create();
  SetProperty("history", "This item once belonged to the great mage of the "
                         "Jidoor Forest.",);
  SetProperty("magic", "The rare material the skullcap is made from only "
                       "begins to suggest to the actual protection this "
                       "object has. It is indeed a powerful armour for "
                       "one's head.");
  SetKeyName("skullcap");
  SetShort("a mithril skullcap");
  SetId( ({ "cap","skullcap" }) );
  SetAdjectives( ({ "mithril" }) );
  SetLong("Forged from mithril, this skullcap protects the wearer's "
          "head from damage.");
  SetMass(20);
  SetSize(SIZE_VERY_SMALL);
  SetArmourClass(ARMOUR_PLATE);
  SetValue(500);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_HELMET);
  SetDamagePoints(1000);
  SetMaterial( ({ "mithril" }) );
  SetWarmth(5);
  SetRepairDifficulty(10);
  // SetProtection(ACID, 15);
  // SetProtection(PIERCE, 15);
  // SetProtection(BLUNT, 15);
  // SetProtection(SLASH, 15);
  // SetProtection(MAGIC, 15);
  SetRepairSkills( (["mithril working" : 10,]) );
  }
