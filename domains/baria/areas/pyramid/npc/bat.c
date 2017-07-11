/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: bat.c
// Area: the dark pyramid
//

#include <lib.h>
#include "../pyramid.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("filthy bat");
  SetShort("a filthy bat");
  SetId( ({ "bat","filthy bat" }) );
  SetRace("bat");
  SetClass("animal");
  SetMorality(-50);
  SetGender("male"); 
  SetLevel(1);
  SetLong("This horrible bat looks very old and disgusting. "
          "It is big for a mere bat but it looks weak and not "
          "well-fed."
         );
  
}
