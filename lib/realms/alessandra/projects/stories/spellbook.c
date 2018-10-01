/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: spellbook.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1997
// Abstract: This magical item can be used to 
//           cast aura on oneself.  After that it
//           becomes a roleplaying aid.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 25th, 1998 - Dragon color changed to green
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() 
  {
  item::create();
  SetKeyName("spellbook");
  SetShort("a mystical spellbook");
  SetId( ({ "book","spellbook" }) );
  SetAdjectives( ({ "mystical" }) );
  SetLong("Although worn with age, the writing in the spellbook is "
           "easily read.  The cover depicts an magnificent green "
           "dragon.");
  SetMass(10);
  SetVendorType(VT_TREASURE);
  SetValue(1);
  SetRead("The words are easily seen but written in a strange and "
           "archaic language.  Judging by the diagrams and such, it "
           "appears to be a spellbook of some sort.");
  }

