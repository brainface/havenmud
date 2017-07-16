// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
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
   SetMorality(20);
   SetInventory( ([ 
     C_OBJ + "lcoat" : "wear jacket" 
   ]) );
}
