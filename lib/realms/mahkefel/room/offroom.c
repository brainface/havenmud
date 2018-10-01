#include <lib.h>                                    
#include <daemons.h>                                
#define TARGET  "/domains/havenwood/areas/parvahosp/npc/hurt"
#define BANDIT  "/std/invasions/bandit/bandit"               
#define PENGUIN   "/realms/mahkefel/npc/zcow"                   


inherit LIB_ROOM;                                            
int PreExit(string dir);                                     
int Shielded = 0;                                            
static void create() {                                       
  room::create();                                            
  SetShort("a room");                                        
  SetProperties( ([                                          
     "wood repair" : 1,                                      
     "metal repair" : 1,                                     
     "natural repair" : 1,                                   
     "textile repair" : 1,                                   
     ]) );                                                   
  SetClimate("arctic");                                      
  SetAmbientLight(40);                                       
  SetInventory( ([                                           
    ]) );                                                    
  SetAmbientLight(40);                                       
  //SetExits( ([                                               
  //  "down" : "/domains/averath/towns/averath/room/wharf",    
  //   ]) );                                                   
  AddExit("north", "../workroom", (: PreExit :) );           
  SetLong("This is a small room.  There is a sign on the wall. "
          "There is a hall of mirrors to the north.");                       
  SetItems( ([                                                    
     "sign"  : "This is a sign.  It has words on it.",            
    ]) );                                                         
  SetRead( ([                                                     
     "sign" : "Functions of this room which are very nice: \n"    
             "summon <thing, filename, no argument> \n"           
             "healme \n"
             "spellme [spell], songme [song]\n"                                          
             "outside,inside \n",                                                    
    ]) );                                                         
  SetEnters( ([                                                   
     //"inn" : "/domains/southern_coast/areas/wtraveller/room/wtraveller",
     //"coffeehouse" : "/domains/southern_coast/areas/coffeehouse/room/coffeehouse",
     ]) );                                                                        
 }                                                                                

void init() {
  ::init();  
  add_action("spellme", "spellme");
  add_action("songme", "songme");  
  add_action("shield", "shield");  
  add_action("summon", "summon");  
  add_action("healme", "healme");  
  add_action("outside", "outside");
  add_action("inside", "inside");
 }                                 

int spellme(string args) {
  int x;
  if (!(SPELLS_D->GetSpell(args))) {
     this_player()->eventPrint("No such spell.");
     return 1;
     }
  if (x = (this_player()->eventLearnSpell(args))) {
     this_player()->SetSpellBookLevel(args, 100);
     this_player()->eventPrint("You succeed.");
    return 1;
    }
  else {
     this_player()->eventPrint("You failed to learn that spell.");
      return 1;
   }
}

int summon(string args) {
   object thing;
  if (!args) args = PENGUIN;
  if (args == "cow") args = PENGUIN;
  if (args == "bandit") args = BANDIT;
  if (args == "target") args = TARGET;
  thing = new(args);
  if (!thing) {
     this_player()->eventPrint("BadThing[tm]");
     return 1;
   }
  thing->eventMove(this_object());
   thing->eventForce("speak You summoned me?");
  return 1;
}

int healme() {
  this_player()->eventCompleteHeal(2500);
  this_player()->eventPrint("You feel much better now.");
  this_player()->SetUndead(0);
  this_player()->SetParalyzed(0);
  this_player()->SetSleeping(0);
  this_player()->SetRecoveryTime(0);
 return 1;
 }

int PreExit(string dir) {
  if (Shielded && !userp(this_player())) {
     return 0;
     }
   return 1;
   }

int shield(string str) {
  if (Shielded) {
       Shielded = 0;
         }
       else {
          Shielded = 1;
         }
   return Shielded;
  }

int songme(string song) {
  if (this_player()->eventLearnSong(song)) {
    this_player()->SetSongBookLevel(song, 100);
    message("system", "Yes.", this_player());
    return 1;
    }
    message("system", "No.", this_player());
    return 0;
 }

int outside() {
  SetClimate("arid");
  eventPrint("Suddenly you stand in the desert.");
  return 1; 
}

int inside() {
  SetClimate("indoors");
  eventPrint("Suddenly walls surround you.");
  return 1;
}

