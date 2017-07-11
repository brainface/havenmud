/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: ryl.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 19th, 1998
// Abstract: Ryl, Evoker Extra Spell Teacher
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("ryl");
   SetShort("Ryl the Grand Magician");
   SetId( ({ "ryl", "evoker","magician","grand magician" }) );
   SetRace("sprite");
   SetClass("evoker");
   SetGender("male");
   SetTown("Jidoor");
   SetFreeEquip( ([ 
      "/std/weapon/pole/staff" : 1,
   ]) );
   SetPlayerTitles( ([ 
      "newbie" : "the Neophyte of Evokation",
      "mortal" : "the Professional Evoker",
      "hm" : "the Grand Magician",
      "legend" : "the Thaumaturgist of Destruction",
      "avatar" : "the Shatterer of Worlds",
      "rogue" : "the Spellweaver in the Shadows",
      "cavalier" : "the Militant Wizard",
   ]) );
   SetLevel(25);
   SetMorality(30);
   SetLong("Ryl, a somewhat small sprite, stands about 11 inches in length. "
           "He appears to be someone who stands here as a resource for young "
           "evokers.");
  SetSpellBook( ([ 
/*01*/      "capsule" : 100,
/*02*/      "energy field" : 100,
/*03*/      "acid blast" : 100,
/*04*/      "acid rain" : 100,
/*05*/      "bolt" : 100,
/*06*/      "sphere" : 100,
/*07*/      "lava storm" : 100,
/*08*/      "dispel invisibility" : 100,
/*09*/      "dispel protections" : 100,
/*10*/      "shock" : 100,
/*11*/      "missile" : 100,
/*12*/      "terra" : 100,
/*13*/      "buffer" : 100,
/*14*/      "aura" : 100,
/*15*/      "invisibility" : 100,
/*16*/      "cloud kill" : 100,
/*17*/      "channeling" : 100,
/*18*/      "fireball": 100,
/*19*/      
/*20*/         
             ]) );
   SetCombatAction(20, ({ 
      "!cast bolt",
      "!cast acid blast",
      "!cast aura",
      "!cast energy field",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
}
