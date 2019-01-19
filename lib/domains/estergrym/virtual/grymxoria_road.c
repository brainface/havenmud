// Edited by Laoise
// Altered some exits and made new set longs to match

#include <lib.h>
#include <domains.h>
#include <std.h>
inherit LIB_ROOM;

void SetLongAndItems(int, int);

varargs static void create(int x, int y) {
  string n, s, e, w, ne, nw = 0;
  string lng;
  room::create();

  SetClimate("sub-arctic");
  SetShort("Grymxoria Road");
  lng = "This small cobblestone road heads east and west through the "
        "Estergrym Mountains. The mountains rise up on both sides of "
        "the road from here, dwarfing everything and casting deep shadows "
        "that prevent most light from reaching the floor of the valley. "
        "To the east lies the town of Grymxoria, while back to the west "
        "lie roads connecting Estergrym to the world.";
   
  w = ESTERGRYM_VIRTUAL "grymxoria_road/" + (x - 1) + "," + y;

  if(x < 40) {
      e = ESTERGRYM_VIRTUAL "grymxoria_road/" + (x + 1) + "," + y;
  }
  if (x == 0) {
      w = ESTERGRYM_VIRTUAL "northroad/0,20";
  }
  if (x == 36) {
      n = ESTERGRYM_AREAS "fwoods/room/forest4";
      lng += " A dark and forbidding forests lies to the north of the road.";
      }
  if (x == 39) {
      n = ESTERGRYM_AREAS "prisoncamp/room/gate";
      lng += " To the north an entrance has been carved in to the side "
             "of the mountain.";
  }
  if (x == 40) {
          s = ESTERGRYM_TOWNS "grymxoria/room/road1"; 
        ne = ESTERGRYM_AREAS "lake/room/road6";
        nw  = ESTERGRYM_AREAS "amelia_caves/room/rooma";
  lng = "This small cobblestone road heads west through the "
        "Estergrym Mountains. The mountains rise up on both sides of "
        "the road from here, dwarfing everything and casting deep shadows "
        "that prevent most light from reaching the floor of the valley. "
        "To the south looms the main gate of Grymxoria, while to the "
        "northeast the path continues, rising in to the mountains. To "
        "the west lie the roads connecting Estergrym to the world.";
  }
  if( n ) AddExit("north", n);
  if( s ) AddExit("south", s);
  if( e ) AddExit("east", e);
  if( w ) AddExit("west", w);
  if( ne ) AddExit("northeast", ne);
  if( nw ) AddExit("northwest", nw);
  SetLong(lng);
  SetLongAndItems(x, y);
}

static void SetLongAndItems(int x, int y) {
  mapping inv     = ([]);
  mapping items   = ([]);
  mapping itemadj = ([]);
/*
  string str = "";
  
  str = "This small cobblestone road heads east and west "
        "through the Estergrym Mountains. The mountains "
        "rise up on both sides of the road from here, dwarfing everything "
        "and casting deep shadows that prevent most light from reaching "
        "the floor of the valley. To the east lies the town of Grymxoria, "
        "while back to the west lie roads connecting Estergrym to the world.";
  SetLong(str);
*/
  SetItems(items);
  SetInventory(inv);
}

