#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_DAEMON;

mapping Docks = ([
SOUTHERN_COAST_TOWNS  "haven/room/wharf"  : ({  0, 1  }),
CRYSTAL_REACHES_TOWNS "lloryk/room/wharf" : ({ -88, 7  }),
CRYSTAL_REACHES_TOWNS "karak/room/rd7"    : ({ -68, -1 }),
CRYSTAL_REACHES_TOWNS "gwonish/room/gw01" : ({ -93, -1 }),
TAIRI_TOWNS           "tairi/room/path11" : ({ 150, -51  }),
AVERATH_TOWNS         "averath/room/wharf": ({ 0, -101 }),
AVERATH_TOWNS         "averath/room/charter" : ({ 1, -101 }),
PENINSULA_TOWNS       "sanctum/room/docks": ({ -32, -11 }),
PENINSULA_TOWNS       "sanctum/room/rd05" : ({ -25, -7 }),
HAVENWOOD_AREAS       "wood/rooms/beach15": ({ 11, 38 }),
HAVENWOOD_AREAS       "wood/rooms/beach14": ({ 11, 37 }),
HAVENWOOD_AREAS       "wood/rooms/beach13": ({ 11, 36 }),
HAVENWOOD_AREAS       "wood/rooms/beach12": ({ 11, 35 }),
HAVENWOOD_AREAS       "wood/rooms/beach11": ({ 10, 34 }),
HAVENWOOD_AREAS       "wood/rooms/beach10": ({ 9, 34 }),
HAVENWOOD_TOWNS       "parva/room/docks1" : ({  29, 46 }),
GUROV_TOWNS           "gurov/room/bay1"   : ({ -51, 109 }),
GUROV_TOWNS           "gurov/room/bay4"   : ({ -50, 109 }),
GUROV_TOWNS           "gurov/room/bay7"   : ({ -49, 109 }),
GUROV_TOWNS           "gurov/room/bay3"   : ({ -51, 111 }),
GUROV_TOWNS           "gurov/room/bay5"   : ({ -50, 110 }),
GUROV_TOWNS           "gurov/room/bay2"   : ({ -51, 110 }),
FROSTMARCHES_TOWNS    "keryth/room/wharf" : ({ -155, 111 }),
DOMAIN_ISLANDS        "areas/assassin/room/bay" : ({ 111, -299 }),
BARIA_TOWNS           "baria/room/path12" : ({ -150, 1 }),
XANDRIA_VIRTUAL       "river/-1,0"        : ({ -1, -501}),
ISLANDS_AREAS         "monkey/room/port"  : ({ -150, -19 }),
ISLANDS_AREAS         "sheep/room/port"   : ({ 14, -18 }),
SOUTHERN_COAST_AREAS  "meadow/rooms/meadow13" : ({ -19, 1 }),
SOUTHERN_COAST_AREAS  "meadow/rooms/meadow12" : ({ -20, 1 }),
SOUTHERN_COAST_AREAS  "meadow/rooms/meadow11" : ({ -21, 1 }),
SOUTHERN_COAST_AREAS  "acove/rooms/cove3"     : ({ -12, 2 }),
 ]);

mapping Towns = ([
"haven"   : SOUTHERN_COAST_TOWNS  "haven/room/wharf"  ,
"lloryk"  : CRYSTAL_REACHES_TOWNS "lloryk/room/wharf" ,
"tairi"   : TAIRI_TOWNS           "tairi/room/path11" ,
"averath" : AVERATH_TOWNS         "averath/room/wharf",
"sanctum" : PENINSULA_TOWNS       "sanctum/room/docks" ,
"parva"   : HAVENWOOD_TOWNS       "parva/room/docks1" ,
"gurov"   : GUROV_TOWNS           "gurov/room/bay5"   ,
"karak"   : CRYSTAL_REACHES_TOWNS "karak/room/rd7"   ,
"gwonish" : CRYSTAL_REACHES_TOWNS "gwonish/room/gw01"   ,
"keryth"  : FROSTMARCHES_TOWNS    "keryth/room/wharf" ,
"lisht"   : XANDRIA_VIRTUAL       "river/-1,0"       ,
"assassin": DOMAIN_ISLANDS        "areas/assassin/room/bay" ,
"baria"   : BARIA_TOWNS           "baria/room/path12" ,
]);

int ForcedEncounters = 1;

int *GetCoordinates(string room) {
  mixed *tmp = ({ });
  string *averath = ({ });
  int x, y, z;
  mixed captain = previous_object(-1);
  if (arrayp(captain)) captain = captain[0];
  if (Docks[room]) {
    tmp = Docks[room];
    return tmp;
  }
  tmp = explode(room, "/");
  if (sizeof(tmp) != 5) {
   //debug("Called for a room to coordinate translation of " + room + " by " + identify(captain));
   //if (!userp(captain)){debug(captain->GetName()); captain->eventDestruct();}
   // this shit doesn't work, commenting out. captain is the fucking ship, not player.
    return ({ });
    }
  if (tmp[1] == "xandria") {
     averath = explode(tmp[4], ",");
     x = to_int(averath[0]);
     y = to_int(averath[1]);
     tmp = ({ x, (y - 1501) });
     return tmp;
     }

  if (tmp[3] != "ocean") {
    debug("Called for a room to coordinate translation of " + room + " by " + identify(previous_object(-1)));
    return ({ });
  }
  tmp = explode(tmp[4], ",");
  foreach(mixed s in tmp) { tmp -= ({ s }); s = to_int(s); tmp += ({ s }); }
  return tmp;
}


string GetTownDock(string town) {
  if (!Towns[town]) return 0;
  return Towns[town];
}

string GetTowns() {
  return conjunction(keys(Towns), "and");
}

string *GetTownArray() { return keys(Towns); }

string *eventEncounter(object who, int x, int y) {
  mapping Encounter = ([ ]);
  object ship;
  string captain;
  int MySailing = who->GetSkillLevel("sailing");

  if (!userp(who)) { return ({ }); }
//  return ({ });  /* Temp Fix for sailing to not crash the mud */
  ship = environment(who);
  if (!ship = environment(ship)) return ({ });


  if (who->GetProperty("ship_debug")) debug("MySailing: " + MySailing + " (I am " + who->GetKeyName() + ")");
  Encounter += ([ INNERSEA_ENCOUNTERS "fisher/fisher" : INNERSEA_ENCOUNTERS "fisher/fishingboat" ]);
  Encounter += ([ INNERSEA_ENCOUNTERS "merchant/merchant" : INNERSEA_ENCOUNTERS "merchant/ship" ]);
  if (MySailing > 50) {
    Encounter += ([ INNERSEA_ENCOUNTERS "darkelf/darkelfcaptain" : INNERSEA_ENCOUNTERS "darkelf/caravel" ]);
  }
  if (MySailing > 260) {
    Encounter += ([ INNERSEA_ENCOUNTERS "undead/undeadcaptain" : INNERSEA_ENCOUNTERS "undead/undeadship" ]);
  }

  /* Near Haven Town */
  if (y < 15 && y > -50 && x < 20 && x > -20) {
    if (who->GetProperty("ship_debug")) debug("Near Haven Town Set");
    if (MySailing > 150) Encounter += ([ INNERSEA_ENCOUNTERS "havenelf/elfcaptain"    : INNERSEA_ENCOUNTERS "havenelf/warbird" ]);
    if (MySailing > 250) Encounter += ([ INNERSEA_ENCOUNTERS "havenelf/elfmarine"     : INNERSEA_ENCOUNTERS "havenelf/warbird" ]);
    if (MySailing > 250) Encounter += ([ INNERSEA_ENCOUNTERS "elfwarship/handcaptain" : INNERSEA_ENCOUNTERS "elfwarship/elvenwarship" ]);
  }

  /* Namatar */
  if (x > -400 && x < -300 && y > -50 && y < 50) {
    if (who->GetProperty("ship_debug")) debug("Near Namatar Set");
  }

  /* West of Sanctum */
  if (x < -30 || x > 400) {
    if (who->GetProperty("ship_debug")) debug("West of Sanctum Set");
    if (MySailing > 120) Encounter += ([ INNERSEA_ENCOUNTERS "viking/godenviking" : INNERSEA_ENCOUNTERS "viking/longship"]);
    if (MySailing > 200) Encounter += ([ INNERSEA_ENCOUNTERS "pirate/piratecaptain" : INNERSEA_ENCOUNTERS "pirate/warship"]);
  }

  /* East of Sanctum (Parva) */
  if (x >= -30 || x <= 400 ) {
    if (MySailing > 200) Encounter += ([ INNERSEA_ENCOUNTERS "elemental_water/nereid" : INNERSEA_ENCOUNTERS "elemental_water/galleon" ]);
    if (MySailing > 400) Encounter += ([ INNERSEA_ENCOUNTERS "delf_marauder/corsair" : INNERSEA_ENCOUNTERS "delf_marauder/demarauder" ]);
  }

  /* Karak to Baria */
  if (y < 25 && y > -300 && x > -175 && x < -50) {
    if (who->GetProperty("ship_debug")) debug("KarakBaria Set");
    Encounter += ([ INNERSEA_ENCOUNTERS "lizardcanoe/liz_raider" : INNERSEA_ENCOUNTERS "lizardcanoe/canoe" ]);
    if (MySailing > 300) Encounter += ([ INNERSEA_ENCOUNTERS "orcknarr/shaman" : INNERSEA_ENCOUNTERS "orcknarr/knarr" ]);
  }

  /* Xandria */
  if (y < -400) {
    if (who->GetProperty("ship_debug")) debug("Xandria Set");
  }

  /* Tairi */
  if (x >= 80 && x <= 220 && y <= -30 && y >= -160) {
    if (who->GetProperty("ship_debug")) debug("Tairi Set");
    Encounter += ([ INNERSEA_ENCOUNTERS "taifisher/fisher" : INNERSEA_ENCOUNTERS "taifisher/taifishingboat" ]);
    Encounter += ([ INNERSEA_ENCOUNTERS "wako/wakocaptain" : INNERSEA_ENCOUNTERS "wako/taigalley" ]);
  }

  /* Averath */
  if (y < -50 && y > -150 && x > -50 && x < 50) {
    if (who->GetProperty("ship_debug")) debug("Averath Set");
    if (MySailing > 45) Encounter += ([ INNERSEA_ENCOUNTERS "averath_corvair/ensign" : INNERSEA_ENCOUNTERS "averath_corvair/corvair" ]);
  }

  if (who->GetProperty("ship_debug")) debug(implode(keys(Encounter), ", "));
  //if (!random(25) ) {
  if (1) { // vehicle.c handles the random % currently. there's no need for another.
    if (who->GetProperty("ship_debug")) debug("!random(25)");
    captain = keys(Encounter)[random(sizeof(keys(Encounter)))];
  }
  if (who->GetProperty("ship_debug") && captain) debug("%^RED%^" + captain + "%^RESET%^");
  return ({ captain, Encounter[captain] });
}

int eventGenerateEncounter(string fcaptain, string fship) {
        object captain, ship;
        object MyShip = environment(this_player());

        if (!environment(MyShip)) return 0;
        MyShip = environment(MyShip);

  if (!fship) return;
  ship = new(fship);
  if (!ship) return;
  captain = new(fcaptain);
  if (!captain) {
    ship->eventDestruct();
    return;
  }
  ship->eventMove(MyShip);
  ship->ResetExit();
  ship->SetCaptain(captain->GetKeyName());
  captain->eventMove(ship);
  this_player()->eventEncounterShip(ship);
  environment(ship)->eventPrint(capitalize(ship->GetShort()) + " has moved within our sights!");
}

void createShipEncounter(int x, int y) {
  string *encounter = ({ });
  if (base_name(environment(this_player())) == "/domains/innersea/virtual/ocean") {
    if (this_player()->GetProperty("ship_debug")) debug("base_name");
    return;
  }
  if (!environment(this_player())) {
    if (this_player()->GetProperty("ship_debug")) debug("!env(tp");
    return;
  }
  if (!sizeof(filter(all_inventory(environment(this_player())), (: userp :)))) {
    if (this_player()->GetProperty("ship_debug")) debug("non userp");
    return;
  }
  if (this_player()->GetProperty("ship_debug")) debug("cSE no return");
  if (userp(this_player()))   encounter = eventEncounter(this_player(), x, y);
  if (sizeof(encounter) == 2) eventGenerateEncounter(encounter[0], encounter[1]);
}

