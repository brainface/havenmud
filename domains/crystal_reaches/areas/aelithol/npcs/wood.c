#include <lib.h>
#include "../aelithol.h"
inherit LIB_NPC;
    static void create() {
    npc::create();
    SetKeyName("woodcutter");
    SetId( ( "woodcutter") );
    SetAdjectives( ({"angry", "furious"}) );
    SetShort("a stout woodcutter");
    SetLong("This stout man sells wood to the "
      "nearby inhabitants of the hills where wood is often scarce.  "
      "Now that the trees are being killed, he is finding his work "
      "harder to complete.  He is currently working to form an "
      "adequate passage into the undergrowth.");              
    
    SetRace("human");
    SetClass("fighter");
    SetLevel(17);
    SetGender("male");
    SetMorality(100);
    SetInventory( ([
      OBJS + "/axe" : "wield axe",
      OBJS + "/pants" : "wear pants",
      OBJS + "/tunic" :  "wear tunic",
    ]) );
    SetAction(5, ({ "The woodcutter hacks furiously at the thick "
      "undergrowth." }));
}
