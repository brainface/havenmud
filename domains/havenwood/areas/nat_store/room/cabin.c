// mahkefel 2011
// nat arm store

#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../nat_store.h"

inherit LIB_ROOM;

static void create() {
   room::create();    
   SetShort("");      
   SetDomain("Havenwood");
   SetClimate("indoors");
   SetAmbientLight(30);  
   SetExits( ([          
      "out" : HAVENWOOD_VIRTUAL "parvapath/0,0",
   ]) );                                        
   SetShort("a taxidermist's shop");            
   SetLong(                                     
     "This dusty cabin is hewed from rough timbers, and decorated with "
     "the heads of wild stags and boars. Simple wooden mannequins stand "
     "along the center of the cabin, covered in hide armours. In "       
     "the eastern corner of the cabin sits a large vat full of some sickly "
     "yellow goop, surrounded by stretched and drying skins."               
   );                                                                       
   SetItems( ([                                                             
     ({ "cabin" }) : (: GetLong :),                                         
     ({ "timbers","ceiling" }) : "The timbers look sturdy enough, if unaesthetic.",
     ({ "heads","stags","boars"}) : "Someone is awfully proud of their "           
        "hunting abilities.",                                                      
     ({ "mannequins"}) : "Covered in simple hide armours, it looks almost "        
        "as if they were advertising wares.",                                      
     ({ "floor" }) : "The same rough-cut timbers as the ceiling and walls, "       
        "they would work hell on uncalloused feet. A few burgundy stains mar "
        "the boards where someone didn't clean well enough after dragging "
        "a carcass in.",                               
     ({ "vat","goop" }) : "You probably shouldn't drink it",
     ({ "armours" }) : "Thick bearhide and deerskin, these probably wouldn't "
        "fit in at an elven ball.",
     ({ "skins" }) : "Likely more materials for the mannequins or mounted heads.",
   ]) );
   SetItemAdjectives( ([
     "cabin" : ({ "dusty" }),
     "timbers" : ({ "rough" }),
     "heads" : ({ "wild" }),
     "mannequins" : ({ "wooden" }),
     "armours" : ({ "simple","hide" }),
     "skins" : ({ "stretched","drying" }),
   ]) );
   SetInventory( ([
      NAT_STORE_NPC "natural_seller" : 1,
      NAT_STORE_NPC "rl_seller" : 1,
      STD_OBJ "lootchest" : 2,
   ]) );
   SetProperties( ([
      "natural working" : 1,
      "wood working" : 1,
      "leather working" : 1,
      "textile working" : 1,
   ]) );
   SetListen( ([
     "default" : "The vat occasionally looses an acidic pop.",
  ]) );
   SetSmell( ([
     "default" : "The sickening smell of decaying animal flesh wars with the "
       "eye-watering aroma of the vat.",
  ]) );
}
