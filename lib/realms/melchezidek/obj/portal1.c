/*  
 *  Portal object for Portal from HavenWood 
 *  to Tairi 
 *    -Melchezidek 7-13-08 
 */ 
 
#include <lib.h> 
#include <std.h> 
#include <domains.h> 
 
inherit LIB_ITEM; 
inherit LIB_SMELL; 
 
static void create() { 
  ::create(); 
  SetId( ({"flowers", "portal" }) ); 
  SetAdjectives( ({"patch of", "lotus"}) ); 
  SetShort("a patch of lotus flowers"); 
  SetLong("This is a patch of beautiful violet and pink lotus" 
          " flowers. The pollen swirls from flower to flower" 
          " in a magical way."); 
  SetPreventGet("A magical force prevents you from getting the flowers."); 
  SetSmell("The smell is overwhelming."); 
  SetProperty("magic", "This patch of flowers will transport one who smells" 
                       " them to Tairi."); 
  SetMass(250); 
} 
 
 
varargs mixed eventSmell(object who, string str) { 
    string DST; 
 
/* Check for the destination */ 
 
      if (base_name(environment(who)) == "/domains/tairi/areas/copse/room/room6") { 
            DST = "/domains/havenwood/areas/wood/rooms/beach22"; 
          } 
      if (base_name(environment(who)) == "/domains/havenwood/areas/wood/rooms/beach22") { 
            DST = "/domains/tairi/areas/copse/room/room6"; 
          } 
 
/* Events and Messages of transportation */ 
 
      send_messages( ({"smell", "drift"}), 
                    "$agent_name $agent_verb the lotus flowers and $agent_verb away to a far" 
                    " away land.", who, 0, environment(who)); 
      who->eventPrint("%^GREEN%^The world blurs as you are swept away by the wind.%^GREEN%^"); 
      who->eventMove(DST); 
      send_messages( ({"land", "drift"}), 
                    "$agent_name $agent_verb roughly in a cloud of lotus petals.", 
                     who, 0, environment(who)); 
      who->SetParalyzed(3); 
      who->AddRecoveryTime(100); 
      return 1; 
} 
 
mixed direct_smell_obj() { 
   return smell::direct_smell_obj(); 
} 
 
