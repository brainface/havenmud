// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetKeyName("dirty gnome");
   SetId( ({ "gnome" }) );
   SetAdjectives( ({ "dirty","old","gruff","comically","comical" }) );
   SetShort("a dirty gnome");
   SetLong(
     "This dirty old gnome hobbles around with an almost "
     "comically gruff look to his face."
   );
   SetRace("gnome");
   SetGender("male");
   SetClass("rogue"); 
   SetLevel(4);
   SetMorality(10);
   SetInventory( ([ 
     C_OBJ + "lcap" : "wear cap" 
   ]) );
}
