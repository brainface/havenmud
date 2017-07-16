#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("temperate"); 
  SetDomain("Valley");
   SetShort("an outdoor corral");
   SetLong("Just behind the cabin lies this corral. The small fenced in area "
           "looks well taken care of, and a bale of hay sits against one "
           "of the fences, half eaten. The door leads back into the cabin.");
   SetItems( ([
      ({ "door" }) :
         "This door is built from thick pine, and leads back into the cabin.", 
      ({ "two room house","small cabin","cabin","house" }) :
         "This is a small cabin, nestled deep in the woods.",
      ({ "corral","outdoor corral" }) :
         "This corral is sturdy and well-built. It looks like it could "
         "rein in a strong animal or two with no problem.",
      ({ "hay","bale of hay" }) :
         "Dried grass and weeds, and it appears it is for feeding an animal.", 
      ({ "dried grass","grass","weeds","weed" }) :
         "These plants are dried, baled, and used as hay.",      ({ "fences","fence" }) :
         "The corral has three fences build against the backside of the "
         "cabin.",
   ]) );
   SetEnters( ([
      "cabin" : PR_ROOM + "/cabin2"
   ]) );
   SetSmell( ([ 
       "default" : "The smell of vegetation and manure is strong here." 
   ]) );
   SetListen( ([
       "default" : "The sounds of the forest abound around the corral." 
   ]) );   SetInventory( ([ PR_NPC + "/stallion" : 1 ,
                    PR_NPC + "/mare" : 1 ,
   ]) );
}

