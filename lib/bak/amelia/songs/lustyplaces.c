#include <domains.h>
#include <music.h>
#include <lib.h>
inherit LIB_SONG;

private mapping LustyPlaces = ([
"blah" : "/realms/amelia/areas/balz/room/eta",
"Averath"     : AVERATH_CITY          "tavern",
"Baria"       : BARIA_TOWNS           "baria/room/commonhut", 
"Durgoroth"   : FROSTMARCHES_TOWNS    "durgoroth/room/tavern",
"Glimmerdin"  : CRYSTAL_REACHES_TOWNS "glimmerdin/room/inn",
"Glistendin"  : AVERATH_AREAS         "glimmerdin/room/tavern",
"Grymxoria"   : ESTERGRYM_TOWNS       "grymxoria/room/p_inn", // no inn
"Gwonish"     : CRYSTAL_REACHES_TOWNS "gwonish/room/gw08", // no inn??
"Gurov"       : GUROV_TOWNS           "gurov/room/inn2", // Nubile Noble Inn
"Haven"       : SOUTHERN_COAST_TOWNS  "haven/room/shops/tavern",
"Jidoor"      : VALLEY_TOWNS          "jidoor/room/misc_buildings/inn",
"Karak"       : CRYSTAL_REACHES_TOWNS "karak/room/shop",
"Keryth"      : FROSTMARCHES_TOWNS    "keryth/room/tavern",
"Lloryk"      : CRYSTAL_REACHES_TOWNS "lloryk/room/gen_store",
"Malveillant" : HAVENWOOD_TOWNS       "malveillant/rooms/inn",
"Parva"       : HAVENWOOD_TOWNS       "parva/room/inn",
"Soleil"      : WESTWOOD_TOWNS        "soleil/room/inn",
"Sanctum"     : PENINSULA_TOWNS      "sanctum/room/inn",
"Tairi"       : TAIRI_TOWNS           "tairi/room/inn",
  ]);

private mapping LustySongs = ([
"blah" : "blahblah",
"Averath"     : "Averath",
"Baria"       : "Baria", 
"Durgoroth"   : "Durgoroth",
"Glimmerdin"  : CRYSTAL_REACHES_TOWNS "glimmerdin/room/inn",
"Glistendin"  : AVERATH_AREAS         "glimmerdin/room/tavern",
"Grymxoria"   : ESTERGRYM_TOWNS       "grymxoria/room/p_inn", // no inn
"Gwonish"     : CRYSTAL_REACHES_TOWNS "gwonish/room/gw08", // no inn??
"Gurov"       : GUROV_TOWNS           "gurov/room/inn2", // Nubile Noble Inn
"Haven"       : SOUTHERN_COAST_TOWNS  "haven/room/shops/tavern",
"Jidoor"      : VALLEY_TOWNS          "jidoor/room/misc_buildings/inn",
"Karak"       : CRYSTAL_REACHES_TOWNS "karak/room/shop",
"Keryth"      : FROSTMARCHES_TOWNS    "keryth/room/tavern",
"Lloryk"      : CRYSTAL_REACHES_TOWNS "lloryk/room/gen_store",
"Malveillant" : HAVENWOOD_TOWNS       "malveillant/rooms/inn",
"Parva"       : HAVENWOOD_TOWNS       "parva/room/inn",
"Soleil"      : WESTWOOD_TOWNS        "soleil/room/inn",
"Sanctum"     : PENINSULA_TOWNS      "sanctum/room/inn",
"Tairi"       : TAIRI_TOWNS           "tairi/room/inn",
  ]);

static void create() {
  ::create();
  SetSong("lusty places");
  SetRules("STR");
  SetSongType(SONG_OTHER);
  SetMagicCost(75, 75);
  SetStaminaCost(75, 75);
  SetDifficulty(50);
  SetSkills( ([
    "vocal music" : 50,
    "instrumental music" : 50,
    ]) );
  SetHelp("This song causes the bard to focus his energy thinking of "
          "a far away place from the description given in bardic "
          "stories.  While thinking of the place, the bard will actually "
          "be moved there from the magic of his song.  Be warned that "
          "this songs does not always work until the bard is very "
          "proficient with it." +
          "\nCurrently allowed Lusty Places are " +
          conjunction(keys(LustyPlaces)));
   }

varargs object *GetTargets(object who, mixed place) {
    who->eventPrint("Bleck?");
    find_player("amelia")->eventPrint("Target thing" + place);
    return ({ (object)"/realms/amelia/balz/room/eta" });
//  return ({ (object)LustyPlaces[place] });
}
 
varargs int CanSing(object who, int level, string place, object *dest) {
    who->eventPrint("Dfkldf." + place);
    return ::CanSing(who, level, place, dest);
}

varargs int eventSing(object who, int level, string place, object *dest) {
  object target = dest[0];
  if (random(100) < who->GetSongLevel("lusty places")) {
    send_messages( ({ "sing", "finish", "disappear" }),
  "$agent_name $agent_verb a song about " + LustySongs[target] + ". "
      "After $agent_nominative $agent_verb $agent_possessive song, "
      "$agent_nominative $agent_verb.",
      who, 0, environment(who) );
      who->eventMove(target);
      return 1;
      }
   send_messages( ({ "sing", "finish", "look" }),
  "$agent_name $agent_verb a song about " + LustySongs[target] + ". "
     "When $agent_nominative $agent_verb $agent_possessive song, $agent_nominative "
     "$agent_verb slightly depressed.",
     who, 0, environment(who) );
   who->AddStaminaPoints(75);  /* Give back the base cost for failure */
   who->AddMagicPoints(75);
   return 1;
 }