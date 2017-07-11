// mahkefel 20101117  
// gave unique items. change desc to 1 eye!
// mahkefel 2011                           
//   gave them little secondary boarders that will attack passengers on
//   the boat. something to involve travelling players in fight where  
//   they can contribute if lower level.                               
#include <lib.h>                                                       
#include <domains.h>                                                   
#include <std.h>                                                       
#include <damage_types.h>                                              
inherit LIB_PIRATE;                                               

static void create() {
  ::create();         
  SetKeyName("pirate captain");
  SetShort("a pirate captain (goden)");
  SetId( ({ "captain", "pirate", "goden" }) );
  SetAdjectives( ({ "pirate", "goden" }) );   
  SetRace("goden");                           
  SetTown("Keryth");                          
  SetClass("viking");                         
  SetLevel(100);                              
  SetLong("At around seven feet tall, this goden captain is one of the largest "
    "of his species. While somewhat lacking in muscle, his body looks very "    
    "agile. His keen eye darts around as he inspects his vessel and crew.");    
  SetGender("male");                                                            
  SetCaptainAggressiveness(110);                                                
  SetInventory( ([                                                              
    STD_WEAPON + "knife/stiletto" : "wield stiletto",                           
    INNERSEA_ENCOUNTERS "obj/eyepatch_leather" : "wear eyepatch",               
    ]) );                                                                       
  SetProperty("pirate", "goden");                                                     
  SetShipWander(1);                                                             
  SetCurrency("senones", 20000);                                                
  pirates = ({ });
  SetMinLevel(80);
  SetMaxLevel(80);
  SetBoarder(INNERSEA_ENCOUNTERS "pirate/piratemen");
  SetFirstMate(INNERSEA_ENCOUNTERS "pirate/piratemen");
  SetPassengerAttacker(INNERSEA_ENCOUNTERS "pirate/smallboarder");
  ScuttlesShip = 1;
}                                                                               

