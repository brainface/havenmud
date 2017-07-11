/* ----------------------------------------------------------------------- 
// Area Title: City of Jidoor
// Filename: ryl.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 19th, 1998
// Abstract: Ryl, Evoker Extra Spell Teacher
// Revision History:  
    
    Modified by Zalbar 11/24/07
    Newbie Equipper for Sprites
 ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("ryl");
   SetShort("Ryl the Grand Magician");
   SetId( ({ "ryl", "evoker","magician","grand magician" }) );
   SetRace("sprite");
   SetGender("male");
   SetSkill("shock magic",1,2);
   SetClass("evoker");
   SetLevel(25);
   SetTown("Jidoor");
   SetFreeEquipment( ([ 
      "dress"   : JID_OBJ "/clothing/vs_dress",
      "sandals" : JID_OBJ "/clothing/vs_sandals",
      "shirt"   : JID_OBJ "/clothing/vs_shirt",
      "slacks"  : JID_OBJ "/clothing/vs_slacks",
      "vest"    : STD_ARMOUR + "free_armour/very_small/oldvest",
      "helmet"  : STD_ARMOUR + "free_armour/very_small/oldhelmet",
      "glove"   : STD_ARMOUR + "free_armour/very_small/oldglove",
      "boots"   : STD_ARMOUR + "free_armour/very_small/oldboots",
      "pants"   : STD_ARMOUR + "free_armour/very_small/oldpants", 
      ]) );
   SetLevelLimit(10);
   SetMorality(30);
   SetLong("Ryl, a somewhat small sprite, stands about eleven inches in length. "
           "He appears to be someone who stands here as a resource for young "
           "sprites of Jidoor. ");
  SetSpellBook( ([ 
      "sphere" : 100,
      "fireball": 100,
      "shock" : 100,
      ]) );
   SetCombatAction(65, ({ 
      "!cast sphere",
      "!cast fireball",
      "!cast shock",
      }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
   ]) );
}
