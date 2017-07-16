#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("young nanny");
   SetShort("a youthful nanny");
   SetId( ({ "nanny","youth" }) );
   SetAdjectives( ({ "young","youthful" }) );
   SetLong("A few strands of hair hang loose from the nanny's tight "
           "bun, but she seems more occupied with keeping children "
           "under control and alive than anything else.");
  
   SetRace("human");
   SetGender("female");
   SetClass("rogue");
   SetLevel(9);
   SetMorality(360);
   SetCurrency("nuggets",20);
   SetInventory( ([
                    VC_OBJ + "/barrette" : "wear barrette on head",
               ]) );
}