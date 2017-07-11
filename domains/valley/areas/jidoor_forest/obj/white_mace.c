/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: white_mace.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 23rd, 1998
// Abstract: This is a white mace used by the wandering priest.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create()
  {
  item::create();
  SetKeyName("white mace");
  SetId( ({ "mace", "white mace" }) );
  SetShort("a white mace");
  SetLong("This white mace used to belong to a priest of the Magildan "
          "faith.  It appears to be a good weapon.");
  SetAdjectives( ({ "white" }) );
  SetValue(350);
  SetDamagePoints(800);
  SetMass(50);
  SetClass(13);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "wood" }) );
  SetRepairDifficulty(20);
  SetRepairSkills( ([
                     "wood working" : 10,
                     "weapon smithing" : 10,
                 ]) );

  }
