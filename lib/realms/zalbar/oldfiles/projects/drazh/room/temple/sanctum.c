// by Dahaka
// Aug 2004

#include <lib.h>
#include <domains.h>
#include "../../drazh.h"

inherit LIB_CHAPEL;


static void create() {
  ::create();
  SetTown("Drazh");
  SetClimate("underground");
  SetAmbientLight(35);
  SetShort("Sanctum of Melchezidek");
  SetLong(
     "The room has one main entrance, through the massive archway, and twelve "
     "smaller entrances around this massive room. The entire floor of this "
     "circular chamber is a massive symbol to Melchezidek. At the end of the room, "
     "on a massive dais, is a giant altar and pulpit. On the pulpit is a "
     "massive book and spread across the altar is a cloth bearing the symbol "
     "of the Prince of Deception, Melchezidek. Behind the dais, on a raised level, is a "
     "massive pillar of amethyst called the Pillar of Commandments.  The "
     "pillar glows with a sickening and mesmerizing inner light that seems to "
     "blur everything about it.  This huge pillar has thirteen sides, each "
     "side intricately inscribed with spidery runes."
     );
  SetItems( ([
   ({"room","sanctum","chamber"}) : (: GetLong :),
   ({"entrance","archway"}) :
   "The massive archway is the main entrance from Drazh to the Sanctum of "
   "Melchezidek.",
   ({"floor","symbol","pentagram","head"}) :
   "The stone floor is covered in the symbol of Melchezidek, a gaint rat head "
   "with horns inside a pentagram.",
   ({"dais","end of room"}) :
   "This massive dais has been carved out of the stone when the masons created "
   "chamber. On the dais, the stone altar and stone pulpit also have been carved out "
   "the same way.",
   ({"altar"}) :
   "Spread across the top of the gaint stone carved altar is a cloth with "
   "symbols of the Prince of Deception, Melchezidek embroidered on it. Sunk "
   "into the surface of the altar is a brass bowl.",
   ({"cloth"}) :
   "The black and red cloth is spread across the gaint altar. Symbols of Melchezidek, "
   "an equilateral triangle, consisting of three overlapping lines, with one of "
   "the points facing down are embroidered into the cloth.",
   ({"bowl"}) :
   "A massive brass bowl, covered in runes obscured by the dry flaking blood, "
   "is sunk into the surface of the stone carved altar.",
   ({"pulpit"}) :
   "The stone pulpit, carved out of the stone when masons created this chamber, "
   "is only raised a few feet above the dais to overlook the Sanctum of Melchezidek.",
   ({"level"}) :
   "Behind the dais, on a raised level is a massive pillar of amethyst.",
   ({"amethyst","pillar","commandments","pillar of commandments","sides","side"}) :
   "This massive amethyst pillar is glowing a sickening and mesmerizing inner light. "
   "The pillar has thirteen sides which has been inscribed with spidery runes.",
   ({"rune","runes"}) :
   "These spidery runes are of from an ancient and forgotten language.",
   ]) );
  SetItemAdjectives( ([
    "room"      : ({"massive","circular"}),
    "entrance"  : ({"main","one"}),
    "entrances" : ({"twelve","smaller"}),
    "symbol"    : ({"massive"}),
    "dais"      : ({"stone","carved","massive"}),
    "altar"     : ({"stone","gaint","carved"}),
    "bowl"      : ({"brass","massive","sunken"}),
    "cloth"     : ({"red","black","embroidered"}),
    "pulpit"    : ({"stone","carved","raised"}),
    "level"     : ({"raised"}),
    "pillar"    : ({"amethyst","massive","commandment","commandments"}),
    "rune"      : ({"spidery"}),
    "light"     : ({"glowing","sickening","inner","mesmerizing"}),
    ]) );
  SetListen( ([
     "default" : 
     "The chamber is filled with the chanting of prayers.",
     ]) );
  SetSmell( ([
     "default" : 
     "The stench of blood fills the air.",
     ]) );
  SetInventory( ([
   V_NPC + "c_agent"        : 2,
   V_NPC + "priest_leader"  : 1,
   ]) );
  SetExits( ([
   "northeast" : V_ROOM + "temple/sanctum_ne",
   "northwest" : V_ROOM + "temple/sanctum_nw",
   "south"     : V_ROOM + "temple/sanctum_s",
   "southwest" : V_ROOM + "temple/sanctum_sw",
   "east"      : V_ROOM + "temple/entrance",
   ]) );

}