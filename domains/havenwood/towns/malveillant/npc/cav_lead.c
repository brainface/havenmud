/*  Portia  10-23-98
   A cavalier Leader.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("varan");
  SetShort("Varan of the Royal Guard");
  SetLong("Varan is a large man, and very proud. His main duties "
          "are to recruit new members to the Royal Guard and protect "
          "the Prince of Malveillant at all costs.");
  SetRace("dark-elf"); 
  SetTown("Malveillant");
  SetMorality(-200);
  SetGender("male");
  SetClass("cavalier");
  SetSkill("cloth armour",1,2);
  SetLevel(80);
  SetCurrency("roni",random(600) + 40);
  SetInventory( ([
      MAL_OBJ + "/clothing/lead_plate"  : "wear plate",
      MAL_OBJ + "/clothing/g_pants"     : "wear pants",
      MAL_OBJ + "/clothing/g_boots"     : "wear boots",
      MAL_OBJ + "/clothing/g_medallion" : "wear medallion",
      MAL_OBJ + "/weapons/gl_sword"     : "wield sword",
      ]) );

  SetAction(6,
     "!say would you like to join the Royal Guard?");
  SetFreeEquip( ([
    "/std/weapon/slash/sword" : 1,
    ]) );
  SetPlayerTitles( ([
      "necromancer" : "the Dark Protector of Malveillant",
      "newbie"      : "the Initiate Guard of Malveillant",
      "mortal"      : "the Guard of Malveillant",
      "hm"          : "the Royal Guard of Malveillant",
      "legend"      : "the Protector of Malveillant",
      "avatar"      : "the Protector of Prince Marikian",
      ]) );
  }
