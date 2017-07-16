/* created by Brugor
 * Sept 2006
 * Slaver's Market - Market Center
 */
 
#include <lib.h>
#include "../slavers_market.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("market center");
  SetClimate("temperate");
  SetNightLight(25);
  SetNightLong(
     "The market center is deserted during the night hours.  The blood "
     "and feces from the daytime activities has mixed completely with "
     "the ground.  The fire pit glows casting shadows about market center.  "
     "There are several wooden pens, which are located east of here.  A "
     "path runs northwest and southwest to other parts of the market.  "
     "A large tent is off to the west.");
  SetDayLong(
     "The market center is bustling with activity.  The ground is wet "
     "from blood and feces of the slaves and livestock being sold.  A "
     "small fire is burning in the fire pit in the center with long iron "
     "brands sticking out of the pit.  There are several wooden pens, "
     "which are located east of here.  A path runs northwest and southwest "
     "to other parts of the market.  A large tent is off to the west.");
  SetItems( ([ 
     ({"center", "market"}) : (: GetLong :),
     ({"blood", "feces", "gound"}) :
     "The blood and feces from the slaves and livestock cover the "
     "ground of the market center.",
     ({"pit", "fire"}) :
     "the fire pit has a small fire to keep the iron brands red hot "
     "for the slavers.",
     ({"shadow", "shadows"}) :
     "The shadows from the glowing fire dance around.",
     ({"pen", "pens"}) :
     "there are three wooden pens located east of the market center.  "
     "The pens have doors facing the market center which look guarded.",
     ({"path", "paths", "parts"}) :
     "A well-worn paths lead northwest down towards the seaward gate "
     "and southwest up towards the Estergrym Mountains.  A path also "
     "leads west towards a large gray tent.",
     ({"tent"}) :
     "A large gray tent stands in the west",
     ({"slave", "slaves", "livestock"}) :
     "The slaves and livestock, looking at all the blood and feces, "
     "are sold and slaughtered all in the market center.", 
     ({"brand", "brands"}) : 
     "This long rounded black piece of metal is as thick as a staff "
     "with brown leather straps on one end and a small symbol etched "
     "into the other which is glowing red. The symbol is that of a half "
     "moon with a three arrows piercing it.",
     ({"gate"}) : 
     "The seaward gate can be seen north of here.  A northwestern path "
     "heads down towards this gate.",
     ({"Estergrym Mountains", "mountain", "mountains"}) :
     "A southwestern path leads up towards to the Estergym Mountains.",
     ]) );
  SetItemAdjectives( ([
     "center" : ({"market"}),
     "pit"    : ({"fire"}),
     "fire"   : ({"small", "glowing"}),
     "brand"  : ({"iron", "long", "rounded", "black", "metal"}),
     "shadow" : ({"dancing", "casting"}),
     "pen"    : ({"three", "wooden", "several"}),
     "path"   : ({"well-worn", "worn"}),
     "gate"   : ({"seaward"}),
     "tent"   : ({"large", "gray"}),
     "parts"  : ({"other"}),
     ]) );
  SetListen( ([
     "default" : "Grunts and hushed cries can be heard."
     ]) );
  SetSmell( ([
     "brand"   : "The stink of burned flesh eminates off the brand.",
     "default" : "The scent of burning wood fills the air."
     ]) );
  
  SetInventory( ([
        ]) );
  SetExits( ([
     "west"      : "/realms/aerelus/test/room/market_center.c",     
     ]) );
  
 }
