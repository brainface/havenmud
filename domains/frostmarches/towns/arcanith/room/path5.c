/*  Continuation of road  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a trail towards the mountain");
  SetClimate("arctic");
  
  SetExits( ([
     "northeast" : ROOM "/path6",
     "west"      : ROOM "/path4",
  ]) );

  SetDayLong("The small trail continues its trek across the wastes.  The "
             "mountain to the northeast seems larger and more majestic than "
             "before.  The mountain is the only landmark that breaks the "
             "flat terrain.");

  SetNightLong("The darkness cloaks the trail as it winds its way through "
               "the frozen wastes.  A silver glow on a dark silhouette to "
               "the northeast breaks the dark night.");
  SetItems( ([
    ({ "small frozen trail", "small trail", "frozen trail", "trail",
       "path" })  :
       "The small frozen trail weaves its way across the tundra.",
    ({ "frozen wastes", "frozen waste", "tundra", "terrain", "wastes", 
       "waste", "terrain", "flat terrain" })   :
       "The terrain is covered in a blanket of ice and snow.  There "
       "appears to be a mountain to the northeast.",
    ({ "blanket of ice and snow", "snow", "ice", "ice and snow", "blanket",
       "white blanket of ice and snow", "white blanket" })  :
       "A white blanket of ice and snow covers everthing for miles.",
    ({ "dark", "darkness", "embrace" })  :
       "The darkness covers everything in its embrace.",
    ({ "mountain", "dark silhouette", "silhouette" })  :
       "The mountain, to the northeast, fills the sky with its majesty.  "
       "The peak is out of sight; it is covered by clouds.  An eerie light "
       "raidiates from a plateau half way up the mountain.",
    ({ "mountain's peak", "peak" })  :
       "The mountain's peak is covered by clouds.",
    ({ "large white clouds", "large white cloud", "large clouds", "large 
        cloud", "white clouds", "white could", "cloud", "clouds" })   :
       "Large white clouds hang around the mountain's peak.",
    ({ "mountain plateau", "plateau" })  :
       "A strange silvery glow radiates from a mountain plateau.",
    ({ "strange silvery light", "strange light", "silvery light", "light",
       "eerie glow", "strange glow" })  :
       "A strange light illuminates a mountain plateau.",
   ]) );

  SetSmell( ([
    "default"  : "The cold air smells fresh and clean.  A faint hint of dirt "
                 "is carried by the wind.",
  ]) );
 
  SetListen( ([
    "default"  : "The roar of the wind is lessened slightly by the mountain.",
  ]) );

}
