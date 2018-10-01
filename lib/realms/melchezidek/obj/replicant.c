#include <lib.h> 
#include <daemons.h> 
 
inherit LIB_NPC; 
 
void eventWarning(); 
void eventDissolve(); 
 
static void create() { 
  ::create(); 
  SetKeyName("replicant"); 
  SetShort("a relicant"); 
  SetDie("The replicant disappears."); 
  SetNoCorpse(1); 
  call_out((: eventWarning :), ((GetLevel() * 10) - 15)); 
} 
 
void eventWarning() { 
    eventForce("emote becomes transparent for a moment."); 
    call_out((: eventDissolve :), 15); 
} 
 
void eventDissolve() { 
     message("dissolve", "The replicant dissolves into thin air.", environment()); 
     eventDestruct(); 
} 
