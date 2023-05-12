// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is tin2.c Tin Road 2 - West hillcrest of the road

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : "tin1",
    "east" : "tin3",
    ]) );
  SetShort("the top of Tin Road Hill");
  SetLong("Widely regarded as the best block of Tin Road, it is looked on as a "
      "respite from climbing up the hill from the east.  Just down the hill "
      "is the beginning of the Circle of Forges with the Tin Forge just ahead. "
      "When descending from the top travelling east caravaners must keep a firm "
      "grip of their reins. "
      "Deep gutters line both sides of the road, allowing refuse and trash to be "
      "washed away by an endless supply of water. The beginnings of commerce "
      "proper begin to show here with a cafe and a small shop. "
      "The cave walls give a dim twinkle from homes far above. From this vantage "
      "the buildings of the center city begin to show their scale. "
      "Troughs and pipes tumble and mass between the buildings with a varied glow. "
      "The mist above obscures most of the roof of the cavern. "
      "Waterfalls from obscurity wet random parts of the road. A great many machines "
      "labor away in their programmed tasks tending the city and her denizens."    
  );
      

  SetItems( ([
   ({ "hill", "west", "out" }) : "The portal opening to the west is lost to "
   "terrain. The main gate to the world lies far off to the west, opening to "
   "the surface. To the east the hill becomes steeper still as it descends "
   "towards center city.",
   ({ "walls", "cave", "ceiling" }) : "This vast cave seems to have been naturally "
    "made. Lava tubes shoot off in several directions around the perimeter of the "
    "city limits. A faint twinkle shows the presence of nook homes along the "
    "walls, however they are hard to make out. Vast waterfalls cascade out of the "
    "seeming nothingness wetting the road.",
    ({ "trough", "troughs", "material", "metal" }) : "Long glowing troughs tumble "
    "between the buildings, carrying precious metals and other raw materials "
    "to the various forges throughout the center of the city. Strange seeming "
    "colors, reds, greens and even blues seem to intermingle through the streets.",
   ({ "machine", "machines", "cogwork", "cogs", "cog", "steamwork" }) :
    "Huge lumbering machines tower over several buildings in the center of the city "
    "off to the east. The tops of which are just visible over the rooftops. "
    "Cogworks and steamworks "
    "move power throughout the city from large lava run generators converting "
    "endless amounts of water into steam, just to light the paths.",
   ({ "buildings", "building", "city", "east" }) : "The buildings to the east are "
   "about eye level to rooftop, with quite a few exceptions. Some grands and tall "
    "spindle up into the darkness. Others are a bit more squat. But every building "
    "seems to have a spot carved out specifically for the footprint of the design.",
   ({ "nook", "nooks", "houses", "house", "crannies", "home", "homes" }) :
    "The walls of the cave that make up Mount Trogg are stunning with "
    "thousands of tiny twinkling lights. The individual homes blend together to make "
    "a kaleidoscopeing effect in the lower light of the cave.",
   ({ "stalactites", "stalactite", "mist", "fog", "steam", "eddies" }) :
    "The thick cloud of steam that seems to hang above the city is a byproduct of "
    "the steamworks and forges throughout the city. A truly epic amount of power is "
    "being harnessed on every street by machines. The whole city lives under a "
    "perpetual storm cloud of it's own making. The stalactites are rarely visible.",
   ({ "waterfalls", "waterfall", "cascade", "cascades" }) : 
    "Snowmelt and rain from the slopes of the great Mount Trogg provide a permanent "
    "supply of water to the city below. Endlessly tall cascades of twinkling water "
    "catch and throw every color of light the city can provide. It appears the city "
    "has a perpetual rain storm lingering above it. Though the rain never moves. "
    "Steadily and timelessly the waterfalls fill the network of infrastructure below.",
   ({ "street", "streets", "bridge", "bridges", "network", "wheel", "wagon wheel" }) : 
   "An intricate network creating the visage of a spoked wagon wheel "
    "stands out in the illumination of the streets in the city below. "
    "The forge ring can clearly be seen surrounding the bazaar circle at the center of "
    "the city. Ornate bridges can be seen arching over rivers of molten metal. "
    "It seems the city was well planned out before a single building was "
    "constructed within the cave itself. The Outer Ring Road is past the opening to the "
    "west, and the forges and center city are to the east.",
   ({ "forge", "forges", "ring", "circle of forges", "chimney", "chimneys" }) :
    "Just east of here is the Circle of Forges. The Tin Forge is blocking out half "
    "the city from here. To the northeast the Copper Forge spits poisonous gasses. "
    "To the southeast, the Ironforge of Floeholm shoots sparks and fire from it's "
    "chimneys. "
    "The tin forge material tumbles down stepped blocks in the trough, "
    "and throws off an impressive amount of heat.",
   ({ "lava", "tin", "liquids" }) : "The series of troughs running parallel to the road "
    "carry primarily tin and lava to the forge. The liquids boil and spit as they "
    "travel at great speeds towards their destinations.",
   
   ({ "gutter", "gutters", "refuse", "water"}) : "Deep gutters run down both sides of "
   "road allowing for swift refuse and waste extraction down to the depths of the city."
   "Fast moving water sweeps away anything placed in the gutters.",
    
   ({ "generator", "generators", "lava generator", "lava generators", "spire", 
      "spires" }) : 
    "Throughout the streets are generators pulling lava from the troughs and "
    "generating rotational power, or steam power. Their placement suggests they power "
    "everything from homes to machines. Naptha and water pipes split off the bottom "
    "of each spired generator.",
    ({ "mountain", "mount", "trogg", "mount trogg", "floeholm", "underland" }) : 
        (: GetLong :),
    
    ({ "shop", "tin shop" }) : "A small shop stands on the north side of the street. "
    "It has it's own small bridge allowing entrance over the river of moltem tin "
    "flowing towards the forge.  The sign reads, 'Tim's Tin Works'.",
    
    "cafe" : "A very inviting cafe has been built on the south side of the road. "
    "There is an outside seating area straddling metal grates over the water troughs. "
    "the air is pleasant when approaching as it commonly smells of sweets and "
    "confectionary. The sign reads, 'Sandy's Sweets'",  
        
    ]) );

  SetSmell("The smell of confectionary wafts in the street.");
  SetListen("Hisses and clanks punctuated by harsh booms echo to the east.");

SetInventory( ([ 
   UNDER_OBJ + "sandysign" : 1,
   UNDER_OBJ + "timsign" : 1, 
]) ); 
  SetEnters( ([
    "cafe" : UNDER_ROOM "tincafe",
    "shop" : UNDER_ROOM "tinshop",
    ]) );
}


