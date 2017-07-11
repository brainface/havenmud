// mahkefel may '10
// water elemental boarder
#include <lib.h>          
#include <domains.h>      
#include <std.h>          
#include <damage_types.h> 
inherit LIB_PIRATE;       

void eventSpecial();
int eventFishies(); 

static void create() {
  ::create();         
  SetRace("elemental");
  SetGender("male");   
  SetClass("fighter"); 
  SetClass("sailor");  
  SetLevel(100);       
  SetKeyName("elemental");
  SetId( ({ "elemental" }) );
  SetShort("a brine elemental");
  SetAdjectives( ({ "brine","water" }) );
  SetLong(                               
    "This water elemental is a flowing beast formed out of the"
    " sea itself. Brine and seaweed mat its surface, and small fish"
    " can be seen struggling to escape its core."                   
  );                                                                
  SetAction(5, ({                                                   
    "!wave",                                                        
  }) );                                                             
  SetCombatAction( 15,                                          
    (: eventSpecial :),                                             
  );                                                             
  SetInventory( ([                                                  
    INNERSEA_ENCOUNTERS "obj/trident" : "wield trident",            
  ]) );                                                             
  SetCaptainAggressiveness(80);                                     
  SetResistance(WATER, "immune");                                   
  SetResistance(COLD|MAGIC|POISON, "high");                         
  SetResistance(SHOCK|HEAT, "weakness");                            
  SetResistance(HEAT, "weakness");                                  
  SetProperty("pirate", "nereid");                                  
  SetShipWander(1);                                                 
  SetNoCorpse(1);                                                   
  SetDie( (:eventFishies:) );                                       

  SetReligion("Damhair");
  SetTown("Parva");      
  SetMinLevel(105);
  SetMaxLevel(300);      
}                        

// decays enemies weapons and deals some damage.
void eventSpecial() {                           
  object who = this_object();                   
  object target = GetCurrentEnemy();            
  if (!who || !target) return;                  
  send_messages("drown",                        
    "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name with a huge gush of water!",
    who, target, environment() );                                                      
  target->eventReceiveDamage(who, WATER,                                               
    GetDamage(GetSkillLevel("melee combat"),                                           
    "melee combat", target->GetDefense()) * 5,                                         
    0, target->GetRandomLimb() );                                                      
  for(int i=0;i<random(4)+1;i++) {
    object array eq = all_inventory(target);
    if(sizeof(eq)) {
      object thing = (eq[random(sizeof(eq))]);
      send_messages("",
        "The gush of water %^BLUE%^erodes%^RESET%^ $target_possessive_noun " +
        remove_article(thing->GetShort())+"!",
        who, target, environment(who));
      thing->eventDeteriorate(WATER);
    }
  }
}

// cause it's funny.
int eventFishies(object killer) {
  string *fishyfishies;
  send_messages("", "A brine elemental %^BOLD%^BLUE%^collapses%^RESET%^ into a messy ball of "
    "seawead and struggling fish!", this_object(),0,environment(this_object()) );

  fishyfishies = ({ STD_FISH "guppy_food"});
  if (random(2)) fishyfishies += ({STD_FISH "guppy_food"});
  if (random(2)) fishyfishies += ({STD_FISH "seabass_food"});
  if (random(4)) fishyfishies += ({STD_FISH "swordfish_food"});
  if (random(4)) fishyfishies += ({STD_FISH "mako_food"});
  foreach( string fishy in fishyfishies ) {
    object fish = new(fishy);
    fish->eventMove(environment(this_object()));
  }
  return 1;
}

