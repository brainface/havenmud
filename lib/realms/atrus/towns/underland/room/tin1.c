// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is tin1.c Tin Road 1 - West end of the road

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : "worc",
    "east" : "tin2",
    ]) );
  SetShort("along Tin Road");
  SetLong("The portal opening from the west gives way into a vast cave here "
      "which opens off to the east allowing below an immense collection of buildings "
      "and streets to be seen. It grows so much the cave floor also begins to descend "
      "east. The cave walls surrounding the city twinkle with "
      "far off lights from nooks cut into them. Vast troughs of material weave through "
      "the streets and bridges that make up the core of the city. Just to the east "
      "the great forge rings glow a multihued shimmer that bathes the walls of the "
      "cavern. Stalactites pepper the ceiling of the cave, if having not been an "
      "obstruction to the buildings below. Several waterfalls cascade through the "
      "mostly still air, catching glints of and throwing back a rainbow of light. "
      "Many of the buildings are billowing clouds of steam towards the top of the cave "
      "giving the stalactites an appearance of floating in fog. Many machines can be "
      "seen chugging and coughing throughout the city.");
      

  SetItems( ([
   ({ "portal", "west", "opening" }) : "To the west the residential ring is fully "
    "encased in the rock. A solid impenetrable fortress of rock seems to coalesce "
    "around the opening. Sealing away this hidden city from the world. The main "
    "gate to the world lies far off to the west, opening to the surface.",
   ({ "walls", "cave", "ceiling" }) : "This vast cave seems to have been naturally "
    "made. Lava tubes shoot off in several directions around the perimeter of the "
    "city limits. Glinting and shimmering lights twinkle with life from the "
    "nook style homes dotting the cave walls. Vast waterfalls cascade out of the "
    "seeming nothingness above the steam that lingers around the stalactites.",
    ({ "trough", "troughs", "material", "metal" }) : "Long glowing troughs zig "
    "zag throughout the city carrying precious metals and other raw materials "
    "to the various forges throughout the center of the city. Strange seeming "
    "colors, reds, greens and even blues seem to intermingle through the streets.",
   ({ "machine", "machines", "cogwork", "cogs", "cog", "steamwork" }) :
    "Huge lumbering machines tower over several buildings in the center of the city "
    "off to the east. Some resemble humans, bending and moving vast loads of "
    "goods and materials around. Other seem to pulsate and shiver as they process "
    "colossal clouds of poisonous gasses from the forges. Cogworks and steamworks "
    "move power throughout the city from large lava run generators converting "
    "endless amounts of water into steam, just to light the paths.",
   ({ "buildings", "building", "city", "east" }) : "The cave explodes open to the east "
    "allowing for vast buildings to be constructed within the cave. The center of the "
    "ceiling is lost in obscurity and there are several buildings that try to touch "
    "it. Their tops being lost in the stable layer of steam that tucks away the "
    "stalactites like trees in the fog. Several of the buildings do not even have "
    "roofs allowing the open air of the cave to keep temperatures for free. Meanwhile "
    "the giant circle of forges surrounding the center of the city give each building "
    "and eerie shadow or a long lit face leaving the rest obscured. It is a hodgepodge "
    "of color.",
   ({ "nook", "nooks", "houses", "house", "crannies", "home", "homes" }) :
    "The walls of the cave that spread away from Tin Road like wings seem to be "
    "covered in every shape and size nook. Some several stories tall, and very wide. "
    "Some give a look of opulence while others are more plain. Not a single one "
    "seems to be mistreated, at least from the outside. Clear evidence that each "
    "home is cared for, even if it isn't by it's own resident. Civic pride shows "
    "through in these simple homes hewn from the very rock of Mount Trogg.",
   ({ "stalactites", "stalactite", "mist", "fog", "steam", "eddies" }) :
    "The thick cloud of steam that seems to hang above the city is a byproduct of "
    "the steamworks and forges throughout the city. A truly epic amount of power is "
    "being harnessed on every street by machines. The whole city seems to labor as "
    "one under this gently undulating mass. The stalactites clinging to the eons "
    "old ceiling of the chamber seem to play games and move as the steam works its "
    "way between them; they appear and disappear randomly.",
   ({ "water", "waterfalls", "waterfall", "cascade", "cascades" }) : 
    "Snowmelt and rain from the slopes of the great Mount Trogg provide an endless "
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
   ({ "forge", "forges", "ring", "circle of forges" }) :
    "The inner ring road houses the four enormous forges of the gnomish city. "
    "Tin street here leads straight east to the tin forge in te Circle of Forges. It "
    "generally is the first step on a much grander picture, but every "
    "artesian started there. To the northeast the Copper Forge can be seen. "
    "To the southeast, the Ironforge of Floeholm can be seen glowing a blazen "
    "bright yellow from many of it's troughs. Far off to the east the Zinc Forge "
    "can be seen by it's almost white, bluish-green that flares from her tall stacks. "
    "The tin forge material trough runs near the path and throws off an impressive "
    "amount of heat.",
   ({ "lava", "tin", "liquids" }) : "The series of troughs running parallel to the road "
    "carry primarily tin and lava in this area. Lava to power machines, and tin to "
    "feed the forges below. The liquids boil and spit as they travel at great speeds "
    "towards their destinations.",
    
    ({ "mountain", "mount", "trogg", "mount trogg", "floeholm", "underland" }) : 
        (: GetLong :),
    ]) );

  SetSmell("There is a strangely comforting scent on the air.");
  SetListen("Far off booms betray the grand machines in the distance.");

/*
  SetEnters( ([
    "tinforge" : UNDER_ROOM "tinforge",
    ]) );
*/
}
