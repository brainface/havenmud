// Amelia
#include <lib.h>
#include "../mines.h"
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("dwarf");
   SetShort("an enslaved dwarf");
   SetId( ({ "dwarf","slave" }) );
   SetAdjectives( ({ "enslaved" }) );
   SetLong("Short and sturdy, the dwarf reaches about shoulder-height "
           "on the average human male.  His beard is dingy and "
           "tattered, and dirt covers his body.");
   SetGender("male");
   SetSkill("blunt combat",1,1);
   SetSkill("blunt combat",1,1);
   SetRace("dwarf");
   SetLevel(21);
   SetInventory( ([
                    MINES_OBJ + "pickax" : "wield ax",
                    MINES_OBJ + "opal" : 6,
               ]) );
   SetMorality(-50);
}
