// changed by mahkefel april 2011: added arcanith, namatar
#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Davantalus' Portal Room");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetObviousExits("west, or \"enter <desintation>\"");
  SetLong("Use this room to get around the world. \n"
          "Enters are arcanith, averath, baria, dalnairn, durgoroth, fire, first, "
          "forest, glimmerdin, grymxoria, gurov, gwonish, haven, havenwood, "
          "heaven, jidoor, karak, keryth, kresh, lisht, lloryk, malveillant, "
          "namatar, parva, sanctum, soleil, staffroom, tairi, unghk, upper, vacazar, "
          "void, and yozrath. ");
  SetItems( ([
     "arcanith"   : "/domains/frostmarches/towns/arcanith/room/ruins1",
     "averath"    : "/domains/averath/towns/averath/room/road2",
     "baria"      : "/domains/baria/towns/baria/room/path9",
     "dalnairn"   : "/domains/averath/towns/dalnairn/road2",
     "durgoroth"  : "/domains/frostmarches/towns/durgoroth/room/fountain",
     "fire"       : "/domains/planes/virtual/fire/0,0",
     "first"      : "/domains/planes/virtual/first/0,0",
     "forest"     : "/domains/planes/virtual/forest/0,0",
     "glimmerdin" : "/domains/crystal_reaches/towns/glimmerdin/room/gh_central",
     "grymxoria"  : "/domains/estergrym/towns/grymxoria/room/road16",
     "gwonish"    : "/domains/crystal_reaches/towns/gwonish/room/gw05",
     "gurov"      : "/domains/gurov/towns/gurov/room/cr3",
     "haven"      : "/domains/southern_coast/towns/haven/room/imperial_road/ir2",
     "havenwood"  : "/domains/havenwood/towns/havenwood/room/gelf1",
     "heaven"     : "/domains/staff/staffroom",
     "jidoor"     : "/domains/valley/towns/jidoor/room/twnsquare",
     "karak"      : "/domains/crystal_reaches/towns/karak/room/rd3",
     "keryth"     : "/domains/frostmarches/towns/keryth/room/road2",
     "kresh"      : "/domains/southern_coast/towns/kresh/room/m_3",
     "lisht"      : "/domains/xandria/towns/lisht/room/gnoll/gate",
     "lloryk"     : "/domains/crystal_reaches/towns/lloryk/room/uh5",
     "malveillant": "/domains/havenwood/towns/malveillant/rooms/center1",
     "namatar"    : "/domains/namatar/virtual/namatar/-351,49",
     "parva"      : "/domains/havenwood/towns/parva/room/path2",
     "sanctum"    : "/domains/peninsula/towns/sanctum/room/vi05",
     "soleil"     : "/domains/westwood/towns/soleil/room/tree_b",
     "staffroom"  : "/domains/staff/staffroom",
     "tairi"      : "/domains/tairi/towns/tairi/room/path6",
     "ungkh"      : "/domains/crystal_reaches/areas/ungkh/room/road02",
     "upper"      : "/domains/planes/virtual/upper/0,0",
     "vacazar"    : "/domains/estergrym/towns/vacazar/room/main_road/mr4",
     "void"       : "/domains/staff/adm/void",
     "yozrath"    : "/domains/yozrath/towns/yozrath/room/gate3",
  ]) );

  SetExits( ([
     "west" : "/domains/staff/staffroom",
  ]) );

  SetEnters( ([
     "arcanith"   : "/domains/frostmarches/towns/arcanith/room/ruins1",
     "averath"    : "/domains/averath/towns/averath/room/road2",
     "baria"      : "/domains/baria/towns/baria/room/path9",
     "dalnairn"   : "/domains/averath/towns/dalnairn/",
     "durgoroth"  : "/domains/frostmarches/towns/durgoroth/room/fountain",
     "fire"       : "/domains/planes/virtual/fire/0,0",
     "first"      : "/domains/planes/virtual/first/0,0",
     "forest"     : "/domains/planes/virtual/forest/0,0",
     "glimmerdin" : "/domains/crystal_reaches/towns/glimmerdin/room/gh_central",
     "grymxoria"  : "/domains/estergrym/towns/grymxoria/room/road16",
     "gurov"      : "/domains/gurov/towns/gurov/room/cr3",
     "gwonish"    : "/domains/crystal_reaches/towns/gwonish/room/gw05",
     "haven"      : "/domains/southern_coast/towns/haven/room/imperial_road/ir2",
     "havenwood"  : "/domains/havenwood/towns/havenwood/room/gelf1",
     "heaven"     : "/domains/staff/staffroom",
     "jidoor"     : "/domains/valley/towns/jidoor/room/twnsquare",
     "karak"      : "/domains/crystal_reaches/towns/karak/room/rd3",
     "keryth"     : "/domains/frostmarches/towns/keryth/room/road2",
     "kresh"      : "/domains/southern_coast/towns/kresh/room/m_3",
     "lisht"      : "/domains/xandria/towns/lisht/room/gnoll/gate",
     "lloryk"     : "/domains/crystal_reaches/towns/lloryk/room/uh5",
     "malveillant": "/domains/havenwood/towns/malveillant/rooms/center1",
     "namatar"    : "/domains/namatar/virtual/namatar/-351,49",
     "parva"      : "/domains/havenwood/towns/parva/room/path2",
     "sanctum"    : "/domains/peninsula/towns/sanctum/room/vi05",
     "soleil"     : "/domains/westwood/towns/soleil/room/tree_b",
     "staffroom"  : "/domains/staff/staffroom",
     "tairi"      : "/domains/tairi/towns/tairi/room/path6",
     "ungkh"      : "/domains/crystal_reaches/areas/ungkh/room/road02",
     "upper"      : "/domains/planes/virtual/upper/0,0",
     "vacazar"    : "/domains/estergrym/towns/vacazar/room/main_road/mr4",
     "void"       : "/domains/staff/adm/void",
     "yozrath"    : "/domains/yozrath/towns/yozrath/room/gate3",
  ]) );
}
