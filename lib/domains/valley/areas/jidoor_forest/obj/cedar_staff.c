/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: cedar_staff.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is a cedar staff.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
  {
  item::create();
  SetKeyName("staff");
  SetShort("a cedar staff");
  SetLong("This long branch from a cedar tree has been carved with "
          "runes and symbols.  It would make a fine weapon in the "
          "right hands, but would also help one walk around if used "
          "as a walking stick.");
  SetHands(2);
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "cedar" }) );
  SetClass(16);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetDamagePoints(1200);
  SetValue(350);
  SetMass(150);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(20);
  SetRepairSkills( ([
                     "wood working" : 10,
                     "weapon smithing" : 10,
                 ]) );
  }
