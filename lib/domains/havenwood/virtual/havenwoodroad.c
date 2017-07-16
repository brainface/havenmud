#include <lib.h>
inherit LIB_ROOM;
#define END "/domains/havenwood/virtual/parvaroad/0,237"
#define START "/domains/southern_cost/virtual/havenroad/0,0"
#define ESTER "/domains/estergrym/virtual/estergrym_road/0,230"
#define ME "/domains/havenwood/virtual/havenwoodroad/"
#define NPCS "/domains/havenwood/virtual/npc"

static int XPosition, YPosition;

static void create(int x, int y) {
   string thelong = "";
   mapping items = ([ ]), itemadjs = ([ ]), inv = ([ ]);
   SetNoReplace(1);
   ::create();
   SetDomain("HavenWood");
   SetClimate("temperate");
   XPosition = x;
   YPosition = y;
   SetShort("the HavenWood Road");
   thelong += "The HavenWood Road is wide and "
              "dusty; the surrounding trees "
              "have a thin layer of dust on "
              "them.";
   items += ([ ({ "HavenWood forest","forest",
                  "havenwood" }) :
                  "The HavenWood forest is made up "
                  "of deciduous trees, coated with "
                  "a thin layer of dust.  Their leaves "
                  "shade the road.",
               ({ "deciduous trees","trees","tree" }) :
                  "The trees shade the road slightly, "
                  "their leaves blowing in the light "
                  "wind.",
               ({ "shaded leaves","leaves","leaf" }) :
                  "The leaves are all green, with some "
                  "light tan dusty covering them and "
                  "making them look old and dry.",
               ({ "dust layer","layer","dust" }) :
                  "The dust lies around the forest, "
                  "coating everything in sight.",
            ]);
   itemadjs += ([ "forest" : ({ "havenwood","deciduous" }),
                  "trees" : ({ "deciduous" }),
                  "leaves" : ({ "shaded","green" }),
                  "dust" : ({ "layer of","thin" }),
               ]);
   if(y == 126) {
      AddExit("southwest",START);
      AddExit("northeast",ME + (x+1) + "," + (y+1));
      thelong += " The road appears to come to "
                 "an end at Haven Road to the southwest, but "
                 "continues to the northeast for "
                 "quite a while.";
      items += ([ ({ "HavenWood road","road" }) :
                     "The road weaves through the "
                     "HavenWood forest in a straight "
                     "manner, ending beyond the forest "
                     "to the southwest, disappearing "
                     "into it to the north.", ]);
      itemadjs += ([ "road" : ({ "havenwood" }) ]);
   }
   else if(y == 165) {
      AddExit("southwest",ME + (x-1) + "," + (y-1));
      thelong += " The road intersects here "
			           "with the North Road, leading to "
			           "Estergrym and points further north, "
			           "and with Parva Road, leading east to "
			           "Parva. To the southwest the road runs "
			           "through the HavenWood, towards Haven Road.";
      items += ([ ({ "HavenWood road","road" }) :
                     "Tall deciduous trees grow on "
                     "either side of the HavenWood "
                     "road, which goes through the "
                     "forest to the northeast "
                     "and southwest.", ]);
      itemadjs += ([ "road" : ({ "havenwood" }) ]);
   }
   else {
      AddExit("northeast",ME + (x+1) + "," + (y+1));
      AddExit("southwest",ME + (x-1) + "," + (y-1));
      thelong += " The road proceeds in a fairly "
                 "straight manner to the northeast "
                 "and southwest, marching forward "
                 "in both directions for quite a "
                 "while.";
      items += ([ ({ "HavenWood road","road" }) :
                     "The forest thins out as the "
                     "HavenWood road comes to an "
                     "end to the northeast.  It "
                     "goes through the forest to "
                     "the southwest for a long ways, "
                     "however.", ]);
      itemadjs += ([ "road" : ({ "havenwood" }) ]);
   }
   SetSmell( ([
                "default" : "Dusty forest smells fill the air.",
           ]) );
   SetListen( ([
                 "default" : "Noises of surrounding "
                    "animal life reach the road.",
            ]) );
   switch(random(6)) {
      case 0:
      thelong += " An old tree is strewn across the "
                 "side of the road.  Fortunately, "
                 "when it fell, it did not block "
                 "the passage.";
      items += ([ ({ "old tree","tree" }) :
                     "One of the older trees "
                     "fell down some time ago, "
                     "but the normal plants "
                     "are growing around it.",
                  ({ "normal plants","plants","plant" }) :
                     "A variety of green plants "
                     "grow in the forest.", ]);
      itemadjs += ([ "plants" : ({ "normal" }) ]);
      break;
      case 1:
      SetSmell( ([
                   "default" : "A very earthy "
                      "smell rises from the "
                      "surrounding forest.",
              ]) );
      break;
      case 2:
      SetListen( ([ "default" : "A bird sings "
                       "sweetly in the distance.",
               ]) );
      break;
      case 3:
      thelong += " The surrounding foliage "
                 "encroaches upon the road.";
      items += ([ ({ "surrounding foliage","foliage",
                     "plants" }) :
                     "The plants grow very healthy "
                     "here, encroaching upon the "
                     "road.  They appear much "
                     "thinner and smaller to the "
                     "northeast and southwest.", ]);
      itemadjs += ([ "foliage" : ({ "surrounding" }) ]);
      break;
      case 4:
      switch(random(6)) {
         case 0:
         inv += ([ NPCS + "/gelfling" : 1 ]);
         break;
         case 1:
         inv += ([ NPCS + "/parvan" : 1 ]);
         break;
      }
      break;
      case 5:
      break;
   }
   SetInventory(inv);
   SetLong(thelong);
   SetItems(items);
   SetItemAdjectives(itemadjs);
}
