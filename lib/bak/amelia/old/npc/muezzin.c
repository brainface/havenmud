#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("muezzin child");
   SetId( ({ "muezzin child","muezzin","child" }) );
   SetShort("a muezzin child");
   SetLong("The muezzin child smiles happily.");
   SetLevel(1);
   SetRace("muezzin");
   SetClass("valkyr");
   SetGender("male");
}
