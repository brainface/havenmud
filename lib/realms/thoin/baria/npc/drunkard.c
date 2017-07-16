//
//  drunk in th common hut.
//  Kyla 11-2-97
//  Modified by Rhakz - Angel Cazares
//  Date:10/13/98
// 
#include <lib.h>
#include "../jungle.h"
inherit LIB_NPC;

static void create() {
 npc::create();
  SetKeyName("drunkard");
  SetId( ({"man","drunk","drunkard" }) );
  SetAdjectives( ({ "drunk"}) );
  SetShort("a drunk man");
  SetGender("male");
  SetRace("human");
  SetClass("fighter");
  SetTown("Baria");
  SetInventory( ([
                  BARIA_OBJ + "coconut" : "wield coconut",
              ]) );
  SetMorality(-10);
  SetLevel(7);
  SetCurrency( ([
                 "chits" : random(25)+5,
             ]) );
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetLong("This poor man is very dirty and smells of concentrated "
          "alcohol. He looks very drunk and as if he was about to "
          "fall to the ground."
         );
  SetAction(4, ({ 
                  "!emote burps rudely.",
                  "!say E'er...would ye buy me a mug 'o ale?",
                  "!lay down"                  
           }) );
}


