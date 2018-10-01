// Dalnairn
// Aerelus
// updated for dalnairn recode torak@haven 2017

#include <lib.h>
#include <std.h>
#include "../../dalnairn.h"
inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetInventory( ([
     DAL_WPN "sword"             : 2,
     DAL_WPN "hooked_axe"        : 2,
     STD_KNIFE "stiletto"        : 2,
     DAL_ARM "lwallshield"       : 2,
     DAL_ARM "chainboots"        : 1,
     DAL_ARM "chaincuisse"       : 1,
     DAL_ARM "chaingauntlet"     : 2,
     DAL_ARM "chainhelm"         : 1,
     DAL_ARM "chainvest"         : 1,
     DAL_ARM "lorica"            : 1,
     DAL_ARM "greaves"           : 1,
     DAL_ARM "hsteelboots"       : 1,
     DAL_ARM "hsteelbreastplate" : 1,
     DAL_ARM "hsteelcuisse"      : 1,
     DAL_ARM "hsteelgauntlet"    : 2,
     DAL_ARM "hsteelhelm"        : 1,
     DAL_ARM "steelboots"        : 1,
     DAL_ARM "steelbreastplate"  : 1,
     DAL_ARM "steelcuisse"       : 1,
     DAL_ARM "steelgauntlet"     : 2,
     DAL_ARM "steelhelm"         : 1,
   ]) );
   SetPurgeInterval(3);
}
